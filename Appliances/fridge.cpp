#include "fridge.h"

double Refrigerator::consumedElectricy() 
{
	double x;
	if (electricityUsageClass == "A")
		x = 3;
	else if (electricityUsageClass == "A+")
		x = 2.5;
	else if (electricityUsageClass == "A++")
		x = 2;
	if (hasFreezer == true)
		return x * 30 + 20;
	else
		return x * 30;
}

string Refrigerator::toString()
{
	std::string newString;
	newString += "ID: ";
	newString += id;
	newString += " | ";
	newString += "weight: ";
	newString += to_string(weight);
	newString += " | ";
	newString += "eClass: ";
	newString += electricityUsageClass;
	newString += " | ";
	newString += "freezer: ";
	if (hasFreezer == true)
		newString += "yes";
	else
		newString += "no";
	return newString;
}

string Refrigerator::getElectricityUsageClass() const
{
	return this->electricityUsageClass;
}

bool Refrigerator::getHasFreezer() const
{
	return this->hasFreezer;
}
