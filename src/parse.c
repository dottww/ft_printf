/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:54:00 by weilin            #+#    #+#             */
/*   Updated: 2020/02/21 13:14:07 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_width(t_data *t)
{
	t->flag.width = va_arg(t->valist, int);
	if (t->flag.width < 0)
	{
		t->flag.width = -(t->flag.width);
		t->flag.minus = 1;
	}
}

void	parse_type(const char *fmt, t_data *t)
{
 	if (fmt[t->i] == 'c' || fmt[t->i] == 's')
		type_chars(fmt[t->i], t);
	else if (fmt[t->i] == '%')
		type_percent(t);
	else if (fmt[t->i] == 'p')
		type_addr(t);
	else if (fmt[t->i] == 'd' || fmt[t->i] == 'i')
		type_int(t);
	// else if (fmt[t->i] == 'u' || fmt[t->i] == 'U')
	// 	type_uint(fmt[t->i], t);
	// else if (ft_strchr("oxX", fmt[t->i])) //b?
	// 	type_num(fmt[t->i], t);
	// else if (fmt[t->i] == 'f' || fmt[t->i] == 'F')
	// 	type_float(fmt[t->i], t);		
	else if (fmt[t->i] != '\0')
		print_char(t, fmt[t->i]);
}

void	parse_prec(const char *fmt, t_data *t)
{
	if (t->flag.prec >= 0)
	{
		t->i++;
		return;
	} //if already exist then do not take more prec
	else if (fmt[t->i] == '.' && fmt[t->i + 1] == '*')
	{
		// t->flag.prec = va_arg(t->valist, int);
		t->flag.prec = 0;
		t->i += 2;
	}
	if (fmt[t->i] == '.' && ft_isdigit(fmt[t->i + 1]))
	{
		t->i++;
		t->flag.prec = ft_atoi(fmt + t->i);
		while (ft_isdigit(fmt[t->i]))
			t->i++;
	}
	else
		t->flag.prec = 0;
}

void	parse_flag(const char *fmt, t_data *t)
{
	while (ft_strchr("'+-0# *.123456789hlLjz", fmt[t->i])) //hlLjz*'
	{
		fmt[t->i] == '+' ? t->flag.plus = 1 : 0;
		fmt[t->i] == '-' ? t->flag.minus = 1 : 0;
		fmt[t->i] == '0' ? t->flag.zero = 1 : 0;
		fmt[t->i] == '#' ? t->flag.hash = 1 : 0;
		fmt[t->i] == ' ' ? t->flag.space = 1 : 0;
		fmt[t->i] == '*' ? parse_width(t) : 0;
		(fmt[t->i] == 'l' && fmt[t->i + 1] != 'l') ? t->flag.mod = MOD_l: 0
		(fmt[t->i] == 'l' && fmt[t->i + 1] == 'l') ? t->flag.mod = MOD_ll: 0
		(fmt[t->i] == 'h' && fmt[t->i + 1] != 'h') ? t->flag.mod = MOD_h: 0
		(fmt[t->i] == 'h' && fmt[t->i + 1] == 'h') ? t->flag.mod = MOD_hh: 0
		//LL size
		if (fmt[t->i] == '.')
			parse_prec(fmt, t);
		else if (ft_isdigit(fmt[t->i]))
		{
			t->flag.width = ft_atoi(fmt + t->i);
			while (ft_isdigit(fmt[t->i]))
				t->i++;
		}
		else
			t->i++;
	}
}

void	parse(const char *fmt, t_data *t)
{
	t->i++;
	init_flag(t);
	parse_flag(fmt, t);
	if (t->i > (int)ft_strlen(fmt) - 1)
		return;
	parse_type(fmt, t);
	//pending
}