#include "domain.h"

Trench::Trench(string size, string color, float price, int quantity, string photo)
{
	this->size = size;
	this->color = color;
	this->price = price;
	this->quantity = quantity;
	this->photo = photo;
}

string Trench::getSize() const
{
	return this->size;
}

string Trench::getColor() const
{
	return this->color;
}

float Trench::getPrice() const
{
	return this->price;
}

int Trench::getQuantity() const
{
	return this->quantity;
}

string Trench::getPhoto() const
{
	return this->photo;
}

void Trench::setQuantity(int newQuantity)
{
	this->quantity = newQuantity;
}
