#pragma once
#include <ostream>
#include <magic_enum.hpp>

namespace monkey {

enum class TokenTypes {
  ILLEGAL,
  _EOF,
  IDENT,
  INT,
  ASSIGN, // =
  PLUS, // +
  MINUS, // -
  BANG, // !
  ASTERISK, // *
  SLASH, // /
  COMMA, // ,
  SEMICOLON, // ;  
  LT, // <
  GT, // >
  LPAREN, // (
  RPAREN, // )
  LBRACE, // {
  RBRACE, // }
  FUNCTION, // fn
  LET, // let
  _TRUE,
  _FALSE,
  IF,
  ELSE,
  RETURN,
};

inline std::ostream &operator<<(std::ostream &os, TokenTypes t) {
  os << magic_enum::enum_name(t);
  return os;
}

} // namespace monkey
