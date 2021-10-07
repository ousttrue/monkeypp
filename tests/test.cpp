#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <lexer.h>

TEST_CASE("lexer", "[monkey]") {

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
