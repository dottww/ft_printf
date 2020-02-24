/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:59:08 by mdavid            #+#    #+#             */
/*   Updated: 2020/02/24 10:26:24 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** FONCTION: ft_flag_plus_space_for_int
** PARAMETERS:	t_data *t: pointer on the principal variable structure.
** 				int sign: sign of the integer received as parameter.
** 				char **val: adress of the number as a string
** DESCRIPTION:
** 	Generate new string made of '+'/' '/'-' and the number as string if
** 	flag.plus = 1.
** If the sign of the number is negative, the sign '+' is not add.
** RETURN:
** 	(int)STAT_OK if everything ok.
** 	(int)STAT_ERR if strjoin/dup return error.
*/

int		ft_flag_plus_space_for_int(t_data *t, char **val, int neg)
{
	int		tot;
	char	*mps;
	char	*tmp;

	tot = neg * 100 + t->flag.plus * 10 + t->flag.space;
	mps = (tot < 10 ) ? " " : "+";
	(tot >= 100 ) ? mps = "-" : 0;
	if (tot != 0)
	{
		if (!(tmp = ft_strjoin(mps, *val)))
		{
			ft_strdel(val);	
			return ((int)STAT_ERR);
		}
		ft_strdel(val);
		if (!(*val = ft_strdup(tmp)))
			return ((int)STAT_ERR);
		ft_strdel(&tmp);
	}
	return ((int)STAT_OK);
}

/*
** FONCTION: ft_flag_zero_for_int
** PARAMETERS:	t_data *t: pointer on the principal variable structure.
** DESCRIPTION:
** 	Specify if the width must be partially field with '0' or ' '.
** 	It depends if flag.minus =1.
** RETURN:
** 	(char)' '.
** 	(char)'0'.
*/

char	ft_flag_zero_for_int(t_data *t)
{
	if (t->flag.zero == 1 && t->flag.minus == 0)
		return ('0');
	return (' ');
}

/*
** FONCTION: ft_flag_minus_for_int
** PARAMETERS:	t_data *t: pointer on the principal variable structure.
** 				char **val: adress of the number as a string
** DESCRIPTION:
** 	Generate new string taking into account flag.zero and the string val.
** 	If flag->minus = 1 flag.zero is ignored, else 
** RETURN:
** 	(int)STAT_OK if everything ok.
** 	(int)STAT_ERR if strjoin/dup return error.
*/

void	ft_flag_minus_for_int(t_data *t, char **val, char **str_w, char **tmp)
{
	if (t->flag.minus == 1)
	{
		if (!(*tmp = ft_strjoin(*val, *str_w)))
			return;
	}
	else
	{
		if (!(*tmp = ft_strjoin(*str_w, *val)))
			return;
	}
	ft_strdel(val);
	ft_strdel(str_w);
}

/*
** FONCTION: ft_flag_prec_for_int
** PARAMETERS:	t_data *t: pointer on the principal variable structure.
** 				char **val: adress of the number as a string
** 				int neg: boolean for the sign of the number (1-> n < 0)
** DESCRIPTION:
** 	Deal with the flag prec.
** RETURN:
** 	(int)STAT_OK if everything ok.
** 	(int)STAT_ERR if strjoin/dup return error.
*/

int		ft_flag_prec_for_int(t_data *t, char **val)
{
	int		len_diff;
	char	*tmp;

	tmp = "";
	len_diff = t->flag.prec - (int)ft_strlen(*val);
	if (len_diff > 0)
	{
		if (!(tmp = ft_strjoin(ft_strnew_c((size_t)len_diff, '0'), *val)))
		{
			ft_strdel(val);
			return ((int)STAT_ERR);
		}
		ft_strdel(val);
		if (!(*val = ft_strdup(tmp)))
			return ((int)STAT_ERR);
	}
	if (t->flag.prec == 0 && ft_strcmp(*val,"0") == 0)
	{
		ft_strdel(val);
		if (!(*val = ft_strdup("")))
			return ((int)STAT_ERR);
	}
	return ((int)STAT_OK);
}

/*
** FONCTION: ft_flag_width_for_int
** PARAMETERS:	t_data *t: pointer on the principal variable structure.
** 				char **val: adress of the number as a string
** DESCRIPTION:
** 	Generate new string made of '+' and the number as string if flag.plus = 1
** 	If the sign of the number is negative, the sign '+' is not add.
** RETURN:
** 	(int)STAT_OK if everything ok.
** 	(int)STAT_ERR if strjoin/dup return error.
*/

int		ft_flag_width_for_int(t_data *t, char **val, int len)
{
	int		len_diff;
	char	*tmp;
	char	*str_w;

	len_diff = t->flag.width - len;
	if (len_diff > 0)
	{
		if (!(str_w = ft_strnew_c((size_t)len_diff, ft_flag_zero_for_int(t))))
			return ((int)STAT_ERR);
		ft_flag_minus_for_int(t, val, &str_w, &tmp);
		if (tmp == NULL)
			return ((int)STAT_ERR);
		if (!(*val = ft_strdup(tmp)))
		{
			ft_strdel(&tmp);
			return ((int)STAT_ERR);
		}
		ft_strdel(&tmp);	
	}
	return ((int)STAT_OK);
}

/*
** FONCTION: type_int
** PARAMETERS:	t_data *t: pointer on the principal variable structure.
** DESCRIPTION:
** 	Deal with the integer (i/d) argument and write the number processed
** 	with all its flags to the correct destination (i.e fd).
** RETURN:
** 	nothing.
*/

void	type_int(t_data *t)
{
	int		n;
	int		neg;
	char	*val;

	n = va_arg(t->valist, int);
	neg = (n < 0) ? 1 : 0;
	val = (neg == 1) ? ft_itoa(-n) : ft_itoa(n);
	if (ft_flag_prec_for_int(t, &val) == (int)STAT_ERR)
		return;
	if (ft_flag_plus_space_for_int(t, &val, neg) == (int)STAT_ERR)
		return;
	if (ft_flag_width_for_int(t, &val, (int)ft_strlen(val)) == (int)STAT_ERR)
		return;
	if (!(t->bf = ft_strdup(val)))
	{
		ft_strdel(&val);
		return;
	}
	print_int(t);
}