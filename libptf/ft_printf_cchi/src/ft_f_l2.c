/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_l2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:13:36 by cchi              #+#    #+#             */
/*   Updated: 2019/07/25 16:11:18 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_mts_ld2(t_bin_ld binary_db, char *s_i, char *s_d, t_tp prt)
{
	char					*bin_z_str;
	int						plusint;
	unsigned long long		binary_i;
	int						ng;

	if (!(bin_z_str = ft_binary_float(64, binary_db.f.mantissa)))
		return (0);
	binary_i = c_i_m_ld(bin_z_str, binary_db.f.exponent, s_i, 16383);
	c_p_mts_ld(bin_z_str, binary_db.f.exponent, s_d, binary_i);
	plusint = ft_round(s_d, prt.prc_width);
	if (plusint == 1)
		ft_plusint_1(s_i);
	ft_strrev(s_i);
	ng = (binary_db.f.sign == 1 ? -1 : 0);
	free(bin_z_str);
	return (ng);
}
