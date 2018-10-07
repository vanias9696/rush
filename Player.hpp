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
		int			_score;

	public:
		Player();
		~Player();
		Player(Player const &rfs);
		Player	&operator=( Player const &rfs );


		void		haveShot();
		void		delete_shot(t_shot *delNext);
		void		moving_shot();
		int			getXPosN(int N);
		int			getYPosN(int N);
		int			getScore(void) const;
		int			check_enemy(int x, int y, Enemy *enemy);
		void 		check_kill(Enemy *enemy);

};

#endif
