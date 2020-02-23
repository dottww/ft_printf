/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_ox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 19:08:09 by weilin            #+#    #+#             */
/*   Updated: 2020/02/23 20:43:17 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void conv_hexa(t_data *t, unsigned long val)
{
	if (t->mod == MOD_n)
		t->bf = ft_uitoa_base((unsigned int)val, 16);
	else if (t->mod == MOD_hh)
		t->bf = ft_uitoa_base((unsigned char)val, 16);
	else if (t->mod == MOD_h)
		t->bf = ft_uitoa_base((unsigned short int)val, 16);
	else if (t->mod == MOD_l)
		t->bf = ft_ultoa_base((unsigned long)val, 16);
	else if (t->mod == MOD_ll)
		t->bf = ft_ulltoa_base((unsigned long long)val, 16);
}

// char *ft_strpre_c(char c, char const *s1
// {
// 	char *dst;
// 	size_t len;

// 	if (!s1)
// 		return (NULL);
// 	len = 0;
// 	while (s1[len] != '\0')
// 		len++;
// 	if (!(dst = ft_strnew(len + 1 + 1)))
// 		return (NULL);
// 	while (len--)
// 		dst[len] = s1[len];
// 	dst[len + 1] = '\0';
// 	dst[0] = c;
// 	return (dst);
// }

void	fillwidth_base(t_data *t)
{
	int		i;

	i = t->flag.width - ft_strlen(t->bf);
	while (i > 0)
	{
		t->nb_print += ((t->flag.zero) == 1 ?
			write(t->fd, "0", 1) : write(t->fd, " ", 1));
		i--;
	}
}
int		base_width(char tp, t_data *t)
{
	char	*tmp;
	char	*new;
	int		len;
	int		i;
	int		x;

	x = (tp == 'o' && t->bf[0] != '0') ? 1 : 0;
	x = (tp == 'x' || tp == 'X') ? 2 : 0;
	len = ft_strlen(t->bf) + x;
	if (t->flag.width > len)
	{
		i = t->flag.width - len;
		if (!(tmp = ft_strnew_c(i, '0')))
			return (0);
		if (!(new = ft_strjoin(tmp, t->bf)))
			return (0);
		free(tmp);
		free(t->bf);
		t->bf = new;
	}
	return (1);
}

int		base_hash(char tp, t_data *t)
{
	char 	*tmp;
	
	if (t->flag.width && t->flag.zero == 1)
		if (!base_width(tp, t))
			return (0);
	
	if (((tp == 'o' && t->bf[0] != '0') && !(tmp = ft_strjoin("0", t->bf)))
			||((tp == 'x' || tp == 'X') &&
				!(tmp = ft_strjoin((tp == 'x' ? "0x" : "0X"), t->bf))))
			return (0);
	free(t->bf);
	t->bf = tmp;
	return (1);
}

int		base_precision(t_data *t)
{
	char	*tmp;
	char	*new;
	int		len;
	int		i;

	len = ft_strlen(t->bf);
	if (t->flag.prec > len)
	{
		i = t->flag.prec - len;
		if (!(tmp = ft_strnew_c(i, '0')))
			return (0);
		if (!(new = ft_strjoin(tmp, t->bf)))
			return (0);
		free(tmp);
		free(t->bf);
		t->bf = new;
	}
	return (1);
}

void	print_base(char type, t_data *t, int n)
{
	if (type != 'o' && n == 0)
		t->flag.hash = 0;
	
	if (!(base_precision(t)))
		return ;
	if ((t->flag.hash) && !base_hash(type, t))
		return ;
	if (t->flag.minus != 1)
		fillwidth_base(t);
	if(!(t->flag.prec == 0 && n ==0))
		t->nb_print += write(1, t->bf, ft_strlen(t->bf));
	if (t->flag.minus == 1)
		fillwidth_base(t);
	free(t->bf);
	t->i++;
}

void	type_base(char type, t_data *t)
{
	unsigned long int val;

	(t->flag.minus == 1 || t->flag.prec >= 0) ? t->flag.zero = 0 : 0;
	t->flag.plus = 0;
	t->flag.space = 0;
	init_uint_arg(type, t, &val);
	if (type == 'X' || type == 'x')
		conv_hexa(t, val);
	if (!(t->bf))
		return;
	if (type == 'x')
		ft_strtolower(t->bf);
	print_base(type, t, (val) ? 1 : 0);
}