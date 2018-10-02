#include <iostream>
#include <Numbers.h>
#include "Game.h"

int main() {
  cows_and_bulls::Game game;
  std::cout << "Hello, World!\n" << cows_and_bulls::Numbers::nums.size() << "\n"
    << game.GetAvailableNumbersCount() << std::endl;
  return 0;
}
