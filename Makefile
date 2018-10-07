NAME = ft_retro

SRCS = main.cpp Object.cpp Shot.cpp\
Player.cpp Viewer.cpp Controller.cpp Enemy.cpp\

OBJ = $(SRCS:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	clang++ $(CPPFLAGS) $(SRCS) -lncurses -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.cpp
	clang++ $(FLAGS) -o $@ -c $<

