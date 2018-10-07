#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Header.hpp"

class Shot;

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
		// Player(Player const &rfs);
		// Player	&operator=( Player const &rfs );
		int			getXPosN(int N);
		int			getYPosN(int N);

};

#endif
