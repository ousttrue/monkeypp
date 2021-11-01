#pragma once
#include "token.h"
#include <memory>
#include <string_view>
#include <vector>

namespace monkey {

struct INode {
  virtual std::string_view TokenLiteral() const = 0;
};

///
/// IExpression
///
struct IExpression : public INode {
  virtual void expressionNode() = 0;
};

struct Identifier : IExpression {
  Token Token;
  void expressionNode() override {}
  std::string_view TokenLiteral() const override { return Token.value; }
};

///
/// IStatement
///
struct IStatement : public INode {
  virtual void StatementNode() = 0;
};

struct LetStatement : public IStatement {
  Token Let;
  Token Name;
  std::shared_ptr<IExpression> Value;
  LetStatement(const Token &let) : Let(let) {}
  void StatementNode() override {}
  std::string_view TokenLiteral() const override { return Let.value; }
};

struct Program {
  std::vector<std::shared_ptr<IStatement>> Statements;

  std::string_view TokenLiteral() const {
    if (Statements.empty()) {
      return "";
    } else {
      return Statements.front()->TokenLiteral();
    }
  }
};

} // namespace monkey