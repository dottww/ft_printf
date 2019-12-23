/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:48:26 by weilin            #+#    #+#             */
/*   Updated: 2019/12/23 19:07:02 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
// #include "ft_printf.h"
int ft_printf(const char *fmt, ...)
{
	int nb_printf;
	va_list ap;

	nb_printf = 0;
	va_start(ap, fmt); // put everything in format into ap
	printf("%s",fmt);
	
	if (*fmt == '%' && *(fmt + 1) == 'c' && *(fmt + 2) == '%' && *(fmt + 3) == 'c')
	{
		char arg = (char)va_arg(ap, int);
		nb_printf+=printf("%c", arg);
		char arg2 = (char)va_arg(ap, int);
		nb_printf+=printf("%c", arg2);
	}

	// nb_printf = ft_vprintf(format, ap);// take out each argument one by one from ap
	va_end(ap);
	return (nb_printf);
}
int main()
{
	// char *c1="%c\n";
	char *c2 = "%c%c%c%c\n";
	char *ptr = c2;
	// printf(ptr, 'c', 'd');
	int k = ft_printf(ptr, 'e', 'f');
	printf("%d", k);

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
	// printf("t6:\n%-6.6s_\n", "whatwhatwhat");

	// int counter = 0;
	// counter = printf("%d\n", 10);
	// printf("counter is %d\n", counter);

	return 0;
}
