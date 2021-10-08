#pragma once
#include "token.h"
#include <string_view>
#include <ostream>

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

inline std::ostream &operator<<(std::ostream &os, const Token &t)
{
  os << t.type << ": " << t.value;
  return os;
}

constexpr Token Assign = {constants::ASSIGN, "="};
constexpr Token Plus = {constants::PLUS, "+"};
constexpr Token LParen = {constants::LPAREN, "("};
constexpr Token RParen = {constants::RPAREN, ")"};
constexpr Token LBrace = {constants::LBRACE, "{"};
constexpr Token RBrace = {constants::RBRACE, "}"};
constexpr Token Comma = {constants::COMMA, ","};
constexpr Token Semicolon = {constants::SEMICOLON, ";"};
constexpr Token Eof = {constants::_EOF};
constexpr Token Illegal = {constants::ILLEGAL};

constexpr Token Let = {constants::LET, "let"};
inline Token Ident(std::string_view value) { return {constants::IDENT, value}; }
inline Token Int(std::string_view value) { return {constants::INT, value}; }
inline Token Function = {constants::FUNCTION, "fn"};

class Lexer {
  std::string_view _input;
  std::string_view::iterator _it;

public:
  Lexer(std::string_view input);
  Token NextToken();
private:
  Token ReadIdentifier();
  void SkipWhiteSpace();
};
} // namespace monkey