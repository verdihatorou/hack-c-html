// Copyright (c) Facebook, Inc. and its affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the "hack" directory of this source tree.

#![cfg(test)]

use arena_deserializer::*;
use bumpalo::Bump;
use serde::{Deserialize, Serialize};
use serde_json;

fn round_trip<'a, X: Deserialize<'a> + Serialize + Eq + std::fmt::Debug>(x: X, arena: &'a Bump) {
    let se = serde_json::to_string(&x).unwrap();
    let mut de = serde_json::Deserializer::from_str(&se);
    let de = ArenaDeserializer::new(arena, &mut de);
    let x2 = X::deserialize(de).unwrap();
    assert_eq!(x, x2);
}

#[test]
fn impl_deserialize_in_arena_for_deserializable() {
    #[derive(Deserialize)]
    struct N;
    impl_deserialize_in_arena!(N);

    #[derive(Deserialize)]
    struct A<'a>(std::marker::PhantomData<&'a ()>);
    impl_deserialize_in_arena!(A<'arena>);

    #[derive(Deserialize)]
    struct B<'a, 'b>(std::marker::PhantomData<(&'a (), &'b ())>);
    impl_deserialize_in_arena!(B<'arena, 'arena>);

    #[derive(Deserialize)]
    struct C<'a, T>(std::marker::PhantomData<(&'a (), T)>);
    impl_deserialize_in_arena!(C<'arena, T>);

    #[derive(Deserialize)]
    struct D<T>(std::marker::PhantomData<T>);
    impl_deserialize_in_arena!(D<T>);

    #[derive(Deserialize)]
    struct E<T, S>(std::marker::PhantomData<(T, S)>);
    impl_deserialize_in_arena!(E<T, S>);
}

#[test]
fn example() {
    #[derive(Serialize, Deserialize, Debug, PartialEq, Eq)]
    struct I(isize);
    impl_deserialize_in_arena!(I);

    #[serde(bound(deserialize = "T: 'de + arena_deserializer::DeserializeInArena<'de>"))]
    #[derive(Serialize, Deserialize, Debug, PartialEq, Eq)]
    enum Num<'a, T> {
        #[serde(deserialize_with = "arena_deserializer::arena")]
        Base(&'a I),
        #[serde(deserialize_with = "arena_deserializer::arena")]
        Succ(&'a Num<'a, T>),
        #[serde(deserialize_with = "arena_deserializer::arena")]
        List(&'a [&'a Num<'a, T>]),
        #[serde(deserialize_with = "arena_deserializer::arena")]
        ListValue(&'a [Num<'a, T>]),
        #[serde(deserialize_with = "arena_deserializer::arena")]
        Str(&'a str),
        String(String),
        #[serde(deserialize_with = "arena_deserializer::arena")]
        OptRef(Option<&'a isize>),
        #[serde(deserialize_with = "arena_deserializer::arena")]
        Opt(Option<isize>),
        #[serde(deserialize_with = "arena_deserializer::arena")]
        PairRef(&'a (bool, &'a isize)),
        #[serde(deserialize_with = "arena_deserializer::arena")]
        Pair((&'a Num<'a, T>, &'a isize)),
        #[serde(deserialize_with = "arena_deserializer::arena")]
        T(T),
        #[serde(deserialize_with = "arena_deserializer::arena")]
        BStr(&'a bstr::BStr),
    }

    impl_deserialize_in_arena!(Num<'arena, T>);

    let arena = Bump::new();

    let x = I(0);
    round_trip(x, &arena);

    let i: Num<'_, ()> = Num::Str("aa");
    let x = Num::Succ(&i);
    round_trip(x, &arena);

    let i = I(3);
    let x: Num<'_, ()> = Num::Base(&i);
    round_trip(x, &arena);

    let i = I(1);
    let n1: Num<'_, ()> = Num::Base(&i);
    let n2 = Num::Succ(&n1);
    let ls = vec![&n1, &n2];
    let x = Num::List(&ls);
    round_trip(x, &arena);

    let i = I(1);
    let n1: Num<'_, ()> = Num::Base(&i);
    let n2 = Num::Succ(&n1);
    let n1 = Num::Base(&i);
    let ls = vec![n1, n2];
    let x = Num::ListValue(&ls);
    round_trip(x, &arena);

    let i: isize = 3;
    let x: Num<'_, ()> = Num::OptRef(Some(&i));
    round_trip(x, &arena);

    let i: isize = 3;
    let x: Num<'_, ()> = Num::Opt(Some(i));
    round_trip(x, &arena);

    let i: isize = 1;
    let n: Num<'_, ()> = Num::Opt(Some(3));
    let p = (&n, &i);
    let x = Num::Pair(p);
    round_trip(x, &arena);

    let x = Num::T(true);
    round_trip(x, &arena);

    let s: &bstr::BStr = "abc".into();
    let x: Num<'_, ()> = Num::BStr(s);
    round_trip(x, &arena);
}

#[test]
fn complex() {
    #[serde(bound(deserialize = "V: 'de + arena_deserializer::DeserializeInArena<'de>"))]
    #[derive(Debug, Deserialize, Serialize, PartialEq, Eq)]
    struct Set<'a, V>(
        #[serde(deserialize_with = "arena_deserializer::arena", borrow)] Option<&'a Node<'a, V>>,
    );

    impl_deserialize_in_arena!(Set<'arena, V>);

    #[serde(bound(deserialize = "V: 'de + arena_deserializer::DeserializeInArena<'de>"))]
    #[derive(Debug, Deserialize, Serialize, PartialEq, Eq)]
    struct Node<'a, V>(
        #[serde(borrow)] Set<'a, V>,
        #[serde(deserialize_with = "arena_deserializer::arena")] V,
        usize,
    );

    impl_deserialize_in_arena!(Node<'arena, V>);

    let arena = bumpalo::Bump::new();

    let x: Set<()> = Set(None);
    round_trip(x, &arena);

    let v: isize = 3;
    let n = Node(Set(None), &v, 1);
    let x = Set(Some(&n));
    round_trip(x, &arena);

    let v: isize = 3;
    let n = Node(Set(None), &v, 1);
    let x: Set<&isize> = Set(Some(&n));

    let n = Node(Set(None), &x, 1);
    let x: Set<&Set<&isize>> = Set(Some(&n));
    round_trip(x, &arena);
}
