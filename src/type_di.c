/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:59:08 by mdavid            #+#    #+#             */
/*   Updated: 2020/02/21 14:59:57 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_int(t_data *t)
{
	char	*val;
	int		sign;
	int		l;

	val = ft_itoa(va_arg(t->valist, int));
	sign = (val[0] == '-') ? -1 : 0;
	if (t->flag.width >= (int)ft_strlen(val) + t->flag.plus + sign)
		if (!(t->bf = ft_strnew(t->flag.width)))
			return
	
	(t->flag.plus == 1 && val[0] != '-') ? += 1 : 0;


}