#pragma once
#include "token.h"
#include <ostream>
#include <string_view>

namespace monkey {

struct Token {
  TokenTypes type;
  std::string_view value;

  Token(TokenTypes t, std::string_view v = {}) : type(t), value(v) {}
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

inline std::ostream &operator<<(std::ostream &os, const Token &t) {
  os << t.type << ": " << t.value;
  return os;
}

class Lexer {
  std::string_view _input;
  std::string_view::iterator _it;

public:
  Lexer(std::string_view input);
  Token NextToken();

private:
  Token ReadIdentifier();
  void SkipWhiteSpace();
  Token ReadInt();
};
} // namespace monkey