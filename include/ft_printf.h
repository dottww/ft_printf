/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:37:37 by weilin            #+#    #+#             */
/*   Updated: 2020/02/24 16:07:03 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <limits.h>

typedef enum	e_stat
{
	STAT_OK,
	STAT_ERR
}				t_stat;

typedef enum	e_mod
{
	MOD_n = 0, //mod_non = 0,
	MOD_l,
	MOD_ll,
	MOD_h,
	MOD_hh,
	//MOD_j,
	//MOD_z,
	//MOD_L
}				t_mod;

typedef	struct	s_flag
{
	int plus;
	int minus;
	int zero;
	int space;
	int hash;
	int width;
	int prec;
	// int		neg;
}				t_flag;

typedef	struct	s_data
{
	va_list valist;
	t_flag flag;
	char *bf;
	int i;
	int fd;
	int nb_print;
	int len;
	t_mod		mod;
}				t_data;

// for testing
#include <stdio.h>
void	ft_printf_debug(t_data *info);
// for testing

int		ft_printf(const char *fmt, ...);

/*
** Functions related to the parsing
** File(s): parse.c
*/
void	parse(const char *fmt, t_data *t);
void	parse_flag(const char *fmt, t_data *t);
void	parse_width(t_data *t);
void	parse_prec(const char *fmt, t_data *t);
void	parse_mod(const char *fmt, t_data *t);
void	parse_type(const char *fmt, t_data *t);

/*
** Functions related to the process of char, str, addr ...
** File(s): type_csp.c, print_chars.c, print_addr.c
*/
void	type_chars(char type, t_data *t);
void	type_percent(t_data *t);
void	type_addr(t_data *t);
void	type_base(char type, t_data *t);
void	print_char(t_data *t, unsigned char ch);
void	print_str(t_data *t);
void	print_addr(t_data *t);
void	print_base(char type, t_data *t, int n);
void	print_hash(char type, t_data *t);
void	fillwidth_str(t_data *t);
void	fillwidth_char(t_data *t);
void	fillwidth_addr(t_data *t);
void	fillwidth_base(t_data *t, int n);
// void	fillwidth_addr2(t_data *t);

void	init_flag(t_data *t);
void	init_uint_arg(char type, t_data *t, unsigned long *val);
int		addr_precision(t_data *t);
int		base_hash(char tp, t_data *t);
int		base_width(char tp, t_data *t);

void	conv_hexa(t_data *t, unsigned long val);
void	conv_octal(t_data *t, unsigned long val);
char	*ft_ulltoa(unsigned long long n);
char	*ft_uitoa(unsigned int n);
char	*ft_uitoa_base(unsigned int n, unsigned int base);
char	*ft_ultoa_base(unsigned long n, unsigned long base);
char	*ft_ulltoa_base(unsigned long long n, unsigned long long base);

/*
** Functions related to the processing of an integer arg
** File(s): type_di.c
*/
void	type_int(t_data *t);
int		ft_flag_width_for_int(t_data *t, char **val, int len);
char	ft_flag_zero_for_int(t_data *t);
int		ft_flag_plus_space_for_int(t_data *t, char **val, int neg);
int		ft_flag_prec_for_int(t_data *t, char **val);
void	print_int(t_data *t);

/*
** Functions related to the processing of an unsigned integer arg
** File(s): type_uint.c
*/
void	type_uint(t_data *t);

#endif
