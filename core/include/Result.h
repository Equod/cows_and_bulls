//
// Created by illya on 02/10/18.
//

#ifndef COWS_AND_BULLS_RESULT_H
#define COWS_AND_BULLS_RESULT_H

#include <map>
#include <ostream>

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
  friend std::ostream& operator<<(std::ostream& os, const Result& result) {
    os << "{" << result.first << ", " << result.second << " }\n";
    return os;
  }
  bool IsValid() const noexcept{
    return GetBullCount() + GetCowCount() <= 4 &&
        (GetBullCount() != 3 || GetCowCount() != 1);
  }
};

}

#endif // COWS_AND_BULLS_RESULT_H
