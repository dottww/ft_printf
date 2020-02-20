/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 14:20:31 by cchi              #+#    #+#             */
/*   Updated: 2019/07/29 09:07:49 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_p_flag(char *flags)
{
	flags[0] = '0';
	flags[1] = '#';
	flags[2] = '+';
	flags[3] = '-';
	flags[4] = ' ';
}

t_tp	ft_flag(t_tp prt, char *pa)
{
	char	flags[6];
	int		i;

	i = 0;
	ft_p_flag(flags);
	while (flags[i])
	{
		if (flags[i] == *pa)
		{
			pa++;
			if (i == 0)
				prt.zero = 1;
			else if (i == 1)
				prt.hashtag = 1;
			else if (i == 2)
				prt.plus = 1;
			else if (i == 3)
				prt.minus = 1;
			else if (i == 4)
				prt.space = 1;
			i = -1;
		}
		i++;
	}
	return (prt);
}

t_tp	ft_fg_width(const char *pa, t_tp prt)
{
	prt = ft_flag(prt, (char*)pa);
	while (*pa == '0' || *pa == '#' || *pa == '+' || *pa == '-' || *pa == ' ')
		pa++;
	if (*pa <= '9' && *pa >= '0')
	{
		prt.op_width = ft_atoi(pa);
		while (*pa <= '9' && *pa >= '0')
			pa++;
	}
	if ((prt.dot = (*pa == '.' ? 1 : 0)) > 0)
	{
		pa++;
		if (*pa >= '0' && *pa <= '9')
			prt.prc_width = ft_atoi(pa);
		else
			prt.prc_width = 0;
	}
	return (prt);
}

t_lh	ft_fg_lh(const char *pa)
{
	t_lh lh;

	lh.ll = 0;
	lh.l = 0;
	lh.hh = 0;
	lh.h = 0;
	lh.m_l = 0;
	if (*pa == 'l' || *pa == 'h' || *pa == 'L')
	{
		if (*pa == 'l' && *(pa + 1) == 'l')
			lh.ll = 1;
		else if (*pa == 'h' && *(pa + 1) == 'h')
			lh.hh = 1;
		else if (*pa == 'l')
			lh.l = 1;
		else if (*pa == 'h')
			lh.h = 1;
		else if (*pa == 'L')
			lh.m_l = 1;
	}
	return (lh);
}
