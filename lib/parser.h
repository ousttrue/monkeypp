#pragma once
#include "ast.h"
#include "lexer.h"

namespace monkey {
class Parser {
  Lexer &l;

  Token current;
  Token peek;

public:
  Parser(Lexer &_l) : l(_l) {
    nextToken();
    nextToken();
  }
  void nextToken() {
    current = peek;
    peek = l.NextToken();
  }
  std::shared_ptr<Program> Parse() { return {}; }
};

} // namespace monkey
