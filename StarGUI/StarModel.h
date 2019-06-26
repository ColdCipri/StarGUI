#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include "Star.h"


class StarsModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	StarsModel(QObject *parent = 0);
	StarsModel(QList<Star> stars, QObject *parent = 0);
	static bool compare(const Star& s1, const Star& s2) {
		return s1.constellation < s2.constellation;
	}
	int rowCount(const QModelIndex &parent) const override;
	int columnCount(const QModelIndex &parent) const override;
	QVariant data(const QModelIndex &index, int role) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
	Qt::ItemFlags flags(const QModelIndex &index) const override;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
	void appendData(Star i);
	bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
	bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
	QList<Star> getStars() const;
	QList<Star> getStarsByConstellation(QString constellation) const;
	QList<Star> getStarsByNameCoordinates(QString name, int coord) const;

private:
	QList<Star> stars;
};

#endif // TABLEMODEL_H



