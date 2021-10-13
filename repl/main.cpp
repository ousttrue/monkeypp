#include <iostream>
#include <lexer.h>

constexpr auto PROMPT = ">> ";

class Repl {
public:
  void Start() {

    while (true) {
      std::cout << PROMPT;

      std::string s;
      if (!std::getline(std::cin, s)) {
        break;
      }

      monkey::Lexer l(s);
      while (true) {
        auto token = l.NextToken();
        if (token.type == monkey::TokenTypes::_EOF) {
          break;
        }
        std::cout << token << std::endl;
      }
    }
  }
};

int main(int argc, char **argv) {

  std::cout << "This is the Monkey programming language!" << std::endl;
  std::cout << "Feel free to type in commands" << std::endl;

  Repl repl;
  repl.Start();

  return 0;
}
