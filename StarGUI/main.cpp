#include "StarGUI.h"
#include <QtWidgets/QApplication>
#include "Controller.h"
#include "StarModel.h"
#include <vector>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Controller* c = new Controller();
	StarsModel* s = c->createAdapter();
	vector<StarGUI*> windows;
	for (int i = 0; i < c->getAstronomerCount(); i++) {
		windows.push_back(new StarGUI(c->getAstronomerAt(i), s, c));
		windows.at(i)->show();
	}
	return a.exec();
}
