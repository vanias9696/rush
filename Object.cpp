#include "Object.hpp"

Object::Object(){}

Object::~Object(){}

int			Object::getXPos(void)
{
	return(_xPos);
}

int			Object::getYPos(void)
{
	return(_yPos);
}

/*int			Object::getSizeX(void)
{
	return(_sizeX);
}

int			Object::getSizeY(void)
{
	return(_sizeY);
}

std::string	Object::getColor(void)
{
	return(_color);
}
*/
char	Object::getSign(void)
{
	return(_sign);
}

void		Object::setXPos(int n)
{
	_xPos = n;
}

void		Object::setYPos(int n)
{
	_yPos = n;
}
/*
void		Object::setSizeX(int n)
{
	_sizeX = n;
}

void		Object::setSizeY(int n)
{
	_sizeY = n;
}

void		Object::setColor(std::string str)
{
	_color = str;
}
*/
