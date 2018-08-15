/**
 * These templates can reverse iterables like std::vectors
 *
 * Note: This code requires C++14
 * Source: https://stackoverflow.com/questions/8542591/c11-reverse-range-based-for-loop
 */

#ifndef REVERSEDITERABLE_H
#define REVERSEDITERABLE_H
#include <iterator>

template <typename T>
struct reversion_wrapper { T& iterable; };

template <typename T>
auto begin (reversion_wrapper<T> w) { return std::rbegin(w.iterable); }

template <typename T>
auto end (reversion_wrapper<T> w) { return std::rend(w.iterable); }

template <typename T>
reversion_wrapper<T> reverse (T&& iterable) { return { iterable }; }

#endif
