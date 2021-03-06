#include "ChannelDataView.h"
#include "ChanneldUtils.h"

//DEFINE_LOG_CATEGORY(LogChanneld);

UChannelDataView::UChannelDataView(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void UChannelDataView::Initialize(UChanneldConnection* InConn)
{
	if (Connection == nullptr)
	{
		Connection = InConn;

		LoadCmdLineArgs();

		Connection->AddMessageHandler(channeldpb::CHANNEL_DATA_UPDATE, this, &UChannelDataView::HandleChannelDataUpdate);
		Connection->AddMessageHandler(channeldpb::UNSUB_FROM_CHANNEL, this, &UChannelDataView::HandleUnsub);
	}

	InitChannels();
	
	UE_LOG(LogChanneld, Log, TEXT("%s initialized channels."), *this->GetClass()->GetName());
}

void UChannelDataView::Unitialize()
{
	if (Connection != nullptr)
	{
		Connection->RemoveMessageHandler(channeldpb::CHANNEL_DATA_UPDATE, this);
	}

	UninitChannels();

	UE_LOG(LogChanneld, Log, TEXT("%s uninitialized channels."), *this->GetClass()->GetName());
}

void UChannelDataView::AddProvider(ChannelId ChId, IChannelDataProvider* Provider)
{
	TSet<IChannelDataProvider*> Providers = ChannelDataProviders.FindOrAdd(ChId);
	Providers.Add(Provider);

	UE_LOG(LogChanneld, Log, TEXT("Added channel data provider %s to channel %d"), *ChanneldUtils::GetProviderName(Provider), ChId);
}

void UChannelDataView::RemoveProvider(ChannelId ChId, IChannelDataProvider* Provider, bool bSendRemoved)
{
	auto Providers = ChannelDataProviders.Find(ChId);
	if (Providers != nullptr)
	{
		UE_LOG(LogChanneld, Log, TEXT("Removing channel data provider %s from channel %d"), *ChanneldUtils::GetProviderName(Provider), ChId);
		
		if (bSendRemoved)
		{
			Provider->SetRemoved();
		}
		else
		{
			Providers->Remove(Provider);
		}
	}
}

void UChannelDataView::RemoveProviderFromAllChannels(IChannelDataProvider* Provider, bool bSendRemoved)
{
	if (Connection == nullptr)
	{
		UE_LOG(LogChanneld, Error, TEXT("Unable to call UChannelDataView::RemoveProviderFromAllChannels. The connection to channeld hasn't been set up yet and there's no subscription to any channel."));
		return;
	}

	for (auto& Pair : Connection->SubscribedChannels)
	{
		if (Pair.Value->channeltype() == Provider->GetChannelType())
		{
			RemoveProvider(Pair.Key, Provider, bSendRemoved);
			return;
		}
	}
}

void UChannelDataView::OnDisconnect()
{
	for (auto& Pair : ChannelDataProviders)
	{
		for (auto Provider : Pair.Value)
		{
			Provider->SetRemoved();
		}
	}

	// Force to send the channel update data with the removed states to channeld
	SendAllChannelUpdates();
}

void UChannelDataView::SendAllChannelUpdates()
{
	if (Connection == nullptr)
		return;

	for (auto& Pair : Connection->SubscribedChannels)
	{
		if (Pair.Value->suboptions().dataaccess() == channeldpb::WRITE_ACCESS)
		{
			ChannelId ChId = Pair.Key;
			auto Providers = ChannelDataProviders.Find(ChId);
			if (Providers == nullptr)
				continue;

			auto MsgTemplate = ChannelDataTemplates.FindRef(Pair.Value->channeltype());
			if (MsgTemplate == nullptr)
				continue;

			auto NewState = MsgTemplate->New();

			int UpdateCount = 0;
			int RemovedCount = 0;
			for (auto Itr = Providers->CreateIterator(); Itr; ++Itr)
			{
				auto Provider = Itr.ElementIt;
				if (Provider->Value->UpdateChannelData(NewState))
					UpdateCount++;
				if (Provider->Value->IsRemoved())
				{
					Itr.RemoveCurrent();
					RemovedCount++;
				}
			}
			if (RemovedCount > 0)
				UE_LOG(LogChanneld, Log, TEXT("Removed %d channel data provider(s) from channel %d"), RemovedCount, ChId);

			if (UpdateCount > 0)
			{
				channeldpb::ChannelDataUpdateMessage UpdateMsg;
				UpdateMsg.mutable_data()->PackFrom(*NewState);
				Connection->Send(ChId, channeldpb::CHANNEL_DATA_UPDATE, UpdateMsg);

				UE_LOG(LogChanneld, Verbose, TEXT("Sent %s update: %s"), NewState->GetTypeName().c_str(), NewState->DebugString().c_str());
			}
		}
	}

}

void UChannelDataView::HandleUnsub(UChanneldConnection* Conn, ChannelId ChId, const google::protobuf::Message* Msg)
{
	auto UnsubMsg = static_cast<const channeldpb::UnsubscribedFromChannelResultMessage*>(Msg);
	if (UnsubMsg->connid() == Connection->GetConnId())
	{
		TSet<IChannelDataProvider*> Providers;
		if (ChannelDataProviders.RemoveAndCopyValue(ChId, Providers))
		{
			UE_LOG(LogChanneld, Log, TEXT("Received Unsub message. Removed all data providers(%d) from channel %d"), Providers.Num(), ChId);
			OnUnsubFromChannel(ChId, Providers);
		}
	}
}

void UChannelDataView::HandleChannelDataUpdate(UChanneldConnection* Conn, ChannelId ChId, const google::protobuf::Message* Msg)
{
	auto UpdateMsg = static_cast<const channeldpb::ChannelDataUpdateMessage*>(Msg);
	auto MsgTemplate = ChannelDataTemplatesByTypeUrl.FindRef(FString(UpdateMsg->data().type_url().c_str()));
	if (MsgTemplate == nullptr)
	{
		UE_LOG(LogChanneld, Error, TEXT("Unable to find channel data parser by typeUrl: %s"), UpdateMsg->data().type_url().c_str());
		return;
	}

	auto UpdateData = MsgTemplate->New();
	if (!UpdateData->ParseFromString(UpdateMsg->data().value()))
	{
		UE_LOG(LogChanneld, Error, TEXT("Failed to parse channel data of type %s, typeUrl: %s"), UpdateMsg->GetTypeName().c_str(), UpdateMsg->data().type_url().c_str());
		return;
	}

	UE_LOG(LogChanneld, Verbose, TEXT("Receive %s update: %s"), UpdateMsg->GetTypeName().c_str(), UpdateMsg->DebugString().c_str());

	auto Providers = ChannelDataProviders.Find(ChId);
	if (Providers == nullptr)
	{
		UE_LOG(LogChanneld, Warning, TEXT("No provider registered for channel %d, typeUrl: %s"), ChId, UpdateMsg->data().type_url().c_str());
		return;
	}

	for (auto Provider : *Providers)
	{
		Provider->OnChannelDataUpdated(UpdateData);
	}
}

