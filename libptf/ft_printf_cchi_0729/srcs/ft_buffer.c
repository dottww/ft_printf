/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:32:01 by cchi              #+#    #+#             */
/*   Updated: 2019/07/29 13:37:02 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_buffer(char *buff, const char *c)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (i < BUFF_SIZE && buff[i])
		i++;
	while (*c)
	{
		if (*c && i < BUFF_SIZE)
			buff[i++] = *c;
		c++;
		if (i == BUFF_SIZE)
		{
			ft_putstr(buff);
			nb += BUFF_SIZE;
			ft_bzero(buff, BUFF_SIZE);
			i = 0;
		}
	}
	return (nb);
}
