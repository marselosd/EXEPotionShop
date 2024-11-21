#ifndef SHOP_H
#define SHOP_H

#include "potion.h"
#include "player.h"

void shop()
{
	std::cout << "Here are our pots for today!" << '\n';
	for (int i{ 0 }; i < Potion::Type::max; ++i)
	{
		std::cout << i << "- " << static_cast<Potion::Type>(i) << " costs " << Potion::potionCost[i] << '\n';
	}
}

void buyPot(Player& player)
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

#endif