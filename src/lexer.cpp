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

namespace monkey {

Lexer::Lexer(std::string_view input) : _input(input) { _it = input.begin(); }

const std::unordered_map<std::string_view, std::string_view> lookup = {
    {"let", constants::LET},
    {"fn", constants::FUNCTION},
};

Token Lexer::NextToken() {
  if (_it == _input.end()) {
    return Eof;
  }

  switch (*_it) {
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
    if (isLetter(*_it)) {
      auto id = ReadIdentifier();
      auto found = lookup.find(id.value);
      if(found!=lookup.end())
      {
        id.type = found->second;
      }
      return id;
    } else {
      return Illegal;
    }
  }
  }
}

Token Lexer::ReadIdentifier() {
  auto position = _it;
  for (; _it != _input.end(); ++_it) {
    if (!isLetter(*_it)) {
      break;
    }
  }
  std::string_view value(position, _it);
  return Ident(value);
}

} // namespace monkey