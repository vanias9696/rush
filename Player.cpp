#include "Header.hpp"

Player::Player()
{
	_xPos = 20;
	_yPos = 48;
	_wideFig = 3;
	_list = NULL;
	_score = 0;
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

Player::Player(Player const &src)
{
	*this = src;
	return ;
}

Player	&Player::operator=(Player const &rhs )
{
	if(this != &rhs)
		return *this;
	return *this;
}

int		Player::getScore(void) const{ return _score;}

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
				_score++;
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
	if (!tmp)
		return -1;
	return (tmp->shot->getYPos());
}

void	Player::delete_shot(t_shot *delNext)
{
	t_shot	*tmp;

	tmp = _list;
	tmp = delNext->next->next;
	delete delNext->next->shot;
	delete delNext->next;
	delNext->next = tmp;
}


void	Player::moving_shot()
{
	t_shot	*tmp;

	if (_list == 0)
		return ;
	tmp = _list;
	while (tmp && tmp->shot->getYPos() - 1 <= 0)
	{
		tmp = tmp->next;
		delete _list->shot;
		if (tmp)
			*(_list) = *tmp;
		else
			_list = NULL;
	}
	if (tmp == NULL)
		return ;
	tmp->shot->setYPos(tmp->shot->getYPos() - 1);
	while(tmp->next)
	{
		tmp->next->shot->setYPos(tmp->next->shot->getYPos() - 1);
		if (tmp->next->shot->getYPos() <= 0)
		{
			delete_shot(tmp);
		}
		tmp = tmp->next;
	}
}


int	Player::check_enemy(int x, int y, Enemy *enemy)
{
	t_enemy *tmp;

	tmp = enemy->_list;
	if ((y == tmp->enemy->getYPos() ||
			y - 1 == tmp->enemy->getYPos()) && 
			(x == tmp->enemy->getXPos() || x - 1 == tmp->enemy->getXPos() ||
			x - 2 == tmp->enemy->getXPos() || x - 3 == tmp->enemy->getXPos()
			|| x - 4 == tmp->enemy->getXPos()))
	{
		enemy->delete_enemy(0, tmp);
	}
	while (tmp && tmp->next)
	{
		if ((y == tmp->next->enemy->getYPos() ||
				y - 1 == tmp->next->enemy->getYPos()) && 
				(x == tmp->next->enemy->getXPos() || x - 1 == tmp->next->enemy->getXPos() ||
				x - 2 == tmp->next->enemy->getXPos() || x - 3 == tmp->next->enemy->getXPos()
				|| x - 4 == tmp->next->enemy->getXPos()))
		{
			_score++;
			enemy->delete_enemy(1, tmp);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}


void Player::check_kill(Enemy *enemy)
{
	t_shot *tmp;

	tmp = _list;

	while (tmp && check_enemy(tmp->shot->getXPos(), tmp->shot->getYPos() , enemy) == 1)
	{
		tmp = tmp->next;
		delete _list->shot;
		if (tmp)
			*(_list) = *tmp;
		else
			_list = NULL;
	}
	while (tmp && tmp->next)
	{
		if (check_enemy(tmp->next->shot->getXPos(), tmp->next->shot->getYPos() , enemy) == 1)
		{
			delete_shot(tmp);
		}
		else
			tmp = tmp->next;
	}
}
