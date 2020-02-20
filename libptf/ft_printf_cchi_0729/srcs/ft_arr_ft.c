/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 13:49:50 by cchi              #+#    #+#             */
/*   Updated: 2019/07/29 10:37:04 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_arr_ft(int (*functptr[12])())
{
	functptr[0] = ft_case_c;
	functptr[1] = ft_case_s;
	functptr[2] = ft_case_p;
	functptr[3] = ft_case_d;
	functptr[4] = ft_case_d;
	functptr[5] = ft_case_o;
	functptr[6] = ft_case_u;
	functptr[7] = ft_case_x;
	functptr[8] = ft_case_f;
	functptr[9] = ft_case_mx;
	functptr[10] = ft_case_per;
}

void	ft_arr_p(char *v)
{
	v[0] = 'c';
	v[1] = 's';
	v[2] = 'p';
	v[3] = 'd';
	v[4] = 'i';
	v[5] = 'o';
	v[6] = 'u';
	v[7] = 'x';
	v[8] = 'f';
	v[9] = 'X';
	v[10] = '%';
}
