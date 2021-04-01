/**
 * Autogenerated by Thrift for /home/fbthrift/thrift/lib/thrift/RocketUpgrade.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/gen/service_h.h>

#include "thrift/lib/thrift/gen-cpp2/RocketUpgradeAsyncClient.h"
#include "thrift/lib/thrift/gen-cpp2/RocketUpgrade_types.h"

namespace folly {
  class IOBuf;
  class IOBufQueue;
}
namespace apache { namespace thrift {
  class Cpp2RequestContext;
  class BinaryProtocolReader;
  class CompactProtocolReader;
  namespace transport { class THeader; }
}}

namespace apache { namespace thrift {

class RocketUpgradeSvAsyncIf {
 public:
  virtual ~RocketUpgradeSvAsyncIf() {}
  virtual void async_tm_upgradeToRocket(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback) = 0;
  virtual folly::Future<folly::Unit> future_upgradeToRocket() = 0;
  virtual folly::SemiFuture<folly::Unit> semifuture_upgradeToRocket() = 0;
};

class RocketUpgradeAsyncProcessor;

class RocketUpgradeSvIf : public RocketUpgradeSvAsyncIf, public apache::thrift::ServerInterface {
 public:
  typedef RocketUpgradeAsyncProcessor ProcessorType;
  std::unique_ptr<apache::thrift::AsyncProcessor> getProcessor() override;


  virtual void upgradeToRocket();
  folly::Future<folly::Unit> future_upgradeToRocket() override;
  folly::SemiFuture<folly::Unit> semifuture_upgradeToRocket() override;
  void async_tm_upgradeToRocket(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback) override;
};

class RocketUpgradeSvNull : public RocketUpgradeSvIf {
 public:
  void upgradeToRocket() override;
};

class RocketUpgradeAsyncProcessor : public ::apache::thrift::GeneratedAsyncProcessor {
 public:
  const char* getServiceName() override;
  void getServiceMetadata(apache::thrift::metadata::ThriftServiceMetadataResponse& response) override;
  using BaseAsyncProcessor = void;
 protected:
  RocketUpgradeSvIf* iface_;
 public:
  void processSerializedCompressedRequest(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) override;
 protected:
  std::shared_ptr<folly::RequestContext> getBaseContextForRequest() override;
 public:
  using ProcessFunc = GeneratedAsyncProcessor::ProcessFunc<RocketUpgradeAsyncProcessor>;
  using ProcessMap = GeneratedAsyncProcessor::ProcessMap<ProcessFunc>;
  static const RocketUpgradeAsyncProcessor::ProcessMap& getBinaryProtocolProcessMap();
  static const RocketUpgradeAsyncProcessor::ProcessMap& getCompactProtocolProcessMap();
 private:
  static const RocketUpgradeAsyncProcessor::ProcessMap binaryProcessMap_;
  static const RocketUpgradeAsyncProcessor::ProcessMap compactProcessMap_;
 private:
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_upgradeToRocket(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_upgradeToRocket(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static folly::IOBufQueue return_upgradeToRocket(int32_t protoSeqId, apache::thrift::ContextStack* ctx);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_upgradeToRocket(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
 public:
  RocketUpgradeAsyncProcessor(RocketUpgradeSvIf* iface) :
      iface_(iface) {}

  virtual ~RocketUpgradeAsyncProcessor() {}
};

}} // apache::thrift
