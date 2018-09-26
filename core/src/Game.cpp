//
// Created by illya on 25/09/18.
//

#include "Game.h"

using cows_and_bulls::Game;
using cows_and_bulls::Number;

Game::Game() {
  for(int i = 1; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      for (int k = 0; k < 10; ++k) {
        for (int l = 0; l < 10; ++l) {
          if (i != j && i != k && i != l && j != k && j != l && k != l) {
            available_numbers.emplace(i, j, k, l);
          }
        }
      }
    }
  }
}
