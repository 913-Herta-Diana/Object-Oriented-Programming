#include "dishwash.h"


double DishWasher::consumedElectricy()
{
	return (double)stoi(consumedElectricityPerHour)*washingCycleLength*8;
}

string DishWasher::toString()
{
	std::string newString;
	newString += "ID: ";
	newString += id;
	newString += " | ";
	newString += "weight: ";
	newString += to_string(weight);
	newString += " | ";
	newString += "Cycle length: ";
	newString += to_string(washingCycleLength);
	newString += " | ";
	newString += "Energy consumed/hour: ";
	newString += consumedElectricityPerHour;
	return newString;
}

double DishWasher::getWashingLength() const
{
	return this->washingCycleLength;
}

string DishWasher::getConsumerElectricity() const
{
	return this->consumedElectricityPerHour;
}


