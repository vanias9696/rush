#include <ncurses.h>
#include "Player.hpp"

void draw_borders(WINDOW *screen)
{ 
	int x, y, i;
	getmaxyx(screen, y, x);
	mvwprintw(screen, 0, 0, "+");
	mvwprintw(screen, y - 1, 0, "+");
	mvwprintw(screen, 0, x - 1, "+");
	mvwprintw(screen, y - 1, x - 1, "+");
	for (i = 1; i < (y - 1); i++) 
	{
		mvwprintw(screen, i, 0, "|");
		mvwprintw(screen, i, x - 1, "|");
	}
	for (i = 1; i < (x - 1); i++)
	{
		mvwprintw(screen, 0, i, "-");
		mvwprintw(screen, y - 1, i, "-");
	}
}

int controller(Player* p, int ch, WINDOW *win)
{
	if(ch == 'q' || ch =='Q') 
		return 0;
	// wrefresh(win);
	wclear(win);
	draw_borders(win);
	 mvwprintw(win, p->getYPos(), p->getXPos(),"---");
	 wrefresh(win);
	// mvwprintw(win, p->getYPos(), p->getXPos(), p->getSign());
	// mvaddch(p->getYPos(), p->getXPos(), p->getSign());

	while(1)
	{
		ch = getch();
		
		if(ch == KEY_LEFT) {
			p->setXPos(p->getXPos() - 1);
			wclear(win);
			draw_borders(win);
			 mvwprintw(win, p->getYPos(), p->getXPos(),"---");
			// mvwprintw(win, p->getYPos(), p->getXPos(), p->getSign());
			// mvaddch(p->getYPos(), p->getXPos(), p->getSign());
			wrefresh(win);
		}
		else if(ch == KEY_RIGHT) {
			p->setXPos(p->getXPos() + 1);
			wclear(win);
			draw_borders(win);
			 mvwprintw(win, p->getYPos(), p->getXPos(),"---");
			// mvwprintw(win, p->getYPos(), p->getXPos(), p->getSign());
			// mvaddch(p->getYPos(), p->getXPos(), p->getSign());
			wrefresh(win);
		}
		else if(ch == 'q' || ch == 'Q') {
			break;
		}
		wrefresh(win);
	}
	return (0);
}

int main() 
{

	initscr();
	clear();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(FALSE);

	WINDOW *win = newwin(50, 120, 0, 0);
	// int ch = getch();

	Player* p = new Player();
	int ch = getch();
	draw_borders(win);
	while(1) 
	{ 
		// mvwprintw(win, 1, 1, " ");
		// wrefresh(win);

		if (!controller(p, ch, win))
			break;

	}
	delwin(win);
	endwin();
	return 0;
}
