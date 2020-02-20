/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:30:34 by cchi              #+#    #+#             */
/*   Updated: 2019/07/29 09:16:29 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int			ft_nprintf2(const char *pa, char *buff, va_list ap)
{
	t_tp	prt;
	t_lh	lh;
	t_ft	ft;
	char	*ft_pointer;
	int		nb;

	nb = 0;
	ft_arr_ft(ft.functptr);
	ft_arr_p(ft.v);
	prt = ft_stru_zero();
	prt = ft_fg_width(pa, prt);
	while ((*pa == ' ' || *pa == '#' || *pa == '+' || *pa == '-'
			|| *pa == '0') && *pa)
		pa++;
	while (((*pa >= '0' && *pa <= '9') || *pa == '.') && *pa)
		pa++;
	lh = ft_fg_lh(pa);
	while ((*pa == 'l' || *pa == 'h' || *pa == 'L') && *pa)
		pa++;
	if (*pa && (ft_pointer = ft_strchr(ft.v, *pa)) != NULL)
	{
		nb += (*ft.functptr[ft_pointer - ft.v])(buff, ap, prt, lh);
		pa++;
	}
	return (nb);
}

int			ft_rt_pa(const char *pa)
{
	int		i;

	i = 0;
	while ((*(pa + i) == ' ' || *(pa + i) == '#' ||
			*(pa + i) == '+' || *(pa + i) == '-' ||
			*(pa + i) == '0') && *(pa + i))
		i++;
	while (((*(pa + i) >= '0' && *(pa + i) <= '9') ||
			*(pa + i) == '.') && *(pa + i))
		i++;
	while ((*(pa + i) == 'l' || *(pa + i) == 'h' ||
			*(pa + i) == 'L') && *(pa + i))
		i++;
	if ((*(pa + i) == 'c' || *(pa + i) == 's' || *(pa + i) == 'p' ||
		*(pa + i) == 'd' || *(pa + i) == 'i' || *(pa + i) == 'o' ||
		*(pa + i) == 'u' || *(pa + i) == 'x' || *(pa + i) == 'f' ||
		*(pa + i) == 'X') || *(pa + i) == '%')
		i++;
	return (i);
}

int			ft_cpy_until_p(char *p, char *buff, const char *pa)
{
	char	*pa_str;
	int		nb;

	nb = 0;
	if (!(pa_str = ft_strsub(pa, 0, p - pa)))
		return (0);
	nb = ft_buffer(buff, pa_str);
	free(pa_str);
	return (nb);
}

int			ft_nprintf(char *buff, const char *pa, va_list ap, char *p)
{
	int		nb;

	nb = 0;
	while (*pa)
	{
		if ((p = ft_memchr(pa, '%', ft_strlen(pa))) != 0)
		{
			nb += ft_cpy_until_p(p, buff, pa);
			pa = p;
			pa++;
			nb += ft_nprintf2(pa, buff, ap);
			pa = pa + ft_rt_pa(pa);
		}
		else
		{
			nb += ft_buffer(buff, pa);
			while (*pa)
				pa++;
		}
	}
	return (nb);
}

int			ft_printf(const char *pa, ...)
{
	int		nb_printf;
	t_buff	b;
	va_list	ap;
	char	*p;

	p = NULL;
	nb_printf = 0;
	va_start(ap, pa);
	ft_bzero(b.buff, BUFF_SIZE);
	nb_printf = ft_nprintf(b.buff, pa, ap, p);
	if (ft_strlen(b.buff) <= BUFF_SIZE)
	{
		nb_printf += ft_strlen(b.buff);
		ft_putstr(b.buff);
	}
	va_end(ap);
	return (nb_printf);
}
