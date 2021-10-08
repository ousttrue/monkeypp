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

const std::unordered_map<std::string_view, std::string_view> lookup = {
    {"let", constants::LET},
    {"fn", constants::FUNCTION},
};

Token Lexer::NextToken() {

  SkipWhiteSpace();

  if (_it == _input.end()) {
    return Eof;
  }

  auto c = *_it;
  switch (c) {
  case '=':
    ++_it;
    return Assign;
  case ';':
    ++_it;
    return Semicolon;
  case '(':
    ++_it;
    return LParen;
  case ')':
    ++_it;
    return RParen;
  case ',':
    ++_it;
    return Comma;
  case '+':
    ++_it;
    return Plus;
  case '{':
    ++_it;
    return LBrace;
  case '}':
    ++_it;
    return RBrace;

  default: {
    if (isLetter(c)) {
      auto t = ReadIdentifier();
      auto found = lookup.find(t.value);
      if (found != lookup.end()) {
        t.type = found->second;
      }
      return t;
    } else if (isDigit(c)) {
      auto t = ReadInt();
      return t;
    } else {
      return Illegal;
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
  return Ident({begin, _it});
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
  return Int({begin, _it});
}

} // namespace monkey