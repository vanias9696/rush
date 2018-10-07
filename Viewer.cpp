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
	my_clear(_win);
	game_over();
	wrefresh(_win);
	sleep(2);
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

void Viewer::game_over()
{
	init_pair(3, COLOR_RED, COLOR_BLACK);

	wattron(_win, COLOR_PAIR(3));
	mvwprintw(_win, 10, 20,"   __ _  __ _ _ __ ___   ___    _____   _____ _ __ ");
	mvwprintw(_win, 11, 20,"  / _` |/ _` | '_ ` _ \\ / _ \\  / _ \\ \\ / / _ \\ '__|");
	mvwprintw(_win, 12, 20," | (_| | (_| | | | | | |  __/ | (_) \\ V /  __/ |    ");
	mvwprintw(_win, 13, 20,"  \\__, |\\__,_|_| |_| |_|\\___|  \\___/ \\_/ \\___|_|   ");
	mvwprintw(_win, 14, 20,"   __/ |                                           ");
	mvwprintw(_win, 15, 20,"  |___/                                            ");
	mvwprintw(_win, 16, 20,"                                          ");
	// mvaddstr(17, 25,"");
	wattroff(_win, COLOR_PAIR(3));
}

void	Viewer::print_shots(Player* p)
{
	init_pair(2, COLOR_RED, COLOR_BLACK);
	for (int i = 0; p->getYPosN(i) != -1 ; ++i)
	{
		wattron(_win, COLOR_PAIR(2));
		mvwprintw(_win, p->getYPosN(i), p->getXPosN(i),"o");
		wattroff(_win, COLOR_PAIR(2));
	}
}

void 	Viewer::print_background(Background *b)
{
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	for (int i = 0; i < b->getNumStars(); ++i)
	{
		wattron(_win, COLOR_PAIR(4));
		mvwprintw(_win, b->getYPosN(i), b->getXPosN(i), "*");
		wattroff(_win, COLOR_PAIR(4));
	}
}

void	Viewer::print_enemy(Enemy* e)
{
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	for (int i = 0; e->getYPosN(i) != -1 ; ++i)
	{
		wattron(_win, COLOR_PAIR(5));
		mvwprintw(_win, e->getYPosN(i), e->getXPosN(i),"\\AAA/");
		wattroff(_win, COLOR_PAIR(5));
	}
}

void	Viewer::my_clear(WINDOW *_win)
{
	for (int i = 0; i < 120; ++i)
	{
		for (int j = 0; j < 50; ++j)
		{
			mvwaddch(_win, j, i, ' ');
		}
	}
}

int Viewer::onScreen(Player* p , int ch, Viewer *v, Enemy *e)
{
	int i;
	if(ch == 'q' || ch =='Q') 
		return 0;
	wclear(_win);
	v->draw_borders(_win);
	mvwprintw(_win, p->getYPos(), p->getXPos(),"###");
	wrefresh(_win);
	e->addRow();
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
		if (i % 2000 == 0)
			_bg->moving_star();
		if (i % 900 == 0)
			e->move();
		if (i % 2700 == 0)
			e->addRow();
		if (i % 300 == 0)
		{
			p->moving_shot();
			p->check_kill(e);
			if (e->check_player(p) == -1)
				break;
		}

		my_clear(_win);
		print_background(_bg);
		draw_borders(_win);
		print_shots(p);
		print_enemy(e);
		mvwprintw(_win, p->getYPos(), p->getXPos(),"###");
		wrefresh(_win);
	}
	return (0);
}