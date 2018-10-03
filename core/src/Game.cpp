//
// Created by illya on 25/09/18.
//

#include "Game.h"

#include <algorithm>
#include "Numbers.h"

using cows_and_bulls::Game;
using cows_and_bulls::Number;
using cows_and_bulls::Numbers;

Game::Game() noexcept :
  available_numbers(Numbers::nums.begin(), Numbers::nums.end())
{}

const Number& Game::GetNumberToAsk() const noexcept {
  // TODO: return the correct type
  return *available_numbers.begin();
}

size_t Game::GetMinErasable(const Number& number) const noexcept {
  std::map<Result, size_t> res_map;
  for (const auto& num : available_numbers) {
    res_map[num.GetResultFor(number)]++;
  }
  return std::min_element(res_map.begin(), res_map.end(), [](const auto& rhs, const auto& lhs) {
    return lhs.second < rhs.second;
  })->second;
}

void cows_and_bulls::Game::InsertResult(const Number& number, const cows_and_bulls::Result& result) {
  for (auto it = available_numbers.begin(); it != available_numbers.end();) {
    if(it->GetResultFor(number) != result) {
      it = available_numbers.erase(it);
    } else {
      ++it;
    }
  }
}
