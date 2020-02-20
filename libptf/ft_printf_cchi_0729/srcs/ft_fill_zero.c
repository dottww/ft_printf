/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 11:31:20 by cchi              #+#    #+#             */
/*   Updated: 2019/07/28 22:39:05 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_nb_zero(char *str, int nb_zero)
{
	while (*str != 0)
		str++;
	while (nb_zero > 0)
	{
		*str = '0';
		str++;
		nb_zero--;
	}
	*str = '\0';
}

char	*ft_fill_zero(char *str, t_tp prt, int deci)
{
	int		nb;
	char	*str2;
	int		len;

	len = (int)ft_strlen(str);
	nb = (prt.prc_width > len ? prt.prc_width - len : 0);
	len = (prt.hashtag == 0 ? len : len + 2);
	if (prt.op_width >= len && prt.prc_width < len)
		nb = prt.op_width - len;
	if ((deci < 0 || prt.space == 1 || prt.plus == 1) && prt.prc_width < len)
		nb--;
	len = (prt.prc_width > len ? prt.prc_width : prt.op_width);
	if (prt.op_width > len)
		len = prt.op_width;
	if (!(str2 = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_bzero(str2, len + 1);
	ft_nb_zero(str2, nb);
	ft_str_str2(str2, str);
	free(str);
	return (str2);
}
