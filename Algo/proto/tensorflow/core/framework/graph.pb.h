// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: tensorflow/core/framework/graph.proto
// Protobuf C++ Version: 5.29.0

#ifndef tensorflow_2fcore_2fframework_2fgraph_2eproto_2epb_2eh
#define tensorflow_2fcore_2fframework_2fgraph_2eproto_2epb_2eh

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
#include "tensorflow/core/framework/function.pb.h"
#include "tensorflow/core/framework/graph_debug_info.pb.h"
#include "tensorflow/core/framework/node_def.pb.h"
#include "tensorflow/core/framework/versions.pb.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_tensorflow_2fcore_2fframework_2fgraph_2eproto

namespace google {
namespace protobuf {
namespace internal {
template <typename T>
::absl::string_view GetAnyMessageName();
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_tensorflow_2fcore_2fframework_2fgraph_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_tensorflow_2fcore_2fframework_2fgraph_2eproto;
namespace tensorflow {
class GraphDef;
struct GraphDefDefaultTypeInternal;
extern GraphDefDefaultTypeInternal _GraphDef_default_instance_;
}  // namespace tensorflow
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace tensorflow {

// ===================================================================


// -------------------------------------------------------------------

class GraphDef final
    : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:tensorflow.GraphDef) */ {
 public:
  inline GraphDef() : GraphDef(nullptr) {}
  ~GraphDef() PROTOBUF_FINAL;

#if defined(PROTOBUF_CUSTOM_VTABLE)
  void operator delete(GraphDef* msg, std::destroying_delete_t) {
    SharedDtor(*msg);
    ::google::protobuf::internal::SizedDelete(msg, sizeof(GraphDef));
  }
#endif

  template <typename = void>
  explicit PROTOBUF_CONSTEXPR GraphDef(
      ::google::protobuf::internal::ConstantInitialized);

  inline GraphDef(const GraphDef& from) : GraphDef(nullptr, from) {}
  inline GraphDef(GraphDef&& from) noexcept
      : GraphDef(nullptr, std::move(from)) {}
  inline GraphDef& operator=(const GraphDef& from) {
    CopyFrom(from);
    return *this;
  }
  inline GraphDef& operator=(GraphDef&& from) noexcept {
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
  static const GraphDef& default_instance() {
    return *internal_default_instance();
  }
  static inline const GraphDef* internal_default_instance() {
    return reinterpret_cast<const GraphDef*>(
        &_GraphDef_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(GraphDef& a, GraphDef& b) { a.Swap(&b); }
  inline void Swap(GraphDef* other) {
    if (other == this) return;
    if (::google::protobuf::internal::CanUseInternalSwap(GetArena(), other->GetArena())) {
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(GraphDef* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  GraphDef* New(::google::protobuf::Arena* arena = nullptr) const {
    return ::google::protobuf::Message::DefaultConstruct<GraphDef>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const GraphDef& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const GraphDef& from) { GraphDef::MergeImpl(*this, from); }

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
  void InternalSwap(GraphDef* other);
 private:
  template <typename T>
  friend ::absl::string_view(
      ::google::protobuf::internal::GetAnyMessageName)();
  static ::absl::string_view FullMessageName() { return "tensorflow.GraphDef"; }

 protected:
  explicit GraphDef(::google::protobuf::Arena* arena);
  GraphDef(::google::protobuf::Arena* arena, const GraphDef& from);
  GraphDef(::google::protobuf::Arena* arena, GraphDef&& from) noexcept
      : GraphDef(arena) {
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
    kNodeFieldNumber = 1,
    kLibraryFieldNumber = 2,
    kVersionsFieldNumber = 4,
    kDebugInfoFieldNumber = 5,
    kVersionFieldNumber = 3,
  };
  // repeated .tensorflow.NodeDef node = 1;
  int node_size() const;
  private:
  int _internal_node_size() const;

  public:
  void clear_node() ;
  ::tensorflow::NodeDef* mutable_node(int index);
  ::google::protobuf::RepeatedPtrField<::tensorflow::NodeDef>* mutable_node();

  private:
  const ::google::protobuf::RepeatedPtrField<::tensorflow::NodeDef>& _internal_node() const;
  ::google::protobuf::RepeatedPtrField<::tensorflow::NodeDef>* _internal_mutable_node();
  public:
  const ::tensorflow::NodeDef& node(int index) const;
  ::tensorflow::NodeDef* add_node();
  const ::google::protobuf::RepeatedPtrField<::tensorflow::NodeDef>& node() const;
  // .tensorflow.FunctionDefLibrary library = 2;
  bool has_library() const;
  void clear_library() ;
  const ::tensorflow::FunctionDefLibrary& library() const;
  PROTOBUF_NODISCARD ::tensorflow::FunctionDefLibrary* release_library();
  ::tensorflow::FunctionDefLibrary* mutable_library();
  void set_allocated_library(::tensorflow::FunctionDefLibrary* value);
  void unsafe_arena_set_allocated_library(::tensorflow::FunctionDefLibrary* value);
  ::tensorflow::FunctionDefLibrary* unsafe_arena_release_library();

  private:
  const ::tensorflow::FunctionDefLibrary& _internal_library() const;
  ::tensorflow::FunctionDefLibrary* _internal_mutable_library();

  public:
  // .tensorflow.VersionDef versions = 4;
  bool has_versions() const;
  void clear_versions() ;
  const ::tensorflow::VersionDef& versions() const;
  PROTOBUF_NODISCARD ::tensorflow::VersionDef* release_versions();
  ::tensorflow::VersionDef* mutable_versions();
  void set_allocated_versions(::tensorflow::VersionDef* value);
  void unsafe_arena_set_allocated_versions(::tensorflow::VersionDef* value);
  ::tensorflow::VersionDef* unsafe_arena_release_versions();

  private:
  const ::tensorflow::VersionDef& _internal_versions() const;
  ::tensorflow::VersionDef* _internal_mutable_versions();

  public:
  // .tensorflow.GraphDebugInfo debug_info = 5;
  bool has_debug_info() const;
  void clear_debug_info() ;
  const ::tensorflow::GraphDebugInfo& debug_info() const;
  PROTOBUF_NODISCARD ::tensorflow::GraphDebugInfo* release_debug_info();
  ::tensorflow::GraphDebugInfo* mutable_debug_info();
  void set_allocated_debug_info(::tensorflow::GraphDebugInfo* value);
  void unsafe_arena_set_allocated_debug_info(::tensorflow::GraphDebugInfo* value);
  ::tensorflow::GraphDebugInfo* unsafe_arena_release_debug_info();

  private:
  const ::tensorflow::GraphDebugInfo& _internal_debug_info() const;
  ::tensorflow::GraphDebugInfo* _internal_mutable_debug_info();

  public:
  // int32 version = 3 [deprecated = true];
  [[deprecated]]  void clear_version() ;
  [[deprecated]] ::int32_t version() const;
  [[deprecated]] void set_version(::int32_t value);

  private:
  ::int32_t _internal_version() const;
  void _internal_set_version(::int32_t value);

  public:
  // @@protoc_insertion_point(class_scope:tensorflow.GraphDef)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      3, 5, 4,
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
                          const GraphDef& from_msg);
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    ::google::protobuf::internal::CachedSize _cached_size_;
    ::google::protobuf::RepeatedPtrField< ::tensorflow::NodeDef > node_;
    ::tensorflow::FunctionDefLibrary* library_;
    ::tensorflow::VersionDef* versions_;
    ::tensorflow::GraphDebugInfo* debug_info_;
    ::int32_t version_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_tensorflow_2fcore_2fframework_2fgraph_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// GraphDef

// repeated .tensorflow.NodeDef node = 1;
inline int GraphDef::_internal_node_size() const {
  return _internal_node().size();
}
inline int GraphDef::node_size() const {
  return _internal_node_size();
}
inline ::tensorflow::NodeDef* GraphDef::mutable_node(int index)
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable:tensorflow.GraphDef.node)
  return _internal_mutable_node()->Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField<::tensorflow::NodeDef>* GraphDef::mutable_node()
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable_list:tensorflow.GraphDef.node)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  return _internal_mutable_node();
}
inline const ::tensorflow::NodeDef& GraphDef::node(int index) const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:tensorflow.GraphDef.node)
  return _internal_node().Get(index);
}
inline ::tensorflow::NodeDef* GraphDef::add_node() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::tensorflow::NodeDef* _add = _internal_mutable_node()->Add();
  // @@protoc_insertion_point(field_add:tensorflow.GraphDef.node)
  return _add;
}
inline const ::google::protobuf::RepeatedPtrField<::tensorflow::NodeDef>& GraphDef::node() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_list:tensorflow.GraphDef.node)
  return _internal_node();
}
inline const ::google::protobuf::RepeatedPtrField<::tensorflow::NodeDef>&
GraphDef::_internal_node() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.node_;
}
inline ::google::protobuf::RepeatedPtrField<::tensorflow::NodeDef>*
GraphDef::_internal_mutable_node() {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return &_impl_.node_;
}

// .tensorflow.VersionDef versions = 4;
inline bool GraphDef::has_versions() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.versions_ != nullptr);
  return value;
}
inline const ::tensorflow::VersionDef& GraphDef::_internal_versions() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  const ::tensorflow::VersionDef* p = _impl_.versions_;
  return p != nullptr ? *p : reinterpret_cast<const ::tensorflow::VersionDef&>(::tensorflow::_VersionDef_default_instance_);
}
inline const ::tensorflow::VersionDef& GraphDef::versions() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:tensorflow.GraphDef.versions)
  return _internal_versions();
}
inline void GraphDef::unsafe_arena_set_allocated_versions(::tensorflow::VersionDef* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.versions_);
  }
  _impl_.versions_ = reinterpret_cast<::tensorflow::VersionDef*>(value);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:tensorflow.GraphDef.versions)
}
inline ::tensorflow::VersionDef* GraphDef::release_versions() {
  ::google::protobuf::internal::TSanWrite(&_impl_);

  _impl_._has_bits_[0] &= ~0x00000002u;
  ::tensorflow::VersionDef* released = _impl_.versions_;
  _impl_.versions_ = nullptr;
  if (::google::protobuf::internal::DebugHardenForceCopyInRelease()) {
    auto* old = reinterpret_cast<::google::protobuf::MessageLite*>(released);
    released = ::google::protobuf::internal::DuplicateIfNonNull(released);
    if (GetArena() == nullptr) {
      delete old;
    }
  } else {
    if (GetArena() != nullptr) {
      released = ::google::protobuf::internal::DuplicateIfNonNull(released);
    }
  }
  return released;
}
inline ::tensorflow::VersionDef* GraphDef::unsafe_arena_release_versions() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:tensorflow.GraphDef.versions)

  _impl_._has_bits_[0] &= ~0x00000002u;
  ::tensorflow::VersionDef* temp = _impl_.versions_;
  _impl_.versions_ = nullptr;
  return temp;
}
inline ::tensorflow::VersionDef* GraphDef::_internal_mutable_versions() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (_impl_.versions_ == nullptr) {
    auto* p = ::google::protobuf::Message::DefaultConstruct<::tensorflow::VersionDef>(GetArena());
    _impl_.versions_ = reinterpret_cast<::tensorflow::VersionDef*>(p);
  }
  return _impl_.versions_;
}
inline ::tensorflow::VersionDef* GraphDef::mutable_versions() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  _impl_._has_bits_[0] |= 0x00000002u;
  ::tensorflow::VersionDef* _msg = _internal_mutable_versions();
  // @@protoc_insertion_point(field_mutable:tensorflow.GraphDef.versions)
  return _msg;
}
inline void GraphDef::set_allocated_versions(::tensorflow::VersionDef* value) {
  ::google::protobuf::Arena* message_arena = GetArena();
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (message_arena == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.versions_);
  }

  if (value != nullptr) {
    ::google::protobuf::Arena* submessage_arena = reinterpret_cast<::google::protobuf::MessageLite*>(value)->GetArena();
    if (message_arena != submessage_arena) {
      value = ::google::protobuf::internal::GetOwnedMessage(message_arena, value, submessage_arena);
    }
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }

  _impl_.versions_ = reinterpret_cast<::tensorflow::VersionDef*>(value);
  // @@protoc_insertion_point(field_set_allocated:tensorflow.GraphDef.versions)
}

// int32 version = 3 [deprecated = true];
inline void GraphDef::clear_version() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.version_ = 0;
}
inline ::int32_t GraphDef::version() const {
  // @@protoc_insertion_point(field_get:tensorflow.GraphDef.version)
  return _internal_version();
}
inline void GraphDef::set_version(::int32_t value) {
  _internal_set_version(value);
  // @@protoc_insertion_point(field_set:tensorflow.GraphDef.version)
}
inline ::int32_t GraphDef::_internal_version() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.version_;
}
inline void GraphDef::_internal_set_version(::int32_t value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.version_ = value;
}

// .tensorflow.FunctionDefLibrary library = 2;
inline bool GraphDef::has_library() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.library_ != nullptr);
  return value;
}
inline const ::tensorflow::FunctionDefLibrary& GraphDef::_internal_library() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  const ::tensorflow::FunctionDefLibrary* p = _impl_.library_;
  return p != nullptr ? *p : reinterpret_cast<const ::tensorflow::FunctionDefLibrary&>(::tensorflow::_FunctionDefLibrary_default_instance_);
}
inline const ::tensorflow::FunctionDefLibrary& GraphDef::library() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:tensorflow.GraphDef.library)
  return _internal_library();
}
inline void GraphDef::unsafe_arena_set_allocated_library(::tensorflow::FunctionDefLibrary* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.library_);
  }
  _impl_.library_ = reinterpret_cast<::tensorflow::FunctionDefLibrary*>(value);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:tensorflow.GraphDef.library)
}
inline ::tensorflow::FunctionDefLibrary* GraphDef::release_library() {
  ::google::protobuf::internal::TSanWrite(&_impl_);

  _impl_._has_bits_[0] &= ~0x00000001u;
  ::tensorflow::FunctionDefLibrary* released = _impl_.library_;
  _impl_.library_ = nullptr;
  if (::google::protobuf::internal::DebugHardenForceCopyInRelease()) {
    auto* old = reinterpret_cast<::google::protobuf::MessageLite*>(released);
    released = ::google::protobuf::internal::DuplicateIfNonNull(released);
    if (GetArena() == nullptr) {
      delete old;
    }
  } else {
    if (GetArena() != nullptr) {
      released = ::google::protobuf::internal::DuplicateIfNonNull(released);
    }
  }
  return released;
}
inline ::tensorflow::FunctionDefLibrary* GraphDef::unsafe_arena_release_library() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:tensorflow.GraphDef.library)

  _impl_._has_bits_[0] &= ~0x00000001u;
  ::tensorflow::FunctionDefLibrary* temp = _impl_.library_;
  _impl_.library_ = nullptr;
  return temp;
}
inline ::tensorflow::FunctionDefLibrary* GraphDef::_internal_mutable_library() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (_impl_.library_ == nullptr) {
    auto* p = ::google::protobuf::Message::DefaultConstruct<::tensorflow::FunctionDefLibrary>(GetArena());
    _impl_.library_ = reinterpret_cast<::tensorflow::FunctionDefLibrary*>(p);
  }
  return _impl_.library_;
}
inline ::tensorflow::FunctionDefLibrary* GraphDef::mutable_library() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  _impl_._has_bits_[0] |= 0x00000001u;
  ::tensorflow::FunctionDefLibrary* _msg = _internal_mutable_library();
  // @@protoc_insertion_point(field_mutable:tensorflow.GraphDef.library)
  return _msg;
}
inline void GraphDef::set_allocated_library(::tensorflow::FunctionDefLibrary* value) {
  ::google::protobuf::Arena* message_arena = GetArena();
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (message_arena == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.library_);
  }

  if (value != nullptr) {
    ::google::protobuf::Arena* submessage_arena = reinterpret_cast<::google::protobuf::MessageLite*>(value)->GetArena();
    if (message_arena != submessage_arena) {
      value = ::google::protobuf::internal::GetOwnedMessage(message_arena, value, submessage_arena);
    }
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }

  _impl_.library_ = reinterpret_cast<::tensorflow::FunctionDefLibrary*>(value);
  // @@protoc_insertion_point(field_set_allocated:tensorflow.GraphDef.library)
}

// .tensorflow.GraphDebugInfo debug_info = 5;
inline bool GraphDef::has_debug_info() const {
  bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.debug_info_ != nullptr);
  return value;
}
inline const ::tensorflow::GraphDebugInfo& GraphDef::_internal_debug_info() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  const ::tensorflow::GraphDebugInfo* p = _impl_.debug_info_;
  return p != nullptr ? *p : reinterpret_cast<const ::tensorflow::GraphDebugInfo&>(::tensorflow::_GraphDebugInfo_default_instance_);
}
inline const ::tensorflow::GraphDebugInfo& GraphDef::debug_info() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:tensorflow.GraphDef.debug_info)
  return _internal_debug_info();
}
inline void GraphDef::unsafe_arena_set_allocated_debug_info(::tensorflow::GraphDebugInfo* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.debug_info_);
  }
  _impl_.debug_info_ = reinterpret_cast<::tensorflow::GraphDebugInfo*>(value);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000004u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000004u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:tensorflow.GraphDef.debug_info)
}
inline ::tensorflow::GraphDebugInfo* GraphDef::release_debug_info() {
  ::google::protobuf::internal::TSanWrite(&_impl_);

  _impl_._has_bits_[0] &= ~0x00000004u;
  ::tensorflow::GraphDebugInfo* released = _impl_.debug_info_;
  _impl_.debug_info_ = nullptr;
  if (::google::protobuf::internal::DebugHardenForceCopyInRelease()) {
    auto* old = reinterpret_cast<::google::protobuf::MessageLite*>(released);
    released = ::google::protobuf::internal::DuplicateIfNonNull(released);
    if (GetArena() == nullptr) {
      delete old;
    }
  } else {
    if (GetArena() != nullptr) {
      released = ::google::protobuf::internal::DuplicateIfNonNull(released);
    }
  }
  return released;
}
inline ::tensorflow::GraphDebugInfo* GraphDef::unsafe_arena_release_debug_info() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:tensorflow.GraphDef.debug_info)

  _impl_._has_bits_[0] &= ~0x00000004u;
  ::tensorflow::GraphDebugInfo* temp = _impl_.debug_info_;
  _impl_.debug_info_ = nullptr;
  return temp;
}
inline ::tensorflow::GraphDebugInfo* GraphDef::_internal_mutable_debug_info() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (_impl_.debug_info_ == nullptr) {
    auto* p = ::google::protobuf::Message::DefaultConstruct<::tensorflow::GraphDebugInfo>(GetArena());
    _impl_.debug_info_ = reinterpret_cast<::tensorflow::GraphDebugInfo*>(p);
  }
  return _impl_.debug_info_;
}
inline ::tensorflow::GraphDebugInfo* GraphDef::mutable_debug_info() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  _impl_._has_bits_[0] |= 0x00000004u;
  ::tensorflow::GraphDebugInfo* _msg = _internal_mutable_debug_info();
  // @@protoc_insertion_point(field_mutable:tensorflow.GraphDef.debug_info)
  return _msg;
}
inline void GraphDef::set_allocated_debug_info(::tensorflow::GraphDebugInfo* value) {
  ::google::protobuf::Arena* message_arena = GetArena();
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (message_arena == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.debug_info_);
  }

  if (value != nullptr) {
    ::google::protobuf::Arena* submessage_arena = reinterpret_cast<::google::protobuf::MessageLite*>(value)->GetArena();
    if (message_arena != submessage_arena) {
      value = ::google::protobuf::internal::GetOwnedMessage(message_arena, value, submessage_arena);
    }
    _impl_._has_bits_[0] |= 0x00000004u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000004u;
  }

  _impl_.debug_info_ = reinterpret_cast<::tensorflow::GraphDebugInfo*>(value);
  // @@protoc_insertion_point(field_set_allocated:tensorflow.GraphDef.debug_info)
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace tensorflow


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // tensorflow_2fcore_2fframework_2fgraph_2eproto_2epb_2eh
