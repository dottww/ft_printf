/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:29:55 by cchi              #+#    #+#             */
/*   Updated: 2019/07/28 22:39:55 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char		*ft_strprc(char *s, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	while ((char)s[i] && len > i)
	{
		str[i] = (char)s[i];
		i++;
	}
	str[i] = '\0';
	free(s);
	return (str);
}

int			ft_case_s(char *buff, va_list ap, t_tp prt, t_lh lh)
{
	char	*str;
	int		space;
	int		nb;

	str = va_arg(ap, char*);
	nb = 0;
	space = 0;
	if (str == NULL)
		str = "(null)";
	str = ft_strdup(str);
	if ((int)ft_strlen(str) > prt.prc_width && prt.prc_width != -1)
	{
		if (!(str = ft_strprc(str, prt.prc_width)))
			return (0);
	}
	if ((int)ft_strlen(str) < prt.op_width)
	{
		if (!(str = ft_fill_space(str, prt)))
			return (0);
	}
	nb = ft_buffer(buff, str);
	free(str);
	(void)lh;
	return (nb);
}
