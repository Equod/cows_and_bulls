//
// Created by illya on 02/10/18.
//

#ifndef COWS_AND_BULLS_RESULT_H
#define COWS_AND_BULLS_RESULT_H

#include <map>

namespace cows_and_bulls {

class Result : public std::pair<size_t, size_t> {
 public:
  using std::pair<size_t, size_t>::pair;
  size_t GetBullCount() const noexcept {
    return first;
  }
  size_t GetCowCount() const noexcept {
    return second;
  }
};

}

#endif // COWS_AND_BULLS_RESULT_H
