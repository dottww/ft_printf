/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:37:37 by weilin            #+#    #+#             */
/*   Updated: 2020/02/14 19:45:44 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// # define BUFF_SIZE 10000
# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_flags
{
	int		plus;
	int		minus;
	int		zero;
	int		space;
	int		hash;
	int		width;
	int		prec;
	// int		neg;
}				t_flags;

typedef struct	s_pfinfo
{
	va_list		valist;
	t_flags		flags;
	char		*bf;
	int			i;
	int			fd;
	int			nb_printf;
	int			len;
	// t_mod		mod;
}				t_pfinfo;

int				ft_printf(const char *fmt, ...);


#endif

//# define U (s[i - 5] == '#')