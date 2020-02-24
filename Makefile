# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/11 16:48:33 by weilin            #+#    #+#              #
#    Updated: 2020/02/24 10:25:41 by mdavid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB_FOLDER = libft/
LIB_FILES = ft_atoi ft_strlen ft_bzero ft_isdigit ft_strchr ft_int_len \
			ft_strdup ft_strsub ft_strtolower ft_strjoin ft_strnew ft_strcat \
			ft_strcpy ft_itoa ft_strnew_c ft_strdel ft_memalloc ft_strjoin \
			ft_putnbr ft_putchar ft_strcmp

FILES = ft_printf parse tool type_csp print_chars print_addr type_di base \
	type_ox print_int

FILES+= $(addprefix $(LIB_FOLDER),$(LIB_FILES))

CC = gcc
FLAG = -Wall -Wextra -Werror -g -I $(INC_DIR)

RM = rm -rf

CCH_DIR = cache/
SRC_DIR = src/
INC_DIR = include/

SRC = $(addprefix $(SRC_DIR),$(addsuffix .c,$(FILES)))
OBJ = $(addprefix $(CCH_DIR),$(addsuffix .o,$(FILES)))

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^
# Running "ar s" on an archive is equivalent to running ranlib on it.

$(CCH_DIR)%.o: $(SRC_DIR)%.c | $(CCH_DIR)
	$(CC) $(FLAG) -c $< -o $@

$(CCH_DIR):
	mkdir $@
	mkdir $(CCH_DIR)$(LIB_FOLDER)

clean:
	$(RM) $(CCH_DIR)
	$(RM) *.o
	$(RM) *.out*

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

norm:
	@echo $(RED)
	@echo $(END)
	# norminette $(SRC) $(INC_DIR) | grep -v Norme -B1 || true

.PHONY: all clean fclean re norm
