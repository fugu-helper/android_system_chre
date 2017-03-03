// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_HOSTMESSAGES_CHRE_FBS_H_
#define FLATBUFFERS_GENERATED_HOSTMESSAGES_CHRE_FBS_H_

#include "flatbuffers/flatbuffers.h"

namespace chre {
namespace fbs {

struct NanoappMessage;

struct MessageContainer;

/// A union that joins together all possible messages. Note that in FlatBuffers,
/// unions have an implicit type
enum class ChreMessage : uint8_t {
  NONE = 0,
  NanoappMessage = 1,
  MIN = NONE,
  MAX = NanoappMessage
};

inline const char **EnumNamesChreMessage() {
  static const char *names[] = {
    "NONE",
    "NanoappMessage",
    nullptr
  };
  return names;
}

inline const char *EnumNameChreMessage(ChreMessage e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesChreMessage()[index];
}

template<typename T> struct ChreMessageTraits {
  static const ChreMessage enum_value = ChreMessage::NONE;
};

template<> struct ChreMessageTraits<NanoappMessage> {
  static const ChreMessage enum_value = ChreMessage::NanoappMessage;
};

bool VerifyChreMessage(flatbuffers::Verifier &verifier, const void *obj, ChreMessage type);
bool VerifyChreMessageVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types);

/// Represents a message sent to/from a nanoapp from/to a client on the host
struct NanoappMessage FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_APP_ID = 4,
    VT_MESSAGE_TYPE = 6,
    VT_HOST_ENDPOINT = 8,
    VT_MESSAGE = 10
  };
  uint64_t app_id() const {
    return GetField<uint64_t>(VT_APP_ID, 0);
  }
  uint32_t message_type() const {
    return GetField<uint32_t>(VT_MESSAGE_TYPE, 0);
  }
  /// Identifies the host-side endpoint on the host that sent or should receive
  /// this message. The default value is a special value defined in the HAL and
  /// elsewhere that indicates that the endpoint is unspecified.
  uint16_t host_endpoint() const {
    return GetField<uint16_t>(VT_HOST_ENDPOINT, 65534);
  }
  /// Vector containing arbitrary application-specific message data
  const flatbuffers::Vector<uint8_t> *message() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_MESSAGE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint64_t>(verifier, VT_APP_ID) &&
           VerifyField<uint32_t>(verifier, VT_MESSAGE_TYPE) &&
           VerifyField<uint16_t>(verifier, VT_HOST_ENDPOINT) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_MESSAGE) &&
           verifier.Verify(message()) &&
           verifier.EndTable();
  }
};

struct NanoappMessageBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_app_id(uint64_t app_id) {
    fbb_.AddElement<uint64_t>(NanoappMessage::VT_APP_ID, app_id, 0);
  }
  void add_message_type(uint32_t message_type) {
    fbb_.AddElement<uint32_t>(NanoappMessage::VT_MESSAGE_TYPE, message_type, 0);
  }
  void add_host_endpoint(uint16_t host_endpoint) {
    fbb_.AddElement<uint16_t>(NanoappMessage::VT_HOST_ENDPOINT, host_endpoint, 65534);
  }
  void add_message(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> message) {
    fbb_.AddOffset(NanoappMessage::VT_MESSAGE, message);
  }
  NanoappMessageBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  NanoappMessageBuilder &operator=(const NanoappMessageBuilder &);
  flatbuffers::Offset<NanoappMessage> Finish() {
    const auto end = fbb_.EndTable(start_, 4);
    auto o = flatbuffers::Offset<NanoappMessage>(end);
    return o;
  }
};

inline flatbuffers::Offset<NanoappMessage> CreateNanoappMessage(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint64_t app_id = 0,
    uint32_t message_type = 0,
    uint16_t host_endpoint = 65534,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> message = 0) {
  NanoappMessageBuilder builder_(_fbb);
  builder_.add_app_id(app_id);
  builder_.add_message(message);
  builder_.add_message_type(message_type);
  builder_.add_host_endpoint(host_endpoint);
  return builder_.Finish();
}

inline flatbuffers::Offset<NanoappMessage> CreateNanoappMessageDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint64_t app_id = 0,
    uint32_t message_type = 0,
    uint16_t host_endpoint = 65534,
    const std::vector<uint8_t> *message = nullptr) {
  return chre::fbs::CreateNanoappMessage(
      _fbb,
      app_id,
      message_type,
      host_endpoint,
      message ? _fbb.CreateVector<uint8_t>(*message) : 0);
}

/// The top-level container that encapsulates all possible messages. Note that
/// per FlatBuffers requirements, we can't use a union as the top-level structure
/// (root type), so we must wrap it in a table.
struct MessageContainer FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_MESSAGE_TYPE = 4,
    VT_MESSAGE = 6
  };
  ChreMessage message_type() const {
    return static_cast<ChreMessage>(GetField<uint8_t>(VT_MESSAGE_TYPE, 0));
  }
  const void *message() const {
    return GetPointer<const void *>(VT_MESSAGE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_MESSAGE_TYPE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_MESSAGE) &&
           VerifyChreMessage(verifier, message(), message_type()) &&
           verifier.EndTable();
  }
};

struct MessageContainerBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_message_type(ChreMessage message_type) {
    fbb_.AddElement<uint8_t>(MessageContainer::VT_MESSAGE_TYPE, static_cast<uint8_t>(message_type), 0);
  }
  void add_message(flatbuffers::Offset<void> message) {
    fbb_.AddOffset(MessageContainer::VT_MESSAGE, message);
  }
  MessageContainerBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  MessageContainerBuilder &operator=(const MessageContainerBuilder &);
  flatbuffers::Offset<MessageContainer> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<MessageContainer>(end);
    return o;
  }
};

inline flatbuffers::Offset<MessageContainer> CreateMessageContainer(
    flatbuffers::FlatBufferBuilder &_fbb,
    ChreMessage message_type = ChreMessage::NONE,
    flatbuffers::Offset<void> message = 0) {
  MessageContainerBuilder builder_(_fbb);
  builder_.add_message(message);
  builder_.add_message_type(message_type);
  return builder_.Finish();
}

inline bool VerifyChreMessage(flatbuffers::Verifier &verifier, const void *obj, ChreMessage type) {
  switch (type) {
    case ChreMessage::NONE: {
      return true;
    }
    case ChreMessage::NanoappMessage: {
      auto ptr = reinterpret_cast<const NanoappMessage *>(obj);
      return verifier.VerifyTable(ptr);
    }
    default: return false;
  }
}

inline bool VerifyChreMessageVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types) {
  if (values->size() != types->size()) return false;
  for (flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyChreMessage(
        verifier,  values->Get(i), types->GetEnum<ChreMessage>(i))) {
      return false;
    }
  }
  return true;
}

inline const chre::fbs::MessageContainer *GetMessageContainer(const void *buf) {
  return flatbuffers::GetRoot<chre::fbs::MessageContainer>(buf);
}

inline bool VerifyMessageContainerBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<chre::fbs::MessageContainer>(nullptr);
}

inline void FinishMessageContainerBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<chre::fbs::MessageContainer> root) {
  fbb.Finish(root);
}

}  // namespace fbs
}  // namespace chre

#endif  // FLATBUFFERS_GENERATED_HOSTMESSAGES_CHRE_FBS_H_
