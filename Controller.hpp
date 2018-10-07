#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include "Header.hpp"

class Viewer;

class Controller
{

	public:
		Controller();
		~Controller();
		Controller(Controller const & rhs);
		Controller			&operator=( Controller const &rfs );

		void			game_loop(Player* p, Viewer *v, Enemy* e);
		
		void 			setLevel(int level);
		void 			setScore(int score);
		int 			getLevel(void);
		int 			getScore(void);
};

#endif