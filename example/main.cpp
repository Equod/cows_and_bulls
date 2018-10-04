#include <iostream>
#include <Numbers.h>
#include "Game.h"

int main() {
  cows_and_bulls::Game game;
  std::cout << "Hello, World!\n" << cows_and_bulls::Numbers::nums.size() << "\n"
    << game.GetAvailableNumbersCount() << std::endl;
  std::cout << game.GetMinErasable(cows_and_bulls::Numbers::nums.front()) << "\n";

  // 1724

  std::cout << cows_and_bulls::Number(1724).GetAsSingleNum() << "\n";

  game.InsertResult(1023, {2, 0});

  std::cout << game.GetAvailableNumbersCount() << std::endl;
  std::cout << game.GetNumbers() << "\n";

  game.InsertResult(8764, {2, 0});

  std::cout << "number to ask: " << game.GetNumberToAsk() << "\n";

  std::cout << game.GetAvailableNumbersCount() << std::endl;
  std::cout << game.GetNumbers() << "\n";

  game.InsertResult(1067, {1, 1});


  std::cout << game.GetAvailableNumbersCount() << std::endl;
  std::cout << game.GetNumbers() << "\n";

  std::cout << cows_and_bulls::Number(1724).GetResultFor(2471) << "\n";

  std::cout << "number to ask: " << game.GetNumberToAsk() << "\n";

  return 0;
}
