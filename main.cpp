#include <ncurses.h>
#include "Player.hpp"

void erase (int y, int x) {
	mvaddch(y, x, ' ');
}

int controller(Player* p, int ch)
{
	if(ch == 'q' || ch =='Q') 
		return 0;

	mvaddch(p->getYPos(), p->getXPos(), p->getSign());
	refresh();

	while(1)
	{
		ch = getch();
		
		if(ch == KEY_LEFT) {
			erase(p->getYPos(), p->getXPos());
			p->setXPos(p->getXPos() - 1);
			mvaddch(p->getYPos(), p->getXPos(), p->getSign());
			refresh();
		}
		else if(ch == KEY_RIGHT) {
			erase(p->getYPos(), p->getXPos());
			p->setXPos(p->getXPos() + 1);
			mvaddch(p->getYPos(), p->getXPos(), p->getSign());
			refresh();
		}
		else if(ch == 'q' || ch == 'Q') {
			break;
		}
	}
	return 1;
}

int main() {

	initscr();
	clear();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);

	int ch = getch();


	Player* p = new Player();

	controller(p, ch);

	endwin();
	return 0;
}
