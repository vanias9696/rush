#include "Header.hpp"

Background::Background(){
	srand( time( NULL ) );
	_numStars = 100;
	// for (int i = 0; i < _numStars; ++i)
	// {
	// 	haveStar();
	// }
}

Background::~Background()
{
	
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
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = new(t_star);
		tmp->next->star = star;
		tmp->next->next = 0;
	}
}

int	Background::getNumStars(void){return _numStars;}
int	Background::getXPos(void){return _xPos;}
int	Background::getYPos(void){return _yPos;}