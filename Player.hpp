#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
	private:
		int		_whereX;
		int		_life;
		int		_sign;
	public:
		Player();
		~Player();

		void	moving(int n);	
		

	
};

#endif


private:
		std::string _name;    
		int			_ap;
		AWeapon		*_wpn;

	public:
		Character();
		~Character();
		Character(std::string const & name);
		Character(Character const &rfs);
		Character	&operator=( Character const &rfs );



 *** 
*****
                                  ....................................................................................................