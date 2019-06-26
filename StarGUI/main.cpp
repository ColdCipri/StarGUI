#include "StarGUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	StarGUI w;
	w.show();
	return a.exec();
}
