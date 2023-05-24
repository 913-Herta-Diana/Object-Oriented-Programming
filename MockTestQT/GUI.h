#pragma once

#include <QObject>

class GUI  : public QObject
{
	Q_OBJECT

public:
	GUI(QObject *parent);
	~GUI();
};
