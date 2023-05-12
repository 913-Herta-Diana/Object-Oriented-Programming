#pragma once
#include "controller.h"
class UserInterface {
private:
	Service service;
public:
	UserInterface(Service service) : service{ service } {};
	void UIadd();
	void UIremove();
	void UIshowSort();
	void UICost();
	void UIStringMatch(string keyword);
	void UIshowAll();
	void runMenu();

};

