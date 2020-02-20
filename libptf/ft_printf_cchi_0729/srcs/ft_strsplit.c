/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:24:36 by cchi              #+#    #+#             */
/*   Updated: 2018/11/26 14:56:16 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		k;
	int		size;

	i = 0;
	k = 0;
	if (!c || !(arr = (char**)malloc(sizeof(char*) * (ft_nmot(s, c) + 1))))
		return (0);
	while (ft_nmot(s, c) > k)
	{
		while ((char)s[i] == c && s[i])
			i++;
		size = 0;
		while ((char)s[i] != c && s[i])
		{
			size++;
			i++;
		}
		arr[k] = ft_strsub(s, i - size, size);
		k++;
		arr[k] = NULL;
	}
	arr[k] = 0;
	return (arr);
}
