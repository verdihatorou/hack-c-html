/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-present Facebook, Inc. (http://www.facebook.com)  |
   | Copyright (c) 1997-2010 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#pragma once

#include "hphp/runtime/ext/std/ext_std.h"
#include "hphp/runtime/ext/stream/ext_stream.h"
#include "hphp/util/network.h"

#include <folly/portability/Syslog.h>

namespace HPHP {

TypedValue HHVM_FUNCTION(gethostname);
Variant HHVM_FUNCTION(gethostbyaddr, const String& ip_address);
String HHVM_FUNCTION(gethostbyname, const String& hostname);
Variant HHVM_FUNCTION(gethostbynamel, const String& hostname);
Variant HHVM_FUNCTION(getprotobyname, const String& name);
Variant HHVM_FUNCTION(getprotobynumber, int64_t number);
Variant HHVM_FUNCTION(getservbyname, const String& service,
                                     const String& protocol);
Variant HHVM_FUNCTION(getservbyport, int64_t port, const String& protocol);
Variant HHVM_FUNCTION(inet_ntop, const String& in_addr);
TypedValue HHVM_FUNCTION(inet_ntop_nullable, const String& in_addr);
TypedValue HHVM_FUNCTION(inet_ntop_folly, const String& in_addr);
Variant HHVM_FUNCTION(inet_pton, const String& address);
Variant HHVM_FUNCTION(ip2long, const String& ip_address);
String HHVM_FUNCTION(long2ip, const String& proper_address);
bool HHVM_FUNCTION(checkdnsrr, const String& host,
                               const String& type = null_string);
Variant HHVM_FUNCTION(dns_get_record, const String& hostname, int64_t type,
                                      Variant& authnsRef,
                                      Variant& addtlRef);
bool HHVM_FUNCTION(getmxrr, const String& hostname,
                            Variant& mxhostsRef,
                            Variant& weightsRef);
void HHVM_FUNCTION(header, const String& str, bool replace = true,
                   int64_t http_response_code = 0);
Variant HHVM_FUNCTION(http_response_code, int64_t response_code = 0);
Array HHVM_FUNCTION(headers_list);
bool HHVM_FUNCTION(headers_sent);
Variant HHVM_FUNCTION(header_register_callback, const Variant& callback);
void HHVM_FUNCTION(header_remove, const Variant& name = null_string);
int64_t HHVM_FUNCTION(get_http_request_size);
bool HHVM_FUNCTION(setcookie, const String& name,
                              const String& value = null_string,
                              int64_t expire = 0,
                              const String& path = null_string,
                              const String& domain = null_string,
                              bool secure = false,
                              bool httponly = false);
bool HHVM_FUNCTION(setrawcookie, const String& name,
                                 const String& value = null_string,
                                 int64_t expire = 0,
                                 const String& path = null_string,
                                 const String& domain = null_string,
                                 bool secure = false,
                                 bool httponly = false);
bool HHVM_FUNCTION(openlog, const String& ident, int64_t option, int64_t facility);
bool HHVM_FUNCTION(closelog);
bool HHVM_FUNCTION(syslog, int64_t priority, const String& message);

bool validate_dns_arguments(const String& host, const String& type,
                            int& ntype);
}
