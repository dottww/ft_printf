/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_str2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:50:10 by cchi              #+#    #+#             */
/*   Updated: 2019/07/25 13:55:32 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_str2(char *str2, char *str)
{
	while (*str2 != 0)
		str2++;
	while (*str)
	{
		*str2 = *str;
		str++;
		str2++;
	}
	*str2 = '\0';
}

void	ft_x_zero(char *str)
{
	int k;

	k = 0;
	while (str[k])
	{
		if (str[k] == '0')
			str[k] = ' ';
		k++;
	}
}

void	ft_x_m(char *str)
{
	int k;

	k = 0;
	while (str[k])
	{
		str[k] = (str[k] >= 'a' && str[k] <= 'z' ? str[k] - 32 : str[k]);
		k++;
	}
}
