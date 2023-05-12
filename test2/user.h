#pragma once
#include "controller.h"
#include "neonatal.h"
#include "surgery.h"
class User
{
	Controller service;
public:
	User(Controller service) : service{ service } {};
	void UIadd();
	void UIshowAll();
	void UIshowEfficient();
	void UIsaveToFile();
	void runMenu();
};