/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_round.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 12:19:30 by cchi              #+#    #+#             */
/*   Updated: 2019/07/28 22:38:27 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_round_str_double(int i, char *str_double)
{
	int carry;
	int plusint;

	carry = 0;
	plusint = 0;
	while (str_double[i])
	{
		if (carry == 1)
		{
			str_double[i] += 1;
			carry = 0;
		}
		if (str_double[i] >= 10 + '0')
		{
			str_double[i] -= 10;
			carry = 1;
		}
		i--;
		if (i < 0 && carry == 1)
			plusint = 1;
	}
	return (plusint);
}

int	ft_round(char *sd, int prt_prc)
{
	int i;
	int k;
	int plusint;

	i = prt_prc;
	k = (int)ft_strlen(sd);
	plusint = 0;
	if (prt_prc > 0 && sd[prt_prc] >= '5' && sd[prt_prc] && prt_prc < k)
	{
		if (sd[prt_prc] == '5' && (sd[prt_prc] - '0') % 2 == 0)
			sd[prt_prc - 1]--;
		sd[prt_prc - 1]++;
		plusint = ft_round_str_double(i, sd);
	}
	else if (prt_prc > (int)ft_strlen(sd))
	{
		while ((int)ft_strlen(sd) < prt_prc)
			sd[k++] = '0';
	}
	else if (sd[prt_prc] >= '5' && prt_prc == 0)
	{
		sd[prt_prc] = '0';
		plusint = 1;
	}
	return (plusint);
}
