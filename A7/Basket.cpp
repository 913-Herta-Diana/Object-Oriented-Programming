#include "Basket.h"


Basket::Basket()
{
	this->current = 0;
}

vector<Trench> Basket::getBasket()
{
	return this->basket;
}

void Basket::add(const Trench& trench)
{
	this->basket.push_back(trench);
}

Trench Basket::getCurrentTrench()
{
	if (this->current == this->basket.size())
		this->current = 0;
	return this->basket[this->current];
	return Trench{};
}

void Basket::see()
{
	if (this->basket.size() == 0)
		return;
	this->current = 0;
	Trench currentTrench = this->getCurrentTrench();
	currentTrench.seeTrench();
}

void Basket::next()
{
	if (this->basket.size() == 0)
		return;
	this->current++;
	Trench currentTrench = this->getCurrentTrench();
	currentTrench.seeTrench();
}

bool Basket::isEmpty()
{
	return this->basket.size() == 0;
}