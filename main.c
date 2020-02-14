/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:48:26 by weilin            #+#    #+#             */
/*   Updated: 2020/02/14 17:29:15 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
// #include "libft/libft.h"
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_printf(const char *fmt, ...)
{
	t_pfinfo e;

	e.nb_printf = 0;
	va_start(e.valist, fmt); // put everything in format into valist

	char arg;
	while (fmt[e.i])
	{
		if (fmt[e.i] == '%')
		{
			arg = (char)va_arg(e.valist, int);
			ft_putchar(arg);
			i = i + 2;
		}
		else if (fmt[i] != '%')
		{
			write(1, fmt + i, 1);
			i++;
		}
	}

	// nb_printf = ft_vprintf(format, valist);// take out each argument one by one from valist
	va_end(e.valist);
	return (e.nb_printf);
}

void my(void)
{	// char *c1="%c\n";
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
	my();
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
	// printf("t6:\n%-6.6s_\n", "whatwhatwhat");

	// int counter = 0;
	// counter = printf("%d\n", 10);
	// printf("counter is %d\n", counter);

	return 0;
}
