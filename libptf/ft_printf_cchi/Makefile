# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 13:05:03 by cchi              #+#    #+#              #
#    Updated: 2019/07/28 23:38:23 by cchi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
FLAGS = -Wall -Wextra -g -Werror

SRC_DIR = src/
LIB_DIR = libft/
CCH_DIR = cache/
INC_DIR = include/

SRC_FILES = ft_printf.c ft_case_c.c ft_case_d.c ft_case_f.c ft_case_o.c \
		ft_case_p.c ft_case_s.c ft_case_u.c ft_case_x.c ft_f_add.c ft_f_bin.c \
		ft_f_cal_p2.c ft_f_l.c ft_f_l2.c ft_f_revcat.c ft_f_round.c \
		ft_fill_sign.c ft_flag.c ft_str_str2.c tp_zeroing.c ft_buffer.c \
		ft_arr_ft.c ft_mts_bin.c ft_fill_zero.c ft_case_per.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJECTS = $(addprefix $(CCH_DIR),$(SRC_FILES:.c=.o))
LIBFT = $(LIB_DIR)libft.a

all: $(NAME)


$(NAME): $(OBJECTS) $(LIBFT)
	ar rcs $@ $^


$(CCH_DIR)%.o: $(SRC_DIR)%.c | $(CCH_DIR)
	$(CC) $(FLAGS) -c $< -o $@ -I$(INC_DIR) -I$(LIB_DIR)


$(LIBFT):
	$(MAKE) -C $(LIB_DIR) all

$(CCH_DIR):
	mkdir $@

clean:
	rm -rf $(CCH_DIR)
	@$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIB_DIR) fclean 

re: fclean all

.PHONY: all clean fclean re
