#pragma once
#include <string>
using namespace std;
class Validator {
public: 
	static bool validateSize(string size);
	static float validatePrice(string price);
	static int validateQuantity(string quantity);
	static bool validatePhoto(string photo);

//string size, string color, float price, int quantity, string photo)
};