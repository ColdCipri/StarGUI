#include "Controller.h"



Controller::Controller()
{

	repo = AstronomerRepository();
	readAstronomer();
}

void Controller::readAstronomer()
{
	ifstream r("astronomers.txt");
	string line;
	while (getline(r, line)) {
		QString l = QString::fromStdString(line);
		QStringList words = l.split(',');
		Astronomer a = Astronomer(words[0], words[1]);
		repo.add(a);
	}
}

StarsModel* Controller::createAdapter()
{
	QList<Star> li;
	ifstream r("stars.txt");
	string line;
	while (getline(r, line)) {
		QString l = QString::fromStdString(line);
		QStringList words = l.split(',');
		Star s = Star(words[0], words[1], words[2].toInt(), words[3].toInt(), words[4].toInt());
		li.append(s);
	}

	return new StarsModel(li);
}


Astronomer Controller::getAstronomerAt(int pos) {
	return repo.get(pos);
}

int Controller::getAstronomerCount() {
	return repo.getCount();
}


Controller::~Controller()
{
}
