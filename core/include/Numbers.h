//
// Created by illya on 26/09/18.
//

#ifndef COWS_AND_BULLS_NUMBERS_H
#define COWS_AND_BULLS_NUMBERS_H

#include <vector>
#include "Number.h"
#include <utility>

namespace cows_and_bulls {

template<size_t...N>
struct NumsTemplateImpl {
  static constexpr size_t size() noexcept { return sizeof...(N); }
  static constexpr std::array<Number, size()> nums = { Number(N) ... };
};

using NumsTemplate = NumsTemplateImpl<
#include "numbers.dat"
>;

struct Numbers {
  static constexpr std::array<Number, NumsTemplate::size()> nums = NumsTemplate::nums;
};

}


#endif // COWS_AND_BULLS_NUMBERS_H
