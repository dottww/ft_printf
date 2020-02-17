/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:37:37 by weilin            #+#    #+#             */
/*   Updated: 2020/02/17 15:41:49 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// # define BUFF_SIZE 10000
//# define U (s[i - 5] == '#')
# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef enum	e_mod
{
	mod_non = 0,
	mod_l,
	mod_ll,
	mod_h,
	mod_hh,
	mod_j,
	mod_z,
	mod_L
}				t_mod;

typedef struct s_flag
{
	int plus;
	int minus;
	int zero;
	int space;
	int hash;
	int width;
	int prec;
	// int		neg;
} t_flag;

typedef struct s_data
{
	va_list valist;
	t_flag flag;
	char *bf;
	int i;
	int fd;
	int nb_printf;
	int len;
	t_mod		mod;
} t_data;

int ft_printf(const char *fmt, ...);
void parse(const char *fmt, t_data *t);
void zero_flag(t_data *t);
void parse_spec(const char *fmt, t_data *t);
void parse_width(t_data *t);
void parse_prec(const char *fmt, t_data *t);
void parse_type(const char *fmt, t_data *t);

void	type_chars(char type, t_data *t);

#endif

