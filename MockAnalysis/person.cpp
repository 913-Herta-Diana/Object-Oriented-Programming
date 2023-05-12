#include "person.h"


void Person::addAnalysis(Analysis& analysisToAdd)
{
	documents.push_back(analysisToAdd);
}

std::vector<Analysis> Person::getAllAnalyses() const
{
	return documents;
}

std::vector<Analysis> Person::getAnalysesByMonth(int month) const
{
	std::vector<Analysis> analysesByMonth;
	for (auto current : getAllAnalyses())
		if (std::to_string(month) == current.getDate().substr(5, 2))
			analysesByMonth.push_back(current);
	return analysesByMonth;
}

bool Person::isIll(int month) const
{
	std::vector<Analysis> analysesIll;
	for (auto current : getAnalysesByMonth(month))
		if (current.isResultOK() == 0)
			return false;
	return true;
}

std::vector<Analysis> Person::getAnalysesBetweenDates(std::string date1, std::string date2) const
{
	std::vector<Analysis> analysesByDates;
	for (auto current : getAllAnalyses())
		if (current.getDate() >= date1 && current.getDate() <= date2)
			analysesByDates.push_back(current);
	return analysesByDates;
}

void Person::writeToFile(std::string filename, std::string date1, std::string date2)
{
	std::vector<Analysis> analysesByDates=getAnalysesBetweenDates(date1,date2);
	std::ofstream fout(filename);
	for (auto current : analysesByDates)
		fout << current.toString() << "\n";

}

void Person::populate()
{
	BMI bmi1("2022.01.01", 22.5);
	BMI bmi2("2022.02.01", 25.0);

	// Create two BP objects
	BP bp1("2022.03.01", 120, 80);
	BP bp2("2022.04.01", 130, 85);

	// Add the objects to the documents vector
	addAnalysis(bmi1);
}

