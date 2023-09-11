# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/09 20:06:48 by wlin              #+#    #+#              #
#    Updated: 2023/09/09 20:06:54 by wlin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCLUDES = libft.h

SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint \
ft_strlen.c ft_tolower.c ft_toupper.c

OBJS = $(SRC:.c=.o)

COMPILER = cc

FLAGS = -Wall -Werror -Wextra

%.o: %.c
	${COMPILER} ${FLAGS} -I ${INCLUDES} -c $< -o $@

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f$(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	fclean all

.PHONY:
	all bonus clean fclean re
//https://dev.to/mcaci/the-meaning-of-the-phony-target-inside-a-makefile-4fj8

/****THIS IS ONLY A COMMENT****
resource:
//specialsigns = https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html#Automatic-Variables
*/
