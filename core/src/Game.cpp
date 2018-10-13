//
// Created by illya on 25/09/18.
//

#include "Game.h"

#include <algorithm>
#include <Game.h>
#include "Number.h"
#include "Numbers.h"

using cows_and_bulls::Game;
using cows_and_bulls::Number;
using cows_and_bulls::Numbers;
using cows_and_bulls::Result;

Game::Game() noexcept :
  available_numbers(Numbers::nums.begin(), Numbers::nums.end())
{}

Number Game::GetNumberToAsk() const noexcept {
  std::array<size_t, Numbers::max()> erasable{};
  for(const auto& num : Numbers::nums) {
    erasable[num.GetAsSingleNum()] = GetMinErasable(num);
  }
  return *std::max_element(erasable.begin(), erasable.end());
}

size_t Game::GetMinErasable(const Number& number) const noexcept {
  std::map<Result, size_t> res_map;
  for (const auto& num : available_numbers) {
    res_map[num.GetResultFor(number)]++;
  }
  return available_numbers.size() - std::min_element(res_map.begin(), res_map.end(), [](const auto& lhs, const auto& rhs) {
    return rhs.second < lhs.second;
  })->second;
}

void Game::InsertResultImpl(const Number& number, const Result& result) noexcept {
  for (auto it = available_numbers.begin(); it != available_numbers.end();) {
    if(it->GetResultFor(number) != result) {
      it = available_numbers.erase(it);
    } else {
      ++it;
    }
  }
}

bool Game::InsertResult(const Number& number, const Result& result) noexcept {
  if(number.IsValid() && result.IsValid()) {
    InsertResultImpl(number, result);
    return true;
  }
  return false;
}
