// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: tensorflow/core/framework/full_type.proto
// Protobuf C++ Version: 5.29.0

#ifndef tensorflow_2fcore_2fframework_2ffull_5ftype_2eproto_2epb_2eh
#define tensorflow_2fcore_2fframework_2ffull_5ftype_2eproto_2epb_2eh

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

#define PROTOBUF_INTERNAL_EXPORT_tensorflow_2fcore_2fframework_2ffull_5ftype_2eproto

namespace google {
namespace protobuf {
namespace internal {
template <typename T>
::absl::string_view GetAnyMessageName();
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_tensorflow_2fcore_2fframework_2ffull_5ftype_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_tensorflow_2fcore_2fframework_2ffull_5ftype_2eproto;
namespace tensorflow {
class FullTypeDef;
struct FullTypeDefDefaultTypeInternal;
extern FullTypeDefDefaultTypeInternal _FullTypeDef_default_instance_;
}  // namespace tensorflow
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace tensorflow {
enum FullTypeId : int {
  TFT_UNSET = 0,
  TFT_VAR = 1,
  TFT_ANY = 2,
  TFT_PRODUCT = 3,
  TFT_NAMED = 4,
  TFT_FOR_EACH = 20,
  TFT_CALLABLE = 100,
  TFT_TENSOR = 1000,
  TFT_ARRAY = 1001,
  TFT_OPTIONAL = 1002,
  TFT_LITERAL = 1003,
  TFT_ENCODED = 1004,
  TFT_SHAPE_TENSOR = 1005,
  TFT_BOOL = 200,
  TFT_UINT8 = 201,
  TFT_UINT16 = 202,
  TFT_UINT32 = 203,
  TFT_UINT64 = 204,
  TFT_INT8 = 205,
  TFT_INT16 = 206,
  TFT_INT32 = 207,
  TFT_INT64 = 208,
  TFT_HALF = 209,
  TFT_FLOAT = 210,
  TFT_DOUBLE = 211,
  TFT_BFLOAT16 = 215,
  TFT_COMPLEX64 = 212,
  TFT_COMPLEX128 = 213,
  TFT_STRING = 214,
  TFT_DATASET = 10102,
  TFT_RAGGED = 10103,
  TFT_ITERATOR = 10104,
  TFT_MUTEX_LOCK = 10202,
  TFT_LEGACY_VARIANT = 10203,
  FullTypeId_INT_MIN_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::min(),
  FullTypeId_INT_MAX_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::max(),
};

bool FullTypeId_IsValid(int value);
extern const uint32_t FullTypeId_internal_data_[];
constexpr FullTypeId FullTypeId_MIN = static_cast<FullTypeId>(0);
constexpr FullTypeId FullTypeId_MAX = static_cast<FullTypeId>(10203);
constexpr int FullTypeId_ARRAYSIZE = 10203 + 1;
const ::google::protobuf::EnumDescriptor*
FullTypeId_descriptor();
template <typename T>
const std::string& FullTypeId_Name(T value) {
  static_assert(std::is_same<T, FullTypeId>::value ||
                    std::is_integral<T>::value,
                "Incorrect type passed to FullTypeId_Name().");
  return ::google::protobuf::internal::NameOfEnum(FullTypeId_descriptor(), value);
}
inline bool FullTypeId_Parse(absl::string_view name, FullTypeId* value) {
  return ::google::protobuf::internal::ParseNamedEnum<FullTypeId>(
      FullTypeId_descriptor(), name, value);
}

// ===================================================================


// -------------------------------------------------------------------

class FullTypeDef final
    : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:tensorflow.FullTypeDef) */ {
 public:
  inline FullTypeDef() : FullTypeDef(nullptr) {}
  ~FullTypeDef() PROTOBUF_FINAL;

#if defined(PROTOBUF_CUSTOM_VTABLE)
  void operator delete(FullTypeDef* msg, std::destroying_delete_t) {
    SharedDtor(*msg);
    ::google::protobuf::internal::SizedDelete(msg, sizeof(FullTypeDef));
  }
#endif

  template <typename = void>
  explicit PROTOBUF_CONSTEXPR FullTypeDef(
      ::google::protobuf::internal::ConstantInitialized);

  inline FullTypeDef(const FullTypeDef& from) : FullTypeDef(nullptr, from) {}
  inline FullTypeDef(FullTypeDef&& from) noexcept
      : FullTypeDef(nullptr, std::move(from)) {}
  inline FullTypeDef& operator=(const FullTypeDef& from) {
    CopyFrom(from);
    return *this;
  }
  inline FullTypeDef& operator=(FullTypeDef&& from) noexcept {
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
  static const FullTypeDef& default_instance() {
    return *internal_default_instance();
  }
  enum AttrCase {
    kS = 3,
    kI = 4,
    ATTR_NOT_SET = 0,
  };
  static inline const FullTypeDef* internal_default_instance() {
    return reinterpret_cast<const FullTypeDef*>(
        &_FullTypeDef_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(FullTypeDef& a, FullTypeDef& b) { a.Swap(&b); }
  inline void Swap(FullTypeDef* other) {
    if (other == this) return;
    if (::google::protobuf::internal::CanUseInternalSwap(GetArena(), other->GetArena())) {
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(FullTypeDef* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  FullTypeDef* New(::google::protobuf::Arena* arena = nullptr) const {
    return ::google::protobuf::Message::DefaultConstruct<FullTypeDef>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const FullTypeDef& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const FullTypeDef& from) { FullTypeDef::MergeImpl(*this, from); }

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
  void InternalSwap(FullTypeDef* other);
 private:
  template <typename T>
  friend ::absl::string_view(
      ::google::protobuf::internal::GetAnyMessageName)();
  static ::absl::string_view FullMessageName() { return "tensorflow.FullTypeDef"; }

 protected:
  explicit FullTypeDef(::google::protobuf::Arena* arena);
  FullTypeDef(::google::protobuf::Arena* arena, const FullTypeDef& from);
  FullTypeDef(::google::protobuf::Arena* arena, FullTypeDef&& from) noexcept
      : FullTypeDef(arena) {
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
    kArgsFieldNumber = 2,
    kTypeIdFieldNumber = 1,
    kSFieldNumber = 3,
    kIFieldNumber = 4,
  };
  // repeated .tensorflow.FullTypeDef args = 2;
  int args_size() const;
  private:
  int _internal_args_size() const;

  public:
  void clear_args() ;
  ::tensorflow::FullTypeDef* mutable_args(int index);
  ::google::protobuf::RepeatedPtrField<::tensorflow::FullTypeDef>* mutable_args();

  private:
  const ::google::protobuf::RepeatedPtrField<::tensorflow::FullTypeDef>& _internal_args() const;
  ::google::protobuf::RepeatedPtrField<::tensorflow::FullTypeDef>* _internal_mutable_args();
  public:
  const ::tensorflow::FullTypeDef& args(int index) const;
  ::tensorflow::FullTypeDef* add_args();
  const ::google::protobuf::RepeatedPtrField<::tensorflow::FullTypeDef>& args() const;
  // .tensorflow.FullTypeId type_id = 1;
  void clear_type_id() ;
  ::tensorflow::FullTypeId type_id() const;
  void set_type_id(::tensorflow::FullTypeId value);

  private:
  ::tensorflow::FullTypeId _internal_type_id() const;
  void _internal_set_type_id(::tensorflow::FullTypeId value);

  public:
  // string s = 3;
  bool has_s() const;
  void clear_s() ;
  const std::string& s() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_s(Arg_&& arg, Args_... args);
  std::string* mutable_s();
  PROTOBUF_NODISCARD std::string* release_s();
  void set_allocated_s(std::string* value);

  private:
  const std::string& _internal_s() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_s(
      const std::string& value);
  std::string* _internal_mutable_s();

  public:
  // int64 i = 4;
  bool has_i() const;
  void clear_i() ;
  ::int64_t i() const;
  void set_i(::int64_t value);

  private:
  ::int64_t _internal_i() const;
  void _internal_set_i(::int64_t value);

  public:
  void clear_attr();
  AttrCase attr_case() const;
  // @@protoc_insertion_point(class_scope:tensorflow.FullTypeDef)
 private:
  class _Internal;
  void set_has_s();
  void set_has_i();
  inline bool has_attr() const;
  inline void clear_has_attr();
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      1, 4, 1,
      32, 2>
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
                          const FullTypeDef& from_msg);
    ::google::protobuf::RepeatedPtrField< ::tensorflow::FullTypeDef > args_;
    int type_id_;
    union AttrUnion {
      constexpr AttrUnion() : _constinit_{} {}
      ::google::protobuf::internal::ConstantInitialized _constinit_;
      ::google::protobuf::internal::ArenaStringPtr s_;
      ::int64_t i_;
    } attr_;
    ::google::protobuf::internal::CachedSize _cached_size_;
    ::uint32_t _oneof_case_[1];
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_tensorflow_2fcore_2fframework_2ffull_5ftype_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// FullTypeDef

// .tensorflow.FullTypeId type_id = 1;
inline void FullTypeDef::clear_type_id() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.type_id_ = 0;
}
inline ::tensorflow::FullTypeId FullTypeDef::type_id() const {
  // @@protoc_insertion_point(field_get:tensorflow.FullTypeDef.type_id)
  return _internal_type_id();
}
inline void FullTypeDef::set_type_id(::tensorflow::FullTypeId value) {
  _internal_set_type_id(value);
  // @@protoc_insertion_point(field_set:tensorflow.FullTypeDef.type_id)
}
inline ::tensorflow::FullTypeId FullTypeDef::_internal_type_id() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return static_cast<::tensorflow::FullTypeId>(_impl_.type_id_);
}
inline void FullTypeDef::_internal_set_type_id(::tensorflow::FullTypeId value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.type_id_ = value;
}

// repeated .tensorflow.FullTypeDef args = 2;
inline int FullTypeDef::_internal_args_size() const {
  return _internal_args().size();
}
inline int FullTypeDef::args_size() const {
  return _internal_args_size();
}
inline void FullTypeDef::clear_args() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.args_.Clear();
}
inline ::tensorflow::FullTypeDef* FullTypeDef::mutable_args(int index)
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable:tensorflow.FullTypeDef.args)
  return _internal_mutable_args()->Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField<::tensorflow::FullTypeDef>* FullTypeDef::mutable_args()
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable_list:tensorflow.FullTypeDef.args)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  return _internal_mutable_args();
}
inline const ::tensorflow::FullTypeDef& FullTypeDef::args(int index) const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:tensorflow.FullTypeDef.args)
  return _internal_args().Get(index);
}
inline ::tensorflow::FullTypeDef* FullTypeDef::add_args() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::tensorflow::FullTypeDef* _add = _internal_mutable_args()->Add();
  // @@protoc_insertion_point(field_add:tensorflow.FullTypeDef.args)
  return _add;
}
inline const ::google::protobuf::RepeatedPtrField<::tensorflow::FullTypeDef>& FullTypeDef::args() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_list:tensorflow.FullTypeDef.args)
  return _internal_args();
}
inline const ::google::protobuf::RepeatedPtrField<::tensorflow::FullTypeDef>&
FullTypeDef::_internal_args() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.args_;
}
inline ::google::protobuf::RepeatedPtrField<::tensorflow::FullTypeDef>*
FullTypeDef::_internal_mutable_args() {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return &_impl_.args_;
}

// string s = 3;
inline bool FullTypeDef::has_s() const {
  return attr_case() == kS;
}
inline void FullTypeDef::set_has_s() {
  _impl_._oneof_case_[0] = kS;
}
inline void FullTypeDef::clear_s() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (attr_case() == kS) {
    _impl_.attr_.s_.Destroy();
    clear_has_attr();
  }
}
inline const std::string& FullTypeDef::s() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:tensorflow.FullTypeDef.s)
  return _internal_s();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void FullTypeDef::set_s(Arg_&& arg,
                                                     Args_... args) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (attr_case() != kS) {
    clear_attr();

    set_has_s();
    _impl_.attr_.s_.InitDefault();
  }
  _impl_.attr_.s_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:tensorflow.FullTypeDef.s)
}
inline std::string* FullTypeDef::mutable_s() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_s();
  // @@protoc_insertion_point(field_mutable:tensorflow.FullTypeDef.s)
  return _s;
}
inline const std::string& FullTypeDef::_internal_s() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  if (attr_case() != kS) {
    return ::google::protobuf::internal::GetEmptyStringAlreadyInited();
  }
  return _impl_.attr_.s_.Get();
}
inline void FullTypeDef::_internal_set_s(const std::string& value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (attr_case() != kS) {
    clear_attr();

    set_has_s();
    _impl_.attr_.s_.InitDefault();
  }
  _impl_.attr_.s_.Set(value, GetArena());
}
inline std::string* FullTypeDef::_internal_mutable_s() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (attr_case() != kS) {
    clear_attr();

    set_has_s();
    _impl_.attr_.s_.InitDefault();
  }
  return _impl_.attr_.s_.Mutable( GetArena());
}
inline std::string* FullTypeDef::release_s() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:tensorflow.FullTypeDef.s)
  if (attr_case() != kS) {
    return nullptr;
  }
  clear_has_attr();
  return _impl_.attr_.s_.Release();
}
inline void FullTypeDef::set_allocated_s(std::string* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (has_attr()) {
    clear_attr();
  }
  if (value != nullptr) {
    set_has_s();
    _impl_.attr_.s_.InitAllocated(value, GetArena());
  }
  // @@protoc_insertion_point(field_set_allocated:tensorflow.FullTypeDef.s)
}

// int64 i = 4;
inline bool FullTypeDef::has_i() const {
  return attr_case() == kI;
}
inline void FullTypeDef::set_has_i() {
  _impl_._oneof_case_[0] = kI;
}
inline void FullTypeDef::clear_i() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (attr_case() == kI) {
    _impl_.attr_.i_ = ::int64_t{0};
    clear_has_attr();
  }
}
inline ::int64_t FullTypeDef::i() const {
  // @@protoc_insertion_point(field_get:tensorflow.FullTypeDef.i)
  return _internal_i();
}
inline void FullTypeDef::set_i(::int64_t value) {
  if (attr_case() != kI) {
    clear_attr();
    set_has_i();
  }
  _impl_.attr_.i_ = value;
  // @@protoc_insertion_point(field_set:tensorflow.FullTypeDef.i)
}
inline ::int64_t FullTypeDef::_internal_i() const {
  if (attr_case() == kI) {
    return _impl_.attr_.i_;
  }
  return ::int64_t{0};
}

inline bool FullTypeDef::has_attr() const {
  return attr_case() != ATTR_NOT_SET;
}
inline void FullTypeDef::clear_has_attr() {
  _impl_._oneof_case_[0] = ATTR_NOT_SET;
}
inline FullTypeDef::AttrCase FullTypeDef::attr_case() const {
  return FullTypeDef::AttrCase(_impl_._oneof_case_[0]);
}
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace tensorflow


namespace google {
namespace protobuf {

template <>
struct is_proto_enum<::tensorflow::FullTypeId> : std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor<::tensorflow::FullTypeId>() {
  return ::tensorflow::FullTypeId_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // tensorflow_2fcore_2fframework_2ffull_5ftype_2eproto_2epb_2eh
