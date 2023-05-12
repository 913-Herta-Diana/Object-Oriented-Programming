#pragma once
#include <string>
using namespace std;
class Trench {
	string size, color; float price; int quantity; string photo;
public:
	Trench(string size, string color, float price, int quantity, string photo);
	string getSize() const;
	string getColor() const;
	float getPrice() const;
	int getQuantity() const;
	string getPhoto() const;
	void setQuantity(int newQuantity);

};