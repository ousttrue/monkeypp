#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <lexer.h>

TEST_CASE("basic", "[monkey::Lexer]") {

  auto input = "=+(){},;";

  monkey::Lexer l(input);

  REQUIRE(monkey::Token{monkey::TokenTypes::ASSIGN} == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::PLUS} == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::LPAREN} == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::RPAREN} == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::LBRACE} == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::RBRACE} == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::COMMA} == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::SEMICOLON} == l.NextToken());
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

  REQUIRE(monkey::Token{monkey::TokenTypes::LET} == l.NextToken());
  REQUIRE(monkey::Token::Ident("five") == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::ASSIGN} == l.NextToken());
  REQUIRE(monkey::Token::Int("5") == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::SEMICOLON} == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::LET} == l.NextToken());
  REQUIRE(monkey::Token::Ident("ten") == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::ASSIGN} == l.NextToken());
  REQUIRE(monkey::Token::Int("10") == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::SEMICOLON} == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::LET} == l.NextToken());
  REQUIRE(monkey::Token::Ident("add") == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::ASSIGN} == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::FUNCTION} == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::LPAREN} == l.NextToken());
  REQUIRE(monkey::Token::Ident("x") == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::COMMA} == l.NextToken());
  REQUIRE(monkey::Token::Ident("y") == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::RPAREN} == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::LBRACE} == l.NextToken());
  REQUIRE(monkey::Token::Ident("x") == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::PLUS} == l.NextToken());
  REQUIRE(monkey::Token::Ident("y") == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::SEMICOLON} == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::RBRACE} == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::SEMICOLON} == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::LET} == l.NextToken());
  REQUIRE(monkey::Token::Ident("result") == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::ASSIGN} == l.NextToken());
  REQUIRE(monkey::Token::Ident("add") == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::LPAREN} == l.NextToken());
  REQUIRE(monkey::Token::Ident("five") == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::COMMA} == l.NextToken());
  REQUIRE(monkey::Token::Ident("ten") == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::RPAREN} == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::SEMICOLON} == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::_EOF} == l.NextToken());
}

TEST_CASE("other", "[monkey::Lexer]") {
  auto input = R"(
!-/*5;
5 < 10 > 5;
  )";

  monkey::Lexer l(input);

  REQUIRE(monkey::Token{monkey::TokenTypes::BANG} == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::MINUS} == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::SLASH} == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::ASTERISK} == l.NextToken());
  REQUIRE(monkey::Token::Int("5") == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::SEMICOLON} == l.NextToken());
  REQUIRE(monkey::Token::Int("5") == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::LT} == l.NextToken());
  REQUIRE(monkey::Token::Int("10") == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::GT} == l.NextToken());
  REQUIRE(monkey::Token::Int("5") == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::SEMICOLON} == l.NextToken());
  REQUIRE(monkey::Token{monkey::TokenTypes::_EOF} == l.NextToken());
}
