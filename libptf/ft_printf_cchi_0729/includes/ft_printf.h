/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchi <cchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:30:15 by cchi              #+#    #+#             */
/*   Updated: 2019/07/29 09:06:59 by cchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BUFF_SIZE 18000
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_tp
{
	int		minus;
	int		dot;
	int		op_width;
	int		prc_width;
	int		zero;
	int		integ;
	int		hashtag;
	int		plus;
	int		space;
	int		zero_len;
	char	charact;
	char	*str;
	size_t	space_len;
}					t_tp;

typedef struct		s_lh
{
	int		h;
	int		hh;
	int		l;
	int		ll;
	int		m_l;
}					t_lh;

typedef struct		s_double
{
	double		d;
	long double l_d;
	char		*str;
}					t_double;

typedef struct		s_b_d
{
	char	*str_integer;
	char	*str_double;
}					t_b_d;

typedef struct		s_ft
{
	char					v[12];
	int						(*functptr[12])();
}					t_ft;

typedef struct		s_buff
{
	char	buff[BUFF_SIZE + 1];
}					t_buff;

typedef struct		s_d_f
{
	unsigned long long mantissa:52;
	unsigned long long exponent:11;
	unsigned long long sign:1;
}					t_d_f;

typedef union		u_bin_double
{
	double			data;
	t_d_f			f;
}					t_bin_d;

typedef struct		s_ld_f
{
	unsigned long long	mantissa:64;
	unsigned long long	exponent:15;
	unsigned long long	sign:1;
}					t_ld_f;

typedef	union		u_bin_long_double
{
	long double			data;
	t_ld_f				f;
}					t_bin_ld;

t_tp				ft_stru_zero(void);
unsigned long long	ft_x(va_list ap, t_lh lh);
unsigned long long	c_i_m_ld(char *br, unsigned long long e, char *si, int bs);
unsigned long long	c_i_m(char *b1, unsigned long long e1, char *s1, int bs);
int					ft_itoa_base_size(unsigned long long value, int base);
char				*ft_itoa_base(unsigned long long value, int base);
char				*ft_bin_fill_zero(char *str, int size);
char				*ft_binary_float(int s, unsigned long long f_ma);
void				ft_strrev(char *str);
char				*ft_int_cat_prc(char *s_d, int p_prc, char *s_i, int h);
char				*ft_x0(char *str);
int					unsign_hex(unsigned long long n, char *buff);
char				*ft_flag_x(t_tp prt, unsigned long long deci);
void				calcul_p_2(char *power_2);
void				calcul_p_n2(char *power_2);
void				ft_add_f_in_str_2(char *p_2, char *sd, int i, int si_s);
void				ft_add_f_in_str(char *p_2, char *s, char b_z, int size_s);
int					ft_u(char *buff, unsigned long long int i);
int					ft_deci_len(unsigned long long int decill);
int					ft_len_ui(va_list ap, t_lh lh, char *str);
char				*ft_flag_u(t_tp prt, char *str, int s);
int					ft_round_str_double(int i, char *str_double);
int					ft_round(char *str_double, int prt_prc);
void				c_p_mts_ld(char *b, int e, char *s, unsigned long long bi);
char				*ft_mts_ld(long double d, t_tp prt, char *s_i, char *s_d);
int					ft_a_i_i_s(int carry, char *s_i, int i);
void				ft_add_int_in_str(char *power_2, char *str_integer);
void				ft_add_in_str(char *power_2, char *s_i, char bin_z_str);
int					p_oct(unsigned long long int k, char *buff);
int					size_oct(unsigned long long int k);
int					ft_len_o(va_list ap, t_lh lh, char *str, t_tp prt);
char				*ft_flag_o(t_tp prt, char *str, int s);
void				c_a_p_m(char *b, int e, char *s, unsigned long long b_i);
int					ft_mts_ld2(t_bin_ld bin_db, char *s_i, char *s_d, t_tp prt);
void				ft_arr_ft(int (*functptr[11])());
void				ft_arr_p(char *v);
char				*ft_mts_represent2(t_tp prt, char *str, int ng);
int					ft_mts_bin(char *d, char *i, t_bin_d b);
int					ft_mts_bin2(char *d, char *i, t_tp prt);
char				*ft_mts_represent(double d, t_tp prt, char *s_i, char *s_d);
int					ft_f_mc(char *str_integer, char *str_double);
int					ft_i(char *buff, long long i);
int					ft_len_int(long long i);
char				*ft_flag_d(char *str, t_tp prt, int s, int ng);
void				ft_str_str2(char *str2, char *str);
void				ft_x_zero(char *str);
void				ft_p_flag(char *flags);
void				ft_nb_space(int nb_space, char *str2);
void				ft_nb_zero(char *str, int nb_zero);
char				*ft_fill_zero(char *str, t_tp prt, int deci);
void				ft_fill_space2(char *s, char *str2, t_tp prt, int nb_s);
char				*ft_fill_space(char *str, t_tp prt);
char				*ft_fill_sign(char *str, int deci, t_tp prt);
int					ft_space_len(int outputlen, t_tp prt, int n);
t_tp				ft_flag(t_tp prt, char *pa);
t_tp				ft_fg_width(const char *pa, t_tp prt);
t_lh				ft_fg_lh(const char *pa);
int					ft_buffer(char *buff, const char *c);
int					len_int(long long int i);
int					cal_exp(double d);
void				ft_add_in_str(char *power_2, char *s_i, char bin_z_str);
int					ft_float_b_d(double d, char *buff, t_tp prt);
char				*ft_strprc(char *s, size_t len);
char				*ft_strj0x(char *str);
int					address_hex(unsigned long long add, char *buff, t_tp prt);
void				ft_x_m(char *str);
int					ft_case_d(char *buf, va_list ap, t_tp prt, t_lh lh);
int					ft_case_o(char *buff, va_list ap, t_tp prt, t_lh lh);
int					ft_case_x(char *buff, va_list ap, t_tp prt, t_lh lh);
int					ft_case_mx(char *buff, va_list ap, t_tp prt, t_lh lh);
int					ft_case_c(char *buff, va_list ap, t_tp prt, t_lh lh);
int					ft_case_p(char *buff, va_list ap, t_tp prt, t_lh lh);
int					ft_case_u(char *buff, va_list ap, t_tp prt, t_lh lh);
int					ft_case_f(char *buff, va_list ap, t_tp prt, t_lh lh);
int					ft_case_s(char *buff, va_list ap, t_tp prt, t_lh lh);
int					ft_case_per(char *buff, va_list ap, t_tp prt, t_lh lh);
int					ft_nprintf2(const char *pa, char *buff, va_list ap);
int					ft_rt_pa(const char *pa);
int					ft_cpy_until_p(char *p, char *buff, const char *pa);
int					ft_nprintf(char *buff, const char *pa, va_list ap, char *p);
int					ft_printf(const char *pa, ...);
void				ft_plusint_1(char *str_integer);
char				*ft_case_f_str(va_list ap, t_tp prt, t_lh lh, t_b_d b_d);
char				*ft_case_f_nan(t_tp prt);
char				*ft_int_cat_prc3(int h, char *s_in, char *s_d);
char				*ft_int_cat_prc2(char *str_double, char *str_integer);
#endif
