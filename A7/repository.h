#pragma once
#include "domain.h"
#include <vector>
#include <exception>
#include <algorithm>

class Repo {
	vector<Trench> repo;
	string filename;
	
public:
	Repo();
	bool addTrench(Trench newTrench);
	bool removeTrench(Trench deletedTrench);
	bool updateTrench(Trench updatedTrench);
	vector<Trench> showAll();
	void populate();
private:
	void getFromFile();
	void saveToFile();


};