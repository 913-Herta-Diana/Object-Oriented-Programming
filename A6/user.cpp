#include "user.h"
#include <iostream>
#include "exception.h"
#include <utility>
using namespace std;
void printMainMenu()
{
	std::cout << "Welcome to Proper Trench Coats...\n\nPress 1 for admin mode, 2 for user mode or 0 to exit:\n";
}
void printAdminMenu()
{
	std::cout << "1.Add a product\n2.Delete a product\n3.Update a product\n4.Display all products\n0.Exit\n";
}
void printUserMenu()
{
	std::cout << "Loading USER mode...\n1.Add a product\n2.See basket\n3.Display all products by size\n0.Exit\n";
}

void User::runMainMenu()
{
	int command;
	int running = 1;
	
	
		while (running) {

			
				printMainMenu();
				std::cout << "Insert command: \n";
				std::cin >> command;
				switch (command) {

				case 0:
					running = 0;
					break;
				case 1:
					runAdmin();
					break;
				case 2:
					runUser();
					break;

				}
			
			
		}
	
	
}
	

void User::runAdmin(){

	
	int command;
	std::cout << "Welcome to ADMIN mode!\n";
	int run = 1;
	while (run)
	{
		try {
			printAdminMenu();
			std::cout << "Insert command: \n";
			std::cin >> command;
			switch (command) {
			case 0:
				run = 0;
				break;
			case 1:
				ADMadd();
				break;
			case 2:
				ADMremove();
				break;
			case 3:
				ADMupdate();
				break;
			case 4:
				ADMshowAll();
				break;

			}
		}
		catch (AppException& e)
		{
			std::cout << "Standard exception: " << e.getMessage() << endl;
		}

	}
	
}


void User::runUser(){
	int command;
	std::cout << "Welcome to USER mode!\n";
	int run = 1;
	while (run)
	{
		try {
			printUserMenu();
			std::cout << "Insert command: \n";
			std::cin >> command;
			switch (command) {
			case 0:
				run = 0;
				break;
			case 1:
				while (1)
				{
					int check = USERaddToBasket();
					if (check == 0)
					{
						break;
					}
				}
				break;
			case 2:
				USERbasketPrice();
				break;
			case 3:
				USERshowBySize();
				break;

			}
		}
		catch (AppException& e)
		{
			std::cout << "Standard exception: " << e.getMessage() << endl;
		}

	}

}

void User::ADMadd()
{
	std::cout << "Enter size:\n";
	string size;
	std::cin >> size;
	std::cout << "Enter color:\n";
	string color;
	std::cin >> color;
	std::cout << "Enter price:\n";
	float price;
	std::cin >> price;
	std::cout << "Enter quantity:\n";
	int quantity;
	std::cin >> quantity;
	std::cout << "Enter photo link:\n";
	string photo;
	std::cin >> photo;
	std::cin.get();
	if (service.SVadd(Trench(size,color,price,quantity,photo))==1) {
		std::cout << "New trench added \n";
	}
	else {
		std::cout << "Trench added to the stock \n";
	}
}

void User::ADMremove()
{
	std::cout << "Enter size:\n";
	string size;
	std::cin >> size;
	std::cout << "Enter color:\n";
	string color;
	std::cin >> color;
	std::cout << "Enter price:\n";
	float price;
	std::cin >> price;
	std::cout << "Enter quantity:\n";
	int quantity;
	std::cin >> quantity;
	std::cout << "Enter photo link:\n";
	string photo;
	std::cin >> photo;
	std::cin.get();
	if (service.SVremove(Trench(size, color, price, quantity, photo)) == 1) {
		std::cout << "This trench is sold out! \n";
	}
	else {
		std::cout << "Tranched removed from the stock \n";
	}
}

void User::ADMupdate()
{
	std::cout << "Enter size:\n";
	string size;
	std::cin >> size;
	std::cout << "Enter color:\n";
	string color;
	std::cin >> color;
	std::cout << "Enter price:\n";
	float price;
	std::cin >> price;
	std::cout << "Enter quantity:\n";
	int quantity;
	std::cin >> quantity;
	std::cout << "Enter photo link:\n";
	string photo;
	std::cin >> photo;
	std::cin.get();
	if (service.SVupdate(Trench(size, color, price, quantity, photo)) == 1) 
		std::cout << "This trench is updated! \n";
}

void User::ADMshowAll()
{
	vector<Trench> trenchList = service.SVshowAll();
	int index=-1;
	for (Trench current : trenchList)
	{
		index++;
		std::cout << index << ". " << current.getSize() << " | " << current.getColor() << " | " << current.getPrice() << " | " << current.getQuantity() << " | " << current.getPhoto() << "\n";
	}
	
}

void User::USERshowBySize()
{
	string size;
	std::cout << "Insert size: \n";
	std::cin >> size;
	vector<Trench> trenchList = service.SVshowBySize(size);
	int index = -1;
	for (Trench current : trenchList)
	{
		index++;
		std::cout << index<<". "<<current.getSize() << " | " << current.getColor() << " | " << current.getPrice() << " | " << current.getQuantity() << " | " << current.getPhoto() << "\n";
	}
}

int User::USERaddToBasket(){
	int option;

	for (Trench current : service.SVshowAll())
	{
		std::cout <<  current.getSize() << " | " << current.getColor() << " | " << current.getPrice() << " | " << current.getQuantity() << " | " << current.getPhoto() << "\n";
		system(std::string("start " + current.getPhoto()).c_str());
		std::cout << "Choose 1 to add, 0 to skip and 3 to exit: \n";
		std::cin >> option;
		if (option == 1)
		{
			service.SVaddToBasket(current);
			std::cout << "Successfully added!\n" << "Total price: " << service.SVseeTotalPrice() << "\n\n\n";
			return 0;
		}
		else if (option == 3)
			return 0;
		
	}
	
	
}


void User::USERbasketPrice()
{
	int index = -1;
	for(Trench current: service.SVgetBasket())
	{
		index++;
		std::cout << index << ". " << current.getSize() << " | " << current.getColor() << " | " << current.getPrice() << " | " << current.getQuantity() << " | " << current.getPhoto() << "\n";
	}
	std::cout << "Total price: " << service.SVseeTotalPrice();

}
