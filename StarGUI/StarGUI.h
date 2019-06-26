#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_StarGUI.h"

class StarGUI : public QMainWindow
{
	Q_OBJECT

public:
	StarGUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::StarGUIClass ui;
};
