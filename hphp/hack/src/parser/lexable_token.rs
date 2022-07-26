// Copyright (c) 2019, Facebook, Inc.
// All rights reserved.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the "hack" directory of this source tree.

use std::fmt::Debug;

use crate::lexable_trivia::LexableTrivia;
use crate::positioned_trivia::PositionedTrivium;
use crate::source_text::SourceText;
use crate::token_kind::TokenKind;
use crate::trivia_kind::TriviaKind;

pub trait LexableToken: Clone + Debug {
    type Trivia: LexableTrivia;

    fn kind(&self) -> TokenKind;

    /// Returns the leading offset if meaningful
    /// (note: each implementor will either always return Some(offset) or always return None).
    fn leading_start_offset(&self) -> Option<usize>;

    fn width(&self) -> usize;
    fn leading_width(&self) -> usize;
    fn trailing_width(&self) -> usize;
    fn full_width(&self) -> usize;

    fn clone_leading(&self) -> Self::Trivia;
    fn clone_trailing(&self) -> Self::Trivia;

    fn leading_is_empty(&self) -> bool;
    fn trailing_is_empty(&self) -> bool;

    fn has_leading_trivia_kind(&self, kind: TriviaKind) -> bool;
    fn has_trailing_trivia_kind(&self, kind: TriviaKind) -> bool;
    fn has_trivia_kind(&self, kind: TriviaKind) -> bool {
        self.has_leading_trivia_kind(kind) || self.has_trailing_trivia_kind(kind)
    }

    fn into_trivia_and_width(self) -> (Self::Trivia, usize, Self::Trivia);
}

pub trait LexablePositionedToken: LexableToken
where
    Self: Debug,
{
    fn text<'b>(&self, source_text: &'b SourceText<'_>) -> &'b str;
    fn text_raw<'b>(&self, source_text: &'b SourceText<'_>) -> &'b [u8];
    fn clone_value(&self) -> Self;
    fn positioned_leading(&self) -> &[PositionedTrivium];
    fn positioned_trailing(&self) -> &[PositionedTrivium];
}
