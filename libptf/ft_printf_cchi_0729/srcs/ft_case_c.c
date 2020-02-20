/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:29:48 by cchi              #+#    #+#             */
/*   Updated: 2019/07/29 13:37:12 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_case_c(char *buff, va_list ap, t_tp prt, t_lh lh)
{
	char	c;
	int		nb;

	nb = 0;
	(void)lh;
	c = va_arg(ap, int);
	if (prt.op_width > 1 && prt.minus == 0)
	{
		while (--prt.op_width > 0)
			nb += ft_buffer(buff, " ");
	}
	nb += ft_strlen(buff);
	ft_putstr(buff);
	ft_bzero(buff, BUFF_SIZE);
	write(1, &c, 1);
	nb++;
	if (prt.op_width > 1 && prt.minus == 1)
	{
		while (--prt.op_width > 0)
			nb += ft_buffer(buff, " ");
	}
	return (nb);
}
