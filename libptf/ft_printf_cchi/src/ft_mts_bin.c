/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mts_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:30:39 by cchi              #+#    #+#             */
/*   Updated: 2019/07/28 22:39:19 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_mts_bin(char *d, char *i, t_bin_d b)
{
	char				*bin_z_str;
	unsigned long long	binary_i;
	int					ng;

	if (!(bin_z_str = ft_binary_float(52, b.f.mantissa)))
		return (0);
	binary_i = c_i_m(bin_z_str, b.f.exponent, i, 1023);
	c_a_p_m(bin_z_str, b.f.exponent, d, binary_i);
	ng = (b.f.sign == 1 ? -1 : 0);
	free(bin_z_str);
	return (ng);
}

int		ft_mts_bin2(char *d, char *i, t_tp prt)
{
	int					plusint;

	plusint = ft_round(d, prt.prc_width);
	if (plusint == 1)
		ft_plusint_1(i);
	ft_strrev(i);
	return (0);
}

char	*ft_strj0x(char *str)
{
	char				*str2;

	str2 = ft_strjoin("0x", str);
	free(str);
	return (str2);
}

void	ft_plusint_1(char *str_integer)
{
	int i;
	int carry;

	i = 0;
	carry = 0;
	while (carry == 1 || i == 0)
	{
		if (i == 0)
			str_integer[i] += 1;
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

char	*ft_case_f_nan(t_tp prt)
{
	char	*str;

	str = ft_strdup("nan");
	if (prt.op_width >= (int)ft_strlen(str))
	{
		if (!(str = ft_fill_space(str, prt)))
			return (0);
	}
	return (str);
}
