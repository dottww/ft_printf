/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_cal_p2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 10:53:25 by cchi              #+#    #+#             */
/*   Updated: 2019/07/29 13:37:49 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	calcul_p_2(char *power_2)
{
	int	i;
	int	carry;

	i = 0;
	carry = 0;
	while (power_2[i] != 0)
	{
		power_2[i] = (power_2[i] - '0') * 2 + '0';
		if (carry == 1)
			power_2[i] += 1;
		if (power_2[i] - '0' >= 10)
		{
			power_2[i] -= 10;
			carry = 1;
		}
		else
			carry = 0;
		i++;
	}
	if (carry == 1 && !(power_2[i]))
		power_2[i] = '1';
}

void	calcul_p_n2(char *power_2)
{
	int i;
	int carry;

	i = 0;
	carry = 0;
	while (power_2[i])
	{
		if ((power_2[i] - '0') % 2 != 0)
			carry = 1;
		power_2[i] = (power_2[i] - '0') / 2 + '0';
		i++;
		if (carry == 1)
		{
			if (!(power_2[i]))
				power_2[i] = '0';
			power_2[i] = power_2[i] + 10;
			carry = 0;
		}
	}
}

void	ft_add_f_in_str_2(char *power_2, char *sd, int i, int size_str)
{
	int carry;

	carry = 0;
	while (power_2[i] && i < size_str)
	{
		if (!(sd[i]))
			sd[i] = power_2[i];
		else if (sd[i])
		{
			sd[i] += power_2[i] - '0';
			if (carry == 1)
			{
				sd[i] += 1;
				carry = 0;
			}
			if (sd[i] >= 10 + '0')
			{
				sd[i] -= 10;
				carry = 1;
			}
		}
		i--;
	}
}

void	ft_add_f_in_str(char *power_2, char *sd, char bin_z_str, int size_str)
{
	int i;

	i = ft_strlen(power_2) - 1;
	if (bin_z_str == '1')
		ft_add_f_in_str_2(power_2, sd, i, size_str);
}

void	c_a_p_m(char *b_z, int e, char *s_d, unsigned long long binary_i)
{
	char				power_2[5001];
	unsigned long long	i;
	unsigned long long	k;

	i = (binary_i > 0 ? binary_i - 1 : 0);
	k = e;
	ft_bzero(power_2, 5000);
	s_d[0] = '0';
	power_2[0] = '5';
	while (k < 1022)
	{
		calcul_p_n2(power_2);
		k++;
	}
	if (binary_i == 0 && e < 1023)
	{
		ft_add_f_in_str(power_2, s_d, '1', 5000);
		calcul_p_n2(power_2);
	}
	while (i < 53)
	{
		ft_add_f_in_str(power_2, s_d, b_z[i], 5000);
		calcul_p_n2(power_2);
		i++;
	}
}
