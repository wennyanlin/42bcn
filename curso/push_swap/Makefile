# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 16:49:23 by wlin              #+#    #+#              #
#    Updated: 2023/11/19 23:02:09 by wlin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INCLUDES = push_swap.h

LIBFT = ./libft/libft.a

SRCS = push_swap_main.c

OBJS = $(SRCS:.c=.o)

COMPILER = gcc

CFLAGS = -Wall -Werror -Wextra

#%.o: %.c Makefile $(INCLUDES)
#	$(COMPILER) $(CFLAGS) -I $(INCLUDES) -c $< -o $(NAME)

$(NAME): lib $(LIBFT) $(OBJS) $(INCLUDES) Makefile
	$(COMPILER) $(SRCS) -L./libft -lft -o $(NAME)

lib:
	$(MAKE) -C ./libft

all: lib $(NAME)

clean:
		rm -f $(OBJS) 
		$(MAKE) -C ./libft fclean

fclean: clean
		rm -f $(NAME)

re:		flean all

.PHONY: all clean fclean re
