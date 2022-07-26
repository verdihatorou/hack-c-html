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

#include "hphp/runtime/base/type-variant.h"
#include "hphp/runtime/base/req-hash-set.h"
#include "hphp/util/functional.h" // for pointer_hash

#include "hphp/util/hdf.h"

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

struct Array;

/**
 * Utility array functions.
 */
struct ArrayUtil final {
  /////////////////////////////////////////////////////////////////////////////
  // Compositions.

  /**
   * Removes the elements designated by offset and length and replace them
   * with supplied array. Adds the removed elements to `removed`, which must
   * be non-null and empty.
   */
  static Variant Splice(const Array& input, int offset, int64_t length,
                        const Variant& replacement, Array& removed);

  /**
   * Returns a copy of input array padded with pad_value to size pad_size.
   */
  static Variant PadLeft(const Array& input, const Variant& pad_value,
                         int pad_size);
  static Variant PadRight(const Array& input, const Variant& pad_value,
                          int pad_size);

  /**
   * Create an array containing the range of integers or characters from low
   * to high (inclusive).
   */
  static Variant Range(unsigned char low, unsigned char high, int64_t step = 1);
  static Variant Range(double low, double high, double step = 1.0);
  static Variant Range(int64_t low, int64_t high, int64_t step = 1);

  /////////////////////////////////////////////////////////////////////////////
  // Information and calculations.

  /**
   * Return the value as key and the frequency of that value in input
   * as value.
   */
  static Variant CountValues(const Array& input);

  /////////////////////////////////////////////////////////////////////////////
  // Manipulations. Note, all these functions will create a new array than
  // modifying input, although names of these functions sound like mutating.

  /**
   * Returns an array with all string keys lowercased [or uppercased].
   */
  static Variant ChangeKeyCase(const Array& input, bool lower);

  /**
   * Return input as a new array with the order of the entries reversed.
   */
  static Variant Reverse(const Array& input, bool preserve_keys = false);

  /**
   * Randomly shuffle the contents of an array.
   */
  static Variant Shuffle(const Array& input);

  /**
   * Return key/keys for random entry/entries in the array.
   */
  static Variant RandomKeys(const Array& input, int num_req = 1);

  /**
   * Removes duplicate string values from array.
   */
  static Variant StringUnique(const Array& input);

  /**
   * Removes values whose numeric conversion is duplicate from array.
   */
  static Variant NumericUnique(const Array& input);

  /**
   * Removes values that compare as equal and that end up in contiguous
   * positions if the input array is sorted.
   */
  static Variant RegularSortUnique(const Array& input);

  /////////////////////////////////////////////////////////////////////////////
  // Iterations.

  using PointerSet = req::fast_set<const ArrayData*,
                                   pointer_hash<const ArrayData>>;

  /**
   * Apply a user function to every member of an array.
   */
  using PFUNC_WALK = void (*)(Variant& value, const Variant& key,
                              const Variant& userdata, const void *data);
  static void Walk(Variant &input, PFUNC_WALK walk_function, const void *data,
                   bool recursive = false, PointerSet *seen = nullptr,
                   const Variant& userdata = uninit_variant);

  /**
   * Iteratively reduce the array to a single value via the callback.
   */
  using PFUNC_REDUCE = Variant (*)(const Variant& result,
                                   const Variant& operand,
                                   const void *data);
  static Variant Reduce(const Array& input, PFUNC_REDUCE reduce_function,
                    const void *data, const Variant& initial = uninit_variant);
};

///////////////////////////////////////////////////////////////////////////////
}

