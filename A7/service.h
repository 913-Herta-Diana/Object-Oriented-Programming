#pragma once
#include "repository.h"
//#include "FileRepository.h"
#include "CSVBasket.h"
#include "HTMLBasket.h"
#include "FileBasket.h"
#include "Basket.h"
class Service {
	Repo repository;
	//FileRepository* file;
	//vector<Trench> basket;
	FileBasket* file;
public:

	Service(Repo repository, FileBasket* file);
	void setFileType(FileBasket* file);
	vector<Trench> SVgetBasket();
	bool SVadd(Trench newTrench);
	bool SVremove(Trench removedTrench);
	bool SVupdate(Trench updatedTrench);
	vector<Trench> SVshowAll();
	vector<Trench> SVshowBySize(string size);

	void SVaddToBasket(Trench& addedTrench); 
	float SVseeTotalPrice();
	void SVsaveToFile(string filename);



	void startBasket();
	
	void nextSongBasket();
	

	void saveBasket(const std::string& filename);
	
	

};