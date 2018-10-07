#include <ncurses.h>
#include "Controller.hpp"

int main() 
{
	Viewer *v = new Viewer();
	Player* p = new Player();
	Controller *c = new Controller();

	c->game_loop(p, v);

	delete v;
	delete p;
	delete c;
	return 0;
}
