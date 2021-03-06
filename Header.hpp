#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <ncurses.h>
#include <iostream>
#include <ctime>
#include "Object.hpp"
#include "Player.hpp"
#include "Shot.hpp"
#include "Enemy.hpp"
#include "Controller.hpp"
#include "Viewer.hpp"
#include "Background.hpp"
#include <stdio.h>
#include <unistd.h>

typedef struct s_list
{
	Enemy		*enemy;
	s_list		*next;
}				t_enemy;

#endif
