#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <lexer.h>

TEST_CASE("basic", "[monkey::Lexer]") {

  auto input = "=+(){},;";

  monkey::Lexer l(input);

  REQUIRE(monkey::Assign == l.NextToken());
  REQUIRE(monkey::Plus == l.NextToken());
  REQUIRE(monkey::LParen == l.NextToken());
  REQUIRE(monkey::RParen == l.NextToken());
  REQUIRE(monkey::LBrace == l.NextToken());
  REQUIRE(monkey::RBrace == l.NextToken());
  REQUIRE(monkey::Comma == l.NextToken());
  REQUIRE(monkey::Semicolon == l.NextToken());
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

  REQUIRE(monkey::Let == l.NextToken());
  REQUIRE(monkey::Ident("five") == l.NextToken());
  REQUIRE(monkey::Assign == l.NextToken());
  REQUIRE(monkey::Int("5") == l.NextToken());
  REQUIRE(monkey::Semicolon == l.NextToken());
  REQUIRE(monkey::Let == l.NextToken());
  REQUIRE(monkey::Ident("ten") == l.NextToken());
  REQUIRE(monkey::Assign == l.NextToken());
  REQUIRE(monkey::Int("10") == l.NextToken());
  REQUIRE(monkey::Semicolon == l.NextToken());
  REQUIRE(monkey::Let == l.NextToken());
  REQUIRE(monkey::Ident("add") == l.NextToken());
  REQUIRE(monkey::Assign == l.NextToken());
  REQUIRE(monkey::Function == l.NextToken());
  REQUIRE(monkey::LParen == l.NextToken());
  REQUIRE(monkey::Ident("x") == l.NextToken());
  REQUIRE(monkey::Comma == l.NextToken());
  REQUIRE(monkey::Ident("y") == l.NextToken());
  REQUIRE(monkey::RParen == l.NextToken());
  REQUIRE(monkey::LBrace == l.NextToken());
  REQUIRE(monkey::Ident("x") == l.NextToken());
  REQUIRE(monkey::Plus == l.NextToken());
  REQUIRE(monkey::Ident("y") == l.NextToken());
  REQUIRE(monkey::Semicolon == l.NextToken());
  REQUIRE(monkey::RBrace == l.NextToken());
  REQUIRE(monkey::Semicolon == l.NextToken());
  REQUIRE(monkey::Let == l.NextToken());
  REQUIRE(monkey::Ident("result") == l.NextToken());
  REQUIRE(monkey::Assign == l.NextToken());
  REQUIRE(monkey::Ident("add") == l.NextToken());
  REQUIRE(monkey::LParen == l.NextToken());
  REQUIRE(monkey::Ident("five") == l.NextToken());
  REQUIRE(monkey::Comma == l.NextToken());
  REQUIRE(monkey::Ident("ten") == l.NextToken());
  REQUIRE(monkey::RParen == l.NextToken());
  REQUIRE(monkey::Semicolon == l.NextToken());
  REQUIRE(monkey::Eof == l.NextToken());
}
