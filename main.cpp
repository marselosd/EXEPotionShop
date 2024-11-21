#include "shop.h"
#include <cctype>

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

	while(true)
	{
		shop();
		buyPot(player);

		std::cout << "Go again? Y or N: ";
		char answer{};
		std::cin >> answer;
		char lowanswer = static_cast<char>(std::tolower(answer));

		if (lowanswer == 'y')
		{
			std::cout << '\n';
			continue;
		}
		else if (lowanswer == 'n')
		{
			std::cout << '\n';
			break;
		}
		else
		{
			std::cout << '\n';
			std::cout << "ERROR, WRONG INPUT";
			break;
		}
	}

	showInventory(player);
	player.goodbye();

	return 0;
}