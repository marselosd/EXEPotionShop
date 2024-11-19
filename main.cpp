#include <iostream>
#include <array>
#include <string_view>
#include <vector>
#include <algorithm>
#include <cctype>

//Desenvolvimento da Questão 2 do Quiz do Capitulo 17.X do learncpp.com

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

constexpr std::string_view getPotionName(Potion::Type potion)
{
	return Potion::potionName[potion];
}

std::ostream& operator<<(std::ostream& out, Potion::Type potion)
{
	return out << getPotionName(potion);
}

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

	const std::string_view getName() const { return m_name; }
	const std::vector<std::string_view> getPotInventory() const { return m_potInventory; }
	const double getGold() const { return m_gold; }
	
	void setName(const std::string& name) { this->m_name = name; }
	void setPotInventory(int index)
	{
		if (index >= 0 && index < static_cast<int>(Potion::Type::max))
		{
			this->m_potInventory.push_back(getPotionName(static_cast<Potion::Type>(index)));
		}
		else
		{
			std::cout << "ERROR! INVALID INPUT FROM POTION ID" << '\n';
		}
	}
	void setGold(double gold) { this->m_gold = gold; }

	void introduction()
	{
		std::cout << "Great! Welcome to my shop " << m_name << "! Buy anything you want (or that you can pay hehe)" << '\n' << "Total Gold: " << m_gold << '\n';
	}

	void goodbye()
	{
		std::cout << "Thanks for stoping by " << m_name << "!" << '\n';
	}


};

void shop()
{
	std::cout << "Here are your pots for today!" << '\n';
	for (int i{ 0 }; i < Potion::Type::max; ++i)
	{
		std::cout << i << "- " << static_cast<Potion::Type>(i) << " costs " << Potion::potionCost[i] << '\n';
	}
}

void buyPot( Player& player)
{
	std::cout << "Did you like any? Select the number of the one you want!: ";
	int selection;
	std::cin >> selection;

	if (Potion::potionCost[selection] > player.getGold())
	{
		std::cout << "You dont have enough gold for this one buddy! " << '\n';
	}
	else if (selection < 0 || selection > Potion::Type::max)
	{
		std::cout << "You misstyped the selection number buddy! " << '\n';
	}
	else
	{
		player.setPotInventory(selection);
		std::cout << "Great! Come buy again!" << '\n';
	}
}

void showInventory(const Player& player)
{
	for (const auto& e : player.getPotInventory())
	{
		std::cout << e << ' ';
	}
	std::cout << '\n';
}

int main()
{
	std::cout << "What is your name stranger? ";
	std::string userName{};
	std::cin >> userName;

	std::cout << "I see, and how many gold coins do you have? ";
	double goldCoins{};
	std::cin >> goldCoins;

	std::vector<std::string_view> inventory{};

	Player player(userName, inventory, goldCoins);

	player.introduction();
	shop();
	buyPot(player);
	showInventory(player);
	player.goodbye();

	return 0;
}