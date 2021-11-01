#pragma once
#include <magic_enum.hpp>
#include <ostream>
#include <unordered_map>

namespace monkey {

enum class TokenTypes {
  NONE,
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

inline const std::unordered_map<std::string_view, TokenTypes> &lookup() {
  static std::unordered_map<std::string_view, TokenTypes> table = {
      {"let", TokenTypes::LET},       {"fn", TokenTypes::FUNCTION},
      {"if", TokenTypes::IF},         {"else", TokenTypes::ELSE},
      {"return", TokenTypes::RETURN}, {"true", TokenTypes::_TRUE},
      {"false", TokenTypes::_FALSE},
  };
  return table;
}
struct Token {
  TokenTypes type;
  std::string_view value;

  Token() : type(TokenTypes::NONE), value("") {}

  Token(TokenTypes t, std::string_view v = {}) : type(t), value(v) {
    if (v.empty()) {
      for (auto [k, symbol] : lookup()) {
        if (t == symbol) {
          value = k;
          break;
        }
      }
    }
  }
  static Token Ident(std::string_view value) {
    return {TokenTypes::IDENT, value};
  }
  static Token Int(std::string_view value) { return {TokenTypes::INT, value}; }

  operator TokenTypes() const { return type; }

  bool operator==(const Token &rhs) const {
    if (type != rhs.type) {
      return false;
    }
    if (value != rhs.value) {
      return false;
    }
    return true;
  }
};

} // namespace monkey
