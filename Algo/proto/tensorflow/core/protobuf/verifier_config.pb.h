// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: tensorflow/core/protobuf/verifier_config.proto
// Protobuf C++ Version: 5.29.0

#ifndef tensorflow_2fcore_2fprotobuf_2fverifier_5fconfig_2eproto_2epb_2eh
#define tensorflow_2fcore_2fprotobuf_2fverifier_5fconfig_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/runtime_version.h"
#if PROTOBUF_VERSION != 5029000
#error "Protobuf C++ gencode is built with an incompatible version of"
#error "Protobuf C++ headers/runtime. See"
#error "https://protobuf.dev/support/cross-version-runtime-guarantee/#cpp"
#endif
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/message_lite.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/generated_enum_reflection.h"
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_tensorflow_2fcore_2fprotobuf_2fverifier_5fconfig_2eproto

namespace google {
namespace protobuf {
namespace internal {
template <typename T>
::absl::string_view GetAnyMessageName();
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_tensorflow_2fcore_2fprotobuf_2fverifier_5fconfig_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_tensorflow_2fcore_2fprotobuf_2fverifier_5fconfig_2eproto;
namespace tensorflow {
class VerifierConfig;
struct VerifierConfigDefaultTypeInternal;
extern VerifierConfigDefaultTypeInternal _VerifierConfig_default_instance_;
}  // namespace tensorflow
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace tensorflow {
enum VerifierConfig_Toggle : int {
  VerifierConfig_Toggle_DEFAULT = 0,
  VerifierConfig_Toggle_ON = 1,
  VerifierConfig_Toggle_OFF = 2,
  VerifierConfig_Toggle_VerifierConfig_Toggle_INT_MIN_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::min(),
  VerifierConfig_Toggle_VerifierConfig_Toggle_INT_MAX_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::max(),
};

bool VerifierConfig_Toggle_IsValid(int value);
extern const uint32_t VerifierConfig_Toggle_internal_data_[];
constexpr VerifierConfig_Toggle VerifierConfig_Toggle_Toggle_MIN = static_cast<VerifierConfig_Toggle>(0);
constexpr VerifierConfig_Toggle VerifierConfig_Toggle_Toggle_MAX = static_cast<VerifierConfig_Toggle>(2);
constexpr int VerifierConfig_Toggle_Toggle_ARRAYSIZE = 2 + 1;
const ::google::protobuf::EnumDescriptor*
VerifierConfig_Toggle_descriptor();
template <typename T>
const std::string& VerifierConfig_Toggle_Name(T value) {
  static_assert(std::is_same<T, VerifierConfig_Toggle>::value ||
                    std::is_integral<T>::value,
                "Incorrect type passed to Toggle_Name().");
  return VerifierConfig_Toggle_Name(static_cast<VerifierConfig_Toggle>(value));
}
template <>
inline const std::string& VerifierConfig_Toggle_Name(VerifierConfig_Toggle value) {
  return ::google::protobuf::internal::NameOfDenseEnum<VerifierConfig_Toggle_descriptor,
                                                 0, 2>(
      static_cast<int>(value));
}
inline bool VerifierConfig_Toggle_Parse(absl::string_view name, VerifierConfig_Toggle* value) {
  return ::google::protobuf::internal::ParseNamedEnum<VerifierConfig_Toggle>(
      VerifierConfig_Toggle_descriptor(), name, value);
}

// ===================================================================


// -------------------------------------------------------------------

class VerifierConfig final
    : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:tensorflow.VerifierConfig) */ {
 public:
  inline VerifierConfig() : VerifierConfig(nullptr) {}
  ~VerifierConfig() PROTOBUF_FINAL;

#if defined(PROTOBUF_CUSTOM_VTABLE)
  void operator delete(VerifierConfig* msg, std::destroying_delete_t) {
    SharedDtor(*msg);
    ::google::protobuf::internal::SizedDelete(msg, sizeof(VerifierConfig));
  }
#endif

  template <typename = void>
  explicit PROTOBUF_CONSTEXPR VerifierConfig(
      ::google::protobuf::internal::ConstantInitialized);

  inline VerifierConfig(const VerifierConfig& from) : VerifierConfig(nullptr, from) {}
  inline VerifierConfig(VerifierConfig&& from) noexcept
      : VerifierConfig(nullptr, std::move(from)) {}
  inline VerifierConfig& operator=(const VerifierConfig& from) {
    CopyFrom(from);
    return *this;
  }
  inline VerifierConfig& operator=(VerifierConfig&& from) noexcept {
    if (this == &from) return *this;
    if (::google::protobuf::internal::CanMoveWithInternalSwap(GetArena(), from.GetArena())) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const VerifierConfig& default_instance() {
    return *internal_default_instance();
  }
  static inline const VerifierConfig* internal_default_instance() {
    return reinterpret_cast<const VerifierConfig*>(
        &_VerifierConfig_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(VerifierConfig& a, VerifierConfig& b) { a.Swap(&b); }
  inline void Swap(VerifierConfig* other) {
    if (other == this) return;
    if (::google::protobuf::internal::CanUseInternalSwap(GetArena(), other->GetArena())) {
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(VerifierConfig* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  VerifierConfig* New(::google::protobuf::Arena* arena = nullptr) const {
    return ::google::protobuf::Message::DefaultConstruct<VerifierConfig>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const VerifierConfig& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const VerifierConfig& from) { VerifierConfig::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  bool IsInitialized() const {
    return true;
  }
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() PROTOBUF_FINAL;
  #if defined(PROTOBUF_CUSTOM_VTABLE)
  private:
  static ::size_t ByteSizeLong(const ::google::protobuf::MessageLite& msg);
  static ::uint8_t* _InternalSerialize(
      const MessageLite& msg, ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream);

  public:
  ::size_t ByteSizeLong() const { return ByteSizeLong(*this); }
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const {
    return _InternalSerialize(*this, target, stream);
  }
  #else   // PROTOBUF_CUSTOM_VTABLE
  ::size_t ByteSizeLong() const final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  #endif  // PROTOBUF_CUSTOM_VTABLE
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  static void SharedDtor(MessageLite& self);
  void InternalSwap(VerifierConfig* other);
 private:
  template <typename T>
  friend ::absl::string_view(
      ::google::protobuf::internal::GetAnyMessageName)();
  static ::absl::string_view FullMessageName() { return "tensorflow.VerifierConfig"; }

 protected:
  explicit VerifierConfig(::google::protobuf::Arena* arena);
  VerifierConfig(::google::protobuf::Arena* arena, const VerifierConfig& from);
  VerifierConfig(::google::protobuf::Arena* arena, VerifierConfig&& from) noexcept
      : VerifierConfig(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::internal::ClassData* GetClassData() const PROTOBUF_FINAL;
  static void* PlacementNew_(const void*, void* mem,
                             ::google::protobuf::Arena* arena);
  static constexpr auto InternalNewImpl_();
  static const ::google::protobuf::internal::ClassDataFull _class_data_;

 public:
  ::google::protobuf::Metadata GetMetadata() const;
  // nested types ----------------------------------------------------
  using Toggle = VerifierConfig_Toggle;
  static constexpr Toggle DEFAULT = VerifierConfig_Toggle_DEFAULT;
  static constexpr Toggle ON = VerifierConfig_Toggle_ON;
  static constexpr Toggle OFF = VerifierConfig_Toggle_OFF;
  static inline bool Toggle_IsValid(int value) {
    return VerifierConfig_Toggle_IsValid(value);
  }
  static constexpr Toggle Toggle_MIN = VerifierConfig_Toggle_Toggle_MIN;
  static constexpr Toggle Toggle_MAX = VerifierConfig_Toggle_Toggle_MAX;
  static constexpr int Toggle_ARRAYSIZE = VerifierConfig_Toggle_Toggle_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor* Toggle_descriptor() {
    return VerifierConfig_Toggle_descriptor();
  }
  template <typename T>
  static inline const std::string& Toggle_Name(T value) {
    return VerifierConfig_Toggle_Name(value);
  }
  static inline bool Toggle_Parse(absl::string_view name, Toggle* value) {
    return VerifierConfig_Toggle_Parse(name, value);
  }

  // accessors -------------------------------------------------------
  enum : int {
    kVerificationTimeoutInMsFieldNumber = 1,
    kStructureVerifierFieldNumber = 2,
  };
  // int64 verification_timeout_in_ms = 1;
  void clear_verification_timeout_in_ms() ;
  ::int64_t verification_timeout_in_ms() const;
  void set_verification_timeout_in_ms(::int64_t value);

  private:
  ::int64_t _internal_verification_timeout_in_ms() const;
  void _internal_set_verification_timeout_in_ms(::int64_t value);

  public:
  // .tensorflow.VerifierConfig.Toggle structure_verifier = 2;
  void clear_structure_verifier() ;
  ::tensorflow::VerifierConfig_Toggle structure_verifier() const;
  void set_structure_verifier(::tensorflow::VerifierConfig_Toggle value);

  private:
  ::tensorflow::VerifierConfig_Toggle _internal_structure_verifier() const;
  void _internal_set_structure_verifier(::tensorflow::VerifierConfig_Toggle value);

  public:
  // @@protoc_insertion_point(class_scope:tensorflow.VerifierConfig)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      1, 2, 0,
      0, 2>
      _table_;

  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from,
                          const VerifierConfig& from_msg);
    ::int64_t verification_timeout_in_ms_;
    int structure_verifier_;
    ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_tensorflow_2fcore_2fprotobuf_2fverifier_5fconfig_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// VerifierConfig

// int64 verification_timeout_in_ms = 1;
inline void VerifierConfig::clear_verification_timeout_in_ms() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.verification_timeout_in_ms_ = ::int64_t{0};
}
inline ::int64_t VerifierConfig::verification_timeout_in_ms() const {
  // @@protoc_insertion_point(field_get:tensorflow.VerifierConfig.verification_timeout_in_ms)
  return _internal_verification_timeout_in_ms();
}
inline void VerifierConfig::set_verification_timeout_in_ms(::int64_t value) {
  _internal_set_verification_timeout_in_ms(value);
  // @@protoc_insertion_point(field_set:tensorflow.VerifierConfig.verification_timeout_in_ms)
}
inline ::int64_t VerifierConfig::_internal_verification_timeout_in_ms() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.verification_timeout_in_ms_;
}
inline void VerifierConfig::_internal_set_verification_timeout_in_ms(::int64_t value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.verification_timeout_in_ms_ = value;
}

// .tensorflow.VerifierConfig.Toggle structure_verifier = 2;
inline void VerifierConfig::clear_structure_verifier() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.structure_verifier_ = 0;
}
inline ::tensorflow::VerifierConfig_Toggle VerifierConfig::structure_verifier() const {
  // @@protoc_insertion_point(field_get:tensorflow.VerifierConfig.structure_verifier)
  return _internal_structure_verifier();
}
inline void VerifierConfig::set_structure_verifier(::tensorflow::VerifierConfig_Toggle value) {
  _internal_set_structure_verifier(value);
  // @@protoc_insertion_point(field_set:tensorflow.VerifierConfig.structure_verifier)
}
inline ::tensorflow::VerifierConfig_Toggle VerifierConfig::_internal_structure_verifier() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return static_cast<::tensorflow::VerifierConfig_Toggle>(_impl_.structure_verifier_);
}
inline void VerifierConfig::_internal_set_structure_verifier(::tensorflow::VerifierConfig_Toggle value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.structure_verifier_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace tensorflow


namespace google {
namespace protobuf {

template <>
struct is_proto_enum<::tensorflow::VerifierConfig_Toggle> : std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor<::tensorflow::VerifierConfig_Toggle>() {
  return ::tensorflow::VerifierConfig_Toggle_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // tensorflow_2fcore_2fprotobuf_2fverifier_5fconfig_2eproto_2epb_2eh
