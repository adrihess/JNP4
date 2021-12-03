#ifndef __TREASURE_H__
#define __TREASURE_H__

#include <iostream>

using std::is_integral;

template <typename T>
concept integer = is_integral<T>::value;

template <typename ValueType, bool IsTrapped>
struct Treasure
{
  // TODO
};

#endif // __TREASURE_H__
