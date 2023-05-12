#pragma once
#include "repository.h"
class UserService {
	Repo repository;
	vector<Trench> basket;
public:
	UserService(Repo repository);
	vector<Trench> showBySize(string size);
	void addToBasket();
};