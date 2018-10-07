#include "Header.hpp"

Controller::Controller(){
}

Controller::~Controller()
{
}

Controller::Controller(Controller const &src)
{
	*this = src;
	return ;
}

Controller & Controller::operator=( Controller const &rhs )
{
	if(this != &rhs)
		return *this;
	return *this;
}

void Controller::game_loop(Player* p, Viewer *v, Enemy *e)
{
	int ch = getch();
	while(1) 
	{
		if (!v->onScreen(p, ch, v, e))
			break;
	}
}