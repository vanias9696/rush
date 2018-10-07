#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include "Header.hpp"

class Viewer;

class Controller
{
	private:
		int	_score;
		int _level;
		std::time_t	_time;

	public:
		Controller();
		~Controller();
		Controller(Controller const & rhs);
		Controller			&operator=( Controller const &rfs );

		void			game_loop(Player* p, Viewer *v);
		
		void 			setLevel(int level);
		void 			setScore(int score);
		int 			getLevel(void);
		int 			getScore(void);
		std::time_t 	getTime(void);
};

#endif