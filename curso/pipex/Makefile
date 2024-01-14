NAME = pipex

INCLUDES = pipex.h

SRCS = pipex.c split.c\

OBJS = $(SRCS:.c=.o)

COMPILER = gcc

CFLAGS = -g -Wall -Werror -Wextra

$(NAME): $(OBJS) $(INCLUDES) Makefile
		$(COMPILER) $(SRCS) -g -fsanitize=address -o $(NAME)

all:
	$(MAKE)

clean:
		rm -f $(OBJS)
		$(MAKE) fclean

fclean:	clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
