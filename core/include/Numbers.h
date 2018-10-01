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

struct Numbers {
  static constexpr auto nums = utils::GetArray<
      #include "numbers.dat"
          >();
  };
}


#endif // COWS_AND_BULLS_NUMBERS_H
