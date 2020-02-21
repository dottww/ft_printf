/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_addr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:40:43 by weilin            #+#    #+#             */
/*   Updated: 2020/02/21 17:27:04 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fillwidth_addr(t_data *t)
{
	int len;
	int i;

	len = ft_strlen(t->bf) + 2;
	i = t->flag.width - len;
	while (i > 0)
	{
		t->nb_print += write(t->fd, " ", 1);
		i--;
	}
}

void	fillwidth_addr2(t_data *t)
{
	int len;
	int i;

	len = ft_strlen(t->bf);
	i = t->flag.prec - len;
	while (i > 0)
	{
		t->nb_print += write(t->fd, "0", 1);
		i--;
	}
}

void	print_hash_base(char type, t_data *t)
{
	if (type == 'o' && t->bf[0] != '0')
		t->nb_print += write(t->fd, "0", 1);
	else if (type == 'x' || type == 'X')
		t->nb_print += write(t->fd, type == 'x' ? "0x" : "0X", 2);
}

/*
int		addr_precision(t_data *t)
{
	char	*tmp;
	char	*new;
	int		len;
	int		i;

	len = ft_strlen(t->bf);
	if (t->flag.prec > len)
	{
		i = t->flag.prec - len;
		if (!(tmp = ft_strnew(i)))
			return (0);
		while (i > 0)
			tmp[--i] = '0';
		if (!(new = ft_strjoin(tmp, t->bf)))
			return (0);
		free(tmp);
		free(t->bf);
		t->bf = new;
	}
	return (1);
}
*/

char	*ultoa_base(unsigned long int n, unsigned long int base)
{
	char				*s;
	int					len;
	unsigned long int	tmp;

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
			(tmp % base) + 87 : (tmp % base) + '0';
		tmp /= base;
	}
	s[--len] = (tmp % base) > 9 ?
		(tmp % base) + 87 : (tmp % base) + '0';
	return (s);
}

void	print_addr(t_data *t)
{
	// t->flag.space = 0;
	// t->flag.plus = 0;
	// t->flag.prec = -1;
	// addr_precision(t);
	// if (!(addr_precision(t)))
	// 	return ;
	// ft_printf_debug(t);
	if (t->flag.prec >= t->flag.width)
	{
		print_hash_base('x', t);
		fillwidth_addr2(t);
		t->nb_print += write(t->fd, t->bf, ft_strlen(t->bf));
	}
	else if (t->flag.minus == 1)
	{
		print_hash_base('x', t);
		t->nb_print += write(t->fd, t->bf, ft_strlen(t->bf));
		fillwidth_addr(t);
	}
	else
	{
		fillwidth_addr(t);
		print_hash_base('x', t);
		t->nb_print += write(t->fd, t->bf, ft_strlen(t->bf));
	}
	t->i++;
	free(t->bf);
}