//
// Created by illya on 25/09/18.
//

#ifndef COWS_AND_BULLS_NUMBER_H
#define COWS_AND_BULLS_NUMBER_H

#include <array>
#include <ostream>
#include "Result.h"

namespace cows_and_bulls {

class Number : public std::array<size_t, 4> {
 public:
  constexpr Number(size_t n0, size_t n1, size_t n2, size_t n3) noexcept
    : array{n0, n1, n2, n3}
  {}
  constexpr Number(size_t num) noexcept
    : array{ (num / 1000) % 10, (num / 100) % 10, (num / 10) % 10, num % 10 }
  {}
  template<size_t N>
  constexpr Number() noexcept
    : array{ (N / 1000) % 10, (N / 100) % 10, (N / 10) % 10, N % 10 }
  {}
  Result GetResultFor(const Number& other) const noexcept;
  size_t GetAsSingleNum() const noexcept;
  friend std::ostream& operator<<(std::ostream& os, const Number& number);
};

}

#endif // COWS_AND_BULLS_NUMBER_H
