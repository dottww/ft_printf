/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:37:37 by weilin            #+#    #+#             */
/*   Updated: 2020/02/19 17:45:29 by weilin           ###   ########.fr       */
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

typedef struct s_flag2
{
	int plus;
	int minus;
	int zero;
	int space;
	int hash;
	int width;
	int prec;
	
	char type;
	int pad;
	// int		neg;
} t_flag2;

typedef struct	s_flag
{
	int plus;
	int minus;
	int zero;
	int space;
	int hash;
	int width;
	int prec;
	int pad;
	char type;
	int i;
	int count;
	char *str;
}				t_flag;

/*function that initialize the struct info to 0*/
void	ft_init_struct_info(t_flag *info)
{
	info->minus = 0;
	info->zero = 0;
	info->pad = 0;
	info->width = 0;
	info->prec = -1;
	info->type = 0;
}
/*functions that printf struct info*/
void	ft_printf_debug(t_flag *info)
{
	printf("----------------DEBUG-------------\n");
	printf("-------------struct info----------\n");
	printf("info minus:			%d\n", info->minus);
	printf("info zero:			%d\n", info->zero);
	printf("info padding:			%d\n", info->pad);
	printf("info width:			%d\n", info->width);
	printf("info precision:			%d\n", info->prec);
	printf("info count:			%d\n", info->count);
	printf("info i:				%d\n", info->i);
	printf("info str:			%s\n", info->str);
	printf("info type:			%c\n", info->type);
	printf("----------------------------------\n");
}
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

