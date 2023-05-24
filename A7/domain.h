#pragma once
#include <string>

using namespace std;
class Trench {
	string size, color; float price; int quantity; string photo;
public:
	Trench() = default;
	Trench(string size, string color, float price, int quantity, string photo) : size{ size }, color{ color }, price{ price }, quantity{ quantity }, photo{ photo } {};
	string getSize() const;
	string getColor() const;
	float getPrice() const;
	int getQuantity() const;
	string getPhoto() const;
	void setQuantity(int newQuantity);
	void seeTrench();
	friend std::istream& operator>>(std::istream& inputStream, Trench& t);
	friend std::ostream& operator<<(std::ostream& outputStream, const Trench& t);

};