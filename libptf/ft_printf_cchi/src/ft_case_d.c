/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 10:58:49 by cchi              #+#    #+#             */
/*   Updated: 2019/07/28 22:41:50 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int			ft_i(char *buff, long long i)
{
	int j;

	if (i == 0)
		return (0);
	j = i % 10;
	ft_i(buff, i / 10);
	while (*buff != '\0')
		buff++;
	if (j > 0)
		j = -j;
	*buff = -j + '0';
	return (0);
}

int			ft_len_int(long long i)
{
	int nb;

	nb = 0;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		i = i / 10;
		nb++;
	}
	return (nb);
}

char		*ft_flag_d(char *str, t_tp prt, int s, int ng)
{
	int k;

	k = 0;
	while (str[k])
	{
		str[k] -= (str[k] >= 'a' && str[k] <= 'z' ? 32 : 0);
		k++;
	}
	if ((prt.zero == 1 && prt.minus == 0) || prt.prc_width > s)
	{
		if (!(str = ft_fill_zero(str, prt, ng)))
			return (0);
	}
	if (!(str = ft_fill_sign(str, ng, prt)))
		return (0);
	if (prt.op_width >= s)
	{
		if (!(str = ft_fill_space(str, prt)))
			return (0);
	}
	return (str);
}

long long	ft_d(va_list ap, t_lh lh)
{
	unsigned long long decill;

	decill = 0;
	if (lh.ll == 1)
		decill = va_arg(ap, long long);
	else if (lh.l == 1)
		decill = va_arg(ap, long);
	else if (lh.h == 1)
		decill = (short)va_arg(ap, int);
	else if (lh.hh == 1)
		decill = (char)va_arg(ap, int);
	else
		decill = va_arg(ap, int);
	return (decill);
}

int			ft_case_d(char *buff, va_list ap, t_tp prt, t_lh lh)
{
	long long	deci;
	int			s;
	int			nb;
	char		*str;
	int			ng;

	deci = ft_d(ap, lh);
	s = ft_len_int(deci);
	ng = (deci < 0 ? -1 : 0);
	if (!(str = (char*)malloc(sizeof(char) * (s + 1))))
		return (0);
	ft_bzero(str, s + 1);
	if (deci != 0)
		ft_i(str, deci);
	else if (deci == 0 && prt.prc_width != 0)
		str[0] = '0';
	if (!(str = ft_flag_d(str, prt, s, ng)))
		return (0);
	nb = ft_buffer(buff, str);
	free(str);
	(void)lh;
	return (nb);
}
