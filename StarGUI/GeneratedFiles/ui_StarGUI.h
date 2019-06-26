/********************************************************************************
** Form generated from reading UI file 'StarGUIVeygWi.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef STARGUIVEYGWI_H
#define STARGUIVEYGWI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StarGUIClass
{
public:
    QTableView *Table;
    QTableView *tableView;
    QPushButton *add;
    QPushButton *search;
    QTextEdit *CoordinatesRA_textEdit;
    QTextEdit *name;
    QLabel *Name;
    QLabel *CoordinatesRA_label;
    QCheckBox *checkBox;
    QLabel *CoordinatesDec_label;
    QTextEdit *CoordinatesDec_textEdit;
    QTextEdit *Search_textEdit;

    void setupUi(QWidget *StarGUIClass)
    {
        if (StarGUIClass->objectName().isEmpty())
            StarGUIClass->setObjectName(QString::fromUtf8("StarGUIClass"));
        StarGUIClass->resize(716, 540);
        Table = new QTableView(StarGUIClass);
        Table->setObjectName(QString::fromUtf8("Table"));
        Table->setGeometry(QRect(0, 0, 721, 551));
        tableView = new QTableView(StarGUIClass);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 0, 721, 331));
        add = new QPushButton(StarGUIClass);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(20, 480, 161, 51));
        search = new QPushButton(StarGUIClass);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(240, 480, 161, 51));
        CoordinatesRA_textEdit = new QTextEdit(StarGUIClass);
        CoordinatesRA_textEdit->setObjectName(QString::fromUtf8("CoordinatesRA_textEdit"));
        CoordinatesRA_textEdit->setGeometry(QRect(110, 380, 111, 21));
        name = new QTextEdit(StarGUIClass);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(90, 350, 131, 21));
        Name = new QLabel(StarGUIClass);
        Name->setObjectName(QString::fromUtf8("Name"));
        Name->setGeometry(QRect(10, 340, 51, 31));
        CoordinatesRA_label = new QLabel(StarGUIClass);
        CoordinatesRA_label->setObjectName(QString::fromUtf8("CoordinatesRA_label"));
        CoordinatesRA_label->setGeometry(QRect(10, 380, 91, 16));
        checkBox = new QCheckBox(StarGUIClass);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(420, 480, 271, 51));
        CoordinatesDec_label = new QLabel(StarGUIClass);
        CoordinatesDec_label->setObjectName(QString::fromUtf8("CoordinatesDec_label"));
        CoordinatesDec_label->setGeometry(QRect(10, 410, 91, 16));
        CoordinatesDec_textEdit = new QTextEdit(StarGUIClass);
        CoordinatesDec_textEdit->setObjectName(QString::fromUtf8("CoordinatesDec_textEdit"));
        CoordinatesDec_textEdit->setGeometry(QRect(110, 410, 111, 21));
        Search_textEdit = new QTextEdit(StarGUIClass);
        Search_textEdit->setObjectName(QString::fromUtf8("Search_textEdit"));
        Search_textEdit->setGeometry(QRect(240, 440, 161, 31));

        retranslateUi(StarGUIClass);

        QMetaObject::connectSlotsByName(StarGUIClass);
    } // setupUi

    void retranslateUi(QWidget *StarGUIClass)
    {
        StarGUIClass->setWindowTitle(QApplication::translate("StarGUIClass", "StarGUI", nullptr));
        add->setText(QApplication::translate("StarGUIClass", "Add", nullptr));
        search->setText(QApplication::translate("StarGUIClass", "Search", nullptr));
        Name->setText(QApplication::translate("StarGUIClass", "Name", nullptr));
        CoordinatesRA_label->setText(QApplication::translate("StarGUIClass", "CoordinatesRA", nullptr));
        checkBox->setText(QApplication::translate("StarGUIClass", "See start which are in studing constelation", nullptr));
        CoordinatesDec_label->setText(QApplication::translate("StarGUIClass", "CoordinatesDec", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StarGUIClass: public Ui_StarGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // STARGUIVEYGWI_H
