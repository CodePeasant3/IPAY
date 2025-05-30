// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: tensorflow/core/protobuf/composite_tensor_variant.proto
// Protobuf C++ Version: 5.29.0

#include "tensorflow/core/protobuf/composite_tensor_variant.pb.h"

#include <algorithm>
#include <type_traits>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/generated_message_tctable_impl.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace tensorflow {

inline constexpr CompositeTensorVariantMetadata::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        type_spec_proto_{nullptr} {}

template <typename>
PROTOBUF_CONSTEXPR CompositeTensorVariantMetadata::CompositeTensorVariantMetadata(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(::_pbi::ConstantInitialized()) {
}
struct CompositeTensorVariantMetadataDefaultTypeInternal {
  PROTOBUF_CONSTEXPR CompositeTensorVariantMetadataDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~CompositeTensorVariantMetadataDefaultTypeInternal() {}
  union {
    CompositeTensorVariantMetadata _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 CompositeTensorVariantMetadataDefaultTypeInternal _CompositeTensorVariantMetadata_default_instance_;
}  // namespace tensorflow
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_tensorflow_2fcore_2fprotobuf_2fcomposite_5ftensor_5fvariant_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_tensorflow_2fcore_2fprotobuf_2fcomposite_5ftensor_5fvariant_2eproto = nullptr;
const ::uint32_t
    TableStruct_tensorflow_2fcore_2fprotobuf_2fcomposite_5ftensor_5fvariant_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        PROTOBUF_FIELD_OFFSET(::tensorflow::CompositeTensorVariantMetadata, _impl_._has_bits_),
        PROTOBUF_FIELD_OFFSET(::tensorflow::CompositeTensorVariantMetadata, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::tensorflow::CompositeTensorVariantMetadata, _impl_.type_spec_proto_),
        0,
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, 9, -1, sizeof(::tensorflow::CompositeTensorVariantMetadata)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::tensorflow::_CompositeTensorVariantMetadata_default_instance_._instance,
};
const char descriptor_table_protodef_tensorflow_2fcore_2fprotobuf_2fcomposite_5ftensor_5fvariant_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n7tensorflow/core/protobuf/composite_ten"
    "sor_variant.proto\022\ntensorflow\032%tensorflo"
    "w/core/protobuf/struct.proto\"T\n\036Composit"
    "eTensorVariantMetadata\0222\n\017type_spec_prot"
    "o\030\001 \001(\0132\031.tensorflow.TypeSpecProtoBWZUgi"
    "thub.com/tensorflow/tensorflow/tensorflo"
    "w/go/core/protobuf/for_core_protos_go_pr"
    "otob\006proto3"
};
static const ::_pbi::DescriptorTable* const descriptor_table_tensorflow_2fcore_2fprotobuf_2fcomposite_5ftensor_5fvariant_2eproto_deps[1] =
    {
        &::descriptor_table_tensorflow_2fcore_2fprotobuf_2fstruct_2eproto,
};
static ::absl::once_flag descriptor_table_tensorflow_2fcore_2fprotobuf_2fcomposite_5ftensor_5fvariant_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_tensorflow_2fcore_2fprotobuf_2fcomposite_5ftensor_5fvariant_2eproto = {
    false,
    false,
    291,
    descriptor_table_protodef_tensorflow_2fcore_2fprotobuf_2fcomposite_5ftensor_5fvariant_2eproto,
    "tensorflow/core/protobuf/composite_tensor_variant.proto",
    &descriptor_table_tensorflow_2fcore_2fprotobuf_2fcomposite_5ftensor_5fvariant_2eproto_once,
    descriptor_table_tensorflow_2fcore_2fprotobuf_2fcomposite_5ftensor_5fvariant_2eproto_deps,
    1,
    1,
    schemas,
    file_default_instances,
    TableStruct_tensorflow_2fcore_2fprotobuf_2fcomposite_5ftensor_5fvariant_2eproto::offsets,
    file_level_enum_descriptors_tensorflow_2fcore_2fprotobuf_2fcomposite_5ftensor_5fvariant_2eproto,
    file_level_service_descriptors_tensorflow_2fcore_2fprotobuf_2fcomposite_5ftensor_5fvariant_2eproto,
};
namespace tensorflow {
// ===================================================================

class CompositeTensorVariantMetadata::_Internal {
 public:
  using HasBits =
      decltype(std::declval<CompositeTensorVariantMetadata>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
      8 * PROTOBUF_FIELD_OFFSET(CompositeTensorVariantMetadata, _impl_._has_bits_);
};

void CompositeTensorVariantMetadata::clear_type_spec_proto() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (_impl_.type_spec_proto_ != nullptr) _impl_.type_spec_proto_->Clear();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
CompositeTensorVariantMetadata::CompositeTensorVariantMetadata(::google::protobuf::Arena* arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:tensorflow.CompositeTensorVariantMetadata)
}
inline PROTOBUF_NDEBUG_INLINE CompositeTensorVariantMetadata::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::tensorflow::CompositeTensorVariantMetadata& from_msg)
      : _has_bits_{from._has_bits_},
        _cached_size_{0} {}

CompositeTensorVariantMetadata::CompositeTensorVariantMetadata(
    ::google::protobuf::Arena* arena,
    const CompositeTensorVariantMetadata& from)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  CompositeTensorVariantMetadata* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);
  ::uint32_t cached_has_bits = _impl_._has_bits_[0];
  _impl_.type_spec_proto_ = (cached_has_bits & 0x00000001u) ? ::google::protobuf::Message::CopyConstruct<::tensorflow::TypeSpecProto>(
                              arena, *from._impl_.type_spec_proto_)
                        : nullptr;

  // @@protoc_insertion_point(copy_constructor:tensorflow.CompositeTensorVariantMetadata)
}
inline PROTOBUF_NDEBUG_INLINE CompositeTensorVariantMetadata::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0} {}

inline void CompositeTensorVariantMetadata::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  _impl_.type_spec_proto_ = {};
}
CompositeTensorVariantMetadata::~CompositeTensorVariantMetadata() {
  // @@protoc_insertion_point(destructor:tensorflow.CompositeTensorVariantMetadata)
  SharedDtor(*this);
}
inline void CompositeTensorVariantMetadata::SharedDtor(MessageLite& self) {
  CompositeTensorVariantMetadata& this_ = static_cast<CompositeTensorVariantMetadata&>(self);
  this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  ABSL_DCHECK(this_.GetArena() == nullptr);
  delete this_._impl_.type_spec_proto_;
  this_._impl_.~Impl_();
}

inline void* CompositeTensorVariantMetadata::PlacementNew_(const void*, void* mem,
                                        ::google::protobuf::Arena* arena) {
  return ::new (mem) CompositeTensorVariantMetadata(arena);
}
constexpr auto CompositeTensorVariantMetadata::InternalNewImpl_() {
  return ::google::protobuf::internal::MessageCreator::ZeroInit(sizeof(CompositeTensorVariantMetadata),
                                            alignof(CompositeTensorVariantMetadata));
}
PROTOBUF_CONSTINIT
PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::google::protobuf::internal::ClassDataFull CompositeTensorVariantMetadata::_class_data_ = {
    ::google::protobuf::internal::ClassData{
        &_CompositeTensorVariantMetadata_default_instance_._instance,
        &_table_.header,
        nullptr,  // OnDemandRegisterArenaDtor
        nullptr,  // IsInitialized
        &CompositeTensorVariantMetadata::MergeImpl,
        ::google::protobuf::Message::GetNewImpl<CompositeTensorVariantMetadata>(),
#if defined(PROTOBUF_CUSTOM_VTABLE)
        &CompositeTensorVariantMetadata::SharedDtor,
        ::google::protobuf::Message::GetClearImpl<CompositeTensorVariantMetadata>(), &CompositeTensorVariantMetadata::ByteSizeLong,
            &CompositeTensorVariantMetadata::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
        PROTOBUF_FIELD_OFFSET(CompositeTensorVariantMetadata, _impl_._cached_size_),
        false,
    },
    &CompositeTensorVariantMetadata::kDescriptorMethods,
    &descriptor_table_tensorflow_2fcore_2fprotobuf_2fcomposite_5ftensor_5fvariant_2eproto,
    nullptr,  // tracker
};
const ::google::protobuf::internal::ClassData* CompositeTensorVariantMetadata::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_class_data_.tc_table);
  return _class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 1, 0, 2> CompositeTensorVariantMetadata::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(CompositeTensorVariantMetadata, _impl_._has_bits_),
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    1,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    _class_data_.base(),
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::tensorflow::CompositeTensorVariantMetadata>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // .tensorflow.TypeSpecProto type_spec_proto = 1;
    {::_pbi::TcParser::FastMtS1,
     {10, 0, 0, PROTOBUF_FIELD_OFFSET(CompositeTensorVariantMetadata, _impl_.type_spec_proto_)}},
  }}, {{
    65535, 65535
  }}, {{
    // .tensorflow.TypeSpecProto type_spec_proto = 1;
    {PROTOBUF_FIELD_OFFSET(CompositeTensorVariantMetadata, _impl_.type_spec_proto_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kMessage | ::_fl::kTvTable)},
  }}, {{
    {::_pbi::TcParser::GetTable<::tensorflow::TypeSpecProto>()},
  }}, {{
  }},
};

PROTOBUF_NOINLINE void CompositeTensorVariantMetadata::Clear() {
// @@protoc_insertion_point(message_clear_start:tensorflow.CompositeTensorVariantMetadata)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    ABSL_DCHECK(_impl_.type_spec_proto_ != nullptr);
    _impl_.type_spec_proto_->Clear();
  }
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::uint8_t* CompositeTensorVariantMetadata::_InternalSerialize(
            const MessageLite& base, ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) {
          const CompositeTensorVariantMetadata& this_ = static_cast<const CompositeTensorVariantMetadata&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::uint8_t* CompositeTensorVariantMetadata::_InternalSerialize(
            ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) const {
          const CompositeTensorVariantMetadata& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(serialize_to_array_start:tensorflow.CompositeTensorVariantMetadata)
          ::uint32_t cached_has_bits = 0;
          (void)cached_has_bits;

          cached_has_bits = this_._impl_._has_bits_[0];
          // .tensorflow.TypeSpecProto type_spec_proto = 1;
          if (cached_has_bits & 0x00000001u) {
            target = ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
                1, *this_._impl_.type_spec_proto_, this_._impl_.type_spec_proto_->GetCachedSize(), target,
                stream);
          }

          if (PROTOBUF_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
            target =
                ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
                    this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
          }
          // @@protoc_insertion_point(serialize_to_array_end:tensorflow.CompositeTensorVariantMetadata)
          return target;
        }

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::size_t CompositeTensorVariantMetadata::ByteSizeLong(const MessageLite& base) {
          const CompositeTensorVariantMetadata& this_ = static_cast<const CompositeTensorVariantMetadata&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::size_t CompositeTensorVariantMetadata::ByteSizeLong() const {
          const CompositeTensorVariantMetadata& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(message_byte_size_start:tensorflow.CompositeTensorVariantMetadata)
          ::size_t total_size = 0;

          ::uint32_t cached_has_bits = 0;
          // Prevent compiler warnings about cached_has_bits being unused
          (void)cached_has_bits;

           {
            // .tensorflow.TypeSpecProto type_spec_proto = 1;
            cached_has_bits = this_._impl_._has_bits_[0];
            if (cached_has_bits & 0x00000001u) {
              total_size += 1 +
                            ::google::protobuf::internal::WireFormatLite::MessageSize(*this_._impl_.type_spec_proto_);
            }
          }
          return this_.MaybeComputeUnknownFieldsSize(total_size,
                                                     &this_._impl_._cached_size_);
        }

void CompositeTensorVariantMetadata::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<CompositeTensorVariantMetadata*>(&to_msg);
  auto& from = static_cast<const CompositeTensorVariantMetadata&>(from_msg);
  ::google::protobuf::Arena* arena = _this->GetArena();
  // @@protoc_insertion_point(class_specific_merge_from_start:tensorflow.CompositeTensorVariantMetadata)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    ABSL_DCHECK(from._impl_.type_spec_proto_ != nullptr);
    if (_this->_impl_.type_spec_proto_ == nullptr) {
      _this->_impl_.type_spec_proto_ =
          ::google::protobuf::Message::CopyConstruct<::tensorflow::TypeSpecProto>(arena, *from._impl_.type_spec_proto_);
    } else {
      _this->_impl_.type_spec_proto_->MergeFrom(*from._impl_.type_spec_proto_);
    }
  }
  _this->_impl_._has_bits_[0] |= cached_has_bits;
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void CompositeTensorVariantMetadata::CopyFrom(const CompositeTensorVariantMetadata& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tensorflow.CompositeTensorVariantMetadata)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void CompositeTensorVariantMetadata::InternalSwap(CompositeTensorVariantMetadata* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  swap(_impl_.type_spec_proto_, other->_impl_.type_spec_proto_);
}

::google::protobuf::Metadata CompositeTensorVariantMetadata::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace tensorflow
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::std::false_type
    _static_init2_ PROTOBUF_UNUSED =
        (::_pbi::AddDescriptors(&descriptor_table_tensorflow_2fcore_2fprotobuf_2fcomposite_5ftensor_5fvariant_2eproto),
         ::std::false_type{});
#include "google/protobuf/port_undef.inc"
