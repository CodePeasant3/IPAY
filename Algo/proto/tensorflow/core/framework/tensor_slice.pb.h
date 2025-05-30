// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: tensorflow/core/framework/tensor_slice.proto
// Protobuf C++ Version: 5.29.0

#ifndef tensorflow_2fcore_2fframework_2ftensor_5fslice_2eproto_2epb_2eh
#define tensorflow_2fcore_2fframework_2ftensor_5fslice_2eproto_2epb_2eh

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
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_tensorflow_2fcore_2fframework_2ftensor_5fslice_2eproto

namespace google {
namespace protobuf {
namespace internal {
template <typename T>
::absl::string_view GetAnyMessageName();
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_tensorflow_2fcore_2fframework_2ftensor_5fslice_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_tensorflow_2fcore_2fframework_2ftensor_5fslice_2eproto;
namespace tensorflow {
class TensorSliceProto;
struct TensorSliceProtoDefaultTypeInternal;
extern TensorSliceProtoDefaultTypeInternal _TensorSliceProto_default_instance_;
class TensorSliceProto_Extent;
struct TensorSliceProto_ExtentDefaultTypeInternal;
extern TensorSliceProto_ExtentDefaultTypeInternal _TensorSliceProto_Extent_default_instance_;
}  // namespace tensorflow
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace tensorflow {

// ===================================================================


// -------------------------------------------------------------------

class TensorSliceProto_Extent final
    : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:tensorflow.TensorSliceProto.Extent) */ {
 public:
  inline TensorSliceProto_Extent() : TensorSliceProto_Extent(nullptr) {}
  ~TensorSliceProto_Extent() PROTOBUF_FINAL;

#if defined(PROTOBUF_CUSTOM_VTABLE)
  void operator delete(TensorSliceProto_Extent* msg, std::destroying_delete_t) {
    SharedDtor(*msg);
    ::google::protobuf::internal::SizedDelete(msg, sizeof(TensorSliceProto_Extent));
  }
#endif

  template <typename = void>
  explicit PROTOBUF_CONSTEXPR TensorSliceProto_Extent(
      ::google::protobuf::internal::ConstantInitialized);

  inline TensorSliceProto_Extent(const TensorSliceProto_Extent& from) : TensorSliceProto_Extent(nullptr, from) {}
  inline TensorSliceProto_Extent(TensorSliceProto_Extent&& from) noexcept
      : TensorSliceProto_Extent(nullptr, std::move(from)) {}
  inline TensorSliceProto_Extent& operator=(const TensorSliceProto_Extent& from) {
    CopyFrom(from);
    return *this;
  }
  inline TensorSliceProto_Extent& operator=(TensorSliceProto_Extent&& from) noexcept {
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
  static const TensorSliceProto_Extent& default_instance() {
    return *internal_default_instance();
  }
  enum HasLengthCase {
    kLength = 2,
    HAS_LENGTH_NOT_SET = 0,
  };
  static inline const TensorSliceProto_Extent* internal_default_instance() {
    return reinterpret_cast<const TensorSliceProto_Extent*>(
        &_TensorSliceProto_Extent_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(TensorSliceProto_Extent& a, TensorSliceProto_Extent& b) { a.Swap(&b); }
  inline void Swap(TensorSliceProto_Extent* other) {
    if (other == this) return;
    if (::google::protobuf::internal::CanUseInternalSwap(GetArena(), other->GetArena())) {
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(TensorSliceProto_Extent* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  TensorSliceProto_Extent* New(::google::protobuf::Arena* arena = nullptr) const {
    return ::google::protobuf::Message::DefaultConstruct<TensorSliceProto_Extent>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const TensorSliceProto_Extent& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const TensorSliceProto_Extent& from) { TensorSliceProto_Extent::MergeImpl(*this, from); }

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
  void InternalSwap(TensorSliceProto_Extent* other);
 private:
  template <typename T>
  friend ::absl::string_view(
      ::google::protobuf::internal::GetAnyMessageName)();
  static ::absl::string_view FullMessageName() { return "tensorflow.TensorSliceProto.Extent"; }

 protected:
  explicit TensorSliceProto_Extent(::google::protobuf::Arena* arena);
  TensorSliceProto_Extent(::google::protobuf::Arena* arena, const TensorSliceProto_Extent& from);
  TensorSliceProto_Extent(::google::protobuf::Arena* arena, TensorSliceProto_Extent&& from) noexcept
      : TensorSliceProto_Extent(arena) {
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
    kStartFieldNumber = 1,
    kLengthFieldNumber = 2,
  };
  // int64 start = 1;
  void clear_start() ;
  ::int64_t start() const;
  void set_start(::int64_t value);

  private:
  ::int64_t _internal_start() const;
  void _internal_set_start(::int64_t value);

  public:
  // int64 length = 2;
  bool has_length() const;
  void clear_length() ;
  ::int64_t length() const;
  void set_length(::int64_t value);

  private:
  ::int64_t _internal_length() const;
  void _internal_set_length(::int64_t value);

  public:
  void clear_has_length();
  HasLengthCase has_length_case() const;
  // @@protoc_insertion_point(class_scope:tensorflow.TensorSliceProto.Extent)
 private:
  class _Internal;
  void set_has_length();
  inline bool has_has_length() const;
  inline void clear_has_has_length();
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 2, 0,
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
                          const TensorSliceProto_Extent& from_msg);
    ::int64_t start_;
    union HasLengthUnion {
      constexpr HasLengthUnion() : _constinit_{} {}
      ::google::protobuf::internal::ConstantInitialized _constinit_;
      ::int64_t length_;
    } has_length_;
    ::google::protobuf::internal::CachedSize _cached_size_;
    ::uint32_t _oneof_case_[1];
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_tensorflow_2fcore_2fframework_2ftensor_5fslice_2eproto;
};
// -------------------------------------------------------------------

class TensorSliceProto final
    : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:tensorflow.TensorSliceProto) */ {
 public:
  inline TensorSliceProto() : TensorSliceProto(nullptr) {}
  ~TensorSliceProto() PROTOBUF_FINAL;

#if defined(PROTOBUF_CUSTOM_VTABLE)
  void operator delete(TensorSliceProto* msg, std::destroying_delete_t) {
    SharedDtor(*msg);
    ::google::protobuf::internal::SizedDelete(msg, sizeof(TensorSliceProto));
  }
#endif

  template <typename = void>
  explicit PROTOBUF_CONSTEXPR TensorSliceProto(
      ::google::protobuf::internal::ConstantInitialized);

  inline TensorSliceProto(const TensorSliceProto& from) : TensorSliceProto(nullptr, from) {}
  inline TensorSliceProto(TensorSliceProto&& from) noexcept
      : TensorSliceProto(nullptr, std::move(from)) {}
  inline TensorSliceProto& operator=(const TensorSliceProto& from) {
    CopyFrom(from);
    return *this;
  }
  inline TensorSliceProto& operator=(TensorSliceProto&& from) noexcept {
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
  static const TensorSliceProto& default_instance() {
    return *internal_default_instance();
  }
  static inline const TensorSliceProto* internal_default_instance() {
    return reinterpret_cast<const TensorSliceProto*>(
        &_TensorSliceProto_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 1;
  friend void swap(TensorSliceProto& a, TensorSliceProto& b) { a.Swap(&b); }
  inline void Swap(TensorSliceProto* other) {
    if (other == this) return;
    if (::google::protobuf::internal::CanUseInternalSwap(GetArena(), other->GetArena())) {
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(TensorSliceProto* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  TensorSliceProto* New(::google::protobuf::Arena* arena = nullptr) const {
    return ::google::protobuf::Message::DefaultConstruct<TensorSliceProto>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const TensorSliceProto& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const TensorSliceProto& from) { TensorSliceProto::MergeImpl(*this, from); }

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
  void InternalSwap(TensorSliceProto* other);
 private:
  template <typename T>
  friend ::absl::string_view(
      ::google::protobuf::internal::GetAnyMessageName)();
  static ::absl::string_view FullMessageName() { return "tensorflow.TensorSliceProto"; }

 protected:
  explicit TensorSliceProto(::google::protobuf::Arena* arena);
  TensorSliceProto(::google::protobuf::Arena* arena, const TensorSliceProto& from);
  TensorSliceProto(::google::protobuf::Arena* arena, TensorSliceProto&& from) noexcept
      : TensorSliceProto(arena) {
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
  using Extent = TensorSliceProto_Extent;

  // accessors -------------------------------------------------------
  enum : int {
    kExtentFieldNumber = 1,
  };
  // repeated .tensorflow.TensorSliceProto.Extent extent = 1;
  int extent_size() const;
  private:
  int _internal_extent_size() const;

  public:
  void clear_extent() ;
  ::tensorflow::TensorSliceProto_Extent* mutable_extent(int index);
  ::google::protobuf::RepeatedPtrField<::tensorflow::TensorSliceProto_Extent>* mutable_extent();

  private:
  const ::google::protobuf::RepeatedPtrField<::tensorflow::TensorSliceProto_Extent>& _internal_extent() const;
  ::google::protobuf::RepeatedPtrField<::tensorflow::TensorSliceProto_Extent>* _internal_mutable_extent();
  public:
  const ::tensorflow::TensorSliceProto_Extent& extent(int index) const;
  ::tensorflow::TensorSliceProto_Extent* add_extent();
  const ::google::protobuf::RepeatedPtrField<::tensorflow::TensorSliceProto_Extent>& extent() const;
  // @@protoc_insertion_point(class_scope:tensorflow.TensorSliceProto)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 1, 1,
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
                          const TensorSliceProto& from_msg);
    ::google::protobuf::RepeatedPtrField< ::tensorflow::TensorSliceProto_Extent > extent_;
    ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_tensorflow_2fcore_2fframework_2ftensor_5fslice_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// TensorSliceProto_Extent

// int64 start = 1;
inline void TensorSliceProto_Extent::clear_start() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.start_ = ::int64_t{0};
}
inline ::int64_t TensorSliceProto_Extent::start() const {
  // @@protoc_insertion_point(field_get:tensorflow.TensorSliceProto.Extent.start)
  return _internal_start();
}
inline void TensorSliceProto_Extent::set_start(::int64_t value) {
  _internal_set_start(value);
  // @@protoc_insertion_point(field_set:tensorflow.TensorSliceProto.Extent.start)
}
inline ::int64_t TensorSliceProto_Extent::_internal_start() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.start_;
}
inline void TensorSliceProto_Extent::_internal_set_start(::int64_t value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.start_ = value;
}

// int64 length = 2;
inline bool TensorSliceProto_Extent::has_length() const {
  return has_length_case() == kLength;
}
inline void TensorSliceProto_Extent::set_has_length() {
  _impl_._oneof_case_[0] = kLength;
}
inline void TensorSliceProto_Extent::clear_length() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (has_length_case() == kLength) {
    _impl_.has_length_.length_ = ::int64_t{0};
    clear_has_has_length();
  }
}
inline ::int64_t TensorSliceProto_Extent::length() const {
  // @@protoc_insertion_point(field_get:tensorflow.TensorSliceProto.Extent.length)
  return _internal_length();
}
inline void TensorSliceProto_Extent::set_length(::int64_t value) {
  if (has_length_case() != kLength) {
    clear_has_length();
    set_has_length();
  }
  _impl_.has_length_.length_ = value;
  // @@protoc_insertion_point(field_set:tensorflow.TensorSliceProto.Extent.length)
}
inline ::int64_t TensorSliceProto_Extent::_internal_length() const {
  if (has_length_case() == kLength) {
    return _impl_.has_length_.length_;
  }
  return ::int64_t{0};
}

inline bool TensorSliceProto_Extent::has_has_length() const {
  return has_length_case() != HAS_LENGTH_NOT_SET;
}
inline void TensorSliceProto_Extent::clear_has_has_length() {
  _impl_._oneof_case_[0] = HAS_LENGTH_NOT_SET;
}
inline TensorSliceProto_Extent::HasLengthCase TensorSliceProto_Extent::has_length_case() const {
  return TensorSliceProto_Extent::HasLengthCase(_impl_._oneof_case_[0]);
}
// -------------------------------------------------------------------

// TensorSliceProto

// repeated .tensorflow.TensorSliceProto.Extent extent = 1;
inline int TensorSliceProto::_internal_extent_size() const {
  return _internal_extent().size();
}
inline int TensorSliceProto::extent_size() const {
  return _internal_extent_size();
}
inline void TensorSliceProto::clear_extent() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.extent_.Clear();
}
inline ::tensorflow::TensorSliceProto_Extent* TensorSliceProto::mutable_extent(int index)
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable:tensorflow.TensorSliceProto.extent)
  return _internal_mutable_extent()->Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField<::tensorflow::TensorSliceProto_Extent>* TensorSliceProto::mutable_extent()
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable_list:tensorflow.TensorSliceProto.extent)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  return _internal_mutable_extent();
}
inline const ::tensorflow::TensorSliceProto_Extent& TensorSliceProto::extent(int index) const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:tensorflow.TensorSliceProto.extent)
  return _internal_extent().Get(index);
}
inline ::tensorflow::TensorSliceProto_Extent* TensorSliceProto::add_extent() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::tensorflow::TensorSliceProto_Extent* _add = _internal_mutable_extent()->Add();
  // @@protoc_insertion_point(field_add:tensorflow.TensorSliceProto.extent)
  return _add;
}
inline const ::google::protobuf::RepeatedPtrField<::tensorflow::TensorSliceProto_Extent>& TensorSliceProto::extent() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_list:tensorflow.TensorSliceProto.extent)
  return _internal_extent();
}
inline const ::google::protobuf::RepeatedPtrField<::tensorflow::TensorSliceProto_Extent>&
TensorSliceProto::_internal_extent() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.extent_;
}
inline ::google::protobuf::RepeatedPtrField<::tensorflow::TensorSliceProto_Extent>*
TensorSliceProto::_internal_mutable_extent() {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return &_impl_.extent_;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace tensorflow


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // tensorflow_2fcore_2fframework_2ftensor_5fslice_2eproto_2epb_2eh
