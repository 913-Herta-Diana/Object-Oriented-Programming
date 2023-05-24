#include "user.h"
#include <iostream>
#include "exception.h"
#include <utility>
constexpr auto ADM_MODE{ 1 };
constexpr auto USER_MODE{ 2 };
constexpr auto EXIT{ 0 };

constexpr auto ADM_ADD{ 1 };
constexpr auto ADM_REMOVE{ 2 };
constexpr auto ADM_UPDATE{ 3 };
constexpr auto ADM_SHOW{ 4 };

constexpr auto USER_ADD{ 1 };
constexpr auto USER_BASKET{ 2 };
constexpr auto USER_SHOW_BY_SIZE{ 3 };
constexpr auto USER_SAVE_TO_FILE{ 4 };

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

				case EXIT:
					running = 0;
					break;
				case ADM_MODE:
					runAdmin();
					break;
				case USER_MODE:
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
			case EXIT:
				run = 0;
				break;
			case ADM_ADD:
				try
				{
					ADMadd();
				}
				catch (ValidatorException& e)
				{
					std::cout << "Standard exception: " << e.getMessage() << endl;
				}
				break;
			case ADM_REMOVE:
				try {
					ADMremove();
				}
				catch (ValidatorException& e)
				{
					std::cout << "Standard exception: " << e.getMessage() << endl;
				}
				break;
			case ADM_UPDATE:
				try {
					ADMupdate();
				}
				catch (ValidatorException& e)
				{
					std::cout << "Standard exception: " << e.getMessage() << endl;
				}
				break;
			case ADM_SHOW:
				try {
					ADMshowAll();
				}
				catch (ValidatorException& e)
				{
					std::cout << "Standard exception: " << e.getMessage() << endl;
				}
				break;
			/*case 5:
				try {
					UIsaveToFile();
				}
				catch (AppException& e)
				{
					std::cout << "Standard exception: " << e.getMessage() << endl;
				}
				break;*/

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
			case EXIT:
				run = 0;
				break;
			case USER_ADD:
				while (1)
				{
						int check = USERaddToBasket();
						if (check == 0)
						{
							break;
						}	
				}
				break;
			case USER_BASKET:
					USERbasketPrice();
					break;
				
			case USER_SHOW_BY_SIZE:
				try {
					USERshowBySize();
				}
				catch (ValidatorException& e)
				{
					std::cout << "Standard exception: " << e.getMessage() << endl;
				}
				break;
			case USER_SAVE_TO_FILE:
				try {
					USERsaveToFile();
					
				}
				catch (ValidatorException& e)
				{
					std::cout << "Standard exception: " << e.getMessage() << endl;
				}
				break;
			/*case 5:
				try {
				USERsaveToHTML();
				}
				catch (ValidatorException& e)
				{
					std::cout << "Standard exception: " << e.getMessage() << endl;
				}
				break;*/

			}
		}
		catch (AppException& e)
		{
			std::cout << "Standard exception: " << e.getMessage() << endl;
		}

	}

}
void User::USERsaveToFile()
{
	std::string filename;
	cout << "Input the file name (absolute path): ";
	cin >> filename;
	//if (filename.find(".html") != std::string::npos)
	//{
	//	cout << "im html";
	//	FileBasket* fhtml = new HTMLBasket{};
	//	service.setFileType(fhtml);
	//	cout << "im html2";
	//}
	//else if (filename.find(".csv") != std::string::npos)
	//{
	//	cout << "im csv";
	//	FileBasket* fcsv = new CSVBasket{};
	//	service.setFileType(fcsv);
	//	cout << "im csv2";
	//}
	//else
	//	cout << "Invalid file type!"; //throw exceptions
	//
	////validate empty string input
	this->service.SVsaveToFile(filename);
	cout << "\nSaved!\n";
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
	string strprice;
	std::cin >> strprice;
	price = Validator::validatePrice(strprice);
	std::cout << "Enter quantity:\n";
	int quantity;
	string strquantity;
	std::cin >> strquantity;
	quantity = Validator::validateQuantity(strquantity);
	std::cout << "Enter photo link:\n";
	string photo;
	std::cin >> photo;
	std::cin.get();
	if (price == -1 || quantity == -1 || !Validator::validatePhoto(photo) || !Validator::validateSize(size))
	{throw ValidatorException("Invalid input!");
	return;}
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
	string strprice;
	std::cin >> strprice;
	price = Validator::validatePrice(strprice);
	std::cout << "Enter quantity:\n";
	int quantity;
	string strquantity;
	std::cin >> strquantity;
	quantity = Validator::validateQuantity(strquantity);
	std::cout << "Enter photo link:\n";
	string photo;
	std::cin >> photo;
	std::cin.get();
	if (service.SVremove(Trench(size, color, price, quantity, photo)) == true) {
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
	string strprice;
	std::cin >> strprice;
	price = Validator::validatePrice(strprice);
	std::cout << "Enter quantity:\n";
	int quantity;
	string strquantity;
	std::cin >> strquantity;
	quantity = Validator::validateQuantity(strquantity);
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
	int index=0;
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
	//cin >> size;
	//std::cin.ignore(); 
	//std::getline(std::cin,size);

	cin >> size; 
	vector<Trench> trenchList = service.SVshowBySize(size);
	int index = 0;
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
		}
		else if (option == 3)
			return 0;
		
	}	
}


void User::USERbasketPrice()
{
	int index = 0;
	for(Trench current: service.SVgetBasket())
	{
		index++;
		std::cout << index << ". " << current.getSize() << " | " << current.getColor() << " | " << current.getPrice() << " | " << current.getQuantity() << " | " << current.getPhoto() << "\n";
	}
	std::cout << "Total price: " << service.SVseeTotalPrice()<<"\n";

}

//void User::USERsaveToCSV()
//{
//	service.SVsaveToCSV();
//	cout << "\nSaved!\n";
//}
//
//void User::USERsaveToHTML()
//{
//	service.SVsaveToHTML();
//	cout << "\nSaved!\n";
//}
//
//
//
