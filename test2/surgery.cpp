#include "surgery.h"

int Surgery::getnbPatients()
{
	return this->nbPatients;
}

bool Surgery::isEfficient()
{
	return (double)(this->nbPatients / this->nbDoctors) >= 2;
}

string Surgery::toString()
{
	string newString;
	newString += "SURGERY:\n";
	newString += "Hospital: ";
	newString += this->getHospital();
	newString += " | ";
	newString += "NbDoctors: ";
	newString += to_string(this->getNbDoctors());
	newString += " | ";
	newString += "NbPatients: ";
	newString += to_string(this->getnbPatients());
	return newString;
}
