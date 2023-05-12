// Projects.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "user.h"
#include "repository.h"
#include "controller.h"
#include "domain.h"
#include <iostream>

int main()
{
	Repo repository{};
	Service service{ repository };
	UserInterface ui{ service };
	ui.runMenu();
	return 0;
}

