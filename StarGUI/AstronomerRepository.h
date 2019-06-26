#pragma once
#include <vector>
#include "Astronomer.h"
class AstronomerRepository
{

private:
	std::vector<Astronomer> arr;
public:

	AstronomerRepository();
	void add(Astronomer a);
	Astronomer get(int pos);
	QString getConstellation(Astronomer a);
	int getCount();

	~AstronomerRepository();
};

