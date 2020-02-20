/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 18:47:11 by cchi              #+#    #+#             */
/*   Updated: 2019/07/25 11:45:34 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_a_i_i_s(int carry, char *str_integer, int i)
{
	if (carry == 1)
	{
		if (str_integer[i])
			str_integer[i] += 1;
		else
			str_integer[i] = '1';
		carry = 0;
	}
	return (carry);
}

void	ft_add_int_in_str(char *power_2, char *str_integer)
{
	int i;
	int carry;

	i = 0;
	carry = 0;
	while (power_2[i] || carry == 1)
	{
		if (!(str_integer[i]) && power_2[i])
			str_integer[i] = power_2[i];
		else if (power_2[i] && str_integer[i])
			str_integer[i] += power_2[i] - '0';
		carry = ft_a_i_i_s(carry, str_integer, i);
		if (str_integer[i] - '0' >= 10)
		{
			str_integer[i] -= 10;
			carry = 1;
		}
		else
			carry = 0;
		i++;
	}
}

void	ft_add_in_str(char *power_2, char *str_integer, char bin_z_str)
{
	int i;
	int carry;

	i = 0;
	carry = 0;
	if (bin_z_str == '1')
		ft_add_int_in_str(power_2, str_integer);
	while (power_2[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (carry == 1)
		{
			power_2[i] += 10;
			carry = 0;
		}
		if ((power_2[i] - '0') % 2 != 0)
			carry = 1;
		else
			carry = 0;
		power_2[i] = ((power_2[i] - '0') / 2) + '0';
		i--;
	}
}
