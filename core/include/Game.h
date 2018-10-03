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
  Game() noexcept;
  size_t GetAvailableNumbersCount() const noexcept {
    return available_numbers.size();
  }
  const Number& GetNumberToAsk() const noexcept;
  size_t GetMinErasable(const Number& number) const noexcept;
  void InsertResult(const Number& number, const Result& result);
  const std::set<Number>& GetNumbers() const {
    return available_numbers;
  }
 private:
  std::set<Number> available_numbers;
};

inline std::ostream& operator << (std::ostream& stream, const std::set<Number>& numbers) {
  stream << "{ ";
  for (const auto& number : numbers) {
    stream << number << " ";
  }
  return stream << "}";
}

}

#endif // COWS_AND_BULLS_GAME_H
