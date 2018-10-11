//
// Created by illya on 26/09/18.
//

#ifndef COWS_AND_BULLS_NUMBERS_H
#define COWS_AND_BULLS_NUMBERS_H

#include <vector>
#include "Number.h"

namespace cows_and_bulls {

template<size_t...N>
struct NumsTemplateImpl {
  static constexpr size_t size() noexcept { return sizeof...(N); }
  static constexpr std::array<Number, size()> nums = { Number(N) ... };
  static constexpr size_t idx[] = { N... };
  static constexpr size_t min() noexcept { return idx[0]; }
  static constexpr size_t max() noexcept { return idx[size() - 1]; }
};

using NumsTemplate = NumsTemplateImpl<
#include "numbers.dat"
>;

struct Numbers {
  static constexpr size_t size() noexcept { return NumsTemplate::size(); }
  static constexpr std::array<Number, NumsTemplate::size()> nums = NumsTemplate::nums;
  static constexpr size_t min() noexcept { return NumsTemplate::min(); }
  static constexpr size_t max() noexcept { return NumsTemplate::max(); }
};

}


#endif // COWS_AND_BULLS_NUMBERS_H
