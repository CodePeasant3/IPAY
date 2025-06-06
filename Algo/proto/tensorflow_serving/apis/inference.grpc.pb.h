// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: tensorflow_serving/apis/inference.proto
// Original file comments:
// This file contains messages for various machine learning inferences
// such as regression and classification.
//
// In many applications more than one type of inference is desired for a single
// input.  For example, given meteorologic data an application may want to
// perform a classification to determine if we should expect rain, snow or sun
// and also perform a regression to predict the temperature.
// Sharing the single input data between two inference tasks can be accomplished
// using MultiInferenceRequest and MultiInferenceResponse.
//
#ifndef GRPC_tensorflow_5fserving_2fapis_2finference_2eproto__INCLUDED
#define GRPC_tensorflow_5fserving_2fapis_2finference_2eproto__INCLUDED

#include "tensorflow_serving/apis/inference.pb.h"

#include <functional>
#include <grpcpp/generic/async_generic_service.h>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/client_context.h>
#include <grpcpp/completion_queue.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/proto_utils.h>
#include <grpcpp/impl/rpc_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/status.h>
#include <grpcpp/support/stub_options.h>
#include <grpcpp/support/sync_stream.h>
#include <grpcpp/ports_def.inc>

namespace tensorflow {
namespace serving {

}  // namespace serving
}  // namespace tensorflow


#include <grpcpp/ports_undef.inc>
#endif  // GRPC_tensorflow_5fserving_2fapis_2finference_2eproto__INCLUDED
