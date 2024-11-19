#include <iostream>
#include <array>
#include <string_view>
#include <vector>

//Desenvolvimento da Quest�o 2 do Quiz do Capitulo 17.X do learncpp.com

class Player
{
private:
	std::string m_name{};
	std::vector<std::string_view> m_potInventory{};
	double m_gold{};

public:
	Player(std::string name, std::vector<std::string_view> potInventory, double gold)
		: m_name{ name }
		, m_potInventory{ potInventory }
		, m_gold{ gold }
	{}



};

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
	constexpr std::array<std::string_view, Type::max> potionName{"Healing", "Mana", "Speed", "Invisibility"};

	static_assert(std::size(potionCost) == Type::max);
	static_assert(std::size(potionName) == Type::max);
}

constexpr std::string_view getPotionName(Potion::Type potion)
{
	return Potion::potionName[potion];
}

std::ostream& operator<<(std::ostream& out, Potion::Type potion)
{
	return out << getPotionName(potion);
}

void shop()
{
	std::cout << "Here are your pots for today!" << '\n';
	for (int i{ 0 }; i < Potion::Type::max; ++i)
	{
		std::cout << i << "- " << static_cast<Potion::Type>(i) << " costs " << Potion::potionCost[i] << '\n';
	}
}

int main()
{
	shop();
	return 0;
}