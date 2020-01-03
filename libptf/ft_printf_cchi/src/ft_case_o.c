/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:04:58 by cchi              #+#    #+#             */
/*   Updated: 2019/07/28 22:40:21 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		p_oct(unsigned long long int k, char *buff)
{
	int	i;

	if (k > 0)
	{
		i = k % 8;
		k = k / 8;
		p_oct(k, buff);
		while (*buff != 0)
			buff++;
		*buff = i + '0';
	}
	return (0);
}

int		size_oct(unsigned long long int k)
{
	int nb;

	nb = 0;
	if (k == 0)
		return (1);
	while (k != 0)
	{
		k = k / 8;
		nb++;
	}
	return (nb);
}

int		ft_len_o(va_list ap, t_lh lh, char *str, t_tp prt)
{
	unsigned long long	decill;
	int					s;

	decill = ft_x(ap, lh);
	s = 0;
	if (decill == 0 && prt.prc_width == 0 && prt.hashtag != 1)
		return (s);
	if (decill == 0)
	{
		ft_buffer(str, "0");
		return (s = 1);
	}
	if (prt.hashtag != 0)
		str[0] = '0';
	p_oct(decill, str);
	s = ft_deci_len(decill);
	return (s);
}

char	*ft_flag_o(t_tp prt, char *str, int s)
{
	if ((prt.zero == 1 && (prt.prc_width > s)) || prt.prc_width > s
		|| (prt.prc_width == -1 && prt.op_width > s &&
		prt.zero == 1 && prt.minus == 0))
	{
		if (prt.prc_width == -1 && prt.op_width > s)
			prt.prc_width = prt.op_width;
		if (!(str = ft_fill_zero(str, prt, 0)))
			return (0);
	}
	if (prt.plus != 0 || prt.space != 0 || prt.hashtag != 0)
	{
		if (!(str = ft_fill_sign(str, 0, prt)))
			return (0);
	}
	return (str);
}

int		ft_case_o(char *buff, va_list ap, t_tp prt, t_lh lh)
{
	char	*str;
	int		nb;
	int		s;

	if (!(str = (char*)malloc(sizeof(char) * 30)))
		return (0);
	ft_bzero(str, 30);
	s = ft_len_o(ap, lh, str, prt);
	if (prt.prc_width <= s && prt.prc_width != -1)
		prt.prc_width = 0;
	if (!(str = ft_flag_o(prt, str, s)))
		return (0);
	if (prt.op_width > s)
	{
		if (!(str = ft_fill_space(str, prt)))
			return (0);
	}
	nb = ft_buffer(buff, str);
	free(str);
	return (nb);
}
