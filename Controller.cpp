#include "Header.hpp"

Controller::Controller(){
	
	_time = std::time(nullptr);
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
	//ДАЛЬШЕ КОСТЫЛЬ
	if(this != &rhs)
		return *this;
	return *this;
}

void Controller::game_loop(Player* p, Viewer *v)
{
	int ch = getch();
	while(1) 
	{ 
		if (!v->onScreen(p, ch, v))
			break;
	}
}

std::time_t Controller::getTime(void){return _time;};