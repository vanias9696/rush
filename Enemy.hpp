#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "Object.hpp"

class Enemy: public Object
{
	typedef struct s_list
	{
		Enemy		*enemy;
		s_list		*next;
	}				t_enemy;

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

	private:
		t_enemy *_list;

};

#endif
