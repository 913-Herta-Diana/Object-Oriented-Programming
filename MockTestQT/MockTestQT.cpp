#include "MockTestQT.h"
#include <iostream>
MockTestQT::MockTestQT(Service& serv, QWidget* parent)
    : QMainWindow(parent), serv{ serv }
{
    ui.setupUi(this);
    populate();
} 

MockTestQT::~MockTestQT()
{}

void MockTestQT::populate()
{
    this->ui.DisplayManufacturerModel->clear();
    vector<Car> allCars = this->serv.getCarsService();
    sort(allCars.begin(), allCars.end(), [](Car car1, Car car2) {return car1.GetName() < car2.GetName(); });
    for (Car& c : allCars)
        this->ui.DisplayManufacturerModel->addItem(QString::fromStdString(c.GetName() + " | "  + c.GetModel()));
}
void MockTestQT::showSortedSlot()
{
    string manufacturer = this->ui.ManufacturerLine->text().toStdString();
    this->ui.manufacturerList->clear();
    vector<Car> newList;
    for (Car c : this->serv.getCarsService())
        if (c.GetName() == manufacturer)
            newList.push_back(c);
    for (Car& car : newList)
        this->ui.manufacturerList->addItem(QString::fromStdString(car.GetName() + " | " + car.GetModel()));
    ui.manufacturerList->addItem(QString::fromStdString("Number of cars: " + to_string(newList.size())));

}
//void MockTestQT::showNbCars()
//{
//     
//}
//int MockTestQT::getSelectedIndex() const
//{
//    QModelIndexList selectedIndexes = this->ui.DisplayManufacturerModel->selectionModel()->selectedIndexes();
//}
//void MockTestQT::connectSignalAndSlots()
//{
//    QObject::connect(this->ui.givenManufacturereButton, &QPushButton::clicked, this, &MockTestQT::showNbCars);
//}

