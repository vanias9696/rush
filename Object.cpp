#include "Header.hpp"

Object::Object()
{
	_wide = 120;
	_hight = 50;
}
//for background
Object::Object(int x, int y)
{
	_xPos = x;
	_yPos = y;
}

Object::~Object(){}

int			Object::getXPos(void)
{
	return(_xPos);
}

int			Object::getYPos(void)
{
	return(_yPos);
}

void		Object::setXPos(int n)
{
	_xPos = n;
	if (n <= 0)
		_xPos = 1;
	if (n + _wideFig > _wide - 2)
		_xPos = _wide - 1 - _wideFig;
}

void		Object::setYPos(int n)
{
	_yPos = n;
}

Object & Object::operator=( Object const &rhs )
{
	if(this != &rhs)
		return *this;
	return *this;
}

Object::Object(Object const &src)
{
	*this = src;
	return ;
}