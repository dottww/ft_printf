/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_sign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 10:30:21 by cchi              #+#    #+#             */
/*   Updated: 2019/07/28 22:38:09 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_nb_space(int nb_space, char *str2)
{
	int	nb;

	nb = nb_space;
	while (*str2)
		str2++;
	while (nb > 0)
	{
		*str2 = ' ';
		str2++;
		nb--;
	}
	*str2 = '\0';
}

void	ft_fill_space2(char *s, char *str2, t_tp prt, int nb_space)
{
	if (prt.minus == 1 && nb_space > 0)
	{
		ft_str_str2(str2, s);
		ft_nb_space(nb_space, str2);
	}
	else if (prt.minus == 0 && nb_space > 0)
	{
		ft_nb_space(nb_space, str2);
		ft_str_str2(str2, s);
	}
}

char	*ft_fill_space(char *s, t_tp prt)
{
	char	*str2;
	int		nb;
	int		nb_space;
	int		len;

	nb = ((int)ft_strlen(s) >= prt.op_width ? (int)ft_strlen(s) : prt.op_width);
	len = (int)ft_strlen(s);
	nb_space = (len >= prt.op_width ? 0 : prt.op_width - len);
	if (!(str2 = (char*)malloc(sizeof(char) * nb + 1)))
		return (0);
	ft_bzero(str2, nb);
	if (prt.minus == 1 && nb_space > 0)
		ft_fill_space2(s, str2, prt, nb_space);
	else if (prt.minus == 0 && nb_space > 0)
		ft_fill_space2(s, str2, prt, nb_space);
	else
	{
		free(str2);
		return (s);
	}
	free(s);
	return (str2);
}

char	*ft_fill_sign(char *str, int deci, t_tp prt)
{
	int		len;
	char	*str2;

	len = ft_strlen(str) + 1;
	if (!(str2 = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_bzero(str2, len + 1);
	if (deci >= 0 && prt.plus == 1)
		str2[0] = '+';
	else if (deci >= 0 && prt.space == 1)
		str2[0] = ' ';
	else if (deci < 0)
		str2[0] = '-';
	else
	{
		free(str2);
		return (str);
	}
	ft_str_str2(str2, str);
	free(str);
	return (str2);
}
