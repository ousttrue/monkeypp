#pragma once
#include "token.h"
#include <string_view>
#include <ostream>

namespace monkey {

struct Token {
  TokenTypes type;
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

inline std::ostream &operator<<(std::ostream &os, const Token &t)
{
  os << t.type << ": " << t.value;
  return os;
}

constexpr Token Assign = {TokenTypes::ASSIGN, "="};
constexpr Token Plus = {TokenTypes::PLUS, "+"};
constexpr Token LParen = {TokenTypes::LPAREN, "("};
constexpr Token RParen = {TokenTypes::RPAREN, ")"};
constexpr Token LBrace = {TokenTypes::LBRACE, "{"};
constexpr Token RBrace = {TokenTypes::RBRACE, "}"};
constexpr Token Comma = {TokenTypes::COMMA, ","};
constexpr Token Semicolon = {TokenTypes::SEMICOLON, ";"};
constexpr Token Eof = {TokenTypes::_EOF};
constexpr Token Illegal = {TokenTypes::ILLEGAL};

constexpr Token Let = {TokenTypes::LET, "let"};
inline Token Ident(std::string_view value) { return {TokenTypes::IDENT, value}; }
inline Token Int(std::string_view value) { return {TokenTypes::INT, value}; }
inline Token Function = {TokenTypes::FUNCTION, "fn"};

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