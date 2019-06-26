#pragma once
#include <QString>

class Astronomer
{
public:
	QString name;
	QString constellation;
public:
	Astronomer();
	Astronomer(QString name, QString constellation);
	QString getConstellation(Astronomer a);
};

