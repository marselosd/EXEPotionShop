#ifndef PLAYER_H
#define PLAYER_H

#include "potion.cpp"
#include <vector>
#include <string>
#include <iostream>

class Player
{

private:

	//VARIAVEIS PLAYER
	std::string m_name{};
	std::vector<std::string_view> m_potInventory{};
	double m_gold{};

public:

	//CONSTRUTOR
	Player(std::string name, std::vector<std::string_view> potInventory, double gold);

	//GETTERS
	const std::string_view getName() const;
	const std::vector<std::string_view> getPotInventory() const;
	const double getGold() const;

	//SETTERS
	void setName(const std::string& name);
	void setPotInventory(int index);
	void setGold(double gold);

	//MENSAGEM DE INTRODUÇÃO
	void introduction();
	//MENSAGEM DE ADEUS
	void goodbye();


};

#endif
