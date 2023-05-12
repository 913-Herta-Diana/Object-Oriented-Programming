#pragma once
#include <string>
class BMI {
	std::string date;
	float value;
public:
	BMI(std::string date, float value) :date{ date }, value{ value } {};
	bool isResultOK() const;
	std::string toString() const;
};