/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 21:15:46 by weilin            #+#    #+#             */
/*   Updated: 2020/02/23 18:59:58 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ulltoa(unsigned long long n)
{
	char					*val;
	int						len;
	unsigned long long int	tmp;

	len = 1;
	tmp = n;
	while (tmp >= 10)
	{
		tmp /= 10;
		len++;
	}
	if (!(val = ft_memalloc(len + 1)))
		return (NULL);
	val[len] = '\0';
	tmp = n;
	while (tmp >= 10)
	{
		val[--len] = (tmp % 10) + '0';
		tmp /= 10;
	}
	val[--len] = (tmp % 10) + '0';
	return (val);
}

char	*ft_ulltoa_base(unsigned long long n, unsigned long long base)
{
	char					*val;
	int						len;
	unsigned long long		tmp;

	len = 1;
	tmp = n;
	while (tmp >= base)
	{
		tmp /= base;
		len++;
	}
	if (!(val = ft_memalloc(len + 1)))
		return (NULL);
	val[len] = '\0';
	tmp = n;
	while (tmp >= base)
	{
		val[--len] = (tmp % base) > 9 ?
			(tmp % base) + 55 : (tmp % base) + '0';
		tmp /= base;
	}
	val[--len] = (tmp % base) > 9 ?
		(tmp % base) + 55 : (tmp % base) + '0';
	return (val);
}

char	*ft_ultoa_base(unsigned long n, unsigned long base)
{
	char				*s;
	int					len;
	unsigned long		tmp;

	len = 1;
	tmp = n;
	while (tmp >= base)
	{
		tmp /= base;
		len++;
	}
	if (!(s = ft_strnew(len)))
		return (NULL);
	s[len] = '\0';
	tmp = n;
	while (tmp >= base)
	{
		s[--len] = (tmp % base) > 9 ?
			(tmp % base) + 55 : (tmp % base) + '0'; // or 87 & no lower
		tmp /= base;
	}
	s[--len] = (tmp % base) > 9 ?
		(tmp % base) + 55 : (tmp % base) + '0'; // or 87 & no lower
	return (s);
}

char	*ft_uitoa_base(unsigned int n, unsigned int base)
{
	char			*val;
	int				len;
	unsigned int	tmp;

	len = 1;
	tmp = n;
	while (tmp >= base)
	{
		tmp /= base;
		len++;
	}
	if (!(val = ft_strnew(len)))
		return (NULL);
	val[len] = '\0';
	tmp = n;
	while (tmp >= base)
	{
		val[--len] = (tmp % base) > 9 ?
			(tmp % base) + 55 : (tmp % base) + '0';
		tmp /= base;
	}
	val[--len] = (tmp % base) > 9 ?
		(tmp % base) + 55 : (tmp % base) + '0';
	return (val);
}
