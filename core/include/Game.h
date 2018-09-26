//
// Created by illya on 25/09/18.
//

#ifndef COWS_AND_BULLS_GAME_H
#define COWS_AND_BULLS_GAME_H

#include <set>
#include "Number.h"

namespace cows_and_bulls {

class Game {
 public:
  Game();
  size_t GetAvailableNumbersCount() const {
    return available_numbers.size();
  }
 private:
  std::set<Number> available_numbers;
};

}

#endif // COWS_AND_BULLS_GAME_H
