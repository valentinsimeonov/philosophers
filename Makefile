NAME = philo

SRC = philosophers.c checkers.c utils.c initialize.c

INCLUDE = philosophers.h

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

RM = rm -f

all: $(NAME)

$(%.o): $(%.c)
	$(CC) -o $@ -c $^

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) -o $@ $(OBJ)


clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re