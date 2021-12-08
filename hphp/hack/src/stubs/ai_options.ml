(*
 * Copyright (c) 2015, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree.
 *
 *)

type t = { analyses: string list }

let prepare ~server:_ _ = { analyses = [] }

let modify_shared_mem _options config = config
