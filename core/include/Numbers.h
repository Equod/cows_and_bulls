//
// Created by illya on 26/09/18.
//

#ifndef COWS_AND_BULLS_NUMBERS_H
#define COWS_AND_BULLS_NUMBERS_H

#include <vector>
#include "Number.h"
#include <utility>
#include "utils.h"

namespace cows_and_bulls {

template<size_t... Idx>
struct NumbersImpl {
  static constexpr std::array<Number, sizeof...(Idx)> nums = { Number(Idx) ... };
};

using Numbers = NumbersImpl<
#include "numbers.dat"
>;

}


#endif // COWS_AND_BULLS_NUMBERS_H
