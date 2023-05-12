#include "domain.h"

Player::Player(string name, string nationality, string team, int goals)
{
	this->name = name;
	this->nationality = nationality;
	this->team = team;
	this->goals = goals;
}

string Player::getName()
{
	return this->name;
}

string Player::getNationality()
{
	return this->nationality;
}

string Player::getTeam()
{
	return this->team;
}

int Player::getGoals()
{
	return this->goals;
}
