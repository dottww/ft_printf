/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:13:59 by weilin            #+#    #+#             */
/*   Updated: 2020/02/21 16:22:44 by weilin           ###   ########.fr       */
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
	t->flag.mod = MOD_n;
}

void	type_percent(t_data *t)
{
	int tmp;
	
	tmp = t->flag.width;
	if (t->flag.minus == 1)
	{
		t->nb_print += write(t->fd, "%", 1);
		while (tmp-- > 1)
			t->nb_print += write(t->fd, " ", 1);
	}
	else
	{
		while (tmp-- > 1)
			t->nb_print += (t->flag.zero ?
					write(t->fd, "0", 1) : write(t->fd, " ", 1));
		t->nb_print += write(t->fd, "%", 1);
	}
	t->i++;
}

void	ft_printf_debug(t_data *info)
{
	printf("----------------DEBUG-------------\n");
	printf("-------------struct info----------\n");
	printf("info plus:			%d\n", info->flag.plus);
	printf("info minus:			%d\n", info->flag.minus);
	printf("info zero:			%d\n", info->flag.zero);
	printf("info space:			%d\n", info->flag.space);
	printf("info hash:			%d\n", info->flag.hash);
	printf("info width:			%d\n", info->flag.width);
	printf("info precision:			%d\n", info->flag.prec);
	printf("info i:				%d\n", info->i);
	printf("info str:			%s\n", info->bf);
	printf("info len:			%c\n", info->len);
	printf("----------------------------------\n");
}