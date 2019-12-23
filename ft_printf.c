/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:47:59 by weilin            #+#    #+#             */
/*   Updated: 2019/12/23 17:23:43 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	int		nb_printf;
	va_list	ap;
	
	nb_printf = 0;
	va_start(ap, format); // put everything in format into ap
	if (format[0]=="%" && format[1]=="c")
	{
		char arg = (char)va_arg(ap, int);
		nb_printf = printf("%c",arg);
	}
	//nb_printf = ft_vprintf(format, ap);// take out each argument one by one from ap
	va_end(ap);
	return (nb_printf);
}