#include <iostream>
#include <Numbers.h>
#include "Game.h"

int main() {
  cows_and_bulls::Game game;
  std::cout << "Hello, World!\n" << cows_and_bulls::Numbers::nums.size() << "\n"
    << game.GetAvailableNumbersCount() << std::endl;
  std::cout << game.GetMinErasable(cows_and_bulls::Numbers::nums.front()) << "\n";

  game.InsertResult(1023, {2, 0});
  game.InsertResult(8764, {2, 0});
  game.InsertResult(5924, {2, 0});

  std::cout << game.GetAvailableNumbersCount() << std::endl;

  std::cout << game.GetNumbers();

  return 0;
}
