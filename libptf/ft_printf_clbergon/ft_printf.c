/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbergon <clbergon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 14:45:13 by clbergon          #+#    #+#             */
/*   Updated: 2018/05/05 16:43:36 by clbergon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_buf	*buf;
	size_t	len;

	buf = buf_new();
	if (!process(format, buf, ap))
		return (ERR);
	va_end(ap);
	write(fd, buf->content, buf->len);
	len = buf->len;
	buf_free(&buf);
	return (len);
}

int		ft_vprintf(const char *format, va_list ap)
{
	return (ft_vdprintf(STDOUT_FILENO, format, ap));
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vdprintf(STDOUT_FILENO, format, ap);
	va_end(ap);
	return (ret);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (ret);
}
