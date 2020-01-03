/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:48:26 by weilin            #+#    #+#             */
/*   Updated: 2019/12/01 21:02:33 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
// #include <stdarg.h>

int main()
{
	char *conv1="%%%-2c\n";// -靠左對齊
	char *conv2="%%%+2c\n";// +靠右對齊

	printf(conv1, 'a');
	printf(conv2, 'b');

	ft_printf(conv1, 'c');
	ft_printf(conv2, 'k');

	printf("%#o\n", 64);
	printf("%#o\n", 9);

	printf("%#x\n", 256);
	printf("%#-6x\n", 9);

	// ft_printf("%o\n", 6);
	// ft_printf("%o\n", 7);

	// ft_printf("%p\n",conv1);
	// ft_printf("%p\n",conv2);
	// ft_printf("%s\n",conv1);
	// ft_printf("%s\n",conv2);
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
