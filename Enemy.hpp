#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "Header.hpp"

typedef struct s_list t_enemy;

class Enemy: public Object
{

	public:
		Enemy();
		Enemy(int x, int y);
		~Enemy();

		Enemy(Enemy const & rhs);
		Enemy &operator=( Enemy const &rfs );
		void		addEnemy(int x, int y);
		void		addRow();
		void		move();
		void		delete_enemy(int i, t_enemy *delNext);
		int			getXPosN(int N);
		int			getYPosN(int N);

	// private:
		t_enemy *_list;

};

#endif
