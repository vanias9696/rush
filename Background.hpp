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

		void	haveStar(void);
		int		getNumStars(void);
		int		getXPos(void);
		int		getYPos(void);


	private:
		t_star	*_stars;
		int		_numStars;

};

#endif