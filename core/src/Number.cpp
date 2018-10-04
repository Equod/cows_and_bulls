//
// Created by illya on 25/09/18.
//

#include <Number.h>
#include <cmath>
#include "Number.h"

using cows_and_bulls::Number;
using cows_and_bulls::Result;

Result Number::GetResultFor(const Number& other) const noexcept {
  size_t bulls = 0;
  size_t cows = 0;
  for (size_t i = 0; i < size(); ++i) {
    if (at(i) == other[i]) {
      ++bulls;
    }
  }
  for (size_t i = 0; i < size(); ++i) {
    for (size_t j = 0; j < other.size(); ++j) {
      if(i != j && at(i) == other[j]) {
        ++cows;
      }
    }
  }
  return { bulls, cows };
}

size_t Number::GetAsSingleNum() const noexcept {
  size_t result = 0;
  for (size_t i = 0; i < size(); ++i) {
    result += at(i) * (size_t)std::pow(10, size() - 1 - i);
  }
  return result;
}

namespace cows_and_bulls {
std::ostream& operator<<(std::ostream& os, const Number& number) {
  return os << number.GetAsSingleNum();
}

}
