#pragma once

#include <QtWidgets/QWidget>
#include "Astronomer.h"
#include "StarModel.h"
#include "Controller.h"
#include "ui_StarGUI.h"
class StarGUI : public QWidget
{
	Q_OBJECT
public slots:
	void addStar();
	void showByConstellation();
	void search();
public:
	StarsModel * s;
	Controller* c;
	Astronomer a;
	StarGUI(Astronomer a, StarsModel* s, Controller* c, QWidget *parent = Q_NULLPTR);


private:
	Ui::StarGUIClass ui;


};
