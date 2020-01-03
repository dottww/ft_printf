/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_per.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:31:04 by cchi              #+#    #+#             */
/*   Updated: 2019/07/28 22:36:01 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_case_per(char *buff, va_list ap, t_tp prt, t_lh lh)
{
	char	*str;
	int		s;
	int		nb;

	(void)ap;
	(void)lh;
	if (!(str = (char*)malloc(sizeof(char) * 2)))
		return (0);
	ft_bzero(str, 2);
	str[0] = '%';
	s = ft_strlen(str);
	if ((prt.zero == 1 && prt.minus == 0) || prt.prc_width > s)
	{
		if (!(str = ft_fill_zero(str, prt, 0)))
			return (0);
	}
	if (prt.op_width > s)
	{
		if (!(str = ft_fill_space(str, prt)))
			return (0);
	}
	nb = ft_buffer(buff, str);
	free(str);
	return (nb);
}
