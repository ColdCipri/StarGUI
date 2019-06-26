#include "StarGUI.h"
#include <QMessageBox>
#include <QModelIndex>
StarGUI::StarGUI(Astronomer a, StarsModel* s, Controller* c, QWidget *parent)
	: QWidget(parent)
{
	this->s = s;
	this->c = c;
	this->a = a;
	ui.setupUi(this);
	this->setWindowTitle(a.name);
	ui.tableView->setModel(s);
	connect(ui.add, SIGNAL(pressed()), this, SLOT(addStar()));
	connect(ui.checkBox, SIGNAL(clicked()), this, SLOT(showByConstellation()));
	//connect(ui.search, SIGNAL(pressed()), this, SLOT(search()));
	connect(ui.Search_textEdit, SIGNAL(textChanged()), this, SLOT(search()));
}

void StarGUI::addStar() {
	try {
		QString name = ui.name->toPlainText();
		if (name.trimmed().size() == 0)
			throw std::exception{ "Name is empty" };
		for (auto i : s->getStars()) {
			if (i.name == name) {

				throw std::exception{ "No duplicates alowed" };
			}
		}
		int coordRA = ui.CoordinatesRA_textEdit->toPlainText().toInt();;
		int coordDec = ui.CoordinatesDec_textEdit->toPlainText().toInt();
		this->s->appendData(Star(name, a.constellation, coordRA, coordDec, 0));
	}
	catch (std::exception e) {
		QMessageBox::information(this, "Error", e.what());

	}
}

void StarGUI::showByConstellation() {

	QList<Star> backup;
	for (int i = 0; i < s->getStars().size(); i++) {
		backup.append(s->getStars().at(i));
	}

	if (ui.checkBox->checkState() == Qt::Checked) {

		QList<Star> filterConstelation = s->getStarsByConstellation(a.constellation);
		this->s->removeRows(0, s->getStars().size());

		for (auto st : filterConstelation) {
			this->s->appendData(st);
		}
	}
	else if (ui.checkBox->checkState() == Qt::Unchecked)
	{
		QList<Star> b = s->getStars();
		this->s->removeRows(0, s->getStarsByConstellation(a.constellation).size());

		for (auto st : b) {
			this->s->appendData(st);
		}
	}

}

void StarGUI::search()
{
	QString input = ui.Search_textEdit->toPlainText();

	QList<Star> backup;
	for (int i = 0; i < s->getStars().size(); i++) {
		backup.append(s->getStars().at(i));
	}

	QList<Star> newList = this->s->getStarsByNameCoordinates(input, input.toInt());
	if (newList.size() == 0) {
		this->s->removeRows(0, s->getStars().size());
		for (auto st : backup) {
			this->s->appendData(st);
		}
	}
	else {
		this->s->removeRows(0, s->getStars().size());
		for (auto st : newList)
			this->s->appendData(st);
	}
}
