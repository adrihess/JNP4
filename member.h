#ifndef __MEMBER_H__
#define __MEMBER_H__

#include "treasure.h"

using strength_t = int32_t;

template <size_t n>
concept small = n < 25;

namespace
{
	template <size_t N>
	constexpr static size_t fibonacci()
	{
		if constexpr (N > 1)
		{
			return fibonacci<N - 1>() + fibonacci<N - 2>();
		}
		else
		{
			return N;
		}
	}
}

template <typename ValueType, bool IsArmed>
requires integer<ValueType>
struct Adventurer
{
private:
	ValueType treasure;
	ValueType tmp;

public:
	constexpr Adventurer()
			: treasure(0) {}

	constexpr bool isArmed() const
	{
		return false;
	}

	constexpr ValueType pay() const
	{
		return (tmp = treasure) + (treasure = 0);
	}
};

template <typename ValueType>
struct Adventurer<ValueType, true>
{
private:
	ValueType treasure;
	ValueType tmp;
	strength_t strength;

public:
	constexpr Adventurer() = delete;

	constexpr Adventurer(strength_t str)
			: treasure(0), strength(str) {}

	constexpr bool isArmed() const
	{
		return true;
	}

	constexpr strength_t getStrength() const
	{
		return strength;
	}

	constexpr ValueType pay() const
	{
		return (tmp = treasure) + (treasure = 0);
	}
};

template <typename ValueType>
using Explorer = Adventurer<ValueType, false>;

template <typename ValueType, size_t completedExpeditions>
requires integer<ValueType> && small<completedExpeditions>
struct Veteran
{
private:
	ValueType treasure;
	ValueType tmp;
	strength_t strength;

public:
	constexpr Veteran()
			: treasure(0), strength(fibonacci<completedExpeditions>()) {}

	constexpr bool isArmed() const
	{
		return true;
	}

	constexpr strength_t getStrength() const
	{
		return strength;
	}

	constexpr ValueType pay() const
	{
		return (tmp = treasure) + (treasure = 0);
	}
};

#endif // __MEMBER_H__
