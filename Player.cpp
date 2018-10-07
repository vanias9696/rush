#include "Player.hpp"

Player::Player()
{
	_xPos = 20;
	_yPos = 48;
	_wideFig = 3;
	// _whereX = 47;//поле ширина 99, при чому з 0, середина на 50
	// _life	= 3;
}

Player::~Player(){}

// void	Player::moving(int n)
// {
// 	_whereX += n;
// 	if (_whereX < 2)
// 		_whereX = 2;
// 	else if (_whereX > 96)
// 		_whereX = 96;
// }