#ifndef __TREASURE_H__
#define __TREASURE_H__

#include <iostream>

using std::is_integral;

template <typename T>
concept integer = is_integral<T>::value;

template <typename ValueType, bool IsTrapped>
struct Treasure
{
private:
  ValueType value;
  ValueType tmp;

public:
  constexpr Treasure(ValueType val)
      : value(val) {}

  constexpr ValueType evaluate()
  {
    return value;
  }

  constexpr ValueType getLoot()
  {
    return (tmp = value) + (value = 0);
  }

  // TODO nie wiem, czy pole IsTrapped trzeba jakoś specjalie oznaczać
};

// TODO SafeTreasure<ValueType>

// TODO TrappedTreasure<ValueType>

#endif // __TREASURE_H__
