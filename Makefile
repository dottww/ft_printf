# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: weilin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/11 16:48:33 by weilin            #+#    #+#              #
#    Updated: 2019/02/12 20:06:13 by weilin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

SRC = main.c

INCL = fillit.h

OBJS = $(SRC:.c=.o)

RM = rm -rf

FLAG = -Wall -Wextra -Werror

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	gcc -g $(FLAG) -L ./libft -lft $(SRC) -o $@
# gcc -g $(FLAG) -L ./libft -lft $(OBJS) -o $@
# to use outside lib, must have that lib already compiled to .a so be able to use it
# -I is to tell the current project header the place where to find ouside header
# -L is to tell the current project header the place where to find ouside lib
# -l tells please use/read lib"ft".a
# $@ == $(NAME)

$(LIBFT):
	make -C libft all
#it will call the makefile in the destination

%.o: %.c
	gcc -c $< -o $@ -I libft/
#if .o is older than .c, then do the content
# $< means the first prerequisite
# $^ means the all prerequisites

clean:
	$(RM) $(OBJS)
	$(RM) *.out*
# make -C libft clean

fclean: clean
	$(RM) $(NAME)
# make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
