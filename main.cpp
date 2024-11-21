#include "shop.h"

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