#pragma once
#include "repository.h"
class User {
	Repo repository;
public:
	User(Repo repository) : repository{ repository } {};
	void UIadd();
	void UIdisplayAll();
	void UIshowByTeam();
	void runMenu();
};