#include "test.h"
#include "domain.h"
#include "repository.h"
#include "user.h"
#include "exception.h"
#include <assert.h>
#include <iostream>
using namespace std;

void testDomain()
{
	Trench t1("a", "b", 1, 1, "h");
	assert(t1.getSize() == "a");
	assert(t1.getColor() == "b");
	assert(t1.getPrice() == 1);
	assert(t1.getQuantity() == 1);
	assert(t1.getPhoto() == "h");
	t1.setQuantity(20);
	assert(t1.getQuantity() == 20);
	cout << "Testing domain...\n";
}

void testRepo()
{
	cout << "\n\nTesting repo..\n";
	Trench t1("a", "b", 1, 1, "h");
	Trench t2("d", "e", 2, 7, "t");
	Trench t3("d", "e", 3, 7, "t");
	Repo repository1;
	assert(repository1.addTrench(t1) == 1);
	assert(repository1.addTrench(t2) == 1);
	assert(repository1.addTrench(t3) == 0);
	cout << "Testing add...\n";

	assert(repository1.removeTrench(t3) == 0);
	assert(repository1.removeTrench(t1) == 1);
	try {
		repository1.removeTrench(t1);
	}
	catch (AppException& repoException) {
		assert(repoException.getMessage() == "Inexistend item!\n");
	}
	cout << "Testing remove...\n";


	repository1.addTrench(t1);
	Trench t4("a", "new", 10, 10, "h");
	Trench t5("x", "x", 3, 3, "link");
	assert(repository1.updateTrench(t4) == 1);
	try {
		repository1.updateTrench(t5);
	}
	catch (AppException& repoException) {
		assert(repoException.getMessage() == "Inexistent item!\n");
	}
	cout << "Testing update...\n";

	
}

void testServiceADM()
{
	cout << "\n\nTesting Admin service..\n";
	Trench t1("a", "b", 1, 1, "h");
	Trench t2("d", "e", 2, 7, "t");
	Trench t3("d", "e", 3, 7, "t");
	Repo repo1;
	Service serv1{ repo1 };
	assert(serv1.SVadd(t1) == 1);
	assert(serv1.SVadd(t2) == 1);
	assert(serv1.SVadd(t3) == 0);
	cout << "Testing add...\n";

	assert(serv1.SVremove(t3) == 0);
	assert(serv1.SVremove(t1) == 1);
	try {
		serv1.SVremove(t1);
	}
	catch (AppException& repoException) {
		assert(repoException.getMessage() == "Inexistend item!\n");
	}
	cout << "Testing remove...\n";


	serv1.SVadd(t1);
	Trench t4("a", "new", 10, 10, "h");
	Trench t5("x", "x", 3, 3, "link");
	assert(serv1.SVupdate(t4) == 1);
	try {
		serv1.SVupdate(t5);
	}
	catch (AppException& repoException) {
		assert(repoException.getMessage() == "Inexistent item!\n");
	}
	cout << "Testing update...\n";
	
	vector<Trench> trenches = serv1.SVshowAll();
	assert(trenches[0].getSize() == "S");
	cout << "Testing show all...\n";

}

void testServiceUSER()
{
	cout << "\n\nTesting User service..\n";
	Repo repo1;
	Service serv1{ repo1 };
	vector<Trench> trenches = serv1.SVshowBySize("S");
	vector<Trench> trenches1 = serv1.SVshowBySize("");
	assert(trenches1[1].getSize() == "M");
	for (Trench current : trenches)
		assert(current.getSize() == "S");
	cout << "Testing show by size..\n";
	Trench t1("a", "b", 1, 1, "h");
	Trench t2("d", "e", 2, 7, "t");
	Trench t3("d", "e", 3, 7, "t");

	serv1.SVaddToBasket(t1);
	trenches = serv1.SVgetBasket();
	for (Trench current : trenches)
		assert(current.getPhoto()==t1.getPhoto()&& current.getSize() == t1.getSize());
	cout << "Testing get basket...\nTesting add to basket\n";
	assert(serv1.SVseeTotalPrice() == 1);
	cout << "Testing see total price..\n\n\n\n";


}

void runTestsAdmin()
{
	testDomain();
	testRepo();
	testServiceADM();
	testServiceUSER();
}
