#include "player.h"

//CONSTRUTOR
Player::Player(std::string name, std::vector<std::string_view> potInventory, double gold)
	: m_name{ name }
	, m_potInventory{ potInventory }
	, m_gold{ gold }
{}

//GETTERS
const std::string_view Player::getName() const { return m_name; }
const std::vector<std::string_view> Player::getPotInventory() const { return m_potInventory; }
const double Player::getGold() const { return m_gold; }

//SETTERS
void Player::setName(const std::string& name) { this->m_name = name; }
void Player::setPotInventory(int index)
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
void Player::setGold(double gold) { this->m_gold = gold; }

//MENSAGEM DE INTRODUÇÃO
void Player::introduction()
{
	std::cout << "Great! Welcome to my shop " << m_name << "! Buy anything you want (or that you can pay hehe)" << '\n' << "Total Gold: " << m_gold << '\n';
}

//MENSAGEM DE ADEUS
void Player::goodbye()
{
	std::cout << "Thanks for stoping by " << m_name << "!" << '\n';
}