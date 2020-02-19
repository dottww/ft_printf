/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:48:26 by weilin            #+#    #+#             */
/*   Updated: 2020/02/20 00:02:43 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fillwidth_char(t_data *t)
{
	int i;

	i = t->flag.width - 1;
	while (i > 0)
	{
		t->nb_print += ((t->flag.zero == 1) ?
			write(t->fd, "0", 1) : write(t->fd, " ", 1));
		i--;
	}
}

void	print_char(t_data *t, unsigned char ch)
{
	if (t->flag.minus == 1)
	{
		t->nb_print += write(t->fd, &ch, 1);
		fillwidth_char(t);
	}
	else
	{
		fillwidth_char(t);
		t->nb_print += write(t->fd, &ch, 1);
	}
	t->i++;
}

void	fillwidth_str(t_data *t)
{
	int	i;

	i = t->flag.width - ft_strlen(t->bf);
	while (i > 0)
	{
		t->nb_print += ((t->flag.zero) == 1 ?
			write(t->fd, "0", 1) : write(t->fd, " ", 1));
		i--;
	}
}
void	print_str(t_data *t)
{
	char	*tmp;

	if (t->flag.prec >= 0 &&
			t->flag.prec <= (int)ft_strlen(t->bf))
	{
		tmp = ft_strsub(t->bf, 0, t->flag.prec);
		free(t->bf);
		t->bf = tmp;
	}
	if (!(t->bf))
		return ;
	if (t->flag.minus == 1)
	{
		t->nb_print += write(t->fd, t->bf, ft_strlen(t->bf));
		fillwidth_str(t);
	}
	else
	{
		fillwidth_str(t);
		t->nb_print += write(t->fd, t->bf, ft_strlen(t->bf));
	}
	t->i++;
	free(t->bf);
}
void	type_chars(char type, t_data *t)
{
	unsigned char	ch;
	char			*str;

	t->flag.minus == 1 ? t->flag.zero = 0 : 0;
	if (type == 'c')
	{
		ch = (unsigned char)va_arg(t->valist, int);
		print_char(t, ch);
	}
	else if (type == 's')
	{
		if ((str = (char*)va_arg(t->valist, char*)) != NULL)
		{
			if (!(t->bf = ft_strdup(str)))
				return ;
		}
		else if (!(t->bf = ft_strdup("(null)")))
			return ;	
		print_str(t);
	}
}
/*void	type_num(char type, t_data *t)
{
	unsigned char	ch;

	t->flag.minus == 1 ? t->flag.zero = 0 : 0;
	if (type == 'c')
	{
		ch = (unsigned char)va_arg(t->valist, int);
		print_char(t, ch);
	}
	char			*str;
	else if (type == 's')
	{
		str = (char*)va_arg(t->valist, char*);
		if (str == NULL)
			return (print_null_str(t));
		if (!(t->bf = ft_strdup(str)))
			return ;
		print_str(t);
	}
}
*/
int			addr_precision(t_data *t)
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
void		print_width_addr(t_data *t)
{
	int len;
	int i;

	len = ft_strlen(t->bf) + 2;
	i = t->flag.width - len;
	while (i > 0)
	{
		t->nb_print += (t->flag.zero == 1 ?
				write(t->fd, "0", 1) : write(t->fd, " ", 1));
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
void		print_addr(t_data *t)
{
	t->flag.space = 0;
	t->flag.plus = 0;
	addr_precision(t);
	if (!(addr_precision(t)))
		return ;
	if (t->flag.minus == 1)
	{
		print_hash_base('x', t);
		t->nb_print += write(t->fd, t->bf, ft_strlen(t->bf));
		print_width_addr(t);
	}
	else
	{
		t->flag.zero == 0 ? print_width_addr(t) : 0;
		print_hash_base('x', t);
		t->flag.zero == 1 ? print_width_addr(t) : 0;
		t->nb_print += write(t->fd, t->bf, ft_strlen(t->bf));
	}
	t->i++;
	free(t->bf);
}

char	*ultoa_base(unsigned long int n, unsigned long int base)
{
	char				*val;
	int					len;
	unsigned long int	tmp;

	len = 1;
	tmp = n;
	while (tmp >= base)
	{
		tmp /= base;
		len++;
	}
	if (!(val = ft_strnew(len)))
		return (NULL);
	val[len] = '\0';
	tmp = n;
	while (tmp >= base)
	{
		val[--len] = (tmp % base) > 9 ?
			(tmp % base) + 55 : (tmp % base) + '0';
		tmp /= base;
	}
	val[--len] = (tmp % base) > 9 ?
		(tmp % base) + 55 : (tmp % base) + '0';
	return (val);
}

void	type_addr(t_data *t)
{
	unsigned long int val;

	t->flag.minus == 1 ? t->flag.zero = 0 : 0;
	val = va_arg(t->valist, unsigned long int);
	if (t->flag.prec == 0)
		t->bf = ft_strdup("\0");
	else
		t->bf = ultoa_base(val, 16);
	if (!t->bf)
		return ;
	ft_strtolower(t->bf);
	print_addr(t);
}
void	get_percent(t_data *t)
{
	int tmp;
	
	tmp = t->flag.width;
	if (t->flag.minus == 1)
	{
		t->nb_print += write(t->fd, "%", 1);
		while (tmp-- > 1)
			t->nb_print += write(t->fd, " ", 1);
	}
	else
	{
		while (tmp-- > 1)
			t->nb_print += (t->flag.zero ?
					write(t->fd, "0", 1) : write(t->fd, " ", 1));
		t->nb_print += write(t->fd, "%", 1);
	}
	t->i++;
}

void parse_type(const char *fmt, t_data *t)
{
	/*
	if (ft_strchr("oxX", fmt[t->i])) //b?
		type_num(fmt[t->i], t);
	
	else if (fmt[t->i] == 'd' || fmt[t->i] == 'i')
		get_int(t);
	else if (fmt[t->i] == 'u' || fmt[t->i] == 'U')
		get_uint(fmt[t->i], e);
	
	else if (fmt[t->i] == 'f' || fmt[t->i] == 'F')
		get_float(fmt[t->i], e);		
	*/
 	if (fmt[t->i] == 'c' || fmt[t->i] == 's')
		type_chars(fmt[t->i], t);
	else if (fmt[t->i] == 'p')
		type_addr(t);
	else if (fmt[t->i] == '%')
		get_percent(t);
	else if (fmt[t->i] != '\0')
		print_char(t, fmt[t->i]);
}

void	init_flag(t_data *t)
{
	t->flag.plus = 0;
	t->flag.minus = 0;
	t->flag.zero = 0;
	t->flag.space = 0;
	t->flag.hash = 0;
	t->flag.width = 0;
	t->flag.prec = -1;
}

void parse_prec(const char *fmt, t_data *t)
{
	if (t->flag.prec >= 0)
	{
		t->i++;
		return;
	} //if already exist then do not take more prec
	else if (fmt[t->i] == '.' && fmt[t->i + 1] == '*')
	{
		// t->flag.prec = va_arg(t->valist, int);
		t->flag.prec = 0;
		t->i += 2;
	}
	if (fmt[t->i] == '.' && ft_isdigit(fmt[t->i + 1]))
	{
		t->i++;
		t->flag.prec = ft_atoi(fmt + t->i);
		while (ft_isdigit(fmt[t->i]))
			t->i++;
	}
	else
		t->flag.prec = 0;
}

void parse_flag(const char *fmt, t_data *t)
{
	while (ft_strchr("'+-0# *.123456789", fmt[t->i])) //hlLjz
	{
		fmt[t->i] == '+' ? t->flag.plus = 1 : 0;
		fmt[t->i] == '-' ? t->flag.minus = 1 : 0;
		fmt[t->i] == '0' ? t->flag.zero = 1 : 0;
		fmt[t->i] == '#' ? t->flag.hash = 1 : 0;
		fmt[t->i] == ' ' ? t->flag.space = 1 : 0;
		//fmt[t->i] == '*' ? parse_width(t) : 0;
		//LL size
		if (fmt[t->i] == '.')
			parse_prec(fmt, t);
		else if (ft_isdigit(fmt[t->i]))
		{
			t->flag.width = ft_atoi(fmt + t->i);
			while (ft_isdigit(fmt[t->i]))
				t->i++;
		}
		else
			t->i++;
	}
}
void parse(const char *fmt, t_data *t)
{
	t->i++;
	init_flag(t);
	parse_flag(fmt, t);
	if (t->i > (int)ft_strlen(fmt) - 1)
		return;
	parse_type(fmt, t);
	//pending
}

int ft_printf(const char *fmt, ...)
{
	t_data t;

	ft_bzero(&t, sizeof(t));
	va_start(t.valist, fmt);
	if ((t.fd = 1) && fmt)
	{
		t.len = (int)ft_strlen(fmt);
		while (t.i < t.len)
		{
			if (fmt[t.i] == '%' && t.len == 1)
				break;
			else if (fmt[t.i] == '%' && fmt[t.i + 1] == '%')
			{
				t.nb_print += write(t.fd, "%", 1);
				t.i += 2;
			}
			else if (fmt[t.i] == '%' && fmt[t.i + 1] != '%')
				parse(fmt, &t);
			else
				t.nb_print += write(t.fd, fmt + (t.i)++, 1);
		}
	}
	va_end(t.valist);
	return (t.nb_print);
}
