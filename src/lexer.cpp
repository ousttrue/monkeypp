#include "lexer.h"

namespace monkey {

Lexer::Lexer(std::string_view input) : _input(input) { _it = input.begin(); }

Token Lexer::NextToken() {
  if (_it == _input.end()) {
    return Eof;
  }

  switch (*(_it++)) {
  case '=':
    return Assign;
  case ';':
    return Semicolon;
  case '(':
    return LParen;
  case ')':
    return RParen;
  case ',':
    return Comma;
  case '+':
    return Plus;
  case '{':
    return LBrace;
  case '}':
    return RBrace;
  }
}

} // namespace monkey