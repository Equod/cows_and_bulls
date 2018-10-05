#include <iostream>
#include <Numbers.h>
#include "Game.h"

int main() {
  cows_and_bulls::Game game;

  // 1724

  game.InsertResult(1023, {2, 0});
  std::cout << "number to ask: " << game.GetNumberToAsk() << "\n";
  game.InsertResult(1245, {1, 2});
  std::cout << "Nums: " << game.GetAvailableNumbersCount() << std::endl;
  std::cout << "number to ask: " << game.GetNumberToAsk() << "\n";
  game.InsertResult(1264, {2, 1});
  std::cout << "Nums: " << game.GetAvailableNumbersCount() << std::endl;
  std::cout << "number to ask: " << game.GetNumberToAsk() << "\n";
  return 0;
}
