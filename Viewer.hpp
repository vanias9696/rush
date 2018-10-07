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

		WINDOW*		getWindow(void) const;


		void 		draw_borders(WINDOW *screen);
		void 		welcome_window();
		int 		onScreen(Player* p, int ch, Viewer *v);
		void		print_shots(Player* p);
		void		print_background(Background *b);
		std::time_t 	getTime(void);
};

#endif