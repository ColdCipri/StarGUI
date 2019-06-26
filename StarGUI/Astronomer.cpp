#include "Astronomer.h"



Astronomer::Astronomer()
{
}

Astronomer::Astronomer(QString name, QString constellation)
{
	this->name = name;
	this->constellation = constellation;
}

QString Astronomer::getConstellation(Astronomer a)
{
	return a.constellation;
}
