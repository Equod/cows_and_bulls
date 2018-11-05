//
// Created by illya on 25/09/18.
//

#include "Game.h"

#include <algorithm>
#include <Game.h>
#include <random>
#include "Number.h"
#include "Numbers.h"

using cows_and_bulls::Game;
using cows_and_bulls::Number;
using cows_and_bulls::Numbers;
using cows_and_bulls::Result;

Game::Game() noexcept :
  available_numbers(Numbers::nums.begin(), Numbers::nums.end()), mt(rd())
{}

Number Game::GetNumberToAsk() const noexcept {
  if (available_numbers.size() != Numbers::size()) {
    std::array<uint64_t, Numbers::max()> erasable{};

    #pragma omp parallel for
    for (auto it = Numbers::nums.begin(); it < Numbers::nums.end(); ++it) {
      erasable[it->GetAsSingleNum()] =
          (GetMinErasable(*it) << 32 | (available_numbers.find(*it) != available_numbers.end()));
    };

    std::vector<Number> candidates;
    uint64_t max_val = 0;
    for (auto it = erasable.begin(); it != erasable.end(); ++it) {
      if (*it == max_val && max_val > 0) {
        candidates.emplace_back(std::distance(erasable.begin(), it));
      } else if (*it > max_val) {
        max_val = *it;
        candidates = {Number(static_cast<size_t>(std::distance(erasable.begin(), it)))};
      }
    }
    if (candidates.size() == 1) {
      return candidates[0];
    }
    if (!candidates.empty()) {
      std::uniform_int_distribution<size_t> dist(0, candidates.size() - 1);
      return candidates[dist(mt)];
    }
  }
  std::uniform_int_distribution<size_t> dist(0, FirstNumbers::size() - 1);
  return Number(FirstNumbers::idx[dist(mt)]);
}

size_t Game::GetMinErasable(const Number& number) const noexcept {
  std::map<Result, size_t> res_map;
  for (const auto& num : available_numbers) {
    res_map[num.GetResultFor(number)]++;
  }
  return available_numbers.size()
      - std::min_element(res_map.begin(), res_map.end(), [](const auto& lhs, const auto& rhs) {
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
