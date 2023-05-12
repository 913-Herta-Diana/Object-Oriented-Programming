#pragma once
#include<string>
class BP {
	std::string date;
	int systolic, diastolic;
	public:
		BP(std::string date, int systolic, int diastolic) : date{ date }, systolic{ systolic }, diastolic{ diastolic } {};
		bool isResultOK() const;
		std::string toString() const;
};