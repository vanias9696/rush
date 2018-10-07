#include <ncurses.h>
#include "Controller.hpp"

int main() 
{
	Viewer *v = new Viewer();
	Player* p = new Player();
	Enemy*	e = new Enemy();
	Controller *c = new Controller();

	c->game_loop(p, v, e);

	delete v;
	delete p;
	delete c;
	return 0;
}
