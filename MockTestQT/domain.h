#pragma once

#include <string>

using namespace std;

class Car {

private:
	string manufacturer_name;
	string model;
	int year_of_fabrication;
	string colour;
public:
	Car(string manufacturer_name, string model, int year_of_fabrication, string colour);
	Car() = default;
	string GetName();
	string GetModel();
	int GetYear();
	string GetColour();
};