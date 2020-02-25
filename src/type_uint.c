/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:35:11 by mdavid            #+#    #+#             */
/*   Updated: 2020/02/25 19:46:43 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_uint(t_data *t)
{
	unsigned long int		n;
	int						neg;
	char					*val;

	(t->flag.prec >= 0) ? t->flag.zero = 0 : 0;
	neg = 0;
	t->flag.plus = 0;
	t->flag.space = 0;
	init_uint_arg(t, &n);
	val = ft_ulltoa(n);
	if (ft_prec_for_int(t, &val) == (int)STAT_ERR ||
		ft_width_for_int(t, &val, ft_strlen(val), neg) == (int)STAT_ERR)
	{
		(val) ? ft_strdel(&val) : 0;
		return ;
	}
	if (!(val))
		return ;
	t->bf = val;
	print_int(t);
}
