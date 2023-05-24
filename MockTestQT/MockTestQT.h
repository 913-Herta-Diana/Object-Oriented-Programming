#pragma once
#include "service.h"
#include <QtWidgets/QMainWindow>
#include "ui_MockTestQT.h"

class MockTestQT : public QMainWindow
{
    Q_OBJECT

public:
    MockTestQT(Service& serv, QWidget *parent = nullptr);
    ~MockTestQT();

private:
    Service serv;
    Ui::MockTestQTClass ui;
    void populate();
    public slots:
        void showSortedSlot();
   /* void connectSignalAndSlots();
    void showNbCars();
    int getSelectedIndex() const;*/
};
