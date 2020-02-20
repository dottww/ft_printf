/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tp_zeroing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:45:59 by cchi              #+#    #+#             */
/*   Updated: 2019/07/29 09:18:24 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tp	ft_stru_zero(void)
{
	t_tp prt;

	prt.minus = 0;
	prt.dot = 0;
	prt.op_width = 0;
	prt.prc_width = -1;
	prt.zero = 0;
	prt.integ = 0;
	prt.charact = 0;
	prt.str = 0;
	prt.hashtag = 0;
	prt.plus = 0;
	prt.space = 0;
	prt.space_len = 0;
	prt.zero_len = 0;
	return (prt);
}
