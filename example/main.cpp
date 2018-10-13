#include <iostream>
#include <Numbers.h>
#include "Game.h"

int main() {
  cows_and_bulls::Game game;
  cows_and_bulls::Number magic_number{6549};

  while (game.GetAvailableNumbersCount() > 1) {
    cows_and_bulls::Number number = game.GetNumberToAsk();
    std::cout << "number to ask: " << number << "\n";
    cows_and_bulls::Result result = magic_number.GetResultFor(number);
    std::cout << number << " -> " << result << "\n";
    game.InsertResult(number, result);
    std::cout << "[" << game.GetAvailableNumbersCount() << "] " << "Nums: " << game.GetNumbers() << std::endl;
  }
  return 0;
}
