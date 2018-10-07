NAME = ft_retro

SRCS = main.cpp Object.cpp Shot.cpp Background.cpp\
Player.cpp Viewer.cpp Controller.cpp Enemy.cpp\

OBJ = $(SRCS:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):$(OBJ)
	clang++ $(CPPFLAGS) $(SRCS) -lncurses -o $(NAME)
	@echo "\x1B[0;32m"$(NAME)" ready!\x1B[0;37m"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.cpp
	clang++ $(FLAGS) -o $@ -c $<
