#pragma once
#include <magic_enum.hpp>
#include <ostream>

namespace monkey {

enum class TokenTypes {
  ILLEGAL,
  _EOF,
  IDENT,
  INT,
  ASSIGN,    // =
  PLUS,      // +
  MINUS,     // -
  BANG,      // !
  ASTERISK,  // *
  SLASH,     // /
  COMMA,     // ,
  SEMICOLON, // ;
  LT,        // <
  GT,        // >
  LPAREN,    // (
  RPAREN,    // )
  LBRACE,    // {
  RBRACE,    // }
  FUNCTION,  // fn
  LET,       // let
  _TRUE,
  _FALSE,
  IF,
  ELSE,
  RETURN,
  EQ,  // ==
  NEQ, // !=
};

inline std::ostream &operator<<(std::ostream &os, TokenTypes t) {
  os << magic_enum::enum_name(t);
  return os;
}

} // namespace monkey
