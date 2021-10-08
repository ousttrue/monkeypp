#pragma once
#include "token.h"
#include <string_view>

namespace monkey {

struct Token {
  std::string_view type;
  std::string_view value;

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

constexpr Token Assign = {constants::ASSIGN, "="};
constexpr Token Plus = {constants::PLUS, "+"};
constexpr Token LParen = {constants::LPAREN, "("};
constexpr Token RParen = {constants::RPAREN, ")"};
constexpr Token LBrace = {constants::LBRACE, "{"};
constexpr Token RBrace = {constants::RBRACE, "}"};
constexpr Token Comma = {constants::COMMA, ","};
constexpr Token Semicolon = {constants::SEMICOLON, ";"};
constexpr Token Eof = {constants::_EOF};

class Lexer {
  std::string_view _input;
  std::string_view::iterator _it;

public:
  Lexer(std::string_view input);
  Token NextToken();
};
} // namespace monkey