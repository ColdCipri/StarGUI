#include "Star.h"



Star::Star()
{
}

Star::Star(QString name, QString constellation, int coordinatesRA, int coordinatesDec, int diameter)
{
	this->name = name;
	this->constellation = constellation;
	this->coordinatesRA = coordinatesRA;
	this->coordinatesDec = coordinatesDec;
	this->diameter = diameter;
}

