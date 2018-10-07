#include "Header.hpp"

Object::Object()
{
	_wide = 120;
	_hight = 50;
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
	if (n <= 0)
		_xPos = 1;
	if (n > _hight - 2)
		_xPos = _hight - 2;

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

// void	Player::moving(int n)
// {
// 	_whereX += n;
// 	if (_whereX < 2)
// 		_whereX = 2;
// 	else if (_whereX > 96)
// 		_whereX = 96;
// }