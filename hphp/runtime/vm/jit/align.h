/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-present Facebook, Inc. (http://www.facebook.com)  |
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

#include "hphp/runtime/vm/jit/types.h"
#include "hphp/runtime/vm/jit/alignment.h"

#include "hphp/util/data-block.h"

namespace HPHP::jit {

struct CGMeta;

///////////////////////////////////////////////////////////////////////////////

/*
 * Whether `frontier' is aligned to `alignment'.
 */
bool is_aligned(TCA frontier, Alignment alignment);

/*
 * Align `cb' to `alignment' in `context'.
 *
 * By default, calling align() registers alignment metadata for relocation.  If
 * this behavior is not desired (e.g., in the relocator itself), it can be
 * disabled by passing nullptr for `meta'.
 */
void align(CodeBlock& cb, CGMeta* meta,
           Alignment alignment, AlignContext context);

/*
 * Size of a cache line, in bytes.
 */
size_t cache_line_size();

///////////////////////////////////////////////////////////////////////////////

}

