#pragma once
#include <ostream>

namespace monkey {

enum class TokenTypes {
  ILLEGAL,
  _EOF,
  IDENT,
  INT,
  ASSIGN,
  PLUS,
  COMMA,
  SEMICOLON,
  LPAREN,
  RPAREN,
  LBRACE,
  RBRACE,
  FUNCTION,
  LET,
};

inline std::ostream &operator<<(std::ostream &os, TokenTypes t) {
  os << (int)t;
  return os;
}

} // namespace monkey
