#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <QString>
#include <QStringList>
#include "AstronomerRepository.h"
#include "Star.h"
#include "StarModel.h"

using namespace std;
class Controller
{
public:
	AstronomerRepository repo;
	Controller();
	void readAstronomer();
	StarsModel* createAdapter();
	Astronomer getAstronomerAt(int pos);
	QString getConstellation();
	int getAstronomerCount();

	~Controller();
};

