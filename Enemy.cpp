#include "Header.hpp"

Enemy::Enemy(){
	_list = NULL;
}

Enemy::Enemy(int x, int y)
{
	_xPos = x;
	_yPos = y;
	_list = NULL;
}

Enemy::~Enemy(){}

Enemy::Enemy(Enemy const &src)
{
	*this = src;
	return ;
}

Enemy	&Enemy::operator=(Enemy const &rhs )
{
	if(this != &rhs)
		return *this;
	return *this;
}

void	Enemy::addEnemy(int x, int y)
{
	t_enemy *tmp;
	Enemy *enemy = new Enemy(x, y);

	if(_list == NULL)
	{
		_list = new(t_enemy);
		_list->enemy = enemy;
		_list->next = NULL;
		return ;
	}
	tmp = _list;
	while(tmp && tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new(t_enemy);
	tmp->next->enemy = enemy;
	tmp->next->next = 0;
}

void	Enemy::addRow()
{
	int x;
	x = rand() % 33 + 1;
	addEnemy(x, 1);
	x = 39 + rand() % 34;
	addEnemy(x, 1);
	x = 80 + rand() % 32;
	addEnemy(x, 1);
}

void	Enemy::delete_enemy(int i, t_enemy *delNext)
{
	t_enemy	*tmp;

	tmp = _list;
	if (i == 0)
	{
		tmp = tmp->next;
		delete _list->enemy;
		*(_list) = *tmp;
		return ;
	}
	tmp = delNext->next->next;
	delete delNext->next->enemy;
	delete delNext->next;
	delNext->next = tmp;
}

void	Enemy::move()
{
	t_enemy	*tmp;

	if (_list == 0)
		return ;
	tmp = _list;
	while (tmp->enemy->getYPos() + 1 >= 49)
	{
		delete_enemy(0, tmp);
	}
	tmp->enemy->setYPos(tmp->enemy->getYPos() + 1);
	while(tmp->next)
	{
		tmp->next->enemy->setYPos(tmp->next->enemy->getYPos() + 1);
		if (tmp->next->enemy->getYPos() >= 49)
			delete_enemy(1, tmp);
		tmp = tmp->next;
	}
}


int			Enemy::getXPosN(int N)
{
	t_enemy	*tmp;

	tmp = _list;
	while (N != 0 && tmp)
	{
		tmp = tmp->next;
		N--;
	}
	return (tmp->enemy->getXPos());
}

int			Enemy::getYPosN(int N)
{
	t_enemy	*tmp;

	tmp = _list;
	while (N != 0 && tmp)
	{
		tmp = tmp->next;
		N--;
	}
	if (!tmp)
		return -1;
	return (tmp->enemy->getYPos());
}

int	Enemy::check_player(Player *p)
{
	t_enemy	*tmp;
	
	tmp = _list;
	while (tmp)
	{
		if ((p->getYPos() == tmp->enemy->getYPos()) &&
			(tmp->enemy->getXPos() - p->getXPos() >= -4 &&
			 tmp->enemy->getXPos() - p->getXPos() <= 2))
		{
			return (-1);
		}
		tmp = tmp->next;
	}
	return (1);
}
















