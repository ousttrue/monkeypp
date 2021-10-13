#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <lexer.h>

TEST_CASE("basic", "[monkey::Lexer]") {

  auto input = "=+(){},;";

  monkey::Lexer l(input);

  REQUIRE(monkey::TokenTypes::ASSIGN == l.NextToken().type);
  REQUIRE(monkey::TokenTypes::PLUS == l.NextToken().type);
  REQUIRE(monkey::TokenTypes::LPAREN == l.NextToken().type);
  REQUIRE(monkey::TokenTypes::RPAREN == l.NextToken().type);
  REQUIRE(monkey::TokenTypes::LBRACE == l.NextToken().type);
  REQUIRE(monkey::TokenTypes::RBRACE == l.NextToken().type);
  REQUIRE(monkey::TokenTypes::COMMA == l.NextToken().type);
  REQUIRE(monkey::TokenTypes::SEMICOLON == l.NextToken().type);
}

TEST_CASE("source", "[monkey::Lexer]") {

  auto input = R"(let five = 5;
let ten = 10;

let add = fn(x, y) {
  x + y;
};

let result = add(five, ten);
)";

  monkey::Lexer l(input);

  REQUIRE(monkey::TokenTypes::LET == l.NextToken().type);
  REQUIRE(monkey::Ident("five") == l.NextToken());
  REQUIRE(monkey::TokenTypes::ASSIGN == l.NextToken().type);
  REQUIRE(monkey::Int("5") == l.NextToken());
  REQUIRE(monkey::TokenTypes::SEMICOLON == l.NextToken().type);
  REQUIRE(monkey::TokenTypes::LET == l.NextToken().type);
  REQUIRE(monkey::Ident("ten") == l.NextToken());
  REQUIRE(monkey::TokenTypes::ASSIGN == l.NextToken().type);
  REQUIRE(monkey::Int("10") == l.NextToken());
  REQUIRE(monkey::TokenTypes::SEMICOLON == l.NextToken().type);
  REQUIRE(monkey::TokenTypes::LET == l.NextToken().type);
  REQUIRE(monkey::Ident("add") == l.NextToken());
  REQUIRE(monkey::TokenTypes::ASSIGN == l.NextToken().type);
  REQUIRE(monkey::TokenTypes::FUNCTION == l.NextToken().type);
  REQUIRE(monkey::TokenTypes::LPAREN == l.NextToken().type);
  REQUIRE(monkey::Ident("x") == l.NextToken());
  REQUIRE(monkey::TokenTypes::COMMA == l.NextToken().type);
  REQUIRE(monkey::Ident("y") == l.NextToken());
  REQUIRE(monkey::TokenTypes::RPAREN == l.NextToken().type);
  REQUIRE(monkey::TokenTypes::LBRACE == l.NextToken().type);
  REQUIRE(monkey::Ident("x") == l.NextToken());
  REQUIRE(monkey::TokenTypes::PLUS == l.NextToken().type);
  REQUIRE(monkey::Ident("y") == l.NextToken());
  REQUIRE(monkey::TokenTypes::SEMICOLON == l.NextToken().type);
  REQUIRE(monkey::TokenTypes::RBRACE == l.NextToken().type);
  REQUIRE(monkey::TokenTypes::SEMICOLON == l.NextToken().type);
  REQUIRE(monkey::TokenTypes::LET == l.NextToken().type);
  REQUIRE(monkey::Ident("result") == l.NextToken());
  REQUIRE(monkey::TokenTypes::ASSIGN == l.NextToken().type);
  REQUIRE(monkey::Ident("add") == l.NextToken());
  REQUIRE(monkey::TokenTypes::LPAREN == l.NextToken().type);
  REQUIRE(monkey::Ident("five") == l.NextToken());
  REQUIRE(monkey::TokenTypes::COMMA == l.NextToken().type);
  REQUIRE(monkey::Ident("ten") == l.NextToken());
  REQUIRE(monkey::TokenTypes::RPAREN == l.NextToken().type);
  REQUIRE(monkey::TokenTypes::SEMICOLON == l.NextToken().type);
  REQUIRE(monkey::TokenTypes::_EOF == l.NextToken().type);
}

TEST_CASE("other", "[monkey::Lexer]") {
  auto input = R"(
!-/*5;
5 < 10 > 5;
  )";

  monkey::Lexer l(input);

  REQUIRE(monkey::TokenTypes::_EOF == l.NextToken().type);
}
