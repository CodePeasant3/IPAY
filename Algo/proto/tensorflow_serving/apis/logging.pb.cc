// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: tensorflow_serving/apis/logging.proto
// Protobuf C++ Version: 5.29.0

#include "tensorflow_serving/apis/logging.pb.h"

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
namespace serving {

inline constexpr LogMetadata::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        saved_model_tags_{},
        dc_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        request_origin_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        request_criticality_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        model_spec_{nullptr},
        sampling_config_{nullptr},
        timestamp_secs_{::int64_t{0}} {}

template <typename>
PROTOBUF_CONSTEXPR LogMetadata::LogMetadata(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(::_pbi::ConstantInitialized()) {
}
struct LogMetadataDefaultTypeInternal {
  PROTOBUF_CONSTEXPR LogMetadataDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~LogMetadataDefaultTypeInternal() {}
  union {
    LogMetadata _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 LogMetadataDefaultTypeInternal _LogMetadata_default_instance_;
}  // namespace serving
}  // namespace tensorflow
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_tensorflow_5fserving_2fapis_2flogging_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_tensorflow_5fserving_2fapis_2flogging_2eproto = nullptr;
const ::uint32_t
    TableStruct_tensorflow_5fserving_2fapis_2flogging_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        PROTOBUF_FIELD_OFFSET(::tensorflow::serving::LogMetadata, _impl_._has_bits_),
        PROTOBUF_FIELD_OFFSET(::tensorflow::serving::LogMetadata, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::tensorflow::serving::LogMetadata, _impl_.model_spec_),
        PROTOBUF_FIELD_OFFSET(::tensorflow::serving::LogMetadata, _impl_.sampling_config_),
        PROTOBUF_FIELD_OFFSET(::tensorflow::serving::LogMetadata, _impl_.saved_model_tags_),
        PROTOBUF_FIELD_OFFSET(::tensorflow::serving::LogMetadata, _impl_.timestamp_secs_),
        PROTOBUF_FIELD_OFFSET(::tensorflow::serving::LogMetadata, _impl_.dc_),
        PROTOBUF_FIELD_OFFSET(::tensorflow::serving::LogMetadata, _impl_.request_origin_),
        PROTOBUF_FIELD_OFFSET(::tensorflow::serving::LogMetadata, _impl_.request_criticality_),
        0,
        1,
        ~0u,
        ~0u,
        ~0u,
        ~0u,
        ~0u,
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, 15, -1, sizeof(::tensorflow::serving::LogMetadata)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::tensorflow::serving::_LogMetadata_default_instance_._instance,
};
const char descriptor_table_protodef_tensorflow_5fserving_2fapis_2flogging_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n%tensorflow_serving/apis/logging.proto\022"
    "\022tensorflow.serving\032#tensorflow_serving/"
    "apis/model.proto\032.tensorflow_serving/con"
    "fig/logging_config.proto\"\360\001\n\013LogMetadata"
    "\0221\n\nmodel_spec\030\001 \001(\0132\035.tensorflow.servin"
    "g.ModelSpec\022;\n\017sampling_config\030\002 \001(\0132\".t"
    "ensorflow.serving.SamplingConfig\022\030\n\020save"
    "d_model_tags\030\003 \003(\t\022\026\n\016timestamp_secs\030\004 \001"
    "(\003\022\n\n\002dc\030\005 \001(\t\022\026\n\016request_origin\030\006 \001(\t\022\033"
    "\n\023request_criticality\030\007 \001(\tB\003\370\001\001b\006proto3"
};
static const ::_pbi::DescriptorTable* const descriptor_table_tensorflow_5fserving_2fapis_2flogging_2eproto_deps[2] =
    {
        &::descriptor_table_tensorflow_5fserving_2fapis_2fmodel_2eproto,
        &::descriptor_table_tensorflow_5fserving_2fconfig_2flogging_5fconfig_2eproto,
};
static ::absl::once_flag descriptor_table_tensorflow_5fserving_2fapis_2flogging_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_tensorflow_5fserving_2fapis_2flogging_2eproto = {
    false,
    false,
    400,
    descriptor_table_protodef_tensorflow_5fserving_2fapis_2flogging_2eproto,
    "tensorflow_serving/apis/logging.proto",
    &descriptor_table_tensorflow_5fserving_2fapis_2flogging_2eproto_once,
    descriptor_table_tensorflow_5fserving_2fapis_2flogging_2eproto_deps,
    2,
    1,
    schemas,
    file_default_instances,
    TableStruct_tensorflow_5fserving_2fapis_2flogging_2eproto::offsets,
    file_level_enum_descriptors_tensorflow_5fserving_2fapis_2flogging_2eproto,
    file_level_service_descriptors_tensorflow_5fserving_2fapis_2flogging_2eproto,
};
namespace tensorflow {
namespace serving {
// ===================================================================

class LogMetadata::_Internal {
 public:
  using HasBits =
      decltype(std::declval<LogMetadata>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
      8 * PROTOBUF_FIELD_OFFSET(LogMetadata, _impl_._has_bits_);
};

void LogMetadata::clear_model_spec() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (_impl_.model_spec_ != nullptr) _impl_.model_spec_->Clear();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
void LogMetadata::clear_sampling_config() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (_impl_.sampling_config_ != nullptr) _impl_.sampling_config_->Clear();
  _impl_._has_bits_[0] &= ~0x00000002u;
}
LogMetadata::LogMetadata(::google::protobuf::Arena* arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:tensorflow.serving.LogMetadata)
}
inline PROTOBUF_NDEBUG_INLINE LogMetadata::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::tensorflow::serving::LogMetadata& from_msg)
      : _has_bits_{from._has_bits_},
        _cached_size_{0},
        saved_model_tags_{visibility, arena, from.saved_model_tags_},
        dc_(arena, from.dc_),
        request_origin_(arena, from.request_origin_),
        request_criticality_(arena, from.request_criticality_) {}

LogMetadata::LogMetadata(
    ::google::protobuf::Arena* arena,
    const LogMetadata& from)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  LogMetadata* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);
  ::uint32_t cached_has_bits = _impl_._has_bits_[0];
  _impl_.model_spec_ = (cached_has_bits & 0x00000001u) ? ::google::protobuf::Message::CopyConstruct<::tensorflow::serving::ModelSpec>(
                              arena, *from._impl_.model_spec_)
                        : nullptr;
  _impl_.sampling_config_ = (cached_has_bits & 0x00000002u) ? ::google::protobuf::Message::CopyConstruct<::tensorflow::serving::SamplingConfig>(
                              arena, *from._impl_.sampling_config_)
                        : nullptr;
  _impl_.timestamp_secs_ = from._impl_.timestamp_secs_;

  // @@protoc_insertion_point(copy_constructor:tensorflow.serving.LogMetadata)
}
inline PROTOBUF_NDEBUG_INLINE LogMetadata::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0},
        saved_model_tags_{visibility, arena},
        dc_(arena),
        request_origin_(arena),
        request_criticality_(arena) {}

inline void LogMetadata::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, model_spec_),
           0,
           offsetof(Impl_, timestamp_secs_) -
               offsetof(Impl_, model_spec_) +
               sizeof(Impl_::timestamp_secs_));
}
LogMetadata::~LogMetadata() {
  // @@protoc_insertion_point(destructor:tensorflow.serving.LogMetadata)
  SharedDtor(*this);
}
inline void LogMetadata::SharedDtor(MessageLite& self) {
  LogMetadata& this_ = static_cast<LogMetadata&>(self);
  this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  ABSL_DCHECK(this_.GetArena() == nullptr);
  this_._impl_.dc_.Destroy();
  this_._impl_.request_origin_.Destroy();
  this_._impl_.request_criticality_.Destroy();
  delete this_._impl_.model_spec_;
  delete this_._impl_.sampling_config_;
  this_._impl_.~Impl_();
}

inline void* LogMetadata::PlacementNew_(const void*, void* mem,
                                        ::google::protobuf::Arena* arena) {
  return ::new (mem) LogMetadata(arena);
}
constexpr auto LogMetadata::InternalNewImpl_() {
  constexpr auto arena_bits = ::google::protobuf::internal::EncodePlacementArenaOffsets({
      PROTOBUF_FIELD_OFFSET(LogMetadata, _impl_.saved_model_tags_) +
          decltype(LogMetadata::_impl_.saved_model_tags_)::
              InternalGetArenaOffset(
                  ::google::protobuf::Message::internal_visibility()),
  });
  if (arena_bits.has_value()) {
    return ::google::protobuf::internal::MessageCreator::CopyInit(
        sizeof(LogMetadata), alignof(LogMetadata), *arena_bits);
  } else {
    return ::google::protobuf::internal::MessageCreator(&LogMetadata::PlacementNew_,
                                 sizeof(LogMetadata),
                                 alignof(LogMetadata));
  }
}
PROTOBUF_CONSTINIT
PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::google::protobuf::internal::ClassDataFull LogMetadata::_class_data_ = {
    ::google::protobuf::internal::ClassData{
        &_LogMetadata_default_instance_._instance,
        &_table_.header,
        nullptr,  // OnDemandRegisterArenaDtor
        nullptr,  // IsInitialized
        &LogMetadata::MergeImpl,
        ::google::protobuf::Message::GetNewImpl<LogMetadata>(),
#if defined(PROTOBUF_CUSTOM_VTABLE)
        &LogMetadata::SharedDtor,
        ::google::protobuf::Message::GetClearImpl<LogMetadata>(), &LogMetadata::ByteSizeLong,
            &LogMetadata::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
        PROTOBUF_FIELD_OFFSET(LogMetadata, _impl_._cached_size_),
        false,
    },
    &LogMetadata::kDescriptorMethods,
    &descriptor_table_tensorflow_5fserving_2fapis_2flogging_2eproto,
    nullptr,  // tracker
};
const ::google::protobuf::internal::ClassData* LogMetadata::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_class_data_.tc_table);
  return _class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<3, 7, 2, 90, 2> LogMetadata::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(LogMetadata, _impl_._has_bits_),
    0, // no _extensions_
    7, 56,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967168,  // skipmap
    offsetof(decltype(_table_), field_entries),
    7,  // num_field_entries
    2,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    _class_data_.base(),
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::tensorflow::serving::LogMetadata>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    {::_pbi::TcParser::MiniParse, {}},
    // .tensorflow.serving.ModelSpec model_spec = 1;
    {::_pbi::TcParser::FastMtS1,
     {10, 0, 0, PROTOBUF_FIELD_OFFSET(LogMetadata, _impl_.model_spec_)}},
    // .tensorflow.serving.SamplingConfig sampling_config = 2;
    {::_pbi::TcParser::FastMtS1,
     {18, 1, 1, PROTOBUF_FIELD_OFFSET(LogMetadata, _impl_.sampling_config_)}},
    // repeated string saved_model_tags = 3;
    {::_pbi::TcParser::FastUR1,
     {26, 63, 0, PROTOBUF_FIELD_OFFSET(LogMetadata, _impl_.saved_model_tags_)}},
    // int64 timestamp_secs = 4;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint64_t, offsetof(LogMetadata, _impl_.timestamp_secs_), 63>(),
     {32, 63, 0, PROTOBUF_FIELD_OFFSET(LogMetadata, _impl_.timestamp_secs_)}},
    // string dc = 5;
    {::_pbi::TcParser::FastUS1,
     {42, 63, 0, PROTOBUF_FIELD_OFFSET(LogMetadata, _impl_.dc_)}},
    // string request_origin = 6;
    {::_pbi::TcParser::FastUS1,
     {50, 63, 0, PROTOBUF_FIELD_OFFSET(LogMetadata, _impl_.request_origin_)}},
    // string request_criticality = 7;
    {::_pbi::TcParser::FastUS1,
     {58, 63, 0, PROTOBUF_FIELD_OFFSET(LogMetadata, _impl_.request_criticality_)}},
  }}, {{
    65535, 65535
  }}, {{
    // .tensorflow.serving.ModelSpec model_spec = 1;
    {PROTOBUF_FIELD_OFFSET(LogMetadata, _impl_.model_spec_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kMessage | ::_fl::kTvTable)},
    // .tensorflow.serving.SamplingConfig sampling_config = 2;
    {PROTOBUF_FIELD_OFFSET(LogMetadata, _impl_.sampling_config_), _Internal::kHasBitsOffset + 1, 1,
    (0 | ::_fl::kFcOptional | ::_fl::kMessage | ::_fl::kTvTable)},
    // repeated string saved_model_tags = 3;
    {PROTOBUF_FIELD_OFFSET(LogMetadata, _impl_.saved_model_tags_), -1, 0,
    (0 | ::_fl::kFcRepeated | ::_fl::kUtf8String | ::_fl::kRepSString)},
    // int64 timestamp_secs = 4;
    {PROTOBUF_FIELD_OFFSET(LogMetadata, _impl_.timestamp_secs_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt64)},
    // string dc = 5;
    {PROTOBUF_FIELD_OFFSET(LogMetadata, _impl_.dc_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // string request_origin = 6;
    {PROTOBUF_FIELD_OFFSET(LogMetadata, _impl_.request_origin_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // string request_criticality = 7;
    {PROTOBUF_FIELD_OFFSET(LogMetadata, _impl_.request_criticality_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }}, {{
    {::_pbi::TcParser::GetTable<::tensorflow::serving::ModelSpec>()},
    {::_pbi::TcParser::GetTable<::tensorflow::serving::SamplingConfig>()},
  }}, {{
    "\36\0\0\20\0\2\16\23"
    "tensorflow.serving.LogMetadata"
    "saved_model_tags"
    "dc"
    "request_origin"
    "request_criticality"
  }},
};

PROTOBUF_NOINLINE void LogMetadata::Clear() {
// @@protoc_insertion_point(message_clear_start:tensorflow.serving.LogMetadata)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.saved_model_tags_.Clear();
  _impl_.dc_.ClearToEmpty();
  _impl_.request_origin_.ClearToEmpty();
  _impl_.request_criticality_.ClearToEmpty();
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      ABSL_DCHECK(_impl_.model_spec_ != nullptr);
      _impl_.model_spec_->Clear();
    }
    if (cached_has_bits & 0x00000002u) {
      ABSL_DCHECK(_impl_.sampling_config_ != nullptr);
      _impl_.sampling_config_->Clear();
    }
  }
  _impl_.timestamp_secs_ = ::int64_t{0};
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::uint8_t* LogMetadata::_InternalSerialize(
            const MessageLite& base, ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) {
          const LogMetadata& this_ = static_cast<const LogMetadata&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::uint8_t* LogMetadata::_InternalSerialize(
            ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) const {
          const LogMetadata& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(serialize_to_array_start:tensorflow.serving.LogMetadata)
          ::uint32_t cached_has_bits = 0;
          (void)cached_has_bits;

          cached_has_bits = this_._impl_._has_bits_[0];
          // .tensorflow.serving.ModelSpec model_spec = 1;
          if (cached_has_bits & 0x00000001u) {
            target = ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
                1, *this_._impl_.model_spec_, this_._impl_.model_spec_->GetCachedSize(), target,
                stream);
          }

          // .tensorflow.serving.SamplingConfig sampling_config = 2;
          if (cached_has_bits & 0x00000002u) {
            target = ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
                2, *this_._impl_.sampling_config_, this_._impl_.sampling_config_->GetCachedSize(), target,
                stream);
          }

          // repeated string saved_model_tags = 3;
          for (int i = 0, n = this_._internal_saved_model_tags_size(); i < n; ++i) {
            const auto& s = this_._internal_saved_model_tags().Get(i);
            ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
                s.data(), static_cast<int>(s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "tensorflow.serving.LogMetadata.saved_model_tags");
            target = stream->WriteString(3, s, target);
          }

          // int64 timestamp_secs = 4;
          if (this_._internal_timestamp_secs() != 0) {
            target = ::google::protobuf::internal::WireFormatLite::
                WriteInt64ToArrayWithField<4>(
                    stream, this_._internal_timestamp_secs(), target);
          }

          // string dc = 5;
          if (!this_._internal_dc().empty()) {
            const std::string& _s = this_._internal_dc();
            ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
                _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "tensorflow.serving.LogMetadata.dc");
            target = stream->WriteStringMaybeAliased(5, _s, target);
          }

          // string request_origin = 6;
          if (!this_._internal_request_origin().empty()) {
            const std::string& _s = this_._internal_request_origin();
            ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
                _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "tensorflow.serving.LogMetadata.request_origin");
            target = stream->WriteStringMaybeAliased(6, _s, target);
          }

          // string request_criticality = 7;
          if (!this_._internal_request_criticality().empty()) {
            const std::string& _s = this_._internal_request_criticality();
            ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
                _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "tensorflow.serving.LogMetadata.request_criticality");
            target = stream->WriteStringMaybeAliased(7, _s, target);
          }

          if (PROTOBUF_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
            target =
                ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
                    this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
          }
          // @@protoc_insertion_point(serialize_to_array_end:tensorflow.serving.LogMetadata)
          return target;
        }

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::size_t LogMetadata::ByteSizeLong(const MessageLite& base) {
          const LogMetadata& this_ = static_cast<const LogMetadata&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::size_t LogMetadata::ByteSizeLong() const {
          const LogMetadata& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(message_byte_size_start:tensorflow.serving.LogMetadata)
          ::size_t total_size = 0;

          ::uint32_t cached_has_bits = 0;
          // Prevent compiler warnings about cached_has_bits being unused
          (void)cached_has_bits;

          ::_pbi::Prefetch5LinesFrom7Lines(&this_);
           {
            // repeated string saved_model_tags = 3;
            {
              total_size +=
                  1 * ::google::protobuf::internal::FromIntSize(this_._internal_saved_model_tags().size());
              for (int i = 0, n = this_._internal_saved_model_tags().size(); i < n; ++i) {
                total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
                    this_._internal_saved_model_tags().Get(i));
              }
            }
          }
           {
            // string dc = 5;
            if (!this_._internal_dc().empty()) {
              total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                              this_._internal_dc());
            }
            // string request_origin = 6;
            if (!this_._internal_request_origin().empty()) {
              total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                              this_._internal_request_origin());
            }
            // string request_criticality = 7;
            if (!this_._internal_request_criticality().empty()) {
              total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                              this_._internal_request_criticality());
            }
          }
          cached_has_bits = this_._impl_._has_bits_[0];
          if (cached_has_bits & 0x00000003u) {
            // .tensorflow.serving.ModelSpec model_spec = 1;
            if (cached_has_bits & 0x00000001u) {
              total_size += 1 +
                            ::google::protobuf::internal::WireFormatLite::MessageSize(*this_._impl_.model_spec_);
            }
            // .tensorflow.serving.SamplingConfig sampling_config = 2;
            if (cached_has_bits & 0x00000002u) {
              total_size += 1 +
                            ::google::protobuf::internal::WireFormatLite::MessageSize(*this_._impl_.sampling_config_);
            }
          }
           {
            // int64 timestamp_secs = 4;
            if (this_._internal_timestamp_secs() != 0) {
              total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(
                  this_._internal_timestamp_secs());
            }
          }
          return this_.MaybeComputeUnknownFieldsSize(total_size,
                                                     &this_._impl_._cached_size_);
        }

void LogMetadata::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<LogMetadata*>(&to_msg);
  auto& from = static_cast<const LogMetadata&>(from_msg);
  ::google::protobuf::Arena* arena = _this->GetArena();
  // @@protoc_insertion_point(class_specific_merge_from_start:tensorflow.serving.LogMetadata)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_internal_mutable_saved_model_tags()->MergeFrom(from._internal_saved_model_tags());
  if (!from._internal_dc().empty()) {
    _this->_internal_set_dc(from._internal_dc());
  }
  if (!from._internal_request_origin().empty()) {
    _this->_internal_set_request_origin(from._internal_request_origin());
  }
  if (!from._internal_request_criticality().empty()) {
    _this->_internal_set_request_criticality(from._internal_request_criticality());
  }
  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      ABSL_DCHECK(from._impl_.model_spec_ != nullptr);
      if (_this->_impl_.model_spec_ == nullptr) {
        _this->_impl_.model_spec_ =
            ::google::protobuf::Message::CopyConstruct<::tensorflow::serving::ModelSpec>(arena, *from._impl_.model_spec_);
      } else {
        _this->_impl_.model_spec_->MergeFrom(*from._impl_.model_spec_);
      }
    }
    if (cached_has_bits & 0x00000002u) {
      ABSL_DCHECK(from._impl_.sampling_config_ != nullptr);
      if (_this->_impl_.sampling_config_ == nullptr) {
        _this->_impl_.sampling_config_ =
            ::google::protobuf::Message::CopyConstruct<::tensorflow::serving::SamplingConfig>(arena, *from._impl_.sampling_config_);
      } else {
        _this->_impl_.sampling_config_->MergeFrom(*from._impl_.sampling_config_);
      }
    }
  }
  if (from._internal_timestamp_secs() != 0) {
    _this->_impl_.timestamp_secs_ = from._impl_.timestamp_secs_;
  }
  _this->_impl_._has_bits_[0] |= cached_has_bits;
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void LogMetadata::CopyFrom(const LogMetadata& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tensorflow.serving.LogMetadata)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void LogMetadata::InternalSwap(LogMetadata* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  _impl_.saved_model_tags_.InternalSwap(&other->_impl_.saved_model_tags_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.dc_, &other->_impl_.dc_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.request_origin_, &other->_impl_.request_origin_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.request_criticality_, &other->_impl_.request_criticality_, arena);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(LogMetadata, _impl_.timestamp_secs_)
      + sizeof(LogMetadata::_impl_.timestamp_secs_)
      - PROTOBUF_FIELD_OFFSET(LogMetadata, _impl_.model_spec_)>(
          reinterpret_cast<char*>(&_impl_.model_spec_),
          reinterpret_cast<char*>(&other->_impl_.model_spec_));
}

::google::protobuf::Metadata LogMetadata::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace serving
}  // namespace tensorflow
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::std::false_type
    _static_init2_ PROTOBUF_UNUSED =
        (::_pbi::AddDescriptors(&descriptor_table_tensorflow_5fserving_2fapis_2flogging_2eproto),
         ::std::false_type{});
#include "google/protobuf/port_undef.inc"
