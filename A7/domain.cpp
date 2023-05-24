#include "domain.h"
#include <sstream>
#include <utility>
#include <iostream>
#include <vector>
//Trench::Trench(string size, string color, float price, int quantity, string photo)
//{
//	this->size = size;
//	this->color = color;
//	this->price = price;
//	this->quantity = quantity;
//	this->photo = photo;
//}
vector<string> lineSize(const string& str, char delimiter)
{
	vector<string> returning;
	stringstream strstream(str); //turns the string into an in/out stream
	string attribute;
	while (getline(strstream, attribute, delimiter))
		returning.push_back(attribute);
	return returning;
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

void Trench::seeTrench()
{
	system(std::string("start " + getPhoto()).c_str());
}

std::istream& operator>>(std::istream& inputStream, Trench& t)
{
	string eachLine;
	getline(inputStream, eachLine);
	vector<string> attributes = lineSize(eachLine, ',');
	if (attributes.size() != 5)
		return inputStream;
	t.size = attributes[0];
	t.color = attributes[1];
	t.price = stof(attributes[2]);
	t.quantity = stoi(attributes[3]);
	t.photo = attributes[4];
	return inputStream;

}

std::ostream& operator<<(std::ostream& outputStream, const Trench& t)
{
	outputStream << t.size << "," << t.color << "," << t.price << "," << t.quantity << "," << t.photo << "/n";
	return outputStream;
}
