#pragma once
#include "MedicalAnalysis.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>

class Person {
	std::string name;
	std::vector<Analysis> documents;
public:
	Person(std::string name) : name{ name } { populate(); };
	void addAnalysis(Analysis& analysisToAdd);
	std::vector<Analysis> getAllAnalyses() const;
	std::vector<Analysis> getAnalysesByMonth(int month) const;
	bool isIll(int month) const;
	std::vector<Analysis> getAnalysesBetweenDates(std::string date1, std::string date2) const;
	void writeToFile(std::string filename, std::string date1, std::string date2);
	void populate();
};
