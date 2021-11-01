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

  bool peekTokenIs(TokenTypes t) const { return peek.type == t; }

  bool expectPeek(TokenTypes t) {
    if (peekTokenIs(t)) {
      nextToken();
      return true;
    } else {
      return false;
    }
  }

  std::shared_ptr<LetStatement> parseLetStatement() {
    auto let = std::make_shared<LetStatement>(current);
    if (!expectPeek(TokenTypes::IDENT)) {
      return {};
    }
    let->Name = current;

    while (!peekTokenIs(TokenTypes::SEMICOLON)) {
      nextToken();
    }

    return let;
  }

  std::shared_ptr<IStatement> parseStatement() {
    switch (current.type) {
    case TokenTypes::LET:
      return parseLetStatement();
    default:
      return {};
    }
  }

  std::shared_ptr<Program> parseProgram() {

    auto program = std::make_shared<Program>();

    while (current.type != TokenTypes::_EOF) {
      auto stmt = parseStatement();
      if (stmt) {
        program->Statements.push_back(stmt);
      }
      nextToken();
    }

    return program;
  }
};

} // namespace monkey
