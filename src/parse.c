/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:54:00 by weilin            #+#    #+#             */
/*   Updated: 2020/02/19 19:01:25 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


/*
void parse_width(t_data *t)
{
	t->flag.width = va_arg(t->valist, int);
	if (t->flag.width < 0)
	{
		t->flag.width = -(t->flag.width);
		t->flag.minus = 1;
	}
}
*/

void parse_prec(const char *fmt, t_data *t)
{
	if (t->flag.prec >= 0)
	{
		t->i++;
		return;
	} //if already exist then do not take more prec
	else if (fmt[t->i] == '.' && fmt[t->i + 1] == '*')
	{
		t->flag.prec = va_arg(t->valist, int);
		t->i += 2;
	}
	if (fmt[t->i] == '.' && ft_isdigit(fmt[t->i + 1]))
	{
		t->i++;
		t->flag.prec = ft_atoi(fmt + t->i);
		while (ft_isdigit(fmt[t->i])) //jump ft_int_len
			t->i++;
	}
	else
		t->flag.prec = 0;
}

void parse_spec(const char *fmt, t_data *t)
{
	while (ft_strchr("'+-0# *.123456789", fmt[t->i])) //hlLjz
	{
		fmt[t->i] == '+' ? t->flag.plus = 1 : 0;
		fmt[t->i] == '-' ? t->flag.minus = 1 : 0;
		fmt[t->i] == '0' ? t->flag.zero = 1 : 0;
		fmt[t->i] == '#' ? t->flag.hash = 1 : 0;
		fmt[t->i] == ' ' ? t->flag.space = 1 : 0;
		//fmt[t->i] == '*' ? parse_width(t) : 0;
		//LL size
		if (fmt[t->i] == '.')
			parse_prec(fmt, t);
		else if (ft_isdigit(fmt[t->i]))
		{
			t->flag.width = ft_atoi(fmt + t->i);
			while (ft_isdigit(fmt[t->i])) //jump ft_int_len
				t->i++;
		}
		else
			t->i++;
	}
}