/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:35:11 by mdavid            #+#    #+#             */
/*   Updated: 2020/02/25 11:48:52 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_uint(char type, t_data *t)
{
	unsigned long int		n;
	int						neg;
	char					*val;

	neg = 0;
	init_uint_arg(type, t, &n);
	val = ft_uitoa(va_arg(t->valist, unsigned int));
	if (ft_flag_prec_for_int(t, &val) == (int)STAT_ERR)
		return;
	if (ft_flag_plus_space_for_int(t, &val, neg) == (int)STAT_ERR)
		return;
	if (ft_flag_width_for_int(t, &val, (int)ft_strlen(val), neg) == (int)STAT_ERR)
		return;
	if (!(t->bf = ft_strdup(val)))
	{
		ft_strdel(&val);
		return;
	}
	print_int(t);
}