#pragma once
#include <QString>

class Star
{
public:
	QString name;
	QString constellation;
	int coordinatesRA;
	int coordinatesDec;
	int diameter;
public:
	Star();
	Star(QString name, QString constellation, int coordinatesRA, int coordinatesDec, int diameter);
};

