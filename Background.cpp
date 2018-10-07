#include "Header.hpp"

Background::Background(){
	srand( time( NULL ) );
	_numStars = 100;
	for (int i = 0; i < _numStars; ++i)
	{
		haveStar();
	}
}

Background::~Background()
{
	t_star	*tmp;

	while (_stars)
	{
		tmp = _stars;
		delete tmp->star;
		_stars = _stars->next;
		delete tmp;
	}
}

Background::Background(Background const &src)
{
	*this = src;
	return ;
}

Background & Background::operator=( Background const &rhs )
{
	if(this != &rhs)
		return *this;
	return *this;
}

void	Background::haveStar()
{
	int randX = rand() % 120;
	int randY = rand() % 50;

	t_star *tmp;
	Object	*star = new Object(randX, randY);

	if (_stars == NULL)
	{
		_stars = new(t_star);
		_stars->star = star;
		_stars->next = NULL;
	}
	else
	{
		tmp = _stars;
		while(tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = new(t_star);
		tmp->next->star = star;
		tmp->next->next = 0;
	}
}

int	Background::getNumStars(void){return _numStars;}
int	Background::getXPosN(int N){
	t_star	*tmp;

	tmp = _stars;
	while (N != 0 && tmp)
	{
		tmp = tmp->next;
		N--;
	}
	return (tmp->star->getXPos());
}
int	Background::getYPosN(int N){
	t_star	*tmp;

	tmp = _stars;
	while (N != 0 && tmp)
	{
		tmp = tmp->next;
		N--;
	}
	return (tmp->star->getYPos());
}

void	Background::new_star(t_star *tmp)
{
	tmp->star->setYPos(1);
	tmp->star->setXPos(15);
}

void	Background::moving_star()
{
	t_star	*tmp;

	if (_stars == 0)
		return ;
	tmp = _stars;
	while(tmp)
	{
		tmp->star->setYPos(tmp->star->getYPos() + 1);
		if (tmp->star->getYPos() >= 48)
		{
			tmp->star->setYPos(1);
		}
		tmp = tmp->next;
	}
}
