#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Header.hpp"

class Object
{
	public:
		Object(void);
		Object(int x, int y);
		Object(Object const &rfs);
		~Object(void);
		Object			&operator=( Object const &rfs );

		int				getXPos(void);
		int				getYPos(void);
		std::string			getSign(void);

		void			setXPos(int n);
		void			setYPos(int n);

	protected:
		int				_xPos;
		int				_yPos;
		int 			_wide;
		int				_hight;
		int				_wideFig;
};

#endif
