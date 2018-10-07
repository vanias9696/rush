#ifndef VIEWER_HPP
#define VIEWER_HPP
#include "Header.hpp"

class Viewer
{
	private:
		WINDOW 		*_win;


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
};

#endif