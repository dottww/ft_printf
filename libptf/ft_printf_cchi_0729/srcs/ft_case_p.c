/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:26:09 by cchi              #+#    #+#             */
/*   Updated: 2019/07/29 13:37:34 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		address_hex(unsigned long long address, char *buff, t_tp prt)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (address == 0 && prt.prc_width != 0)
		buff[k] = '0';
	while (address > 0)
	{
		i = address % 16;
		address = address / 16;
		buff[k] = (i < 10 && i >= 0 ? i + '0' : i + 87);
		k++;
	}
	return (0);
}

char	*ft_x0(char *str)
{
	char *str2;

	if (!(str2 = ft_strjoin("0x", str)))
		return (0);
	free(str);
	return (str2);
}

int		ft_case_p(char *buff, va_list ap, t_tp prt, t_lh lh)
{
	unsigned long long	add;
	char				*str;
	int					nb;
	int					s;

	nb = 0;
	add = va_arg(ap, unsigned long long);
	if (!(str = (char*)malloc(sizeof(char) * 15)))
		return (0);
	ft_bzero(str, 15);
	address_hex(add, str, prt);
	ft_strrev(str);
	s = (int)ft_strlen(str);
	if (prt.prc_width > s)
	{
		if (!(str = ft_fill_zero(str, prt, 0)))
			return (0);
	}
	str = ft_x0(str);
	if ((int)ft_strlen(str) < prt.op_width)
		str = ft_fill_space(str, prt);
	nb = ft_buffer(buff, str);
	free(str);
	(void)lh;
	return (nb);
}
