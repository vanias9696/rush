#ifndef SHOT_HPP
#define SHOT_HPP
#include "Header.hpp"

class Object;

class Shot : public Object
{
	public:
		Shot(int x, int y); // гравець пускає на y = 1 пуля з X = середина корабля
		~Shot();
		// Shot(Shot const &rfs);
		// Shot	&operator=( Shot const &rfs );

};

#endif
