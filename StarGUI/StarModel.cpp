#include "StarModel.h"
#include <algorithm>
StarsModel::StarsModel(QObject *parent)
	: QAbstractTableModel(parent)
{
}

StarsModel::StarsModel(QList<Star> stars, QObject *parent)
	: QAbstractTableModel(parent)
	, stars(stars)
{
}

int StarsModel::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return stars.size();
}

int StarsModel::columnCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return 5;
}

QVariant StarsModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();

	if (index.row() >= stars.size() || index.row() < 0)
		return QVariant();

	if (role == Qt::DisplayRole) {
		const auto &star = stars.at(index.row());

		if (index.column() == 0)
			return star.name;
		else if (index.column() == 1)
			return star.constellation;
		else if (index.column() == 2)
			return star.coordinatesRA;
		else if (index.column() == 3)
			return star.coordinatesDec;
		else if (index.column() == 4)
			return star.diameter;

	}
	return QVariant();
}

QVariant StarsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role != Qt::DisplayRole)
		return QVariant();

	if (orientation == Qt::Horizontal) {
		switch (section) {
		case 0:
			return tr("Name");
		case 1:
			return tr("Constellation");
		case 2:
			return tr("CoordinatesRA");
		case 3:
			return tr("CoordinatesDec");
		case 4:
			return tr("Diameter");
		default:
			return QVariant();
		}
	}
	return QVariant();
}

bool StarsModel::insertRows(int position, int rows, const QModelIndex &index)
{
	Q_UNUSED(index);
	beginInsertRows(QModelIndex(), position, position + rows - 1);
	for (int row = 0; row < rows; ++row)
		stars.insert(position, { QString{}, QString{}, 0, 0, 0 });

	endInsertRows();
	return true;
}

bool StarsModel::removeRows(int position, int rows, const QModelIndex &index)
{
	Q_UNUSED(index);
	beginRemoveRows(QModelIndex(), position, position + rows - 1);

	for (int row = 0; row < rows; ++row)
		stars.removeAt(position);

	endRemoveRows();
	return true;
}

bool StarsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (index.isValid() && role == Qt::EditRole) {
		int row = index.row();

		auto star = stars.value(row);

		if (index.column() == 0)
			star.name = value.toString();
		else if (index.column() == 1)
			star.constellation = value.toString();
		else if (index.column() == 2)
			star.coordinatesRA = value.toInt();
		else if (index.column() == 3)
			star.coordinatesDec = value.toInt();
		else if (index.column() == 4)
			star.diameter = value.toInt();

		stars.replace(row, star);
		emit(dataChanged(index, index));

		return true;
	}

	return false;
}
// Input 
// Star I
//
// Output
// QList<Star> stars + Star i;(star appended to the list of stars)
void StarsModel::appendData(Star i) {
	int newRow = stars.count();
	beginInsertRows(QModelIndex(), newRow, newRow);
	stars.append(i);
	std::sort(stars.begin(), stars.end(), StarsModel::compare);
	endInsertRows();
}
Qt::ItemFlags StarsModel::flags(const QModelIndex &index) const
{

	if (!index.isValid())
		return Qt::ItemIsEnabled;
	return QAbstractTableModel::flags(index);
}

QList<Star> StarsModel::getStars() const
{
	return stars;
}


QList<Star> StarsModel::getStarsByConstellation(QString constellation) const
{
	QList<Star> constellations;
	for (auto i : stars) {
		if (i.constellation == constellation)
			constellations.push_back(i);
	}
	return constellations;
}


// Input 
// name (QString)- from textbox(it can be only part of it)
// coordinates (int) it needs to be the same as in the star
//
// Output
// search (List<Star>) new created with elements that passes the condition
QList<Star> StarsModel::getStarsByNameCoordinates(QString name, int coord) const
{
	QList<Star> search;
	for (auto i : stars) {
		if (i.name.toLower().contains(name.toLower()) || i.coordinatesRA == coord || i.coordinatesDec == coord) {
			search.push_back(i);
		}
	}
	return search;
}
