#include "lexer.h"
#include <algorithm>
#include <unordered_map>

static bool isLetter(char c) {
  if ('a' <= c && c <= 'z') {
    return true;
  }
  if ('A' <= c && c <= 'Z') {
    return true;
  }
  if (c == '_') {
    return true;
  }
  return false;
}

static bool isDigit(char c) {
  if ('0' <= c && c <= '9') {
    return true;
  }
  return false;
}

namespace monkey {

Lexer::Lexer(std::string_view input) : _input(input) { _it = input.begin(); }

const std::unordered_map<std::string_view, TokenTypes> lookup = {
    {"let", TokenTypes::LET},
    {"fn", TokenTypes::FUNCTION},
    {"if", TokenTypes::IF},
    {"else", TokenTypes::ELSE},
    {"return", TokenTypes::RETURN},
    {"true", TokenTypes::_TRUE},
    {"false", TokenTypes::_FALSE},
};

Token Lexer::NextToken() {

  SkipWhiteSpace();

  if (_it == _input.end()) {
    return TokenTypes::_EOF;
  }

  auto c = *_it;
  switch (c) {
  case '=':
    ++_it;
    return TokenTypes::ASSIGN;
  case ';':
    ++_it;
    return TokenTypes::SEMICOLON;
  case '(':
    ++_it;
    return TokenTypes::LPAREN;
  case ')':
    ++_it;
    return {TokenTypes::RPAREN};
  case ',':
    ++_it;
    return {TokenTypes::COMMA};
  case '+':
    ++_it;
    return {TokenTypes::PLUS};
  case '-':
    ++_it;
    return {TokenTypes::MINUS};
  case '!':
    ++_it;
    return {TokenTypes::BANG};
  case '*':
    ++_it;
    return {TokenTypes::ASTERISK};
  case '/':
    ++_it;
    return {TokenTypes::SLASH};
  case '<':
    ++_it;
    return {TokenTypes::LT};
  case '>':
    ++_it;
    return {TokenTypes::GT};
  case '{':
    ++_it;
    return {TokenTypes::LBRACE};
  case '}':
    ++_it;
    return {TokenTypes::RBRACE};

  default: {
    if (isLetter(c)) {
      auto t = ReadIdentifier();
      auto found = lookup.find(t.value);
      if (found != lookup.end()) {
        return found->second;
      }
      return t;
    } else if (isDigit(c)) {
      auto t = ReadInt();
      return t;
    } else {
      return {TokenTypes::ILLEGAL};
    }
  }
  }
}

Token Lexer::ReadIdentifier() {
  auto begin = _it;
  for (; _it != _input.end(); ++_it) {
    if (!isLetter(*_it)) {
      break;
    }
  }
  return Token::Ident({begin, _it});
}

void Lexer::SkipWhiteSpace() {

  for (; _it != _input.end(); ++_it) {
    switch (*_it) {
    case ' ':
    case '\t':
    case '\n':
    case '\r':
      break;
    default:
      return;
    }
  }
}

Token Lexer::ReadInt() {
  auto begin = _it;
  for (; _it != _input.end(); ++_it) {
    if (!isDigit(*_it)) {
      break;
    }
  }
  return Token::Int({begin, _it});
}

} // namespace monkey