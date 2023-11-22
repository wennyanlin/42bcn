# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 16:49:23 by wlin              #+#    #+#              #
#    Updated: 2023/11/22 19:25:26 by wlin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INCLUDES = push_swap.h

LIBFT = ./libft/libft.a

SRCS = push_swap_main.c move_swap.c move_rotate.c

OBJS = $(SRCS:.c=.o)

COMPILER = gcc

CFLAGS = -g -Wall -Werror -Wextra -fsanitize=address

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

re:		fclean all

.PHONY: all clean fclean re
