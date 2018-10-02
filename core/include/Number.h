//
// Created by illya on 25/09/18.
//

#ifndef COWS_AND_BULLS_NUMBER_H
#define COWS_AND_BULLS_NUMBER_H

#include <array>

namespace cows_and_bulls {

class Number : public std::array<int, 4> {
 public:
  constexpr Number(int n0, int n1, int n2, int n3) noexcept
    : array{n0, n1, n2, n3}
  {}
  constexpr Number(int num) noexcept
    : array{ (num / 1000) % 10, (num / 100) % 10, (num / 10) % 10, num % 10 }
  {}
};

}

#endif // COWS_AND_BULLS_NUMBER_H
