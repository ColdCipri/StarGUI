#include "AstronomerRepository.h"



AstronomerRepository::AstronomerRepository()
{

}

void AstronomerRepository::add(Astronomer a)
{
	arr.push_back(a);

}

Astronomer AstronomerRepository::get(int pos)
{
	return arr[pos];
}
QString AstronomerRepository::getConstellation(Astronomer a)
{
	return a.constellation;
}
int AstronomerRepository::getCount()
{
	return arr.size();
}

AstronomerRepository::~AstronomerRepository()
{

}
