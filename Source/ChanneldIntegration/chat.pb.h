// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: chat.proto

#ifndef PROTOBUF_chat_2eproto__INCLUDED
#define PROTOBUF_chat_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobuf_chat_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsChatMessageImpl();
void InitDefaultsChatMessage();
void InitDefaultsChatChannelDataImpl();
void InitDefaultsChatChannelData();
inline void InitDefaults() {
  InitDefaultsChatMessage();
  InitDefaultsChatChannelData();
}
}  // namespace protobuf_chat_2eproto
namespace chatpb {
class ChatChannelData;
class ChatChannelDataDefaultTypeInternal;
extern ChatChannelDataDefaultTypeInternal _ChatChannelData_default_instance_;
class ChatMessage;
class ChatMessageDefaultTypeInternal;
extern ChatMessageDefaultTypeInternal _ChatMessage_default_instance_;
}  // namespace chatpb
namespace chatpb {

enum ChatChannelType {
  UNKNOWN = 0,
  GLOBAL = 1,
  PRIVATE = 2,
  SUBWORLD = 3,
  ChatChannelType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  ChatChannelType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool ChatChannelType_IsValid(int value);
const ChatChannelType ChatChannelType_MIN = UNKNOWN;
const ChatChannelType ChatChannelType_MAX = SUBWORLD;
const int ChatChannelType_ARRAYSIZE = ChatChannelType_MAX + 1;

const ::google::protobuf::EnumDescriptor* ChatChannelType_descriptor();
inline const ::std::string& ChatChannelType_Name(ChatChannelType value) {
  return ::google::protobuf::internal::NameOfEnum(
    ChatChannelType_descriptor(), value);
}
inline bool ChatChannelType_Parse(
    const ::std::string& name, ChatChannelType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ChatChannelType>(
    ChatChannelType_descriptor(), name, value);
}
// ===================================================================

class ChatMessage : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:chatpb.ChatMessage) */ {
 public:
  ChatMessage();
  virtual ~ChatMessage();

  ChatMessage(const ChatMessage& from);

  inline ChatMessage& operator=(const ChatMessage& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ChatMessage(ChatMessage&& from) noexcept
    : ChatMessage() {
    *this = ::std::move(from);
  }

  inline ChatMessage& operator=(ChatMessage&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const ChatMessage& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ChatMessage* internal_default_instance() {
    return reinterpret_cast<const ChatMessage*>(
               &_ChatMessage_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(ChatMessage* other);
  friend void swap(ChatMessage& a, ChatMessage& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ChatMessage* New() const PROTOBUF_FINAL { return New(NULL); }

  ChatMessage* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const ChatMessage& from);
  void MergeFrom(const ChatMessage& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(ChatMessage* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string sender = 1;
  void clear_sender();
  static const int kSenderFieldNumber = 1;
  const ::std::string& sender() const;
  void set_sender(const ::std::string& value);
  #if LANG_CXX11
  void set_sender(::std::string&& value);
  #endif
  void set_sender(const char* value);
  void set_sender(const char* value, size_t size);
  ::std::string* mutable_sender();
  ::std::string* release_sender();
  void set_allocated_sender(::std::string* sender);

  // string content = 3;
  void clear_content();
  static const int kContentFieldNumber = 3;
  const ::std::string& content() const;
  void set_content(const ::std::string& value);
  #if LANG_CXX11
  void set_content(::std::string&& value);
  #endif
  void set_content(const char* value);
  void set_content(const char* value, size_t size);
  ::std::string* mutable_content();
  ::std::string* release_content();
  void set_allocated_content(::std::string* content);

  // int64 sendTime = 2;
  void clear_sendtime();
  static const int kSendTimeFieldNumber = 2;
  ::google::protobuf::int64 sendtime() const;
  void set_sendtime(::google::protobuf::int64 value);

  // uint32 senderConnId = 4;
  void clear_senderconnid();
  static const int kSenderConnIdFieldNumber = 4;
  ::google::protobuf::uint32 senderconnid() const;
  void set_senderconnid(::google::protobuf::uint32 value);

  // .chatpb.ChatChannelType chatChannelType = 5;
  void clear_chatchanneltype();
  static const int kChatChannelTypeFieldNumber = 5;
  ::chatpb::ChatChannelType chatchanneltype() const;
  void set_chatchanneltype(::chatpb::ChatChannelType value);

  // @@protoc_insertion_point(class_scope:chatpb.ChatMessage)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr sender_;
  ::google::protobuf::internal::ArenaStringPtr content_;
  ::google::protobuf::int64 sendtime_;
  ::google::protobuf::uint32 senderconnid_;
  int chatchanneltype_;
  mutable int _cached_size_;
  friend struct ::protobuf_chat_2eproto::TableStruct;
  friend void ::protobuf_chat_2eproto::InitDefaultsChatMessageImpl();
};
// -------------------------------------------------------------------

class ChatChannelData : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:chatpb.ChatChannelData) */ {
 public:
  ChatChannelData();
  virtual ~ChatChannelData();

  ChatChannelData(const ChatChannelData& from);

  inline ChatChannelData& operator=(const ChatChannelData& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ChatChannelData(ChatChannelData&& from) noexcept
    : ChatChannelData() {
    *this = ::std::move(from);
  }

  inline ChatChannelData& operator=(ChatChannelData&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const ChatChannelData& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ChatChannelData* internal_default_instance() {
    return reinterpret_cast<const ChatChannelData*>(
               &_ChatChannelData_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(ChatChannelData* other);
  friend void swap(ChatChannelData& a, ChatChannelData& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ChatChannelData* New() const PROTOBUF_FINAL { return New(NULL); }

  ChatChannelData* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const ChatChannelData& from);
  void MergeFrom(const ChatChannelData& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(ChatChannelData* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .chatpb.ChatMessage chatMessages = 1;
  int chatmessages_size() const;
  void clear_chatmessages();
  static const int kChatMessagesFieldNumber = 1;
  const ::chatpb::ChatMessage& chatmessages(int index) const;
  ::chatpb::ChatMessage* mutable_chatmessages(int index);
  ::chatpb::ChatMessage* add_chatmessages();
  ::google::protobuf::RepeatedPtrField< ::chatpb::ChatMessage >*
      mutable_chatmessages();
  const ::google::protobuf::RepeatedPtrField< ::chatpb::ChatMessage >&
      chatmessages() const;

  // @@protoc_insertion_point(class_scope:chatpb.ChatChannelData)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::chatpb::ChatMessage > chatmessages_;
  mutable int _cached_size_;
  friend struct ::protobuf_chat_2eproto::TableStruct;
  friend void ::protobuf_chat_2eproto::InitDefaultsChatChannelDataImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ChatMessage

// string sender = 1;
inline void ChatMessage::clear_sender() {
  sender_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ChatMessage::sender() const {
  // @@protoc_insertion_point(field_get:chatpb.ChatMessage.sender)
  return sender_.GetNoArena();
}
inline void ChatMessage::set_sender(const ::std::string& value) {
  
  sender_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:chatpb.ChatMessage.sender)
}
#if LANG_CXX11
inline void ChatMessage::set_sender(::std::string&& value) {
  
  sender_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:chatpb.ChatMessage.sender)
}
#endif
inline void ChatMessage::set_sender(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  sender_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:chatpb.ChatMessage.sender)
}
inline void ChatMessage::set_sender(const char* value, size_t size) {
  
  sender_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:chatpb.ChatMessage.sender)
}
inline ::std::string* ChatMessage::mutable_sender() {
  
  // @@protoc_insertion_point(field_mutable:chatpb.ChatMessage.sender)
  return sender_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ChatMessage::release_sender() {
  // @@protoc_insertion_point(field_release:chatpb.ChatMessage.sender)
  
  return sender_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ChatMessage::set_allocated_sender(::std::string* sender) {
  if (sender != NULL) {
    
  } else {
    
  }
  sender_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), sender);
  // @@protoc_insertion_point(field_set_allocated:chatpb.ChatMessage.sender)
}

// int64 sendTime = 2;
inline void ChatMessage::clear_sendtime() {
  sendtime_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ChatMessage::sendtime() const {
  // @@protoc_insertion_point(field_get:chatpb.ChatMessage.sendTime)
  return sendtime_;
}
inline void ChatMessage::set_sendtime(::google::protobuf::int64 value) {
  
  sendtime_ = value;
  // @@protoc_insertion_point(field_set:chatpb.ChatMessage.sendTime)
}

// string content = 3;
inline void ChatMessage::clear_content() {
  content_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ChatMessage::content() const {
  // @@protoc_insertion_point(field_get:chatpb.ChatMessage.content)
  return content_.GetNoArena();
}
inline void ChatMessage::set_content(const ::std::string& value) {
  
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:chatpb.ChatMessage.content)
}
#if LANG_CXX11
inline void ChatMessage::set_content(::std::string&& value) {
  
  content_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:chatpb.ChatMessage.content)
}
#endif
inline void ChatMessage::set_content(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:chatpb.ChatMessage.content)
}
inline void ChatMessage::set_content(const char* value, size_t size) {
  
  content_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:chatpb.ChatMessage.content)
}
inline ::std::string* ChatMessage::mutable_content() {
  
  // @@protoc_insertion_point(field_mutable:chatpb.ChatMessage.content)
  return content_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ChatMessage::release_content() {
  // @@protoc_insertion_point(field_release:chatpb.ChatMessage.content)
  
  return content_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ChatMessage::set_allocated_content(::std::string* content) {
  if (content != NULL) {
    
  } else {
    
  }
  content_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), content);
  // @@protoc_insertion_point(field_set_allocated:chatpb.ChatMessage.content)
}

// uint32 senderConnId = 4;
inline void ChatMessage::clear_senderconnid() {
  senderconnid_ = 0u;
}
inline ::google::protobuf::uint32 ChatMessage::senderconnid() const {
  // @@protoc_insertion_point(field_get:chatpb.ChatMessage.senderConnId)
  return senderconnid_;
}
inline void ChatMessage::set_senderconnid(::google::protobuf::uint32 value) {
  
  senderconnid_ = value;
  // @@protoc_insertion_point(field_set:chatpb.ChatMessage.senderConnId)
}

// .chatpb.ChatChannelType chatChannelType = 5;
inline void ChatMessage::clear_chatchanneltype() {
  chatchanneltype_ = 0;
}
inline ::chatpb::ChatChannelType ChatMessage::chatchanneltype() const {
  // @@protoc_insertion_point(field_get:chatpb.ChatMessage.chatChannelType)
  return static_cast< ::chatpb::ChatChannelType >(chatchanneltype_);
}
inline void ChatMessage::set_chatchanneltype(::chatpb::ChatChannelType value) {
  
  chatchanneltype_ = value;
  // @@protoc_insertion_point(field_set:chatpb.ChatMessage.chatChannelType)
}

// -------------------------------------------------------------------

// ChatChannelData

// repeated .chatpb.ChatMessage chatMessages = 1;
inline int ChatChannelData::chatmessages_size() const {
  return chatmessages_.size();
}
inline void ChatChannelData::clear_chatmessages() {
  chatmessages_.Clear();
}
inline const ::chatpb::ChatMessage& ChatChannelData::chatmessages(int index) const {
  // @@protoc_insertion_point(field_get:chatpb.ChatChannelData.chatMessages)
  return chatmessages_.Get(index);
}
inline ::chatpb::ChatMessage* ChatChannelData::mutable_chatmessages(int index) {
  // @@protoc_insertion_point(field_mutable:chatpb.ChatChannelData.chatMessages)
  return chatmessages_.Mutable(index);
}
inline ::chatpb::ChatMessage* ChatChannelData::add_chatmessages() {
  // @@protoc_insertion_point(field_add:chatpb.ChatChannelData.chatMessages)
  return chatmessages_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::chatpb::ChatMessage >*
ChatChannelData::mutable_chatmessages() {
  // @@protoc_insertion_point(field_mutable_list:chatpb.ChatChannelData.chatMessages)
  return &chatmessages_;
}
inline const ::google::protobuf::RepeatedPtrField< ::chatpb::ChatMessage >&
ChatChannelData::chatmessages() const {
  // @@protoc_insertion_point(field_list:chatpb.ChatChannelData.chatMessages)
  return chatmessages_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace chatpb

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::chatpb::ChatChannelType> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::chatpb::ChatChannelType>() {
  return ::chatpb::ChatChannelType_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_chat_2eproto__INCLUDED
