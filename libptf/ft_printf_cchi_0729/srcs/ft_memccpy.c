/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:08:47 by cchi              #+#    #+#             */
/*   Updated: 2019/07/25 19:27:42 by sid              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n-- > 0)
	{
		*(char *)dst = *(const char *)src;
		if (*(char *)dst == (char)c)
			return (dst + 1);
		dst++;
		src++;
	}
	return (NULL);
}
