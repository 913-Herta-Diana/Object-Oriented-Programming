#pragma once
#include "repository.h"
class Service {
	Repo repository;
	vector<Trench> basket;
public:
	Service(Repo repository);
	bool SVadd(Trench newTrench);
	bool SVremove(Trench removedTrench);
	bool SVupdate(Trench updatedTrench);
	vector<Trench> SVshowAll();
	vector<Trench> SVshowBySize(string size);
	vector<Trench> SVgetBasket();
	void SVaddToBasket(Trench addedTrench); 
	float SVseeTotalPrice();


};