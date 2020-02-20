# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 13:05:03 by cchi              #+#    #+#              #
#    Updated: 2019/07/29 14:44:23 by cchi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_FILES = ft_strlen.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
	  ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c \
	  ft_strncmp.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	  ft_memchr.c ft_memcmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
	  ft_isalnum.c ft_isascii.c ft_isprint.c ft_bzero.c ft_toupper.c\
	  ft_tolower.c ft_strdup.c ft_memalloc.c ft_memdel.c ft_strnew.c\
	  ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c\
	  ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strlcat.c\
	  ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c\
	  ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c\
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_nmot.c ft_lstnew.c\
	  ft_lstdelone.c ft_lstdelone.c ft_lstdel.c ft_lstiter.c ft_lstadd.c\
	  ft_lstmap.c ft_printf.c ft_case_c.c ft_case_d.c ft_case_f.c ft_case_o.c \
		ft_case_p.c ft_case_s.c ft_case_u.c ft_case_x.c ft_f_add.c ft_f_bin.c \
		ft_f_cal_p2.c ft_f_l.c ft_f_l2.c ft_f_revcat.c ft_f_round.c \
		ft_fill_sign.c ft_flag.c ft_str_str2.c tp_zeroing.c ft_buffer.c \
		ft_arr_ft.c ft_mts_bin.c ft_fill_zero.c ft_case_per.c

SRC_DIR = srcs/
INC_DIR = includes/

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJECT = $(SRC:.c=.o)

FLAG = -Wall -Wextra -g -Werror

all: $(NAME)

$(NAME): $(OBJECT)
	ar rcs $@ $^

%.o: %.c
	gcc $(FLAG) -c $^ -o $@ -I$(INC_DIR)

clean:
	rm -rf $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
