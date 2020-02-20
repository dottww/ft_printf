/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:05:46 by cchi              #+#    #+#             */
/*   Updated: 2019/07/29 13:38:06 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_u(char *buff, unsigned long long int i)
{
	int j;

	if (i == 0)
		return (0);
	j = i % 10;
	ft_u(buff, i / 10);
	while (*buff != '\0')
		buff++;
	*buff = j + '0';
	return (0);
}

int		ft_deci_len(unsigned long long int decill)
{
	int s;

	s = 0;
	while (decill != 0)
	{
		decill = decill / 10;
		s += 1;
	}
	return (s);
}

int		ft_len_ui(va_list ap, t_lh lh, char *str)
{
	unsigned long long	decill;
	int					s;

	decill = ft_x(ap, lh);
	ft_u(str, decill);
	if (decill == 0)
	{
		ft_buffer(str, "0");
		return (s = 1);
	}
	s = ft_deci_len(decill);
	return (s);
}

char	*ft_flag_u(t_tp prt, char *str, int s)
{
	if ((prt.zero == 1 && (prt.prc_width > s)) ||
		(prt.op_width > s && prt.prc_width == -1 && prt.zero == 1) ||
		prt.prc_width > s)
	{
		if (!(str = ft_fill_zero(str, prt, 0)))
			return (0);
	}
	if (prt.op_width > s)
	{
		if (!(str = ft_fill_space(str, prt)))
			return (0);
	}
	return (str);
}

int		ft_case_u(char *buff, va_list ap, t_tp prt, t_lh lh)
{
	char	*str;
	int		nb;
	int		s;

	nb = 0;
	if (!(str = (char*)malloc(sizeof(char) * 22)))
		return (0);
	if (prt.prc_width == 0)
	{
		free(str);
		return (0);
	}
	ft_bzero(str, 22);
	s = ft_len_ui(ap, lh, str);
	if (prt.prc_width <= s && prt.prc_width != -1)
		prt.prc_width = -1;
	if (!(str = ft_flag_u(prt, str, s)))
		return (0);
	nb = ft_buffer(buff, str);
	free(str);
	return (nb);
}
