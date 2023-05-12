#pragma once
#include "BP.h"
#include "BMI.h"
class Analysis {
protected:
	std::string date;
public:
	Analysis(std::string date) : date{ date } {};
	std::string getDate() const;
	virtual bool isResultOK() const = 0;
	virtual std::string toString() const = 0;
};