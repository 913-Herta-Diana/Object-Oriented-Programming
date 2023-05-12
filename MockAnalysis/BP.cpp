#include "BP.h"

bool BP::isResultOK() const
{
	return systolic>=90 && systolic<=119 && diastolic>=60 && diastolic<=79;
}

std::string BP::toString() const
{
	std::string stringFormat;
	stringFormat += "BP values> systolic: ";
	stringFormat += std::to_string(systolic);
	stringFormat += ", ";
	stringFormat += "diastolic: ";
	stringFormat += std::to_string(diastolic);
	stringFormat += ", ";
	stringFormat += date;

	return stringFormat;
}
