#pragma once
#include "token.h"
#include <ostream>
#include <string_view>

namespace monkey {



inline std::ostream &operator<<(std::ostream &os, const Token &t) {
  os << t.type;
  if (!t.value.empty()) {
    os << ": " << t.value;
  }
  return os;
}

class Lexer {
  std::string_view _input;
  std::string_view::iterator _it;

public:
  Lexer(std::string_view input);
  Token NextToken();

private:
  Token ReadIdentifier();
  void SkipWhiteSpace();
  Token ReadInt();
  char Peek() const;
};
} // namespace monkey