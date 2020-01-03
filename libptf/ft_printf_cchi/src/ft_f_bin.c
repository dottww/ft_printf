/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 10:53:17 by cchi              #+#    #+#             */
/*   Updated: 2019/07/25 13:55:26 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_itoa_base_size(unsigned long long value, int base)
{
	int		nb;

	nb = 0;
	while (value != 0)
	{
		value /= base;
		nb++;
	}
	return (nb);
}

char		*ft_itoa_base(unsigned long long int value, int base)
{
	char	*bin;
	int		i;
	char	*tab;
	int		nb;

	i = 1;
	tab = "0123456789";
	nb = ft_itoa_base_size(value, base);
	if (!(bin = (char*)malloc(sizeof(char) * (nb + 1))))
		return (0);
	if (value == 0)
		bin[0] = '0';
	while (value != 0)
	{
		bin[nb - i++] = tab[value % base];
		value /= base;
	}
	bin[nb] = '\0';
	return (bin);
}

char		*ft_bin_fill_zero(char *str, int size)
{
	char	*str_2;

	if (!(str_2 = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (*(str + 1) != 0)
		str++;
	str_2[size--] = '\0';
	while (*str)
	{
		str_2[size--] = *str;
		str--;
	}
	while (size >= 0)
	{
		str_2[size] = '0';
		size--;
	}
	return (str_2);
}

char		*ft_binary_float(int size, unsigned long long int fields_mantissa)
{
	char	*b;
	char	*b2;

	if (!(b = ft_itoa_base(fields_mantissa, 2)))
		return (0);
	if (!(b2 = ft_bin_fill_zero(b, size)))
		return (0);
	free(b);
	return (b2);
}
