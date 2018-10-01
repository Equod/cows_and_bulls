#include <iostream>
#include "Game.h"

int main() {
  cows_and_bulls::Game game;
  std::cout << "Hello, World! " << game.GetAvailableNumbersCount() <<  std::endl;
  return 0;
}
