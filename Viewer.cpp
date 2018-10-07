#include "Header.hpp"

Viewer::Viewer(){
	initscr();
	clear();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(FALSE);
	start_color();

	_win = newwin(50, 120, 0, 0);
	welcome_window();
	draw_borders(_win);
}

Viewer::~Viewer()
{
	delwin(_win);
	endwin();
}

Viewer::Viewer(Viewer const &src)
{
	*this = src;
	return ;
}

Viewer & Viewer::operator=( Viewer const &rhs )
{
	if(this != &rhs)
		_win = rhs.getWindow();
	return *this;
}

WINDOW*	Viewer::getWindow() const
{
	return _win;
}

void Viewer::draw_borders(WINDOW *screen)
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

void Viewer::welcome_window()
{
	init_pair(1, COLOR_GREEN, COLOR_BLACK);

	attron(COLOR_PAIR(1));
	mvaddstr(10, 20,"               _                          ");
	mvaddstr(11, 20,"              | |                         ");
	mvaddstr(12, 20," __      _____| | ___ ___  _ __ ___   ___ ");
	mvaddstr(13, 20," \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\");
	mvaddstr(14, 20,"  \\ V  V /  __/ | (_| (_) | | | | | |  __/");
	mvaddstr(15, 20,"   \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|");
	mvaddstr(16, 20,"                                          ");
	mvaddstr(17, 25,"press a button to begin the game");
	attroff(COLOR_PAIR(1));
}

void	Viewer::print_shots(Player* p)
{
	for (int i = 0; p->getYPosN(i) != -1 ; ++i)
	{
		mvwprintw(_win, p->getYPosN(i), p->getXPosN(i),"o");
	}
}

int Viewer::onScreen(Player* p , int ch, Viewer *v)
{

	if(ch == 'q' || ch =='Q') 
		return 0;
	wclear(_win);
	v->draw_borders(_win);
	mvwprintw(_win, p->getYPos(), p->getXPos(),"---");
	wrefresh(_win);

	while(1)
	{
		ch = getch();
		
		if(ch == KEY_LEFT)
			p->setXPos(p->getXPos() - 1);
		else if(ch == KEY_RIGHT)
			p->setXPos(p->getXPos() + 1);
		else if (ch == ' ')
			p->haveShot();
		else if(ch == 'q' || ch == 'Q')
			break;
		wclear(_win);
		draw_borders(_win);
		print_shots(p);
		mvwprintw(_win, p->getYPos(), p->getXPos(),"---");
		wrefresh(_win);
	}
	return (0);
}