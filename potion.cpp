#include "potion.h"

#include <iostream>
#include <string>

constexpr std::string_view getPotionName(Potion::Type potion)
{
	return Potion::potionName[potion];
}

inline std::ostream& operator<<(std::ostream& out, Potion::Type potion)
{
	return out << getPotionName(potion);
}