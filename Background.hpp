#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "Header.hpp"

class Background : public Object
{
	typedef struct s_list
	{
		Object		*star;
		s_list		*next;
	}				t_star;

	public:
		Background();
		~Background();
		Background(Background const & rhs);
		Background			&operator=( Background const &rfs );

		void	haveStar();
		int		getNumStars(void);
		int		getXPosN(int N);
		int		getYPosN(int N);

		void	new_star(t_star *tmp);
		void	moving_star();

	private:
		t_star	*_stars;
		int		_numStars;

};

#endif
