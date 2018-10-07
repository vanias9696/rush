#include "Header.hpp"

Shot::Shot(int x, int y)
{
	_xPos = x;
	_yPos = y;
	_wideFig = 1;
	// _whereX = 47;//поле ширина 99, при чому з 0, середина на 50
}

Shot::~Shot(){}

Shot::Shot(Shot const &src)
{
	*this = src;
	return ;
}

Shot	&Shot::operator=(Shot const &rhs )
{
	if(this != &rhs)
		return *this;
	return *this;
}