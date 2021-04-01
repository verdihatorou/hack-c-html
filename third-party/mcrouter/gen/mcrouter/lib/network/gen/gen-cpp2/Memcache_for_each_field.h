/**
 * Autogenerated by Thrift for Memcache.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include "mcrouter/lib/network/gen/gen-cpp2/Memcache_metadata.h"
#include <thrift/lib/cpp2/visitation/for_each.h>

namespace apache {
namespace thrift {
namespace detail {

template <>
struct ForEachField<::facebook::memcache::thrift::McGetRequest> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).key_ref()...);
    f(1, static_cast<T&&>(t).flags_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McGetReply> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).result_ref()...);
    f(1, static_cast<T&&>(t).value_ref()...);
    f(2, static_cast<T&&>(t).flags_ref()...);
    f(3, static_cast<T&&>(t).message_ref()...);
    f(4, static_cast<T&&>(t).appSpecificErrorCode_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McSetRequest> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).key_ref()...);
    f(1, static_cast<T&&>(t).exptime_ref()...);
    f(2, static_cast<T&&>(t).flags_ref()...);
    f(3, static_cast<T&&>(t).value_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McSetReply> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).result_ref()...);
    f(1, static_cast<T&&>(t).flags_ref()...);
    f(2, static_cast<T&&>(t).value_ref()...);
    f(3, static_cast<T&&>(t).message_ref()...);
    f(4, static_cast<T&&>(t).appSpecificErrorCode_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McDeleteRequest> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).key_ref()...);
    f(1, static_cast<T&&>(t).flags_ref()...);
    f(2, static_cast<T&&>(t).exptime_ref()...);
    f(3, static_cast<T&&>(t).value_ref()...);
    f(4, static_cast<T&&>(t).attributes_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McDeleteReply> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).result_ref()...);
    f(1, static_cast<T&&>(t).flags_ref()...);
    f(2, static_cast<T&&>(t).value_ref()...);
    f(3, static_cast<T&&>(t).message_ref()...);
    f(4, static_cast<T&&>(t).appSpecificErrorCode_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McLeaseGetRequest> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).key_ref()...);
    f(1, static_cast<T&&>(t).flags_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McLeaseGetReply> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).result_ref()...);
    f(1, static_cast<T&&>(t).leaseToken_ref()...);
    f(2, static_cast<T&&>(t).value_ref()...);
    f(3, static_cast<T&&>(t).flags_ref()...);
    f(4, static_cast<T&&>(t).message_ref()...);
    f(5, static_cast<T&&>(t).appSpecificErrorCode_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McLeaseSetRequest> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).key_ref()...);
    f(1, static_cast<T&&>(t).exptime_ref()...);
    f(2, static_cast<T&&>(t).flags_ref()...);
    f(3, static_cast<T&&>(t).value_ref()...);
    f(4, static_cast<T&&>(t).leaseToken_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McLeaseSetReply> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).result_ref()...);
    f(1, static_cast<T&&>(t).message_ref()...);
    f(2, static_cast<T&&>(t).appSpecificErrorCode_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McAddRequest> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).key_ref()...);
    f(1, static_cast<T&&>(t).exptime_ref()...);
    f(2, static_cast<T&&>(t).flags_ref()...);
    f(3, static_cast<T&&>(t).value_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McAddReply> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).result_ref()...);
    f(1, static_cast<T&&>(t).message_ref()...);
    f(2, static_cast<T&&>(t).appSpecificErrorCode_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McReplaceRequest> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).key_ref()...);
    f(1, static_cast<T&&>(t).exptime_ref()...);
    f(2, static_cast<T&&>(t).flags_ref()...);
    f(3, static_cast<T&&>(t).value_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McReplaceReply> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).result_ref()...);
    f(1, static_cast<T&&>(t).message_ref()...);
    f(2, static_cast<T&&>(t).appSpecificErrorCode_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McGetsRequest> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).key_ref()...);
    f(1, static_cast<T&&>(t).flags_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McGetsReply> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).result_ref()...);
    f(1, static_cast<T&&>(t).casToken_ref()...);
    f(2, static_cast<T&&>(t).value_ref()...);
    f(3, static_cast<T&&>(t).flags_ref()...);
    f(4, static_cast<T&&>(t).message_ref()...);
    f(5, static_cast<T&&>(t).appSpecificErrorCode_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McCasRequest> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).key_ref()...);
    f(1, static_cast<T&&>(t).exptime_ref()...);
    f(2, static_cast<T&&>(t).flags_ref()...);
    f(3, static_cast<T&&>(t).value_ref()...);
    f(4, static_cast<T&&>(t).casToken_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McCasReply> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).result_ref()...);
    f(1, static_cast<T&&>(t).message_ref()...);
    f(2, static_cast<T&&>(t).appSpecificErrorCode_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McIncrRequest> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).key_ref()...);
    f(1, static_cast<T&&>(t).delta_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McIncrReply> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).result_ref()...);
    f(1, static_cast<T&&>(t).delta_ref()...);
    f(2, static_cast<T&&>(t).message_ref()...);
    f(3, static_cast<T&&>(t).appSpecificErrorCode_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McDecrRequest> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).key_ref()...);
    f(1, static_cast<T&&>(t).delta_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McDecrReply> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).result_ref()...);
    f(1, static_cast<T&&>(t).delta_ref()...);
    f(2, static_cast<T&&>(t).message_ref()...);
    f(3, static_cast<T&&>(t).appSpecificErrorCode_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McMetagetRequest> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).key_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McMetagetReply> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).result_ref()...);
    f(1, static_cast<T&&>(t).age_ref()...);
    f(2, static_cast<T&&>(t).exptime_ref()...);
    f(3, static_cast<T&&>(t).ipv_ref()...);
    f(4, static_cast<T&&>(t).ipAddress_ref()...);
    f(5, static_cast<T&&>(t).message_ref()...);
    f(6, static_cast<T&&>(t).appSpecificErrorCode_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McAppendRequest> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).key_ref()...);
    f(1, static_cast<T&&>(t).exptime_ref()...);
    f(2, static_cast<T&&>(t).flags_ref()...);
    f(3, static_cast<T&&>(t).value_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McAppendReply> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).result_ref()...);
    f(1, static_cast<T&&>(t).message_ref()...);
    f(2, static_cast<T&&>(t).appSpecificErrorCode_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McPrependRequest> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).key_ref()...);
    f(1, static_cast<T&&>(t).exptime_ref()...);
    f(2, static_cast<T&&>(t).flags_ref()...);
    f(3, static_cast<T&&>(t).value_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McPrependReply> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).result_ref()...);
    f(1, static_cast<T&&>(t).message_ref()...);
    f(2, static_cast<T&&>(t).appSpecificErrorCode_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McTouchRequest> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).key_ref()...);
    f(1, static_cast<T&&>(t).exptime_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McTouchReply> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).result_ref()...);
    f(1, static_cast<T&&>(t).message_ref()...);
    f(2, static_cast<T&&>(t).appSpecificErrorCode_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McFlushReRequest> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).key_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McFlushReReply> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).result_ref()...);
    f(1, static_cast<T&&>(t).message_ref()...);
    f(2, static_cast<T&&>(t).appSpecificErrorCode_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McFlushAllRequest> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).key_ref()...);
    f(1, static_cast<T&&>(t).delay_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McFlushAllReply> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).result_ref()...);
    f(1, static_cast<T&&>(t).message_ref()...);
    f(2, static_cast<T&&>(t).appSpecificErrorCode_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McGatRequest> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).exptime_ref()...);
    f(1, static_cast<T&&>(t).key_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McGatReply> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).result_ref()...);
    f(1, static_cast<T&&>(t).value_ref()...);
    f(2, static_cast<T&&>(t).flags_ref()...);
    f(3, static_cast<T&&>(t).message_ref()...);
    f(4, static_cast<T&&>(t).appSpecificErrorCode_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McGatsRequest> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).exptime_ref()...);
    f(1, static_cast<T&&>(t).key_ref()...);
  }
};

template <>
struct ForEachField<::facebook::memcache::thrift::McGatsReply> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).result_ref()...);
    f(1, static_cast<T&&>(t).casToken_ref()...);
    f(2, static_cast<T&&>(t).value_ref()...);
    f(3, static_cast<T&&>(t).flags_ref()...);
    f(4, static_cast<T&&>(t).message_ref()...);
    f(5, static_cast<T&&>(t).appSpecificErrorCode_ref()...);
  }
};
} // namespace detail
} // namespace thrift
} // namespace apache
