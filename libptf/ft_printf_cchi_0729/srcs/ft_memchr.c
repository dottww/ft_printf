/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 19:32:49 by cchi              #+#    #+#             */
/*   Updated: 2019/07/25 19:11:10 by sid              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_s;

	s_s = (unsigned char *)s;
	while (n)
	{
		if ((*s_s) == (unsigned char)c)
			return (s_s);
		n--;
		s_s++;
	}
	return (NULL);
}
