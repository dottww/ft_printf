/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:48:26 by weilin            #+#    #+#             */
/*   Updated: 2020/02/17 16:59:45 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_zerowidth_char(t_data *t)
{
	int i;

	i = t->flag.width - 1;
	while (i > 0)
	{
		t->nb_printf += ((t->flag.zero == 1) ?
			write(t->fd, "0", 1) : write(t->fd, " ", 1));
		i--;
	}
}

void	print_char(t_data *t, unsigned char ch)
{
	if (t->flag.minus)
	{
		t->nb_printf += write(t->fd, &ch, 1);
		print_zerowidth_char(t);
	}
	else
	{
		print_zerowidth_char(t);
		t->nb_printf += write(t->fd, &ch, 1);
	}
	t->i++;
}

void	type_chars(char type, t_data *t)
{
	unsigned char	ch;
	// char			*str;

	t->flag.minus == 1 ? t->flag.zero = 0 : 0;
	if (type == 'c')
	{
		ch = (unsigned char)va_arg(t->valist, int);
		print_char(t, ch);
	}
	// else if (type == 's')
	// {
	// 	str = (char*)va_arg(e->ap, char*);
	// 	if (str == NULL)
	// 		return (print_null_str(e));
	// 	if (!(e->bf = ft_strdup(str)))
	// 		return ;
	// 	print_str(e);
	// }

}

void parse_type(const char *fmt, t_data *t)
{
	/*if (ft_strchr("oxX", fmt[t->i])) //b?
		get_base(fmt[t->i], t);
	else if (fmt[t->i] == '%')
		get_percent(t);
	else if (fmt[t->i] == 'd' || fmt[t->i] == 'i')
		get_int(t);
	else if (fmt[t->i] == 'u' || fmt[t->i] == 'U')
		get_uint(fmt[t->i], e);
	else if (fmt[t->i] == 'p')
		get_addr(t);
	else if (fmt[t->i] == 'f' || fmt[t->i] == 'F')
		get_float(fmt[t->i], e);		
	*/
 	if (fmt[t->i] == 'c' || fmt[t->i] == 's')
		type_chars(fmt[t->i], t);
	else if (fmt[t->i] != '\0')
		print_char(t, fmt[t->i]);
}

void parse(const char *fmt, t_data *t)
{
	t->i++;
	zero_flag(t);
	parse_spec(fmt, t);
	//pending
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
				t.nb_printf += write(t.fd, "%", 1);
				t.i += 2;
			}
			else if (fmt[t.i] == '%' && fmt[t.i + 1] != '%')
				parse(fmt, &t);
			else
				t.nb_printf += write(t.fd, fmt + (t.i)++, 1);
		}
	}
	va_end(t.valist);
	return (t.nb_printf);
}
