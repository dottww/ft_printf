/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:07:29 by cchi              #+#    #+#             */
/*   Updated: 2019/07/29 13:37:57 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int					unsign_hex(unsigned long long n, char *buff)
{
	int i;
	int k;

	k = 0;
	if (n == 0)
		buff[k] = '0';
	while (n > 0)
	{
		i = n % 16;
		n = n / 16;
		buff[k] = (i < 10 && i >= 0 ? i + '0' : i + 87);
		k++;
	}
	return (0);
}

unsigned long long	ft_x(va_list ap, t_lh lh)
{
	unsigned long long int decill;

	decill = 0;
	if (lh.ll == 1)
		decill = va_arg(ap, unsigned long long);
	else if (lh.l == 1)
		decill = va_arg(ap, unsigned long);
	else if (lh.h == 1)
		decill = (unsigned short)va_arg(ap, unsigned int);
	else if (lh.hh == 1)
		decill = (unsigned char)va_arg(ap, unsigned int);
	else
		decill = va_arg(ap, unsigned int);
	return (decill);
}

char				*ft_flag_x(t_tp prt, unsigned long long deci)
{
	int		s;
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * 17)))
		return (0);
	ft_bzero(str, 17);
	unsign_hex(deci, str);
	s = (int)ft_strlen(str);
	ft_strrev(str);
	if (prt.prc_width == 0 && prt.op_width == 0)
	{
		free(str);
		return (0);
	}
	if ((prt.zero == 1 && prt.op_width && prt.minus == 0) || prt.prc_width > s)
	{
		if (!(str = ft_fill_zero(str, prt, 0)))
			return (0);
	}
	if (prt.hashtag != 0 && deci != 0)
	{
		if (!(str = ft_strj0x(str)))
			return (0);
	}
	return (str);
}

int					ft_case_x(char *buff, va_list ap, t_tp prt, t_lh lh)
{
	char				*str;
	int					nb;
	int					s;
	int					k;
	unsigned long long	deci;

	nb = 0;
	k = 0;
	deci = ft_x(ap, lh);
	if (!(str = ft_flag_x(prt, deci)))
		return (0);
	s = (int)ft_strlen(str);
	if (prt.op_width > s)
	{
		if (!(str = ft_fill_space(str, prt)))
			return (0);
		if (deci == 0)
			ft_x_zero(str);
	}
	nb = ft_buffer(buff, str);
	free(str);
	return (nb);
}

int					ft_case_mx(char *buff, va_list ap, t_tp prt, t_lh lh)
{
	char				*str;
	int					nb;
	int					s;
	int					k;
	unsigned long long	deci;

	nb = 0;
	k = 0;
	deci = ft_x(ap, lh);
	if (!(str = ft_flag_x(prt, deci)))
		return (0);
	ft_x_m(str);
	s = (int)ft_strlen(str);
	if (prt.op_width > s)
	{
		if (!(str = ft_fill_space(str, prt)))
			return (0);
		if (deci == 0)
			ft_x_zero(str);
	}
	nb = ft_buffer(buff, str);
	free(str);
	return (nb);
}
