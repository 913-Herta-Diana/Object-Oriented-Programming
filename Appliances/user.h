#pragma once
#include "controller.h"
#include <iostream>
#include <vector>

#include "fridge.h"
#include "dishwash.h"
class User {
	Controller service;
public:
	User(Controller service) : service{ service } {};
	void UIadd();
	void UIshowAll();
	void UIshowAllByWeight();
	void UIsaveToFile();
	void runMenu();
};