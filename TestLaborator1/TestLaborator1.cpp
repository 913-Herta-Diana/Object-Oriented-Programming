#include "domain.h"
#include "repository.h"
#include "user.h"
#include "test.h"
#include <iostream>

int main()
{
    Repo repos;
    User ui{ repos };
    testAdd();
    testTeams();
    ui.runMenu();
}

