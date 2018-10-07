#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Header.hpp"

class Shot;
class Enemy;

class Player : public Object
{
	typedef struct s_list
	{
		Shot		*shot;
		s_list		*next;
	}				t_shot;

	private:
		t_shot		*_list;
		// int		_life;

	public:
		Player();
		~Player();
		void	haveShot();
		void	delete_shot(t_shot *delNext);
		void	moving_shot();
		Player(Player const &rfs);
		Player	&operator=( Player const &rfs );
		int			getXPosN(int N);
		int			getYPosN(int N);
		int	check_enemy(int x, int y, Enemy *enemy);
		void check_kill(Enemy *enemy);

};

#endif
