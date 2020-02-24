/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:13:59 by weilin            #+#    #+#             */
/*   Updated: 2020/02/24 16:37:45 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flag(t_data *t)
{
	t->flag.plus = 0;
	t->flag.minus = 0;
	t->flag.zero = 0;
	t->flag.space = 0;
	t->flag.hash = 0;
	t->flag.width = 0;
	t->flag.prec = -1;
	t->mod = MOD_n;
}

void	init_int_arg(t_data *t, long int *val)
{
	if (t->mod == MOD_n)
		*val = (long int)va_arg(t->valist, int);
	else if (t->mod == MOD_hh)
		*val = (long int)va_arg(t->valist, int);
	else if (t->mod == MOD_h)
		*val = (long int)va_arg(t->valist, int);
	else if (t->mod == MOD_l)
		*val = (long int)va_arg(t->valist, long int);
	else if (t->mod == MOD_ll)
		*val = (long int)va_arg(t->valist, long int);
}

void	init_uint_arg(char type, t_data *t, unsigned long *val)
{
	if (type == 'U')
		*val = (unsigned long)va_arg(t->valist, unsigned long);
	else
	{
		if (t->mod == MOD_n)
			*val = (unsigned long)va_arg(t->valist, unsigned int);
		else if (t->mod == MOD_hh)
			*val = (unsigned long)va_arg(t->valist, unsigned int);
		else if (t->mod == MOD_h)
			*val = (unsigned long)va_arg(t->valist, unsigned int);
		else if (t->mod == MOD_l)
			*val = (unsigned long)va_arg(t->valist, unsigned long);
		else if (t->mod == MOD_ll)
			*val = (unsigned long)va_arg(t->valist, unsigned long);
	}
}

void	ft_printf_debug(t_data *info)
{
	printf("----------------DEBUG-------------\n");
	printf("-------------struct info----------\n");
	printf("info minus:			%d\n", info->flag.plus);
	printf("info minus:			%d\n", info->flag.minus);
	printf("info zero:			%d\n", info->flag.zero);
	printf("info space:			%d\n", info->flag.space);
	printf("info hash:			%d\n", info->flag.hash);
	printf("info width:			%d\n", info->flag.width);
	printf("info precision:			%d\n", info->flag.prec);
	printf("info i:				%d\n", info->i);
	printf("info bf:			%s\n", info->bf);
	printf("info len:			%c\n", info->len);
	printf("----------------------------------\n");
}

void	conv_octal(t_data *t, unsigned long val)
{
	if (t->mod == MOD_n)
		t->bf = ft_uitoa_base((unsigned int)val, 8);
	else if (t->mod == MOD_hh)
		t->bf = ft_uitoa_base((unsigned char)val, 8);
	else if (t->mod == MOD_h)
		t->bf = ft_uitoa_base((unsigned short int)val, 8);
	else if (t->mod == MOD_l)
		t->bf = ft_ultoa_base((unsigned long)val, 8);
	else if (t->mod == MOD_ll)
		t->bf = ft_ulltoa_base((unsigned long long)val, 8);
}

void	conv_hexa(t_data *t, unsigned long val)
{
	if (t->mod == MOD_n)
		t->bf = ft_uitoa_base((unsigned int)val, 16);
	else if (t->mod == MOD_hh)
		t->bf = ft_uitoa_base((unsigned char)val, 16);
	else if (t->mod == MOD_h)
		t->bf = ft_uitoa_base((unsigned short int)val, 16);
	else if (t->mod == MOD_l)
		t->bf = ft_ultoa_base((unsigned long)val, 16);
	else if (t->mod == MOD_ll)
		t->bf = ft_ulltoa_base((unsigned long long)val, 16);
}
