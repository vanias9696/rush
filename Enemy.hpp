#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "Object.hpp"

class Enemy: public Object
{
	public:
		Enemy();
		~Enemy();

		Enemy(Enemy const & rhs);
		Enemy &operator=( Enemy const &rfs );

	private:

};

#endif