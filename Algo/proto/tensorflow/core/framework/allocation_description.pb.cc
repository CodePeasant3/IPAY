// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: tensorflow/core/framework/allocation_description.proto
// Protobuf C++ Version: 5.29.0

#include "tensorflow/core/framework/allocation_description.pb.h"

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

inline constexpr AllocationDescription::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : allocator_name_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        requested_bytes_{::int64_t{0}},
        allocated_bytes_{::int64_t{0}},
        allocation_id_{::int64_t{0}},
        ptr_{::uint64_t{0u}},
        has_single_reference_{false},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR AllocationDescription::AllocationDescription(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(::_pbi::ConstantInitialized()) {
}
struct AllocationDescriptionDefaultTypeInternal {
  PROTOBUF_CONSTEXPR AllocationDescriptionDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~AllocationDescriptionDefaultTypeInternal() {}
  union {
    AllocationDescription _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 AllocationDescriptionDefaultTypeInternal _AllocationDescription_default_instance_;
}  // namespace tensorflow
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_tensorflow_2fcore_2fframework_2fallocation_5fdescription_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_tensorflow_2fcore_2fframework_2fallocation_5fdescription_2eproto = nullptr;
const ::uint32_t
    TableStruct_tensorflow_2fcore_2fframework_2fallocation_5fdescription_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::tensorflow::AllocationDescription, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::tensorflow::AllocationDescription, _impl_.requested_bytes_),
        PROTOBUF_FIELD_OFFSET(::tensorflow::AllocationDescription, _impl_.allocated_bytes_),
        PROTOBUF_FIELD_OFFSET(::tensorflow::AllocationDescription, _impl_.allocator_name_),
        PROTOBUF_FIELD_OFFSET(::tensorflow::AllocationDescription, _impl_.allocation_id_),
        PROTOBUF_FIELD_OFFSET(::tensorflow::AllocationDescription, _impl_.has_single_reference_),
        PROTOBUF_FIELD_OFFSET(::tensorflow::AllocationDescription, _impl_.ptr_),
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::tensorflow::AllocationDescription)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::tensorflow::_AllocationDescription_default_instance_._instance,
};
const char descriptor_table_protodef_tensorflow_2fcore_2fframework_2fallocation_5fdescription_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n6tensorflow/core/framework/allocation_d"
    "escription.proto\022\ntensorflow\"\243\001\n\025Allocat"
    "ionDescription\022\027\n\017requested_bytes\030\001 \001(\003\022"
    "\027\n\017allocated_bytes\030\002 \001(\003\022\026\n\016allocator_na"
    "me\030\003 \001(\t\022\025\n\rallocation_id\030\004 \001(\003\022\034\n\024has_s"
    "ingle_reference\030\005 \001(\010\022\013\n\003ptr\030\006 \001(\004B\233\001\n\030o"
    "rg.tensorflow.frameworkB\033AllocationDescr"
    "iptionProtosP\001Z]github.com/tensorflow/te"
    "nsorflow/tensorflow/go/core/framework/al"
    "location_description_go_proto\370\001\001b\006proto3"
};
static ::absl::once_flag descriptor_table_tensorflow_2fcore_2fframework_2fallocation_5fdescription_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_tensorflow_2fcore_2fframework_2fallocation_5fdescription_2eproto = {
    false,
    false,
    400,
    descriptor_table_protodef_tensorflow_2fcore_2fframework_2fallocation_5fdescription_2eproto,
    "tensorflow/core/framework/allocation_description.proto",
    &descriptor_table_tensorflow_2fcore_2fframework_2fallocation_5fdescription_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_tensorflow_2fcore_2fframework_2fallocation_5fdescription_2eproto::offsets,
    file_level_enum_descriptors_tensorflow_2fcore_2fframework_2fallocation_5fdescription_2eproto,
    file_level_service_descriptors_tensorflow_2fcore_2fframework_2fallocation_5fdescription_2eproto,
};
namespace tensorflow {
// ===================================================================

class AllocationDescription::_Internal {
 public:
};

AllocationDescription::AllocationDescription(::google::protobuf::Arena* arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:tensorflow.AllocationDescription)
}
inline PROTOBUF_NDEBUG_INLINE AllocationDescription::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::tensorflow::AllocationDescription& from_msg)
      : allocator_name_(arena, from.allocator_name_),
        _cached_size_{0} {}

AllocationDescription::AllocationDescription(
    ::google::protobuf::Arena* arena,
    const AllocationDescription& from)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  AllocationDescription* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);
  ::memcpy(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, requested_bytes_),
           reinterpret_cast<const char *>(&from._impl_) +
               offsetof(Impl_, requested_bytes_),
           offsetof(Impl_, has_single_reference_) -
               offsetof(Impl_, requested_bytes_) +
               sizeof(Impl_::has_single_reference_));

  // @@protoc_insertion_point(copy_constructor:tensorflow.AllocationDescription)
}
inline PROTOBUF_NDEBUG_INLINE AllocationDescription::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : allocator_name_(arena),
        _cached_size_{0} {}

inline void AllocationDescription::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, requested_bytes_),
           0,
           offsetof(Impl_, has_single_reference_) -
               offsetof(Impl_, requested_bytes_) +
               sizeof(Impl_::has_single_reference_));
}
AllocationDescription::~AllocationDescription() {
  // @@protoc_insertion_point(destructor:tensorflow.AllocationDescription)
  SharedDtor(*this);
}
inline void AllocationDescription::SharedDtor(MessageLite& self) {
  AllocationDescription& this_ = static_cast<AllocationDescription&>(self);
  this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  ABSL_DCHECK(this_.GetArena() == nullptr);
  this_._impl_.allocator_name_.Destroy();
  this_._impl_.~Impl_();
}

inline void* AllocationDescription::PlacementNew_(const void*, void* mem,
                                        ::google::protobuf::Arena* arena) {
  return ::new (mem) AllocationDescription(arena);
}
constexpr auto AllocationDescription::InternalNewImpl_() {
  return ::google::protobuf::internal::MessageCreator::CopyInit(sizeof(AllocationDescription),
                                            alignof(AllocationDescription));
}
PROTOBUF_CONSTINIT
PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::google::protobuf::internal::ClassDataFull AllocationDescription::_class_data_ = {
    ::google::protobuf::internal::ClassData{
        &_AllocationDescription_default_instance_._instance,
        &_table_.header,
        nullptr,  // OnDemandRegisterArenaDtor
        nullptr,  // IsInitialized
        &AllocationDescription::MergeImpl,
        ::google::protobuf::Message::GetNewImpl<AllocationDescription>(),
#if defined(PROTOBUF_CUSTOM_VTABLE)
        &AllocationDescription::SharedDtor,
        ::google::protobuf::Message::GetClearImpl<AllocationDescription>(), &AllocationDescription::ByteSizeLong,
            &AllocationDescription::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
        PROTOBUF_FIELD_OFFSET(AllocationDescription, _impl_._cached_size_),
        false,
    },
    &AllocationDescription::kDescriptorMethods,
    &descriptor_table_tensorflow_2fcore_2fframework_2fallocation_5fdescription_2eproto,
    nullptr,  // tracker
};
const ::google::protobuf::internal::ClassData* AllocationDescription::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_class_data_.tc_table);
  return _class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<3, 6, 0, 55, 2> AllocationDescription::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    6, 56,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967232,  // skipmap
    offsetof(decltype(_table_), field_entries),
    6,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    _class_data_.base(),
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::tensorflow::AllocationDescription>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    {::_pbi::TcParser::MiniParse, {}},
    // int64 requested_bytes = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint64_t, offsetof(AllocationDescription, _impl_.requested_bytes_), 63>(),
     {8, 63, 0, PROTOBUF_FIELD_OFFSET(AllocationDescription, _impl_.requested_bytes_)}},
    // int64 allocated_bytes = 2;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint64_t, offsetof(AllocationDescription, _impl_.allocated_bytes_), 63>(),
     {16, 63, 0, PROTOBUF_FIELD_OFFSET(AllocationDescription, _impl_.allocated_bytes_)}},
    // string allocator_name = 3;
    {::_pbi::TcParser::FastUS1,
     {26, 63, 0, PROTOBUF_FIELD_OFFSET(AllocationDescription, _impl_.allocator_name_)}},
    // int64 allocation_id = 4;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint64_t, offsetof(AllocationDescription, _impl_.allocation_id_), 63>(),
     {32, 63, 0, PROTOBUF_FIELD_OFFSET(AllocationDescription, _impl_.allocation_id_)}},
    // bool has_single_reference = 5;
    {::_pbi::TcParser::SingularVarintNoZag1<bool, offsetof(AllocationDescription, _impl_.has_single_reference_), 63>(),
     {40, 63, 0, PROTOBUF_FIELD_OFFSET(AllocationDescription, _impl_.has_single_reference_)}},
    // uint64 ptr = 6;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint64_t, offsetof(AllocationDescription, _impl_.ptr_), 63>(),
     {48, 63, 0, PROTOBUF_FIELD_OFFSET(AllocationDescription, _impl_.ptr_)}},
    {::_pbi::TcParser::MiniParse, {}},
  }}, {{
    65535, 65535
  }}, {{
    // int64 requested_bytes = 1;
    {PROTOBUF_FIELD_OFFSET(AllocationDescription, _impl_.requested_bytes_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt64)},
    // int64 allocated_bytes = 2;
    {PROTOBUF_FIELD_OFFSET(AllocationDescription, _impl_.allocated_bytes_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt64)},
    // string allocator_name = 3;
    {PROTOBUF_FIELD_OFFSET(AllocationDescription, _impl_.allocator_name_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // int64 allocation_id = 4;
    {PROTOBUF_FIELD_OFFSET(AllocationDescription, _impl_.allocation_id_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt64)},
    // bool has_single_reference = 5;
    {PROTOBUF_FIELD_OFFSET(AllocationDescription, _impl_.has_single_reference_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kBool)},
    // uint64 ptr = 6;
    {PROTOBUF_FIELD_OFFSET(AllocationDescription, _impl_.ptr_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUInt64)},
  }},
  // no aux_entries
  {{
    "\40\0\0\16\0\0\0\0"
    "tensorflow.AllocationDescription"
    "allocator_name"
  }},
};

PROTOBUF_NOINLINE void AllocationDescription::Clear() {
// @@protoc_insertion_point(message_clear_start:tensorflow.AllocationDescription)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.allocator_name_.ClearToEmpty();
  ::memset(&_impl_.requested_bytes_, 0, static_cast<::size_t>(
      reinterpret_cast<char*>(&_impl_.has_single_reference_) -
      reinterpret_cast<char*>(&_impl_.requested_bytes_)) + sizeof(_impl_.has_single_reference_));
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::uint8_t* AllocationDescription::_InternalSerialize(
            const MessageLite& base, ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) {
          const AllocationDescription& this_ = static_cast<const AllocationDescription&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::uint8_t* AllocationDescription::_InternalSerialize(
            ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) const {
          const AllocationDescription& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(serialize_to_array_start:tensorflow.AllocationDescription)
          ::uint32_t cached_has_bits = 0;
          (void)cached_has_bits;

          // int64 requested_bytes = 1;
          if (this_._internal_requested_bytes() != 0) {
            target = ::google::protobuf::internal::WireFormatLite::
                WriteInt64ToArrayWithField<1>(
                    stream, this_._internal_requested_bytes(), target);
          }

          // int64 allocated_bytes = 2;
          if (this_._internal_allocated_bytes() != 0) {
            target = ::google::protobuf::internal::WireFormatLite::
                WriteInt64ToArrayWithField<2>(
                    stream, this_._internal_allocated_bytes(), target);
          }

          // string allocator_name = 3;
          if (!this_._internal_allocator_name().empty()) {
            const std::string& _s = this_._internal_allocator_name();
            ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
                _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "tensorflow.AllocationDescription.allocator_name");
            target = stream->WriteStringMaybeAliased(3, _s, target);
          }

          // int64 allocation_id = 4;
          if (this_._internal_allocation_id() != 0) {
            target = ::google::protobuf::internal::WireFormatLite::
                WriteInt64ToArrayWithField<4>(
                    stream, this_._internal_allocation_id(), target);
          }

          // bool has_single_reference = 5;
          if (this_._internal_has_single_reference() != 0) {
            target = stream->EnsureSpace(target);
            target = ::_pbi::WireFormatLite::WriteBoolToArray(
                5, this_._internal_has_single_reference(), target);
          }

          // uint64 ptr = 6;
          if (this_._internal_ptr() != 0) {
            target = stream->EnsureSpace(target);
            target = ::_pbi::WireFormatLite::WriteUInt64ToArray(
                6, this_._internal_ptr(), target);
          }

          if (PROTOBUF_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
            target =
                ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
                    this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
          }
          // @@protoc_insertion_point(serialize_to_array_end:tensorflow.AllocationDescription)
          return target;
        }

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::size_t AllocationDescription::ByteSizeLong(const MessageLite& base) {
          const AllocationDescription& this_ = static_cast<const AllocationDescription&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::size_t AllocationDescription::ByteSizeLong() const {
          const AllocationDescription& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(message_byte_size_start:tensorflow.AllocationDescription)
          ::size_t total_size = 0;

          ::uint32_t cached_has_bits = 0;
          // Prevent compiler warnings about cached_has_bits being unused
          (void)cached_has_bits;

          ::_pbi::Prefetch5LinesFrom7Lines(&this_);
           {
            // string allocator_name = 3;
            if (!this_._internal_allocator_name().empty()) {
              total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                              this_._internal_allocator_name());
            }
            // int64 requested_bytes = 1;
            if (this_._internal_requested_bytes() != 0) {
              total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(
                  this_._internal_requested_bytes());
            }
            // int64 allocated_bytes = 2;
            if (this_._internal_allocated_bytes() != 0) {
              total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(
                  this_._internal_allocated_bytes());
            }
            // int64 allocation_id = 4;
            if (this_._internal_allocation_id() != 0) {
              total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(
                  this_._internal_allocation_id());
            }
            // uint64 ptr = 6;
            if (this_._internal_ptr() != 0) {
              total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(
                  this_._internal_ptr());
            }
            // bool has_single_reference = 5;
            if (this_._internal_has_single_reference() != 0) {
              total_size += 2;
            }
          }
          return this_.MaybeComputeUnknownFieldsSize(total_size,
                                                     &this_._impl_._cached_size_);
        }

void AllocationDescription::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<AllocationDescription*>(&to_msg);
  auto& from = static_cast<const AllocationDescription&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:tensorflow.AllocationDescription)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_allocator_name().empty()) {
    _this->_internal_set_allocator_name(from._internal_allocator_name());
  }
  if (from._internal_requested_bytes() != 0) {
    _this->_impl_.requested_bytes_ = from._impl_.requested_bytes_;
  }
  if (from._internal_allocated_bytes() != 0) {
    _this->_impl_.allocated_bytes_ = from._impl_.allocated_bytes_;
  }
  if (from._internal_allocation_id() != 0) {
    _this->_impl_.allocation_id_ = from._impl_.allocation_id_;
  }
  if (from._internal_ptr() != 0) {
    _this->_impl_.ptr_ = from._impl_.ptr_;
  }
  if (from._internal_has_single_reference() != 0) {
    _this->_impl_.has_single_reference_ = from._impl_.has_single_reference_;
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void AllocationDescription::CopyFrom(const AllocationDescription& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tensorflow.AllocationDescription)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void AllocationDescription::InternalSwap(AllocationDescription* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.allocator_name_, &other->_impl_.allocator_name_, arena);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(AllocationDescription, _impl_.has_single_reference_)
      + sizeof(AllocationDescription::_impl_.has_single_reference_)
      - PROTOBUF_FIELD_OFFSET(AllocationDescription, _impl_.requested_bytes_)>(
          reinterpret_cast<char*>(&_impl_.requested_bytes_),
          reinterpret_cast<char*>(&other->_impl_.requested_bytes_));
}

::google::protobuf::Metadata AllocationDescription::GetMetadata() const {
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
        (::_pbi::AddDescriptors(&descriptor_table_tensorflow_2fcore_2fframework_2fallocation_5fdescription_2eproto),
         ::std::false_type{});
#include "google/protobuf/port_undef.inc"
