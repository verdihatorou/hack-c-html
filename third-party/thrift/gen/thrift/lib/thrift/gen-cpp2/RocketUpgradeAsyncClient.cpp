/**
 * Autogenerated by Thrift for /home/fbthrift/thrift/lib/thrift/RocketUpgrade.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#include "thrift/lib/thrift/gen-cpp2/RocketUpgradeAsyncClient.h"

#include <thrift/lib/cpp2/gen/client_cpp.h>

namespace apache { namespace thrift {
typedef apache::thrift::ThriftPresult<false> RocketUpgrade_upgradeToRocket_pargs;
typedef apache::thrift::ThriftPresult<true> RocketUpgrade_upgradeToRocket_presult;

template <typename Protocol_>
void RocketUpgradeAsyncClient::upgradeToRocketT(Protocol_* prot, apache::thrift::RpcOptions rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback) {

  std::shared_ptr<apache::thrift::transport::THeader> header(ctx, &ctx->header);
  RocketUpgrade_upgradeToRocket_pargs args;
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };
  static constexpr std::string_view methodName = "upgradeToRocket";
  apache::thrift::clientSendT<apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, Protocol_>(prot, std::move(rpcOptions), std::move(callback), ctx->ctx, std::move(header), channel_.get(), apache::thrift::ManagedStringView::from_static(methodName), writer, sizer);
  ctx->reqContext.setRequestHeader(nullptr);
}



void RocketUpgradeAsyncClient::upgradeToRocket(std::unique_ptr<apache::thrift::RequestCallback> callback) {
  ::apache::thrift::RpcOptions rpcOptions;
  upgradeToRocket(rpcOptions, std::move(callback));
}

void RocketUpgradeAsyncClient::upgradeToRocket(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  auto ctx = upgradeToRocketCtx(&rpcOptions);
  apache::thrift::RequestCallback::Context callbackContext;
  callbackContext.protocolId =
      apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  callbackContext.ctx = std::shared_ptr<apache::thrift::ContextStack>(ctx, &ctx->ctx);
  auto wrappedCallback = apache::thrift::toRequestClientCallbackPtr(std::move(callback), std::move(callbackContext));
  upgradeToRocketImpl(rpcOptions, std::move(ctx), std::move(wrappedCallback));
}

void RocketUpgradeAsyncClient::upgradeToRocketImpl(const apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback) {
  switch (apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      upgradeToRocketT(&writer, rpcOptions, std::move(ctx), std::move(callback));
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      upgradeToRocketT(&writer, rpcOptions, std::move(ctx), std::move(callback));
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

std::shared_ptr<::apache::thrift::detail::ac::ClientRequestContext> RocketUpgradeAsyncClient::upgradeToRocketCtx(apache::thrift::RpcOptions* rpcOptions) {
  return std::make_shared<apache::thrift::detail::ac::ClientRequestContext>(
      channel_->getProtocolId(),
      rpcOptions ? rpcOptions->releaseWriteHeaders() : std::map<std::string, std::string>{},
      handlers_,
      getServiceName(),
      "RocketUpgrade.upgradeToRocket");
}

void RocketUpgradeAsyncClient::sync_upgradeToRocket() {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_upgradeToRocket(rpcOptions);
}

void RocketUpgradeAsyncClient::sync_upgradeToRocket(apache::thrift::RpcOptions& rpcOptions) {
  apache::thrift::ClientReceiveState returnState;
  apache::thrift::ClientSyncCallback<false> callback(&returnState);
  auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto evb = apache::thrift::GeneratedAsyncClient::getChannel()->getEventBase();
  auto ctx = upgradeToRocketCtx(&rpcOptions);
  auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(&callback);
  upgradeToRocketImpl(rpcOptions, ctx, std::move(wrappedCallback));
  callback.waitUntilDone(evb);

  if (returnState.isException()) {
    returnState.exception().throw_exception();
  }
  returnState.resetProtocolId(protocolId);
  returnState.resetCtx(std::shared_ptr<apache::thrift::ContextStack>(ctx, &ctx->ctx));
  SCOPE_EXIT {
    if (returnState.header() && !returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(returnState.header()->releaseHeaders());
    }
  };
  return folly::fibers::runInMainContext([&] {
      recv_upgradeToRocket(returnState);
  });
}


folly::Future<folly::Unit> RocketUpgradeAsyncClient::future_upgradeToRocket() {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_upgradeToRocket(rpcOptions);
}

folly::SemiFuture<folly::Unit> RocketUpgradeAsyncClient::semifuture_upgradeToRocket() {
  ::apache::thrift::RpcOptions rpcOptions;
  return semifuture_upgradeToRocket(rpcOptions);
}

folly::Future<folly::Unit> RocketUpgradeAsyncClient::future_upgradeToRocket(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<folly::Unit> promise;
  auto future = promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback<folly::Unit>>(std::move(promise), recv_wrapped_upgradeToRocket, channel_);
  upgradeToRocket(rpcOptions, std::move(callback));
  return future;
}

folly::SemiFuture<folly::Unit> RocketUpgradeAsyncClient::semifuture_upgradeToRocket(apache::thrift::RpcOptions& rpcOptions) {
  auto callbackAndFuture = makeSemiFutureCallback(recv_wrapped_upgradeToRocket, channel_);
  auto callback = std::move(callbackAndFuture.first);
  upgradeToRocket(rpcOptions, std::move(callback));
  return std::move(callbackAndFuture.second);
}

folly::Future<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> RocketUpgradeAsyncClient::header_future_upgradeToRocket(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> promise;
  auto future = promise.getFuture();
  auto callback = std::make_unique<apache::thrift::HeaderFutureCallback<folly::Unit>>(std::move(promise), recv_wrapped_upgradeToRocket, channel_);
  upgradeToRocket(rpcOptions, std::move(callback));
  return future;
}

folly::SemiFuture<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> RocketUpgradeAsyncClient::header_semifuture_upgradeToRocket(apache::thrift::RpcOptions& rpcOptions) {
  auto callbackAndFuture = makeHeaderSemiFutureCallback(recv_wrapped_upgradeToRocket, channel_);
  auto callback = std::move(callbackAndFuture.first);
  upgradeToRocket(rpcOptions, std::move(callback));
  return std::move(callbackAndFuture.second);
}

void RocketUpgradeAsyncClient::upgradeToRocket(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback) {
  upgradeToRocket(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)));
}

#if FOLLY_HAS_COROUTINES
#endif // FOLLY_HAS_COROUTINES
folly::exception_wrapper RocketUpgradeAsyncClient::recv_wrapped_upgradeToRocket(::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.buf()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }

  using result = RocketUpgrade_upgradeToRocket_presult;
  constexpr auto const fname = "upgradeToRocket";
  switch (state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          fname, &reader, state);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          fname, &reader, state);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void RocketUpgradeAsyncClient::recv_upgradeToRocket(::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_upgradeToRocket(state);
  if (ew) {
    ew.throw_exception();
  }
}

void RocketUpgradeAsyncClient::recv_instance_upgradeToRocket(::apache::thrift::ClientReceiveState& state) {
  recv_upgradeToRocket(state);
}

folly::exception_wrapper RocketUpgradeAsyncClient::recv_instance_wrapped_upgradeToRocket(::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_upgradeToRocket(state);
}


}} // apache::thrift
