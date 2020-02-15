/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:48:26 by weilin            #+#    #+#             */
/*   Updated: 2020/02/15 21:26:37 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"
# define FLAGS "+-0# *."

void	init_flags(t_pfinfo *e)
{
	e->flags.plus = 0;
	e->flags.minus = 0;
	e->flags.zero = 0;
	e->flags.space = 0;
	e->flags.hash = 0;
	e->flags.width = 0;
	e->flags.prec = 0;
}
static void get_flags(const char *fmt, t_pfinfo *e)
{
	while(ft_strchr(FLAGS, fmt[e->i]))
	{
		fmt[e->i] == '+' ? e->flags.plus = 1 : 0;
		fmt[e->i] == '-' ? e->flags.minus = 1 : 0;
		fmt[e->i] == '0' ? e->flags.zero = 1 : 0;
		fmt[e->i] == '#' ? e->flags.hash = 1 : 0;
		fmt[e->i] == ' ' ? e->flags.space = 1 : 0;
		
	}
}

void get_input(const char *fmt, t_pfinfo *e)
{
	e->i++;
	init_flags(e);
	get_flags(fmt, e);

}

int ft_printf(const char *fmt, ...)
{
	t_pfinfo e;

	ft_bzero(&e, sizeof(e));
	va_start(e.valist, fmt);
	if ((e.fd = 1) && fmt)
	{
		e.len = (int)ft_strlen(fmt);
		while (e.i < e.len)
		{
			if (fmt[e.i] == '%' && e.len == 1)
				break;
			else if (fmt[e.i] == '%' && fmt[e.i + 1] == '%')
			{
				e.nb_printf += write(1, "%", 1);
		 		e.i += 2;
			}
			else if (fmt[e.i] == '%' && fmt[e.i + 1] != '%')
				get_input(fmt, &e);
			else
				e.nb_printf += write(1, fmt + (e.i)++, 1);
		}
	}
	va_end(e.valist);
	return (e.nb_printf);
}

void my(void)
{ // char *c1="%c\n";
	// char *ptr = "%c%c%c";
	char *ptr2 = "1C-Nothing_%1.3d%_";

	// char *ptr = c2;
	// printf(ptr, 'c', 'd');
	int k = ft_printf("%c%c%c", 't', 'j', 'i');
	printf("\n%d", k);
	printf(ptr2, -1);
	(void)ptr2;
}
void t1(void)
{
	// printf("1-Simple String.", 0);
	// printf("2-Stringception _%s_", "Hello World");
	// printf("3-Stringception _%12s_", "Hello World");
	// printf("4-Stringception _%-12s_", "Hello World");
	// printf("5-Stringception _%20.5s_", "Hello World");
	// printf("6-Stringception _%-20.5s_", "Hello World");
	// printf("7-Stringception _%20s_", "Hello World");
	// printf("7-Stringception _%020s_", "Hello World");
	// printf("8-Stringception _%0-.20s_", "Hello World");
	// printf("9-Stringception _%20s_", "Hello World");
	// printf("A-Stringception _%20s_", "Hello World");
	// printf("B-Stringception _%20.s_", "Hello World");
	// printf("C-Stringception _%-#20s_", "Hello World");
}
void n1(void)
{
	// printf("1-Simple String.", 0);
	// printf("2-Stringception _%s_", "Hello World");
	// printf("3-Stringception _%12s_", "Hello World");
	// printf("4-Stringception _%-12s_", "Hello World");
	// printf("5-Stringception _%20.5s_", "Hello World");
	// printf("6-Stringception _%-20.5s_", "Hello World");
	printf("7-Stringception _%20d_", -'*');
	printf("7-Stringception _%020d_", -'*');
	// printf("8-Stringception _%0-.20s_", "Hello World");
	// printf("9-Stringception _%20s_", "Hello World");
	// printf("A-Stringception _%20s_", "Hello World");
	// printf("B-Stringception _%20.s_", "Hello World");
	// printf("C-Stringception _%-#20s_", "Hello World");
}
int main()
{
	// char *c1 = "%%%";
	// ft_printf(c1);
	// printf("\n%d", k);
	// n1();
	// char *conv2="%s\n";
	// printf(conv2, "string");

	// char *conv3="%p\n";
	// printf(conv3, "string");

	// printf(conv3, conv1);
	// printf(conv3, conv2);
	// printf(conv3, conv3);

	// printf("%%%%");
	// printf("%*d", -5, 12);
	// int a = 1;
	// printf("t1.1:\n%1.1s\n", "what");
	// printf("t1.2:\n%1.2s\n", "what");
	// printf("t1.3:\n%1.3s\n", "what");
	// printf("t1.4:\n%1.4s\n", "what");
	// printf("t2.1:\n%2.1s\n", "what");
	// printf("t2.2:\n%2.2s\n", "what");
	// printf("t2.3:\n%2.3s\n", "what");
	// printf("t2.4:\n%2.4s\n", "what");
	// printf("%%c=%c\n", 'c');
	// printf("%%C=%C\n", 'c');
	// // printf("%%c=%c\n",'中');
	// // printf("%%C=%C\n",'中');
	// printf("%%");//印出 %
	// printf("t1:\n%-1.1s_\n", "whatwhatwhat");
	// printf("t2:\n%-2.2s_\n", "whatwhatwhat");
	// printf("t3:\n%-3.3s_\n", "whatwhatwhat");
	// printf("t4:\n%-4.4s_\n", "whatwhatwhat");
	// printf("t5:\n%-5.5s_\n", "whatwhatwhat");
	printf("%-3.2d", 756654);

	// int counter = 0;
	// counter = printf("%d\n", 10);
	// printf("counter is %d\n", counter);

	return 0;
}
