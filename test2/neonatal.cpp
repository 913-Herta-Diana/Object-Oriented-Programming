#include "neonatal.h"

double Neonatal::getAverageGradeNewBorn()
{
	return this->averageGradeNewBorns;
}

bool Neonatal::isEfficient()
{
	return this->averageGradeNewBorns>8.5;
}

string Neonatal::toString()
{
	string newString;
	newString += "NEONATAL:\n";
	newString += "Hospital: ";
	newString += this->getHospital();
	newString += " | ";
	newString += "NbDoctors: ";
	newString += to_string(this->getNbDoctors());
	newString += " | ";
	newString += "AverageGrade: ";
	newString += to_string(this->getAverageGradeNewBorn());
	return newString;
}
