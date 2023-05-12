#pragma once
#include "service.h"
#include "serviceUser.h"
class User {
	Service service;
public:
	User(Service service) : service {service} {};
	void runMainMenu();
	void runAdmin();
	void runUser();

	void ADMadd();
	void ADMremove();
	void ADMupdate();
	void ADMshowAll();

	void USERshowBySize();
	int USERaddToBasket();
	void USERbasketPrice();


};