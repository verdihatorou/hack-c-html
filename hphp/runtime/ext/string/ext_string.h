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

#include "hphp/zend/zend-html.h"
#include "hphp/runtime/ext/std/ext_std_misc.h"
#include "hphp/runtime/ext/extension.h"
#include "hphp/runtime/base/req-vector.h"
#include "hphp/runtime/base/zend-string.h"
#include "hphp/runtime/base/zend-printf.h"
#include "hphp/util/bstring.h"
#ifndef _MSC_VER
#include <langinfo.h>
#endif

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////
// transformations and manipulations

extern const HPHP::StaticString k_HPHP_TRIM_CHARLIST;

constexpr int64_t k_ENT_HTML_QUOTE_NONE = 0;
constexpr int64_t k_ENT_HTML_QUOTE_SINGLE = 1;
constexpr int64_t k_ENT_HTML_QUOTE_DOUBLE = 2;
constexpr int64_t k_ENT_HTML_IGNORE_ERRORS = 4;
constexpr int64_t k_ENT_HTML_SUBSTITUTE_ERRORS = 8;
constexpr int64_t k_ENT_HTML_DOC_TYPE_MASK = (16|32);
constexpr int64_t k_ENT_HTML_DOC_HTML401 = 0;
constexpr int64_t k_ENT_HTML_DOC_XML1 = 16;
constexpr int64_t k_ENT_HTML_DOC_XHTML = 32;
constexpr int64_t k_ENT_HTML_DOC_HTML5 = (16|32);
constexpr int64_t k_ENT_HTML_SUBSTITUTE_DISALLOWED_CHARS = 128;
constexpr int64_t k_ENT_FB_UTF8 = 32768;
constexpr int64_t k_ENT_FB_UTF8_ONLY = 65536;

constexpr int64_t k_ENT_QUOTES = k_ENT_HTML_QUOTE_DOUBLE |
                                 k_ENT_HTML_QUOTE_SINGLE;

constexpr int64_t k_HTML_SPECIALCHARS = 0;
constexpr int64_t k_HTML_ENTITIES = 1;

constexpr int64_t k_STR_PAD_LEFT  = 0;
constexpr int64_t k_STR_PAD_RIGHT = 1;
constexpr int64_t k_STR_PAD_BOTH  = 2;

String HHVM_FUNCTION(addcslashes,
                     const String& str,
                     const String& charlist);
String HHVM_FUNCTION(stripcslashes,
                     const String& str);
String HHVM_FUNCTION(addslashes,
                     const String& str);
String HHVM_FUNCTION(stripslashes,
                     const String& str);
String HHVM_FUNCTION(bin2hex,
                     const String& str);
Variant HHVM_FUNCTION(hex2bin,
                      const String& str);
String HHVM_FUNCTION(nl2br,
                     const String& str,
                     bool is_xhtml = true);
String HHVM_FUNCTION(quotemeta,
                     const String& str);
String HHVM_FUNCTION(str_shuffle,
                     const String& str);
String HHVM_FUNCTION(strrev,
                     const String& str);
String HHVM_FUNCTION(strtolower,
                     const String& str);
String HHVM_FUNCTION(strtoupper,
                     const String& str);
String HHVM_FUNCTION(ucfirst,
                     const String& str);
String HHVM_FUNCTION(lcfirst,
                     const String& str);
String HHVM_FUNCTION(ucwords,
                     const String& str,
                     const String& delimiters = " \t\r\n\f\v");
String HHVM_FUNCTION(strip_tags,
                     const String& str,
                     const Variant& allowable_tags = "");
String HHVM_FUNCTION(trim,
                     const String& str,
                     const String& charlist = k_HPHP_TRIM_CHARLIST);
String HHVM_FUNCTION(ltrim,
                     const String& str,
                     const String& charlist = k_HPHP_TRIM_CHARLIST);
String HHVM_FUNCTION(rtrim,
                     const String& str,
                     const String& charlist = k_HPHP_TRIM_CHARLIST);
String HHVM_FUNCTION(chop,
                     const String& str,
                     const String& charlist = k_HPHP_TRIM_CHARLIST);
Variant HHVM_FUNCTION(explode,
                      const String& delimiter,
                      const String& str,
                      int64_t limit = k_PHP_INT_MAX);
String HHVM_FUNCTION(implode,
                     const Variant& arg1,
                     const Variant& arg2 = uninit_variant);
String HHVM_FUNCTION(join,
                     const Variant& arg1,
                     const Variant& arg2 = uninit_variant);
TypedValue HHVM_FUNCTION(str_split,
                         const String& str,
                         int64_t split_length = 1);
TypedValue HHVM_FUNCTION(chunk_split,
                         const String& body,
                         int64_t chunklen = 76,
                         const String& end = "\r\n");
TypedValue HHVM_FUNCTION(strtok,
                         const String& str,
                         const Variant& token = uninit_variant);
TypedValue HHVM_FUNCTION(str_replace,
                         const Variant& search,
                         const Variant& replace,
                         const Variant& subject);
TypedValue HHVM_FUNCTION(str_ireplace,
                         const Variant& search,
                         const Variant& replace,
                         const Variant& subject);
TypedValue HHVM_FUNCTION(substr_replace,
                         const Variant& str,
                         const Variant& replacement,
                         const Variant& start,
                         const Variant& length = 0x7FFFFFFF);
String HHVM_FUNCTION(str_pad,
                     const String& input,
                     int64_t pad_length,
                     const String& pad_string = " ",
                     int64_t pad_type = k_STR_PAD_RIGHT);
String HHVM_FUNCTION(str_repeat,
                     const String& input,
                     int64_t multiplier);

///////////////////////////////////////////////////////////////////////////////
// encoding/decoding

String HHVM_FUNCTION(html_entity_decode,
                     const String& str,
                     int64_t quote_style = k_ENT_HTML_QUOTE_DOUBLE,
                     const String& charset = "UTF-8");
String HHVM_FUNCTION(htmlentities,
                     const String& str,
                     int64_t quote_style = k_ENT_HTML_QUOTE_DOUBLE,
                     const String& charset = "UTF-8",
                     bool double_encode = true);
String HHVM_FUNCTION(htmlspecialchars_decode,
                     const String& str,
                     int64_t quote_style = k_ENT_HTML_QUOTE_DOUBLE);
String HHVM_FUNCTION(htmlspecialchars,
                     const String& str,
                     int64_t quote_style = k_ENT_HTML_QUOTE_DOUBLE,
                     const String& charset = "UTF-8",
                     bool double_encode = true);
String HHVM_FUNCTION(fb_htmlspecialchars,
                     const String& str,
                     int64_t quote_style,
                     const String& charset,
                     const Variant& extra);
String HHVM_FUNCTION(quoted_printable_encode,
                     const String& str);
String HHVM_FUNCTION(quoted_printable_decode,
                     const String& str);
Variant HHVM_FUNCTION(convert_uudecode,
                      const String& data);
Variant HHVM_FUNCTION(convert_uuencode,
                      const String& data);
String HHVM_FUNCTION(str_rot13,
                     const String& str);
String HHVM_FUNCTION(crypt,
                     const String& str,
                     const String& salt = "");
String HHVM_FUNCTION(md5,
                     const String& str,
                     bool raw_output = false);
String HHVM_FUNCTION(sha1,
                     const String& str,
                     bool raw_output = false);
Variant HHVM_FUNCTION(strtr,
                      const String& str,
                      const Variant& from,
                      const Variant& to = uninit_variant);
String HHVM_FUNCTION(convert_cyr_string,
                     const String& str,
                     const String& from,
                     const String& to);
Array HHVM_FUNCTION(get_html_translation_table,
                    int64_t table = 0,
                    int64_t quote_style = k_ENT_HTML_QUOTE_DOUBLE,
                    const String& encoding = "UTF-8");
String HHVM_FUNCTION(hebrev,
                     const String& hebrew_text,
                     int64_t max_chars_per_line = 0);
String HHVM_FUNCTION(hebrevc,
                     const String& hebrew_text,
                     int64_t max_chars_per_line = 0);
Variant HHVM_FUNCTION(setlocale,
                      int64_t category,
                      const Variant& locale,
                      const Array& _argv = null_array);
Array HHVM_FUNCTION(localeconv);
Variant HHVM_FUNCTION(nl_langinfo, int64_t item);

///////////////////////////////////////////////////////////////////////////////
// input/output

Variant f_printf(int64_t _argc,
                 const String& format,
                 const Array& _argv = null_array);
Variant f_vprintf(const String& format,
                  const Array& args);
Variant f_sprintf(int64_t _argc,
                  const String& format,
                  const Array& _argv = null_array);
Variant f_vsprintf(const String& format,
                   const Array& args);


Variant HHVM_FUNCTION(sscanf,
                      const String& str,
                      const String& format);
String HHVM_FUNCTION(chr, const Variant& ascii);
int64_t HHVM_FUNCTION(ord,
                      const String& str);
Variant HHVM_FUNCTION(money_format,
                      const String& format,
                      double number);
String HHVM_FUNCTION(number_format,
                     double number,
                     int64_t decimals = 0,
                     const Variant& dec_point = ".",
                     const Variant& thousands_sep = ",");

///////////////////////////////////////////////////////////////////////////////
// analysis

bool str_contains_any_of(const String& haystack, const String& char_list);

int64_t HHVM_FUNCTION(strcmp,
                      const String& str1,
                      const String& str2);
TypedValue HHVM_FUNCTION(strncmp,
                         const String& str1,
                         const String& str2,
                         int64_t len);
int64_t HHVM_FUNCTION(strnatcmp,
                      const String& str1,
                      const String& str2);
int64_t HHVM_FUNCTION(strcasecmp,
                      const String& str1,
                      const String& str2);
TypedValue HHVM_FUNCTION(strncasecmp,
                         const String& str1,
                         const String& str2,
                         int64_t len);
int64_t HHVM_FUNCTION(strnatcasecmp,
                      const String& str1,
                      const String& str2);
int64_t HHVM_FUNCTION(strcoll,
                      const String& str1,
                      const String& str2);
TypedValue HHVM_FUNCTION(substr_compare,
                         const String& main_str,
                         const String& str,
                         int64_t offset,
                         int64_t length = INT_MAX,
                         bool case_insensitivity = false);
TypedValue HHVM_FUNCTION(strchr,
                         const String& haystack,
                         const Variant& needle);
TypedValue HHVM_FUNCTION(strrchr,
                         const String& haystack,
                         const Variant& needle);
TypedValue HHVM_FUNCTION(strstr,
                         const String& haystack,
                         const Variant& needle,
                         bool before_needle = false);
TypedValue HHVM_FUNCTION(stristr,
                         const String& haystack,
                         const Variant& needle,
                         bool before_needle = false);
TypedValue HHVM_FUNCTION(strpbrk,
                         const String& haystack,
                         const String& char_list);
TypedValue HHVM_FUNCTION(strpos,
                         const String& haystack,
                         const Variant& needle,
                         int64_t offset = 0);
TypedValue HHVM_FUNCTION(stripos,
                         const String& haystack,
                         const Variant& needle,
                         int64_t offset = 0);
TypedValue HHVM_FUNCTION(strrpos,
                        const String& haystack,
                        const Variant& needle,
                        int64_t offset = 0);
TypedValue HHVM_FUNCTION(strripos,
                        const String& haystack,
                        const Variant& needle,
                        int64_t offset = 0);
TypedValue HHVM_FUNCTION(substr_count,
                         const String& haystack,
                         const String& needle,
                         int64_t offset = 0,
                         int64_t length = 0x7FFFFFFF);
TypedValue HHVM_FUNCTION(strspn,
                         const String& str1,
                         const String& str2,
                         int64_t start = 0,
                         int64_t length = 0x7FFFFFFF);
TypedValue HHVM_FUNCTION(strcspn,
                         const String& str1,
                         const String& str2,
                         int64_t start = 0,
                         int64_t length = 0x7FFFFFFF);
Array HHVM_FUNCTION(str_getcsv,
                    const String& str,
                    const String& delimiter = ",",
                    const String& enclosure = "\"",
                    const String& escape = "\\");
Variant HHVM_FUNCTION(count_chars,
                      const String& str,
                      int64_t mode = 0);
Variant HHVM_FUNCTION(str_word_count,
                      const String& str,
                      int64_t format = 0,
                      const String& charlist = "");
int64_t HHVM_FUNCTION(levenshtein,
                      const String& str1,
                      const String& str2,
                      int64_t cost_ins = 1,
                      int64_t cost_rep = 1,
                      int64_t cost_del = 1);
int64_t HHVM_FUNCTION(similar_text,
                      const String& first,
                      const String& second,
                      double& percent);
Variant HHVM_FUNCTION(soundex,
                      const String& str);
Variant HHVM_FUNCTION(metaphone,
                      const String& str,
                      int64_t phones = 0);
bool HHVM_FUNCTION(HH_str_number_coercible,
                   const String& str);
Variant HHVM_FUNCTION(HH_str_to_numeric,
                      const String& str);

///////////////////////////////////////////////////////////////////////////////

}
