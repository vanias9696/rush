#include "Header.hpp"

Viewer::Viewer(){
	_bg = new Background();
	initscr();
	clear();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(FALSE);
	start_color();

	_win = newwin(50, 120, 0, 0);
	nodelay(_win, true);
	_time = std::time(nullptr);
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

WINDOW*		Viewer::getWindow() const{return _win;}
std::time_t Viewer::getTime(void){return _time;};

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

// void 	Viewer::print_background(Background *b)
// {
// 	for (int i = 0; i < b->getNumStars(); ++i)
// 	{
// 		mvwprintw(_win, b->_stars->star->getXPos(), b->_stars->star->getYPos();,"*");
// 	}
// }

int Viewer::onScreen(Player* p , int ch, Viewer *v)
{
	int i;
	if(ch == 'q' || ch =='Q') 
		return 0;
	wclear(_win);
	v->draw_borders(_win);
	mvwprintw(_win, p->getYPos(), p->getXPos(),"---");
	wrefresh(_win);
	i = 0;
	while (1)
	{
		i++;
		ch = 0;
		ch = wgetch(_win);
		if(ch == 'a' || ch == 'A')
			p->setXPos(p->getXPos() - 1);
		else if(ch == 'd' || ch == 'D')
			p->setXPos(p->getXPos() + 1);
		else if (ch == ' ')
			p->haveShot();
		else if(ch == 'q' || ch == 'Q')
			break;
		if (i % 300 == 0)
		{
			// p->setYPos(p->getYPos() - 1);
		}
		wclear(_win);
		draw_borders(_win);
		// print_background(_bg);
		print_shots(p);
		mvwprintw(_win, p->getYPos(), p->getXPos(),"---");
		wrefresh(_win);
	}
	return (0);
}