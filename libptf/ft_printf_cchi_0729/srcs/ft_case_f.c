/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 13:57:30 by cchi              #+#    #+#             */
/*   Updated: 2019/07/29 13:37:28 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_mts_represent2(t_tp prt, char *str, int ng)
{
	int					s;

	s = ft_strlen(str);
	if ((prt.zero == 1 && prt.op_width) || (prt.prc_width > s && str[0] != 'i'))
	{
		if (!(str = ft_fill_zero(str, prt, ng)))
			return (0);
	}
	if (!(str = ft_fill_sign(str, ng, prt)))
		return (0);
	if (prt.op_width > s)
	{
		if (!(str = ft_fill_space(str, prt)))
			return (0);
	}
	return (str);
}

char	*ft_mts_represent(double d, t_tp prt, char *s_i, char *s_d)
{
	t_bin_d	binary_db;
	int		nb;
	char	*str;
	int		ng;

	nb = 0;
	binary_db.data = d;
	if (binary_db.f.exponent == 2047 && binary_db.f.mantissa == 0)
	{
		str = ft_strdup("inf");
		ng = (binary_db.f.sign == 1 ? -1 : 0);
	}
	else
	{
		ng = ft_mts_bin(s_d, s_i, binary_db);
		ft_mts_bin2(s_d, s_i, prt);
		if (!(str = ft_int_cat_prc(s_d, prt.prc_width, s_i, prt.hashtag)))
			return (0);
	}
	if (!(str = ft_mts_represent2(prt, str, ng)))
		return (0);
	return (str);
}

int		ft_f_mc(char *str_integer, char *str_double)
{
	ft_bzero(str_integer, 5000);
	ft_bzero(str_double, 17000);
	return (0);
}

char	*ft_case_f_str(va_list ap, t_tp prt, t_lh lh, t_b_d bd)
{
	t_double		d;

	if (lh.m_l == 1)
	{
		d.l_d = va_arg(ap, long double);
		if (d.l_d != d.l_d)
		{
			if (!(d.str = ft_case_f_nan(prt)))
				return (0);
		}
		else
			d.str = ft_mts_ld(d.l_d, prt, bd.str_integer, bd.str_double);
	}
	else
	{
		d.d = va_arg(ap, double);
		if (d.d != d.d)
		{
			if (!(d.str = ft_case_f_nan(prt)))
				return (0);
		}
		else
			d.str = ft_mts_represent(d.d, prt, bd.str_integer, bd.str_double);
	}
	return (d.str);
}

int		ft_case_f(char *buff, va_list ap, t_tp prt, t_lh lh)
{
	int					nb;
	t_b_d				b_d;
	char				*str;

	if (!(b_d.str_integer = (char*)malloc(sizeof(char) * 5001)))
		return (0);
	if (!(b_d.str_double = (char*)malloc(sizeof(char) * 17001)))
		return (0);
	ft_f_mc(b_d.str_integer, b_d.str_double);
	if (prt.prc_width == -1)
		prt.prc_width = 6;
	if (!(str = ft_case_f_str(ap, prt, lh, b_d)))
		return (0);
	nb = ft_buffer(buff, str);
	free(str);
	return (nb);
}
