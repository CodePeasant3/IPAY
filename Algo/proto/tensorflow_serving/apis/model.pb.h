// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: tensorflow_serving/apis/model.proto
// Protobuf C++ Version: 5.29.0

#ifndef tensorflow_5fserving_2fapis_2fmodel_2eproto_2epb_2eh
#define tensorflow_5fserving_2fapis_2fmodel_2eproto_2epb_2eh

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
#include "google/protobuf/unknown_field_set.h"
#include "google/protobuf/wrappers.pb.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_tensorflow_5fserving_2fapis_2fmodel_2eproto

namespace google {
namespace protobuf {
namespace internal {
template <typename T>
::absl::string_view GetAnyMessageName();
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_tensorflow_5fserving_2fapis_2fmodel_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_tensorflow_5fserving_2fapis_2fmodel_2eproto;
namespace tensorflow {
namespace serving {
class ModelSpec;
struct ModelSpecDefaultTypeInternal;
extern ModelSpecDefaultTypeInternal _ModelSpec_default_instance_;
}  // namespace serving
}  // namespace tensorflow
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace tensorflow {
namespace serving {

// ===================================================================


// -------------------------------------------------------------------

class ModelSpec final
    : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:tensorflow.serving.ModelSpec) */ {
 public:
  inline ModelSpec() : ModelSpec(nullptr) {}
  ~ModelSpec() PROTOBUF_FINAL;

#if defined(PROTOBUF_CUSTOM_VTABLE)
  void operator delete(ModelSpec* msg, std::destroying_delete_t) {
    SharedDtor(*msg);
    ::google::protobuf::internal::SizedDelete(msg, sizeof(ModelSpec));
  }
#endif

  template <typename = void>
  explicit PROTOBUF_CONSTEXPR ModelSpec(
      ::google::protobuf::internal::ConstantInitialized);

  inline ModelSpec(const ModelSpec& from) : ModelSpec(nullptr, from) {}
  inline ModelSpec(ModelSpec&& from) noexcept
      : ModelSpec(nullptr, std::move(from)) {}
  inline ModelSpec& operator=(const ModelSpec& from) {
    CopyFrom(from);
    return *this;
  }
  inline ModelSpec& operator=(ModelSpec&& from) noexcept {
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
  static const ModelSpec& default_instance() {
    return *internal_default_instance();
  }
  enum VersionChoiceCase {
    kVersion = 2,
    kVersionLabel = 4,
    VERSION_CHOICE_NOT_SET = 0,
  };
  static inline const ModelSpec* internal_default_instance() {
    return reinterpret_cast<const ModelSpec*>(
        &_ModelSpec_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(ModelSpec& a, ModelSpec& b) { a.Swap(&b); }
  inline void Swap(ModelSpec* other) {
    if (other == this) return;
    if (::google::protobuf::internal::CanUseInternalSwap(GetArena(), other->GetArena())) {
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ModelSpec* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  ModelSpec* New(::google::protobuf::Arena* arena = nullptr) const {
    return ::google::protobuf::Message::DefaultConstruct<ModelSpec>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const ModelSpec& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const ModelSpec& from) { ModelSpec::MergeImpl(*this, from); }

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
  void InternalSwap(ModelSpec* other);
 private:
  template <typename T>
  friend ::absl::string_view(
      ::google::protobuf::internal::GetAnyMessageName)();
  static ::absl::string_view FullMessageName() { return "tensorflow.serving.ModelSpec"; }

 protected:
  explicit ModelSpec(::google::protobuf::Arena* arena);
  ModelSpec(::google::protobuf::Arena* arena, const ModelSpec& from);
  ModelSpec(::google::protobuf::Arena* arena, ModelSpec&& from) noexcept
      : ModelSpec(arena) {
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

  // accessors -------------------------------------------------------
  enum : int {
    kNameFieldNumber = 1,
    kSignatureNameFieldNumber = 3,
    kVersionFieldNumber = 2,
    kVersionLabelFieldNumber = 4,
  };
  // string name = 1;
  void clear_name() ;
  const std::string& name() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_name(Arg_&& arg, Args_... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* value);

  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(
      const std::string& value);
  std::string* _internal_mutable_name();

  public:
  // string signature_name = 3;
  void clear_signature_name() ;
  const std::string& signature_name() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_signature_name(Arg_&& arg, Args_... args);
  std::string* mutable_signature_name();
  PROTOBUF_NODISCARD std::string* release_signature_name();
  void set_allocated_signature_name(std::string* value);

  private:
  const std::string& _internal_signature_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_signature_name(
      const std::string& value);
  std::string* _internal_mutable_signature_name();

  public:
  // .google.protobuf.Int64Value version = 2;
  bool has_version() const;
  private:
  bool _internal_has_version() const;

  public:
  void clear_version() ;
  const ::google::protobuf::Int64Value& version() const;
  PROTOBUF_NODISCARD ::google::protobuf::Int64Value* release_version();
  ::google::protobuf::Int64Value* mutable_version();
  void set_allocated_version(::google::protobuf::Int64Value* value);
  void unsafe_arena_set_allocated_version(::google::protobuf::Int64Value* value);
  ::google::protobuf::Int64Value* unsafe_arena_release_version();

  private:
  const ::google::protobuf::Int64Value& _internal_version() const;
  ::google::protobuf::Int64Value* _internal_mutable_version();

  public:
  // string version_label = 4;
  bool has_version_label() const;
  void clear_version_label() ;
  const std::string& version_label() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_version_label(Arg_&& arg, Args_... args);
  std::string* mutable_version_label();
  PROTOBUF_NODISCARD std::string* release_version_label();
  void set_allocated_version_label(std::string* value);

  private:
  const std::string& _internal_version_label() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_version_label(
      const std::string& value);
  std::string* _internal_mutable_version_label();

  public:
  void clear_version_choice();
  VersionChoiceCase version_choice_case() const;
  // @@protoc_insertion_point(class_scope:tensorflow.serving.ModelSpec)
 private:
  class _Internal;
  void set_has_version();
  void set_has_version_label();
  inline bool has_version_choice() const;
  inline void clear_has_version_choice();
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      2, 4, 1,
      68, 2>
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
                          const ModelSpec& from_msg);
    ::google::protobuf::internal::ArenaStringPtr name_;
    ::google::protobuf::internal::ArenaStringPtr signature_name_;
    union VersionChoiceUnion {
      constexpr VersionChoiceUnion() : _constinit_{} {}
      ::google::protobuf::internal::ConstantInitialized _constinit_;
      ::google::protobuf::Int64Value* version_;
      ::google::protobuf::internal::ArenaStringPtr version_label_;
    } version_choice_;
    ::google::protobuf::internal::CachedSize _cached_size_;
    ::uint32_t _oneof_case_[1];
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_tensorflow_5fserving_2fapis_2fmodel_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// ModelSpec

// string name = 1;
inline void ModelSpec::clear_name() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.name_.ClearToEmpty();
}
inline const std::string& ModelSpec::name() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:tensorflow.serving.ModelSpec.name)
  return _internal_name();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void ModelSpec::set_name(Arg_&& arg,
                                                     Args_... args) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.name_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:tensorflow.serving.ModelSpec.name)
}
inline std::string* ModelSpec::mutable_name() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:tensorflow.serving.ModelSpec.name)
  return _s;
}
inline const std::string& ModelSpec::_internal_name() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.name_.Get();
}
inline void ModelSpec::_internal_set_name(const std::string& value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.name_.Set(value, GetArena());
}
inline std::string* ModelSpec::_internal_mutable_name() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  return _impl_.name_.Mutable( GetArena());
}
inline std::string* ModelSpec::release_name() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:tensorflow.serving.ModelSpec.name)
  return _impl_.name_.Release();
}
inline void ModelSpec::set_allocated_name(std::string* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.name_.SetAllocated(value, GetArena());
  if (::google::protobuf::internal::DebugHardenForceCopyDefaultString() && _impl_.name_.IsDefault()) {
    _impl_.name_.Set("", GetArena());
  }
  // @@protoc_insertion_point(field_set_allocated:tensorflow.serving.ModelSpec.name)
}

// .google.protobuf.Int64Value version = 2;
inline bool ModelSpec::has_version() const {
  return version_choice_case() == kVersion;
}
inline bool ModelSpec::_internal_has_version() const {
  return version_choice_case() == kVersion;
}
inline void ModelSpec::set_has_version() {
  _impl_._oneof_case_[0] = kVersion;
}
inline ::google::protobuf::Int64Value* ModelSpec::release_version() {
  // @@protoc_insertion_point(field_release:tensorflow.serving.ModelSpec.version)
  if (version_choice_case() == kVersion) {
    clear_has_version_choice();
    auto* temp = _impl_.version_choice_.version_;
    if (GetArena() != nullptr) {
      temp = ::google::protobuf::internal::DuplicateIfNonNull(temp);
    }
    _impl_.version_choice_.version_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline const ::google::protobuf::Int64Value& ModelSpec::_internal_version() const {
  return version_choice_case() == kVersion ? *_impl_.version_choice_.version_ : reinterpret_cast<::google::protobuf::Int64Value&>(::google::protobuf::_Int64Value_default_instance_);
}
inline const ::google::protobuf::Int64Value& ModelSpec::version() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:tensorflow.serving.ModelSpec.version)
  return _internal_version();
}
inline ::google::protobuf::Int64Value* ModelSpec::unsafe_arena_release_version() {
  // @@protoc_insertion_point(field_unsafe_arena_release:tensorflow.serving.ModelSpec.version)
  if (version_choice_case() == kVersion) {
    clear_has_version_choice();
    auto* temp = _impl_.version_choice_.version_;
    _impl_.version_choice_.version_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline void ModelSpec::unsafe_arena_set_allocated_version(::google::protobuf::Int64Value* value) {
  // We rely on the oneof clear method to free the earlier contents
  // of this oneof. We can directly use the pointer we're given to
  // set the new value.
  clear_version_choice();
  if (value) {
    set_has_version();
    _impl_.version_choice_.version_ = value;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:tensorflow.serving.ModelSpec.version)
}
inline ::google::protobuf::Int64Value* ModelSpec::_internal_mutable_version() {
  if (version_choice_case() != kVersion) {
    clear_version_choice();
    set_has_version();
    _impl_.version_choice_.version_ =
        ::google::protobuf::Message::DefaultConstruct<::google::protobuf::Int64Value>(GetArena());
  }
  return _impl_.version_choice_.version_;
}
inline ::google::protobuf::Int64Value* ModelSpec::mutable_version() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  ::google::protobuf::Int64Value* _msg = _internal_mutable_version();
  // @@protoc_insertion_point(field_mutable:tensorflow.serving.ModelSpec.version)
  return _msg;
}

// string version_label = 4;
inline bool ModelSpec::has_version_label() const {
  return version_choice_case() == kVersionLabel;
}
inline void ModelSpec::set_has_version_label() {
  _impl_._oneof_case_[0] = kVersionLabel;
}
inline void ModelSpec::clear_version_label() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (version_choice_case() == kVersionLabel) {
    _impl_.version_choice_.version_label_.Destroy();
    clear_has_version_choice();
  }
}
inline const std::string& ModelSpec::version_label() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:tensorflow.serving.ModelSpec.version_label)
  return _internal_version_label();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void ModelSpec::set_version_label(Arg_&& arg,
                                                     Args_... args) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (version_choice_case() != kVersionLabel) {
    clear_version_choice();

    set_has_version_label();
    _impl_.version_choice_.version_label_.InitDefault();
  }
  _impl_.version_choice_.version_label_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:tensorflow.serving.ModelSpec.version_label)
}
inline std::string* ModelSpec::mutable_version_label() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_version_label();
  // @@protoc_insertion_point(field_mutable:tensorflow.serving.ModelSpec.version_label)
  return _s;
}
inline const std::string& ModelSpec::_internal_version_label() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  if (version_choice_case() != kVersionLabel) {
    return ::google::protobuf::internal::GetEmptyStringAlreadyInited();
  }
  return _impl_.version_choice_.version_label_.Get();
}
inline void ModelSpec::_internal_set_version_label(const std::string& value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (version_choice_case() != kVersionLabel) {
    clear_version_choice();

    set_has_version_label();
    _impl_.version_choice_.version_label_.InitDefault();
  }
  _impl_.version_choice_.version_label_.Set(value, GetArena());
}
inline std::string* ModelSpec::_internal_mutable_version_label() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (version_choice_case() != kVersionLabel) {
    clear_version_choice();

    set_has_version_label();
    _impl_.version_choice_.version_label_.InitDefault();
  }
  return _impl_.version_choice_.version_label_.Mutable( GetArena());
}
inline std::string* ModelSpec::release_version_label() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:tensorflow.serving.ModelSpec.version_label)
  if (version_choice_case() != kVersionLabel) {
    return nullptr;
  }
  clear_has_version_choice();
  return _impl_.version_choice_.version_label_.Release();
}
inline void ModelSpec::set_allocated_version_label(std::string* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (has_version_choice()) {
    clear_version_choice();
  }
  if (value != nullptr) {
    set_has_version_label();
    _impl_.version_choice_.version_label_.InitAllocated(value, GetArena());
  }
  // @@protoc_insertion_point(field_set_allocated:tensorflow.serving.ModelSpec.version_label)
}

// string signature_name = 3;
inline void ModelSpec::clear_signature_name() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.signature_name_.ClearToEmpty();
}
inline const std::string& ModelSpec::signature_name() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:tensorflow.serving.ModelSpec.signature_name)
  return _internal_signature_name();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void ModelSpec::set_signature_name(Arg_&& arg,
                                                     Args_... args) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.signature_name_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:tensorflow.serving.ModelSpec.signature_name)
}
inline std::string* ModelSpec::mutable_signature_name() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_signature_name();
  // @@protoc_insertion_point(field_mutable:tensorflow.serving.ModelSpec.signature_name)
  return _s;
}
inline const std::string& ModelSpec::_internal_signature_name() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.signature_name_.Get();
}
inline void ModelSpec::_internal_set_signature_name(const std::string& value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.signature_name_.Set(value, GetArena());
}
inline std::string* ModelSpec::_internal_mutable_signature_name() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  return _impl_.signature_name_.Mutable( GetArena());
}
inline std::string* ModelSpec::release_signature_name() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:tensorflow.serving.ModelSpec.signature_name)
  return _impl_.signature_name_.Release();
}
inline void ModelSpec::set_allocated_signature_name(std::string* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.signature_name_.SetAllocated(value, GetArena());
  if (::google::protobuf::internal::DebugHardenForceCopyDefaultString() && _impl_.signature_name_.IsDefault()) {
    _impl_.signature_name_.Set("", GetArena());
  }
  // @@protoc_insertion_point(field_set_allocated:tensorflow.serving.ModelSpec.signature_name)
}

inline bool ModelSpec::has_version_choice() const {
  return version_choice_case() != VERSION_CHOICE_NOT_SET;
}
inline void ModelSpec::clear_has_version_choice() {
  _impl_._oneof_case_[0] = VERSION_CHOICE_NOT_SET;
}
inline ModelSpec::VersionChoiceCase ModelSpec::version_choice_case() const {
  return ModelSpec::VersionChoiceCase(_impl_._oneof_case_[0]);
}
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace serving
}  // namespace tensorflow


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // tensorflow_5fserving_2fapis_2fmodel_2eproto_2epb_2eh
