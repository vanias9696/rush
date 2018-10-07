#ifndef VIEWER_HPP
#define VIEWER_HPP
#include "Header.hpp"

class Background;

class Viewer
{
	private:
		WINDOW 		*_win;
		Background*  _bg;
		std::time_t	_time;


	public:
		Viewer();
		~Viewer();
		Viewer(Viewer const &src);
		Viewer	&operator=( Viewer const &rhs );

		WINDOW*			getWindow(void) const;


		void 			draw_borders(WINDOW *screen);
		void 			welcome_window();
		void 			game_over();
		int 			onScreen(Player* p, int ch, Viewer *v, Enemy *e);
		void			print_shots(Player* p);
		void			print_background(Background *b);
		void			print_enemy(Enemy* e);
		std::time_t 	getTime(void);
		void			my_clear(WINDOW *_win);
};

#endif
