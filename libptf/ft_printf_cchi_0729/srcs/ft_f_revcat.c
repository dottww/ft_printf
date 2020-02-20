/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_revcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:15:41 by cchi              #+#    #+#             */
/*   Updated: 2019/07/28 22:39:37 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_strrev(char *str)
{
	int nb;
	int nb2;
	int exch;

	nb = 0;
	while (str[nb] != '\0')
	{
		nb++;
	}
	nb2 = 0;
	while (nb - 1 > nb2)
	{
		exch = str[nb - 1];
		str[nb - 1] = str[nb2];
		str[nb2] = exch;
		nb--;
		nb2++;
	}
}

char	*ft_int_cat_prc3(int h, char *str_integer, char *str_double)
{
	char *str2;

	if (h == 1)
	{
		str2 = ft_strjoin(str_integer, ".");
		free(str_integer);
	}
	else
		str2 = str_integer;
	free(str_double);
	return (str2);
}

char	*ft_int_cat_prc2(char *str_double, char *str_integer)
{
	char *str;
	char *str2;

	str = ft_strjoin(str_integer, ".");
	str2 = ft_strjoin(str, str_double);
	free(str);
	free(str_integer);
	free(str_double);
	return (str2);
}

char	*ft_int_cat_prc(char *str_double, int prt_prc, char *str_integer, int h)
{
	char	*str2;
	char	*str;
	int		k;

	k = prt_prc;
	if (prt_prc != 0)
	{
		while (str_double[k] != '\0')
			str_double[k++] = '\0';
	}
	str = str_integer;
	if (prt_prc == 0)
	{
		if (!(str2 = ft_int_cat_prc3(h, str, str_double)))
			return (0);
		return (str2);
	}
	else
	{
		if (!(str2 = ft_int_cat_prc2(str_double, str)))
			return (0);
		return (str2);
	}
	return (str);
}
