/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:18:09 by cchi              #+#    #+#             */
/*   Updated: 2019/07/25 16:55:45 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

unsigned long long	c_i_m_ld(char *br, unsigned long long e, char *si, int bs)
{
	char	power_2[5001];
	int		i;
	int		j;

	ft_bzero(power_2, 5001);
	si[0] = '0';
	power_2[0] = '1';
	i = 0;
	j = e;
	if (j < bs)
		return (0);
	while (j-- > bs)
		calcul_p_2(power_2);
	while (i < 65 && e > (unsigned long long)bs - 1)
	{
		ft_add_in_str(power_2, si, br[i]);
		i++;
		e--;
	}
	return (i);
}

unsigned long long	c_i_m(char *b1, unsigned long long e1, char *s1, int bs)
{
	char	power_2[5001];
	int		i;
	int		j;

	ft_bzero(power_2, 5001);
	s1[0] = '0';
	power_2[0] = '1';
	i = 0;
	j = e1;
	if (j < bs)
		return (0);
	while (j-- > bs)
		calcul_p_2(power_2);
	ft_add_in_str(power_2, s1, '1');
	while (i < 53 && e1 > (unsigned long long)bs - 1)
	{
		ft_add_in_str(power_2, s1, b1[i]);
		i++;
		e1--;
	}
	return (i);
}

void				c_p_mts_ld(char *br, int e, char *sd, unsigned long long bi)
{
	char				power_2[17001];
	unsigned long long	i;
	unsigned long long	k;

	i = bi;
	k = e;
	ft_bzero(power_2, 17001);
	sd[0] = '0';
	power_2[0] = '5';
	while (k < 16382)
	{
		calcul_p_n2(power_2);
		k++;
	}
	while (i < 65)
	{
		ft_add_f_in_str(power_2, sd, br[i], 17000);
		calcul_p_n2(power_2);
		i++;
	}
}

char				*ft_mts_ld(long double d, t_tp prt, char *s_i, char *s_d)
{
	t_bin_ld	binary_db;
	char		*str;
	int			s;
	int			ng;

	binary_db.data = d;
	ng = ft_mts_ld2(binary_db, s_i, s_d, prt);
	if (!(str = ft_int_cat_prc(s_d, prt.prc_width, s_i, prt.hashtag)))
		return (0);
	s = ft_strlen(str);
	if ((prt.zero == 1 && prt.op_width) || prt.prc_width > s)
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
