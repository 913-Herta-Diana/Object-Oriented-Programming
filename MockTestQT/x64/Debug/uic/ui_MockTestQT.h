/********************************************************************************
** Form generated from reading UI file 'MockTestQT.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOCKTESTQT_H
#define UI_MOCKTESTQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MockTestQTClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *DisplayManufacturerModel;
    QFormLayout *formLayout;
    QLabel *Manufacturer;
    QLineEdit *ManufacturerLine;
    QLabel *Model;
    QLineEdit *ModelLine;
    QHBoxLayout *horizontalLayout;
    QPushButton *showAllButton;
    QPushButton *givenManufacturereButton;
    QLabel *label;
    QListWidget *manufacturerList;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MockTestQTClass)
    {
        if (MockTestQTClass->objectName().isEmpty())
            MockTestQTClass->setObjectName("MockTestQTClass");
        MockTestQTClass->resize(480, 623);
        centralWidget = new QWidget(MockTestQTClass);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        DisplayManufacturerModel = new QListWidget(centralWidget);
        DisplayManufacturerModel->setObjectName("DisplayManufacturerModel");

        verticalLayout->addWidget(DisplayManufacturerModel);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName("formLayout");
        Manufacturer = new QLabel(centralWidget);
        Manufacturer->setObjectName("Manufacturer");

        formLayout->setWidget(0, QFormLayout::LabelRole, Manufacturer);

        ManufacturerLine = new QLineEdit(centralWidget);
        ManufacturerLine->setObjectName("ManufacturerLine");

        formLayout->setWidget(0, QFormLayout::FieldRole, ManufacturerLine);

        Model = new QLabel(centralWidget);
        Model->setObjectName("Model");

        formLayout->setWidget(1, QFormLayout::LabelRole, Model);

        ModelLine = new QLineEdit(centralWidget);
        ModelLine->setObjectName("ModelLine");

        formLayout->setWidget(1, QFormLayout::FieldRole, ModelLine);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        showAllButton = new QPushButton(centralWidget);
        showAllButton->setObjectName("showAllButton");

        horizontalLayout->addWidget(showAllButton);

        givenManufacturereButton = new QPushButton(centralWidget);
        givenManufacturereButton->setObjectName("givenManufacturereButton");

        horizontalLayout->addWidget(givenManufacturereButton);


        verticalLayout->addLayout(horizontalLayout);

        label = new QLabel(centralWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        manufacturerList = new QListWidget(centralWidget);
        manufacturerList->setObjectName("manufacturerList");

        verticalLayout->addWidget(manufacturerList);

        MockTestQTClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MockTestQTClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 480, 22));
        MockTestQTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MockTestQTClass);
        mainToolBar->setObjectName("mainToolBar");
        MockTestQTClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MockTestQTClass);
        statusBar->setObjectName("statusBar");
        MockTestQTClass->setStatusBar(statusBar);

        retranslateUi(MockTestQTClass);
        QObject::connect(givenManufacturereButton, SIGNAL(clicked()), MockTestQTClass, SLOT(showSortedSlot()));

        QMetaObject::connectSlotsByName(MockTestQTClass);
    } // setupUi

    void retranslateUi(QMainWindow *MockTestQTClass)
    {
        MockTestQTClass->setWindowTitle(QCoreApplication::translate("MockTestQTClass", "MockTestQT", nullptr));
        Manufacturer->setText(QCoreApplication::translate("MockTestQTClass", "Manufacturer", nullptr));
        ManufacturerLine->setText(QString());
        Model->setText(QCoreApplication::translate("MockTestQTClass", "Model", nullptr));
        showAllButton->setText(QCoreApplication::translate("MockTestQTClass", "Show All", nullptr));
        givenManufacturereButton->setText(QCoreApplication::translate("MockTestQTClass", "Show given manufacturer", nullptr));
        label->setText(QCoreApplication::translate("MockTestQTClass", "Show By Manufacturer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MockTestQTClass: public Ui_MockTestQTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOCKTESTQT_H
