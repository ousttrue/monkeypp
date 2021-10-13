#pragma once
#include <ostream>
#include <magic_enum.hpp>

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
  os << magic_enum::enum_name(t);
  return os;
}

} // namespace monkey
