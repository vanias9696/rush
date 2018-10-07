#include "Header.hpp"

Player::Player()
{
	_xPos = 20;
	_yPos = 48;
	_wideFig = 3;
	_list = NULL;
	// _whereX = 47;//поле ширина 99, при чому з 0, середина на 50
	// _life	= 3;
}

Player::~Player()
{
	t_shot	*tmp;

	while (_list)
	{
		tmp = _list;
		delete tmp->shot;
		_list = _list->next;
		delete tmp;
	}
}

void	Player::haveShot()
{
	t_shot *tmp;
	Shot	*shot = new Shot(_xPos + 1, _yPos - 1);

	if (_list == NULL)
	{
		_list = new(t_shot);
		_list->shot = shot;
		_list->next = NULL;
	}
	else
	{
		tmp = _list;
		while(tmp->next)
		{
			if ((tmp->shot->getXPos() == _xPos + 1) && (tmp->shot->getYPos() == 47))
			{
				delete shot;
				return;
			}
			tmp = tmp->next;
		}
		tmp->next = new(t_shot);
		tmp->next->shot = shot;
		tmp->next->next = 0;
	}
}

int			Player::getXPosN(int N)
{
	t_shot	*tmp;

	tmp = _list;
	while (N != 0 && tmp)
	{
		tmp = tmp->next;
		N--;
	}
	return (tmp->shot->getXPos());
}

int			Player::getYPosN(int N)
{
	t_shot	*tmp;

	tmp = _list;
	while (N != 0 && tmp)
	{
		tmp = tmp->next;
		N--;
	}
	return (tmp->shot->getYPos());
}
