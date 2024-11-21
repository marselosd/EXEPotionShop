#ifndef POTION_H
#define POTION_H

#include <array>
#include <string_view>
#include <ostream>

namespace Potion
{
	enum Type
	{
		healing,
		mana,
		speed,
		invisibility,
		max
	};

	constexpr std::array potionCost{ 30,20,40,60 };
	constexpr std::array<std::string_view, Type::max> potionName{ "Healing", "Mana", "Speed", "Invisibility" };

	static_assert(std::size(potionCost) == Type::max);
	static_assert(std::size(potionName) == Type::max);
}

constexpr std::string_view getPotionName(Potion::Type potion);

inline std::ostream& operator<<(std::ostream& out, Potion::Type potion);

#endif