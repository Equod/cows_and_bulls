#include <iostream>
#include <Numbers.h>
#include "Game.h"

int main() {
  cows_and_bulls::Game game;

  // 1724

  std::cout << "number to ask: " << game.GetNumberToAsk() << "\n";
  game.InsertResult(1234, {2, 1});
  std::cout << "Nums: " << game.GetAvailableNumbersCount() << std::endl;
  std::cout << "number to ask: " << game.GetNumberToAsk() << "\n";
  game.InsertResult(2035, {0, 1});
  std::cout << "Nums: " << game.GetAvailableNumbersCount() << std::endl;
  std::cout << game.GetNumbers() << "\n";
  std::cout << "number to ask: " << game.GetNumberToAsk() << "\n";
  game.InsertResult(1346, {1, 1});
  std::cout << "Nums: " << game.GetAvailableNumbersCount() << std::endl;
  std::cout << game.GetNumbers() << "\n";
  std::cout << "number to ask: " << game.GetNumberToAsk() << "\n";
  game.InsertResult(1708, {2, 0});
  std::cout << "Nums: " << game.GetAvailableNumbersCount() << std::endl;
  std::cout << game.GetNumbers() << "\n";
  return 0;
}
