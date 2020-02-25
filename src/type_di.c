/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:59:08 by mdavid            #+#    #+#             */
/*   Updated: 2020/02/25 14:50:39 by weilin           ###   ########.fr       */
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

int		ft_flag_minus_for_int(t_data *t, char **val, char **str_w, int neg)
{
	char	*tmp;

	tmp = *val;
	(t->flag.zero == 0 || t->flag.minus == 1) ?
	ft_flag_plus_space_for_int(t, &tmp, neg) : ft_flag_plus_space_for_int(t, str_w, neg);
	if (t->flag.minus == 1)
	{
		if (!(*val = ft_strjoin(tmp, *str_w)))
		{
			ft_strdel(val);
			ft_strdel(str_w);
			return ((int)STAT_ERR);
		}
	}
	else
	{
		if (!(*val = ft_strjoin(*str_w, tmp)))
		{
			ft_strdel(val);
			ft_strdel(str_w);
			return ((int)STAT_ERR);
		}
	}
	ft_strdel(&tmp);
	ft_strdel(str_w);
	return((int)STAT_OK);
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
	char	*ctmp;

	len_diff = t->flag.prec - (int)ft_strlen(*val);
	if (len_diff > 0)
	{	
		if (!(ctmp = ft_strnew_c((size_t)len_diff, '0')) ||
		 	!(tmp = ft_strjoin(ctmp, *val)))
		{
			ft_strdel(val);
			return ((int)STAT_ERR);
		}
		free(ctmp);
		*val = ft_strreset2(val, tmp);
		t->flag.zero = 0;
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

int		ft_flag_width_for_int(t_data *t, char **val, size_t len, int neg)
{
	int		len_diff;
	char	*str_w;

	len_diff = t->flag.width - (int)len;
	(t->flag.plus == 1 || t->flag.space == 1 || neg == 1) ? len_diff -= 1 : 0;
	if (len_diff > 0)
	{
		if (!(str_w = ft_strnew_c((size_t)len_diff, ft_flag_zero_for_int(t))))
			return ((int)STAT_ERR);
		if (ft_flag_minus_for_int(t, val, &str_w, neg) == (int)STAT_ERR)
			return((int)STAT_ERR);
	}
	else
		ft_flag_plus_space_for_int(t, val, neg);/// modification for unsigned here
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
	long int		n;
	int				neg;
	char			*val;

	init_int_arg(t, &n);
	neg = (n < 0) ? 1 : 0;
	val = (neg == 1) ? ft_ulltoa(-n) : ft_ulltoa(n);
	if (ft_flag_prec_for_int(t, &val) == (int)STAT_ERR)
		return;
	if (ft_flag_width_for_int(t, &val, ft_strlen(val), neg) == (int)STAT_ERR)
		return;
	//if (ft_flag_plus_space_for_int(t, &val, neg) == (int)STAT_ERR)
	//	return;
	if (!(val))
		return;
	t->bf = val;
	print_int(t);
}