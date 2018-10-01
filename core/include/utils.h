//
// Created by illya on 29/09/18.
//

#ifndef COWS_AND_BULLS_UTILS_H
#define COWS_AND_BULLS_UTILS_H

#include <cstdio>
#include <utility>
#include <array>
#include <tuple>

namespace cows_and_bulls {
namespace utils {

//template<size_t N>
//struct NumberValidator {
//  static constexpr size_t n0 = (N / 1000) % 10;
//  static constexpr size_t n1 = (N / 100) % 10;
//  static constexpr size_t n2 = (N / 10) % 10;
//  static constexpr size_t n3 = N % 10;
//  static constexpr bool value = n0 > 0 && n0 != n1 && n0 != n2 && n0 != n3 && n1 != n2 && n1 != n3 && n2 != n3;
//};

template<size_t N>
struct NumberValidator {
  static constexpr bool value = N % 2 == 0;
};

template<size_t... Idx>
struct SplitSequence;

template<size_t N, size_t T>
struct SplitSequence<N, T> {
  static constexpr size_t head = N;
  using _tail = std::_Index_tuple<T>;
};

template<size_t N, size_t... Idx>
struct SplitSequence<N, Idx...> {
  static constexpr size_t head = N;
  using _tail = std::_Index_tuple<Idx...>;
};

template<typename Ok, typename ToDo>
struct NumberAnalyzer;

template<size_t... Ok, size_t Todo>
struct NumberAnalyzer<std::_Index_tuple<Ok...>, std::_Index_tuple<Todo>> {
  using result = typename std::conditional<NumberValidator<Todo>::value, std::_Index_tuple<Ok..., Todo>,
                                           std::_Index_tuple<Ok...>>::type;
};

template<size_t... Ok, size_t... Todo>
struct NumberAnalyzer<std::_Index_tuple<Ok...>, std::_Index_tuple<Todo...>>
    : std::conditional<NumberValidator<SplitSequence<Todo...>::head>::value,
                       NumberAnalyzer<std::_Index_tuple<Ok..., SplitSequence<Todo...>::head>,
                                    typename SplitSequence<Todo...>::_tail>,
                       NumberAnalyzer<std::_Index_tuple<Ok...>,
                                    typename SplitSequence<Todo...>::_tail>
    >::type {
};

template<typename T>
struct NumberFilterT;

template<size_t... Idx>
struct NumberFilterT<std::_Index_tuple<Idx...>>
    : std::conditional<NumberValidator<SplitSequence<Idx...>::head>::value,
                       NumberAnalyzer<std::_Index_tuple<SplitSequence<Idx...>::head>,
                                    typename SplitSequence<Idx...>::_tail>,
                       NumberAnalyzer<std::_Index_tuple<>, typename SplitSequence<Idx...>::_tail>
    >::type {
};

template<size_t... Idx>
struct NumberFilter : NumberFilterT<std::_Index_tuple<Idx...>> {
};

template<size_t... Idx>
static constexpr std::array<size_t, sizeof...(Idx)> GetArray() {
  return {Idx...};
}

template<typename T>
struct ArrayContainer;

template<size_t... Idx>
struct ArrayContainer<std::_Index_tuple<Idx...>> {
  static constexpr std::array<size_t, sizeof...(Idx)> items{Idx...};
};

template<size_t N>
struct Num {
  static constexpr size_t value = N;
};

template<size_t N>
struct IsOk {
  static constexpr bool value = N % 2 == 0;
};

template<size_t N>
struct CheckNumber {
  using type = typename std::conditional<IsOk<N>::value, std::tuple<Num<N>>, std::tuple<>>::type;

  using pure_type = std::tuple<Num<N>>;
};

template<size_t... Idx>
struct CheckNumbersImpl {
  using type = typename std::__tuple_cat_result<typename CheckNumber<Idx>::type...>::__type;
};

template<typename T>
struct CheckNumbers;

template<size_t... Idx>
struct CheckNumbers<std::integer_sequence<size_t, Idx...>> {
  using type = typename CheckNumbersImpl<Idx...>::type;
};

}

}

#endif // COWS_AND_BULLS
