/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:54:00 by weilin            #+#    #+#             */
/*   Updated: 2020/02/15 20:55:44 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_pfinfo *e)
{
	e->flags.plus = 0;
	e->flags.minus = 0;
	e->flags.zero = 0;
	e->flags.space = 0;
	e->flags.hash = 0;
	e->flags.width = 0;
	e->flags.prec = 0;
}