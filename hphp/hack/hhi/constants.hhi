<?hh
/**
 * Copyright (c) 2014, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree.
 *
 */

const string PHP_EOL = "\n";

const string PHP_OS = '';
const string PHP_BINARY = 'hhvm';

const string PHP_VERSION = '5.6.99-hhvm';
const int PHP_MAJOR_VERSION = 5;
const int PHP_MINOR_VERSION = 6;
const int PHP_RELEASE_VERSION = 99;
const int PHP_VERSION_ID = 50699;
const string PHP_EXTRA_VERSION = 'hhvm';

const string HHVM_VERSION = 'typechecker placeholder, see runtime';
const string HHVM_COMPILER_ID = 'typechecker placeholder, see runtime';
const int HHVM_COMPILER_TIMESTAMP = 0; // typechecker placeholder, see runtime
const string HHVM_REPO_SCHEMA = 'typechecker placeholder, see runtime';
const int HHVM_VERSION_ID = 0;
const int HHVM_VERSION_MAJOR = 0;
const int HHVM_VERSION_MINOR = 0;
const int HHVM_VERSION_PATCH = 0;

const int PHP_INT_MAX = (1 << 63) - 1;
const int PHP_INT_MIN = -1 << 63;
const int PHP_INT_SIZE = 8;

const int DEBUG_BACKTRACE_PROVIDE_OBJECT = 1 << 0;
const int DEBUG_BACKTRACE_IGNORE_ARGS = 1 << 1;
const int DEBUG_BACKTRACE_PROVIDE_METADATA = 1 << 16;

const int E_ERROR = 1;
const int E_WARNING = 1 << 1;
const int E_PARSE = 1 << 2;
const int E_NOTICE = 1 << 3;
const int E_CORE_ERROR = 1 << 4;
const int E_CORE_WARNING = 1 << 5;
const int E_COMPILE_ERROR = 1 << 6;
const int E_COMPILE_WARNING = 1 << 7;
const int E_USER_ERROR = 1 << 8;
const int E_USER_WARNING = 1 << 9;
const int E_USER_NOTICE = 1 << 10;
const int E_RECOVERABLE_ERROR = 1 << 12;
const int E_DEPRECATED = 1 << 13;
const int E_USER_DEPRECATED = 1 << 14;
const int E_ALL = (1 << 15) - 1;
const int E_STRICT = 1 << 11;


// Built in pseudoconstants
const int __LINE__ = 0;
const string __CLASS__ = '';
const string __TRAIT__ = '';
const string __FILE__ = '';
const string __DIR__ = '';
const string __FUNCTION__ = '';
const string __METHOD__ = '';
const string __NAMESPACE__ = '';
const string __COMPILER_FRONTEND__ = '';
/* HH_FIXME[4110] This isn't really a constant, and there's no way to
 * write a proper constant initializer because the value is an object */
const FunctionCredential __FUNCTION_CREDENTIAL__ = 0;
