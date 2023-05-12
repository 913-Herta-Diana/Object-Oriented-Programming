#include "BMI.h"

bool BMI::isResultOK() const
{
	return value>=18.5 && value<=25;
}

std::string BMI::toString() const
{
	std::string stringFormat;
	stringFormat += "BMI value: ";
	stringFormat += std::to_string(value);
	stringFormat += ", ";
	stringFormat += date;

	return stringFormat;
}
