/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:17:21 by lgaultie          #+#    #+#             */
/*   Updated: 2020/02/17 18:54:45 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include "include/ft_printf.h"
// #include "libft.h"


//leak de %-----s corrigé en mettant un free dans ft_minus....
// printf("18) Vrai PRINTF : |%.u|\n", 0);
// ft_printf("18) Mon PRINTF  : |%.u|\n", 0);			//JARRRIVE PAS A LE DEBUG
/*
void rest2(void)
{
	ft_printf("--------------------%%d-et-%%i--------------------\n");	//perfect
	printf("01) Vrai PRINTF : |%d|\n", 42);
	ft_printf("01) Mon PRINTF  : |%d|\n", 42);
	printf("02) Vrai PRINTF : |%i|\n", 42);
	ft_printf("02) Mon PRINTF  : |%i|\n", 42);
	printf("03) Vrai PRINTF : |%+d|\n", 42);
	ft_printf("03) Mon PRINTF  : |%+d|\n", 42);
	printf("04) Vrai PRINTF : |%-d|\n", 42);
	ft_printf("04) Mon PRINTF  : |%-d|\n", 42);
	printf("05) Vrai PRINTF : |%10d|\n", 100);
	ft_printf("05) Mon PRINTF  : |%10d|\n", 100);
	printf("06) Vrai PRINTF : |%-10d|\n", 64);
	ft_printf("06) Mon PRINTF  : |%-10d|\n", 64);
	printf("07) Vrai PRINTF : |%.10d|\n", 100);
	ft_printf("07) Mon PRINTF  : |%.10d|\n", 100);
	printf("08) Vrai PRINTF : |%10.5d|\n", 100);
	ft_printf("08) Mon PRINTF  : |%10.5d|\n", 100);
	printf("09) Vrai PRINTF : |%5.10d|\n", 64);
	ft_printf("09) Mon PRINTF  : |%5.10d|\n", 64);
	printf("10) Vrai PRINTF : |%1.1d|\n", 16);
	ft_printf("10) Mon PRINTF  : |%1.1d|\n", 16);
	printf("11) Vrai PRINTF : |%+10d|\n", 50);
	ft_printf("11) Mon PRINTF  : |%+10d|\n", 50);
	printf("12) Vrai PRINTF : |%+2d|\n", 50);
	ft_printf("12) Mon PRINTF  : |%+2d|\n", 50);
	printf("13) Vrai PRINTF : |%+.10d|\n", 50);
	ft_printf("13) Mon PRINTF  : |%+.10d|\n", 50);
	printf("14) Vrai PRINTF : |%+.2d|\n", 50);
	ft_printf("14) Mon PRINTF  : |%+.2d|\n", 50);
	printf("15) Vrai PRINTF : |%          d|\n", 1);
	ft_printf("15) Mon PRINTF  : |%          d|\n", 1);
	printf("16) Vrai PRINTF : |% -d|\n", 1);
	ft_printf("16) Mon PRINTF  : |% -d|\n", 1);
	printf("17) Vrai PRINTF : |%-+d|\n", 32);
	ft_printf("17) Mon PRINTF  : |%-+d|\n", 32);
	printf("18) Vrai PRINTF : |%+-d|\n", 32);
	ft_printf("18) Mon PRINTF  : |%+-d|\n", 32);
	printf("19) Vrai PRINTF : |%-+10d|\n", 42);
	ft_printf("19) Mon PRINTF  : |%-+10d|\n", 42);
	printf("20) Vrai PRINTF : |%-+.10d|\n", 42);
	ft_printf("20) Mon PRINTF  : |%-+.10d|\n", 42);
	printf("21) Vrai PRINTF : |%d|\n", -42);
	ft_printf("21) Mon PRINTF  : |%d|\n", -42);
	printf("22) Vrai PRINTF : |%10d|\n", -42);
	ft_printf("22) Mon PRINTF  : |%10d|\n", -42);
	printf("23) Vrai PRINTF : |%.10d|\n", -42);
	ft_printf("23) Mon PRINTF  : |%.10d|\n", -42);
	printf("24) Vrai PRINTF : |%+d|\n", -10);
	ft_printf("24) Mon PRINTF  : |%+d|\n", -10);
	printf("25) Vrai PRINTF : |%10.5d|\n", -16);
	ft_printf("25) Mon PRINTF  : |%10.5d|\n", -16);
	printf("26) Vrai PRINTF : |%5.10d|\n", -16);
	ft_printf("26) Mon PRINTF  : |%5.10d|\n", -16);
	printf("27) Vrai PRINTF : |%1.1d|\n", -20);
	ft_printf("27) Mon PRINTF  : |%1.1d|\n", -20);
	printf("28) Vrai PRINTF : |%-10d|\n", -50);
	ft_printf("29) Mon PRINTF  : |%-10d|\n", -50);
	printf("30) Vrai PRINTF : |%++++++++++d|\n", 69);
	ft_printf("30) Mon PRINTF  : |%++++++++++d|\n", 69);
	printf("31) Vrai PRINTF : |%+10d|\n", -64);
	ft_printf("31) Mon PRINTF  : |%+10d|\n", -64);
	printf("32) Vrai PRINTF : |%+.10d|\n", -64);
	ft_printf("32) Mon PRINTF  : |%+.10d|\n", -64);
	printf("33) Vrai PRINTF : |%2d|\n", -20);
	ft_printf("33) Mon PRINTF  : |%2d|\n", -20);
	printf("34) Vrai PRINTF : |%.2d|\n", -20);
	ft_printf("34) Mon PRINTF  : |%.2d|\n", -20);
	printf("35) Vrai PRINTF : |%2d|\n", -1);
	ft_printf("35) Mon PRINTF  : |%2d|\n", -1);
	printf("36) Vrai PRINTF : |%.2d|\n", -1);
	ft_printf("36) Mon PRINTF  : |%.2d|\n", -1);
	printf("37) Vrai PRINTF : |%-10d|\n", -80);
	ft_printf("37) Mon PRINTF  : |%-10d|\n", -80);
	printf("38) Vrai PRINTF : |%-.10d|\n", -80);
	ft_printf("38) Mon PRINTF  : |%-.10d|\n", -80);
	printf("39) Vrai PRINTF : |%06d|\n", 35);
	ft_printf("39) Mon PRINTF  : |%06d|\n", 35);
	printf("40) Vrai PRINTF : |%06d|\n", -35);
	ft_printf("40) Mon PRINTF  : |%06d|\n", -35);
	printf("41) Vrai PRINTF : |%-+10d|\n", -40);
	ft_printf("41) Mon PRINTF  : |%-+10d|\n", -40);
	printf("42) Vrai PRINTF : |%+-10d|\n", -40);
	ft_printf("42) Mon PRINTF  : |%+-10d|\n", -40);
	printf("43) Vrai PRINTF : |%05.3d|\n", 5);
	ft_printf("43) Mon PRINTF  : |%05.3d|\n", 5);
	printf("44) Vrai PRINTF : |%03.5d|\n", 5);
	ft_printf("44) Mon PRINTF  : |%03.5d|\n", 5);
	printf("45) Vrai PRINTF : |%05.3d|\n", -5);
	ft_printf("45) Mon PRINTF  : |%05.3d|\n", -5);
	printf("46) Vrai PRINTF : |%03.5d|\n", -5);
	ft_printf("46) Mon PRINTF  : |%03.5d|\n", -5);
	printf("47) Vrai PRINTF : |%d| |%d|\n", INT_MAX, INT_MIN);
	ft_printf("47) Mon PRINTF  : |%d| |%d|\n", INT_MAX, INT_MIN);
	printf("48) Vrai PRINTF : |%d| |%d|\n", INT_MAX + 1, INT_MIN - 1);
	ft_printf("48) Mon PRINTF  : |%d| |%d|\n", INT_MAX + 1, INT_MIN - 1);
	printf("49) Vrai PRINTF : |%.d|\n", 0);
	ft_printf("49) Mon PRINTF  : |%.d|\n", 0);
	printf("50) Vrai PRINTF : |%.d|\n", 100);
	ft_printf("50) Mon PRINTF  : |%.d|\n", 100);
	ft_printf("--------------------%%hd-et-%%hi--------------------\n");	//perfect
	printf("01) Vrai PRINTF : |%hd|\n", (short)42);
	ft_printf("01) Mon PRINTF  : |%hd|\n", (short)42);
	printf("02) Vrai PRINTF : |%hi|\n", (short)42);
	ft_printf("02) Mon PRINTF  : |%hi|\n", (short)42);
	printf("03) Vrai PRINTF : |%+hd|\n", (short)42);
	ft_printf("03) Mon PRINTF  : |%+hd|\n", (short)42);
	printf("04) Vrai PRINTF : |%-hd|\n", (short)42);
	ft_printf("04) Mon PRINTF  : |%-hd|\n", (short)42);
	printf("05) Vrai PRINTF : |%10hd|\n", (short)100);
	ft_printf("05) Mon PRINTF  : |%10hd|\n", (short)100);
	printf("06) Vrai PRINTF : |%-10hd|\n", (short)64);
	ft_printf("06) Mon PRINTF  : |%-10hd|\n", (short)64);
	printf("07) Vrai PRINTF : |%.10hd|\n", (short)100);
	ft_printf("07) Mon PRINTF  : |%.10hd|\n", (short)100);
	printf("08) Vrai PRINTF : |%10.5hd|\n", (short)100);
	ft_printf("08) Mon PRINTF  : |%10.5hd|\n", (short)100);
	printf("09) Vrai PRINTF : |%5.10hd|\n", (short)64);
	ft_printf("09) Mon PRINTF  : |%5.10hd|\n", (short)64);
	printf("10) Vrai PRINTF : |%1.1hd|\n", (short)16);
	ft_printf("10) Mon PRINTF  : |%1.1hd|\n", (short)16);
	printf("11) Vrai PRINTF : |%+10hd|\n", (short)50);
	ft_printf("11) Mon PRINTF  : |%+10hd|\n", (short)50);
	printf("12) Vrai PRINTF : |%+2hd|\n", (short)50);
	ft_printf("12) Mon PRINTF  : |%+2hd|\n", (short)50);
	printf("13) Vrai PRINTF : |%+.10hd|\n", (short)50);
	ft_printf("13) Mon PRINTF  : |%+.10hd|\n", (short)50);
	printf("14) Vrai PRINTF : |%+.2hd|\n", (short)50);
	ft_printf("14) Mon PRINTF  : |%+.2hd|\n", (short)50);
	printf("15) Vrai PRINTF : |%          hd|\n", (short)1);
	ft_printf("15) Mon PRINTF  : |%          hd|\n", (short)1);
	printf("16) Vrai PRINTF : |% -hd|\n", (short)1);
	ft_printf("16) Mon PRINTF  : |% -hd|\n", (short)1);
	printf("17) Vrai PRINTF : |%-+hd|\n", (short)32);
	ft_printf("17) Mon PRINTF  : |%-+hd|\n", (short)32);
	printf("18) Vrai PRINTF : |%+-hd|\n", (short)32);
	ft_printf("18) Mon PRINTF  : |%+-hd|\n", (short)32);
	printf("19) Vrai PRINTF : |%-+10hd|\n", (short)42);
	ft_printf("19) Mon PRINTF  : |%-+10hd|\n", (short)42);
	printf("20) Vrai PRINTF : |%-+.10hd|\n", (short)42);
	ft_printf("20) Mon PRINTF  : |%-+.10hd|\n", (short)42);
	printf("21) Vrai PRINTF : |%hd|\n", (short)-42);
	ft_printf("21) Mon PRINTF  : |%hd|\n", (short)-42);
	printf("22) Vrai PRINTF : |%10hd|\n", (short)-42);
	ft_printf("22) Mon PRINTF  : |%10hd|\n", (short)-42);
	printf("23) Vrai PRINTF : |%.10hd|\n", (short)-42);
	ft_printf("23) Mon PRINTF  : |%.10hd|\n", (short)-42);
	printf("24) Vrai PRINTF : |%+hd|\n", (short)-10);
	ft_printf("24) Mon PRINTF  : |%+hd|\n", (short)-10);
	printf("25) Vrai PRINTF : |%10.5hd|\n", (short)-16);
	ft_printf("25) Mon PRINTF  : |%10.5hd|\n", (short)-16);
	printf("26) Vrai PRINTF : |%5.10hd|\n", (short)-16);
	ft_printf("26) Mon PRINTF  : |%5.10hd|\n", (short)-16);
	printf("27) Vrai PRINTF : |%1.1hd|\n", (short)-20);
	ft_printf("27) Mon PRINTF  : |%1.1hd|\n", (short)-20);
	printf("28) Vrai PRINTF : |%-10hd|\n", (short)-50);
	ft_printf("29) Mon PRINTF  : |%-10hd|\n", (short)-50);
	printf("30) Vrai PRINTF : |%++++++++++hd|\n", (short)69);
	ft_printf("30) Mon PRINTF  : |%++++++++++hd|\n", (short)69);
	printf("31) Vrai PRINTF : |%+10hd|\n", (short)-64);
	ft_printf("31) Mon PRINTF  : |%+10hd|\n", (short)-64);
	printf("32) Vrai PRINTF : |%+.10hd|\n", (short)-64);
	ft_printf("32) Mon PRINTF  : |%+.10hd|\n", (short)-64);
	printf("33) Vrai PRINTF : |%2hd|\n", (short)-20);
	ft_printf("33) Mon PRINTF  : |%2hd|\n", (short)-20);
	printf("34) Vrai PRINTF : |%.2hd|\n", (short)-20);
	ft_printf("34) Mon PRINTF  : |%.2hd|\n", (short)-20);
	printf("35) Vrai PRINTF : |%2hd|\n", (short)-1);
	ft_printf("35) Mon PRINTF  : |%2hd|\n", (short)-1);
	printf("36) Vrai PRINTF : |%.2hd|\n", (short)-1);
	ft_printf("36) Mon PRINTF  : |%.2hd|\n", (short)-1);
	printf("37) Vrai PRINTF : |%-10hd|\n", (short)-80);
	ft_printf("37) Mon PRINTF  : |%-10hd|\n", (short)-80);
	printf("38) Vrai PRINTF : |%-.10hd|\n", (short)-80);
	ft_printf("38) Mon PRINTF  : |%-.10hd|\n", (short)-80);
	printf("39) Vrai PRINTF : |%06hd|\n", (short)35);
	ft_printf("39) Mon PRINTF  : |%06hd|\n", (short)35);
	printf("40) Vrai PRINTF : |%06hd|\n", (short)-35);
	ft_printf("40) Mon PRINTF  : |%06hd|\n", (short)-35);
	printf("41) Vrai PRINTF : |%-+10hd|\n", (short)-40);
	ft_printf("41) Mon PRINTF  : |%-+10hd|\n", (short)-40);
	printf("42) Vrai PRINTF : |%+-10hd|\n", (short)-40);
	ft_printf("42) Mon PRINTF  : |%+-10hd|\n", (short)-40);
	printf("43) Vrai PRINTF : |%05.3hd|\n", (short)5);
	ft_printf("43) Mon PRINTF  : |%05.3hd|\n", (short)5);
	printf("44) Vrai PRINTF : |%03.5hd|\n", (short)5);
	ft_printf("44) Mon PRINTF  : |%03.5hd|\n", (short)5);
	printf("45) Vrai PRINTF : |%05.3hd|\n", (short)-5);
	ft_printf("45) Mon PRINTF  : |%05.3hd|\n", (short)-5);
	printf("46) Vrai PRINTF : |%03.5hd|\n", (short)-5);
	ft_printf("46) Mon PRINTF  : |%03.5hd|\n", (short)-5);
	printf("47) Vrai PRINTF : |%hd| |%hd|\n", (short)32767, (short)-32768);
	ft_printf("47) Mon PRINTF  : |%hd| |%hd|\n", (short)32767, (short)-32768);
	printf("48) Vrai PRINTF : |%hd| |%hd|\n", (short)32768, (short)-32769);
	ft_printf("48) Mon PRINTF  : |%hd| |%hd|\n", (short)32768, (short)-32769);
	printf("49) Vrai PRINTF : |%.hd|\n", (short)0);
	ft_printf("49) Mon PRINTF  : |%.hd|\n", (short)0);
	printf("50) Vrai PRINTF : |%.hd|\n", (short)100);
	ft_printf("50) Mon PRINTF  : |%.hd|\n", (short)100);
	ft_printf("--------------------%%hhd-et-%%hhi--------------------\n");	//perfect
	printf("01) Vrai PRINTF : |%hhd|\n", (char)42);
	ft_printf("01) Mon PRINTF  : |%hhd|\n", (char)42);
	printf("02) Vrai PRINTF : |%hhi|\n", (char)42);
	ft_printf("02) Mon PRINTF  : |%hhi|\n", (char)42);
	printf("03) Vrai PRINTF : |%+hhd|\n", (char)42);
	ft_printf("03) Mon PRINTF  : |%+hhd|\n", (char)42);
	printf("04) Vrai PRINTF : |%-hhd|\n", (char)42);
	ft_printf("04) Mon PRINTF  : |%-hhd|\n", (char)42);
	printf("05) Vrai PRINTF : |%10hhd|\n", (char)100);
	ft_printf("05) Mon PRINTF  : |%10hhd|\n", (char)100);
	printf("06) Vrai PRINTF : |%-10hhd|\n", (char)64);
	ft_printf("06) Mon PRINTF  : |%-10hhd|\n", (char)64);
	printf("07) Vrai PRINTF : |%.10hhd|\n", (char)100);
	ft_printf("07) Mon PRINTF  : |%.10hhd|\n", (char)100);
	printf("08) Vrai PRINTF : |%10.5hhd|\n", (char)100);
	ft_printf("08) Mon PRINTF  : |%10.5hhd|\n", (char)100);
	printf("09) Vrai PRINTF : |%5.10hhd|\n", (char)64);
	ft_printf("09) Mon PRINTF  : |%5.10hhd|\n", (char)64);
	printf("10) Vrai PRINTF : |%1.1hhd|\n", (char)16);
	ft_printf("10) Mon PRINTF  : |%1.1hhd|\n", (char)16);
	printf("11) Vrai PRINTF : |%+10hhd|\n", (char)50);
	ft_printf("11) Mon PRINTF  : |%+10hhd|\n", (char)50);
	printf("12) Vrai PRINTF : |%+2hhd|\n", (char)50);
	ft_printf("12) Mon PRINTF  : |%+2hhd|\n", (char)50);
	printf("13) Vrai PRINTF : |%+.10hhd|\n", (char)50);
	ft_printf("13) Mon PRINTF  : |%+.10hhd|\n", (char)50);
	printf("14) Vrai PRINTF : |%+.2hhd|\n", (char)50);
	ft_printf("14) Mon PRINTF  : |%+.2hhd|\n", (char)50);
	printf("15) Vrai PRINTF : |%          hhd|\n", (char)1);
	ft_printf("15) Mon PRINTF  : |%          hhd|\n", (char)1);
	printf("16) Vrai PRINTF : |% -hhd|\n", (char)1);
	ft_printf("16) Mon PRINTF  : |% -hhd|\n", (char)1);
	printf("17) Vrai PRINTF : |%-+hhd|\n", (char)32);
	ft_printf("17) Mon PRINTF  : |%-+hhd|\n", (char)32);
	printf("18) Vrai PRINTF : |%+-hhd|\n", (char)32);
	ft_printf("18) Mon PRINTF  : |%+-hhd|\n", (char)32);
	printf("19) Vrai PRINTF : |%-+10hhd|\n", (char)42);
	ft_printf("19) Mon PRINTF  : |%-+10hhd|\n", (char)42);
	printf("20) Vrai PRINTF : |%-+.10hhd|\n", (char)42);
	ft_printf("20) Mon PRINTF  : |%-+.10hhd|\n", (char)42);
	printf("21) Vrai PRINTF : |%hhd|\n", (char)-42);
	ft_printf("21) Mon PRINTF  : |%hhd|\n", (char)-42);
	printf("22) Vrai PRINTF : |%10hhd|\n", (char)-42);
	ft_printf("22) Mon PRINTF  : |%10hhd|\n", (char)-42);
	printf("23) Vrai PRINTF : |%.10hhd|\n", (char)-42);
	ft_printf("23) Mon PRINTF  : |%.10hhd|\n", (char)-42);
	printf("24) Vrai PRINTF : |%+hhd|\n", (char)-10);
	ft_printf("24) Mon PRINTF  : |%+hhd|\n", (char)-10);
	printf("25) Vrai PRINTF : |%10.5hhd|\n", (char)-16);
	ft_printf("25) Mon PRINTF  : |%10.5hhd|\n", (char)-16);
	printf("26) Vrai PRINTF : |%5.10hhd|\n", (char)-16);
	ft_printf("26) Mon PRINTF  : |%5.10hhd|\n", (char)-16);
	printf("27) Vrai PRINTF : |%1.1hhd|\n", (char)-20);
	ft_printf("27) Mon PRINTF  : |%1.1hhd|\n", (char)-20);
	printf("28) Vrai PRINTF : |%-10hhd|\n", (char)-50);
	ft_printf("29) Mon PRINTF  : |%-10hhd|\n", (char)-50);
	printf("30) Vrai PRINTF : |%++++++++++hhd|\n", (char)69);
	ft_printf("30) Mon PRINTF  : |%++++++++++hhd|\n", (char)69);
	printf("31) Vrai PRINTF : |%+10hhd|\n", (char)-64);
	ft_printf("31) Mon PRINTF  : |%+10hhd|\n", (char)-64);
	printf("32) Vrai PRINTF : |%+.10hhd|\n", (char)-64);
	ft_printf("32) Mon PRINTF  : |%+.10hhd|\n", (char)-64);
	printf("33) Vrai PRINTF : |%2hhd|\n", (char)-20);
	ft_printf("33) Mon PRINTF  : |%2hhd|\n", (char)-20);
	printf("34) Vrai PRINTF : |%.2hhd|\n", (char)-20);
	ft_printf("34) Mon PRINTF  : |%.2hhd|\n", (char)-20);
	printf("35) Vrai PRINTF : |%2hhd|\n", (char)-1);
	ft_printf("35) Mon PRINTF  : |%2hhd|\n", (char)-1);
	printf("36) Vrai PRINTF : |%.2hhd|\n", (char)-1);
	ft_printf("36) Mon PRINTF  : |%.2hhd|\n", (char)-1);
	printf("37) Vrai PRINTF : |%-10hhd|\n", (char)-80);
	ft_printf("37) Mon PRINTF  : |%-10hhd|\n", (char)-80);
	printf("38) Vrai PRINTF : |%-.10hhd|\n", (char)-80);
	ft_printf("38) Mon PRINTF  : |%-.10hhd|\n", (char)-80);
	printf("39) Vrai PRINTF : |%06hhd|\n", (char)35);
	ft_printf("39) Mon PRINTF  : |%06hhd|\n", (char)35);
	printf("40) Vrai PRINTF : |%06hhd|\n", (char)-35);
	ft_printf("40) Mon PRINTF  : |%06hhd|\n", (char)-35);
	printf("41) Vrai PRINTF : |%-+10hhd|\n", (char)-40);
	ft_printf("41) Mon PRINTF  : |%-+10hhd|\n", (char)-40);
	printf("42) Vrai PRINTF : |%+-10hhd|\n", (char)-40);
	ft_printf("42) Mon PRINTF  : |%+-10hhd|\n", (char)-40);
	printf("43) Vrai PRINTF : |%05.3hhd|\n", (char)5);
	ft_printf("43) Mon PRINTF  : |%05.3hhd|\n", (char)5);
	printf("44) Vrai PRINTF : |%03.5hhd|\n", (char)5);
	ft_printf("44) Vrai PRINTF : |%03.5hhd|\n", (char)5);
	printf("45) Vrai PRINTF : |%05.3hhd|\n", (char)-5);
	ft_printf("45) Mon PRINTF  : |%05.3hhd|\n", (char)-5);
	printf("46) Vrai PRINTF : |%03.5hhd|\n", (char)-5);
	ft_printf("46) Mon PRINTF  : |%03.5hhd|\n", (char)-5);
	printf("47) Vrai PRINTF : |%hhd| |%hhd|\n", (char)127, (char)-128);
	ft_printf("47) Mon PRINTF  : |%hhd| |%hhd|\n", (char)127, (char)-128);
	printf("48) Vrai PRINTF : |%hhd| |%hhd|\n", (char)128, (char)-129);
	ft_printf("48) Mon PRINTF  : |%hhd| |%hhd|\n", (char)128, (char)-129);
	printf("49) Vrai PRINTF : |%.hhd|\n", (char)0);
	ft_printf("49) Mon PRINTF  : |%.hhd|\n", (char)0);
	printf("50) Vrai PRINTF : |%.hhd|\n", (char)100);
	ft_printf("50) Mon PRINTF  : |%.hhd|\n", (char)100);
	ft_printf("--------------------%%ld-et-%%li--------------------\n");	//48/50
	printf("01) Vrai PRINTF : |%ld|\n", (long)42);
	ft_printf("01) Mon PRINTF  : |%ld|\n", (long)42);
	printf("02) Vrai PRINTF : |%li|\n", (long)42);
	ft_printf("02) Mon PRINTF  : |%li|\n", (long)42);
	printf("03) Vrai PRINTF : |%+ld|\n", (long)42);
	ft_printf("03) Mon PRINTF  : |%+ld|\n", (long)42);
	printf("04) Vrai PRINTF : |%-ld|\n", (long)42);
	ft_printf("04) Mon PRINTF  : |%-ld|\n", (long)42);
	printf("05) Vrai PRINTF : |%10ld|\n", (long)100);
	ft_printf("05) Mon PRINTF  : |%10ld|\n", (long)100);
	printf("06) Vrai PRINTF : |%-10ld|\n", (long)64);
	ft_printf("06) Mon PRINTF  : |%-10ld|\n", (long)64);
	printf("07) Vrai PRINTF : |%.10ld|\n", (long)100);
	ft_printf("07) Mon PRINTF  : |%.10ld|\n", (long)100);
	printf("08) Vrai PRINTF : |%10.5ld|\n", (long)100);
	ft_printf("08) Mon PRINTF  : |%10.5ld|\n", (long)100);
	printf("09) Vrai PRINTF : |%5.10ld|\n", (long)64);
	ft_printf("09) Mon PRINTF  : |%5.10ld|\n", (long)64);
	printf("10) Vrai PRINTF : |%1.1ld|\n", (long)16);
	ft_printf("10) Mon PRINTF  : |%1.1ld|\n", (long)16);
	printf("11) Vrai PRINTF : |%+10ld|\n", (long)50);
	ft_printf("11) Mon PRINTF  : |%+10ld|\n", (long)50);
	printf("12) Vrai PRINTF : |%+2ld|\n", (long)50);
	ft_printf("12) Mon PRINTF  : |%+2ld|\n", (long)50);
	printf("13) Vrai PRINTF : |%+.10ld|\n", (long)50);
	ft_printf("13) Mon PRINTF  : |%+.10ld|\n", (long)50);
	printf("14) Vrai PRINTF : |%+.2ld|\n", (long)50);
	ft_printf("14) Mon PRINTF  : |%+.2ld|\n", (long)50);
	printf("15) Vrai PRINTF : |%          ld|\n", (long)1);
	ft_printf("15) Mon PRINTF  : |%          ld|\n", (long)1);
	printf("16) Vrai PRINTF : |% -ld|\n", (long)1);
	ft_printf("16) Mon PRINTF  : |% -ld|\n", (long)1);
	printf("17) Vrai PRINTF : |%-+ld|\n", (long)32);
	ft_printf("17) Mon PRINTF  : |%-+ld|\n", (long)32);
	printf("18) Vrai PRINTF : |%+-ld|\n", (long)32);
	ft_printf("18) Mon PRINTF  : |%+-ld|\n", (long)32);
	printf("19) Vrai PRINTF : |%-+10ld|\n", (long)42);
	ft_printf("19) Mon PRINTF  : |%-+10ld|\n", (long)42);
	printf("20) Vrai PRINTF : |%-+.10ld|\n", (long)42);
	ft_printf("20) Mon PRINTF  : |%-+.10ld|\n", (long)42);
	printf("21) Vrai PRINTF : |%ld|\n", (long)-42);
	ft_printf("21) Mon PRINTF  : |%ld|\n", (long)-42);
	printf("22) Vrai PRINTF : |%10ld|\n", (long)-42);
	ft_printf("22) Mon PRINTF  : |%10ld|\n", (long)-42);
	printf("23) Vrai PRINTF : |%.10ld|\n", (long)-42);
	ft_printf("23) Mon PRINTF  : |%.10ld|\n", (long)-42);
	printf("24) Vrai PRINTF : |%+ld|\n", (long)-10);
	ft_printf("24) Mon PRINTF  : |%+ld|\n", (long)-10);
	printf("25) Vrai PRINTF : |%10.5ld|\n", (long)-16);
	ft_printf("25) Mon PRINTF  : |%10.5ld|\n", (long)-16);
	printf("26) Vrai PRINTF : |%5.10ld|\n", (long)-16);
	ft_printf("26) Mon PRINTF  : |%5.10ld|\n", (long)-16);
	printf("27) Vrai PRINTF : |%1.1ld|\n", (long)-20);
	ft_printf("27) Mon PRINTF  : |%1.1ld|\n", (long)-20);
	printf("28) Vrai PRINTF : |%-10ld|\n", (long)-50);
	ft_printf("29) Mon PRINTF  : |%-10ld|\n", (long)-50);
	printf("30) Vrai PRINTF : |%++++++++++ld|\n", (long)69);
	ft_printf("30) Mon PRINTF  : |%++++++++++ld|\n", (long)69);
	printf("31) Vrai PRINTF : |%+10ld|\n", (long)-64);
	ft_printf("31) Mon PRINTF  : |%+10ld|\n", (long)-64);
	printf("32) Vrai PRINTF : |%+.10ld|\n", (long)-64);
	ft_printf("32) Mon PRINTF  : |%+.10ld|\n", (long)-64);
	printf("33) Vrai PRINTF : |%2ld|\n", (long)-20);
	ft_printf("33) Mon PRINTF  : |%2ld|\n", (long)-20);
	printf("34) Vrai PRINTF : |%.2ld|\n", (long)-20);
	ft_printf("34) Mon PRINTF  : |%.2ld|\n", (long)-20);
	printf("35) Vrai PRINTF : |%2ld|\n", (long)-1);
	ft_printf("35) Mon PRINTF  : |%2ld|\n", (long)-1);
	printf("36) Vrai PRINTF : |%.2ld|\n", (long)-1);
	ft_printf("36) Mon PRINTF  : |%.2ld|\n", (long)-1);
	printf("37) Vrai PRINTF : |%-10ld|\n", (long)-80);
	ft_printf("37) Mon PRINTF  : |%-10ld|\n", (long)-80);
	printf("38) Vrai PRINTF : |%-.10ld|\n", (long)-80);
	ft_printf("38) Mon PRINTF  : |%-.10ld|\n", (long)-80);
	printf("39) Vrai PRINTF : |%06ld|\n", (long)35);
	ft_printf("39) Mon PRINTF  : |%06ld|\n", (long)35);
	printf("40) Vrai PRINTF : |%06ld|\n", (long)-35);
	ft_printf("40) Mon PRINTF  : |%06ld|\n", (long)-35);
	printf("41) Vrai PRINTF : |%-+10ld|\n", (long)-40);
	ft_printf("41) Mon PRINTF  : |%-+10ld|\n", (long)-40);
	printf("42) Vrai PRINTF : |%+-10ld|\n", (long)-40);
	ft_printf("42) Mon PRINTF  : |%+-10ld|\n", (long)-40);
	printf("43) Vrai PRINTF : |%05.3ld|\n", (long)5);
	ft_printf("43) Mon PRINTF  : |%05.3ld|\n", (long)5);
	printf("44) Vrai PRINTF : |%03.5ld|\n", (long)5);
	ft_printf("44) Vrai PRINTF : |%03.5ld|\n", (long)5);
	printf("45) Vrai PRINTF : |%05.3ld|\n", (long)-5);
	ft_printf("45) Mon PRINTF  : |%05.3ld|\n", (long)-5);
	printf("46) Vrai PRINTF : |%03.5ld|\n", (long)-5);
	ft_printf("46) Mon PRINTF  : |%03.5ld|\n", (long)-5);
	printf("47) Vrai PRINTF : |%ld| |%ld|\n", (long)LONG_MAX, (long)LONG_MIN);
	ft_printf("47) Mon PRINTF  : |%ld| |%ld|\n", (long)LONG_MAX, (long)LONG_MIN);
	printf("48) Vrai PRINTF : |%ld| |%ld|\n", (long)LONG_MAX + 1, (long)LONG_MIN - 1);
	ft_printf("48) Mon PRINTF  : |%ld| |%ld|\n", (long)LONG_MAX + 1, (long)LONG_MIN - 1);
	printf("49) Vrai PRINTF : |%.ld|\n", (long)0);
	ft_printf("49) Mon PRINTF  : |%.ld|\n", (long)0);
	printf("50) Vrai PRINTF : |%.ld|\n", (long)100);
	ft_printf("50) Mon PRINTF  : |%.ld|\n", (long)100);
	ft_printf("--------------------%%lld-et-%%lli--------------------\n");	//perfect
	printf("01) Vrai PRINTF : |%lld|\n", (long long)42);
	ft_printf("01) Mon PRINTF  : |%lld|\n", (long long)42);
	printf("02) Vrai PRINTF : |%lli|\n", (long long)42);
	ft_printf("02) Mon PRINTF  : |%lli|\n", (long long)42);
	printf("03) Vrai PRINTF : |%+lld|\n", (long long)42);
	ft_printf("03) Mon PRINTF  : |%+lld|\n", (long long)42);
	printf("04) Vrai PRINTF : |%-lld|\n", (long long)42);
	ft_printf("04) Mon PRINTF  : |%-lld|\n", (long long)42);
	printf("05) Vrai PRINTF : |%10lld|\n", (long long)100);
	ft_printf("05) Mon PRINTF  : |%10lld|\n", (long long)100);
	printf("06) Vrai PRINTF : |%-10lld|\n", (long long)64);
	ft_printf("06) Mon PRINTF  : |%-10lld|\n", (long long)64);
	printf("07) Vrai PRINTF : |%.10lld|\n", (long long)100);
	ft_printf("07) Mon PRINTF  : |%.10lld|\n", (long long)100);
	printf("08) Vrai PRINTF : |%10.5lld|\n", (long long)100);
	ft_printf("08) Mon PRINTF  : |%10.5lld|\n", (long long)100);
	printf("09) Vrai PRINTF : |%5.10lld|\n", (long long)64);
	ft_printf("09) Mon PRINTF  : |%5.10lld|\n", (long long)64);
	printf("10) Vrai PRINTF : |%1.1lld|\n", (long long)16);
	ft_printf("10) Mon PRINTF  : |%1.1lld|\n", (long long)16);
	printf("11) Vrai PRINTF : |%+10lld|\n", (long long)50);
	ft_printf("11) Mon PRINTF  : |%+10lld|\n", (long long)50);
	printf("12) Vrai PRINTF : |%+2lld|\n", (long long)50);
	ft_printf("12) Mon PRINTF  : |%+2lld|\n", (long long)50);
	printf("13) Vrai PRINTF : |%+.10lld|\n", (long long)50);
	ft_printf("13) Mon PRINTF  : |%+.10lld|\n", (long long)50);
	printf("14) Vrai PRINTF : |%+.2lld|\n", (long long)50);
	ft_printf("14) Mon PRINTF  : |%+.2lld|\n", (long long)50);
	printf("15) Vrai PRINTF : |%          lld|\n", (long long)1);
	ft_printf("15) Mon PRINTF  : |%          lld|\n", (long long)1);
	printf("16) Vrai PRINTF : |% -lld|\n", (long long)1);
	ft_printf("16) Mon PRINTF  : |% -lld|\n", (long long)1);
	printf("17) Vrai PRINTF : |%-+lld|\n", (long long)32);
	ft_printf("17) Mon PRINTF  : |%-+lld|\n", (long long)32);
	printf("18) Vrai PRINTF : |%+-lld|\n", (long long)32);
	ft_printf("18) Mon PRINTF  : |%+-lld|\n", (long long)32);
	printf("19) Vrai PRINTF : |%-+10lld|\n", (long long)42);
	ft_printf("19) Mon PRINTF  : |%-+10lld|\n", (long long)42);
	printf("20) Vrai PRINTF : |%-+.10lld|\n", (long long)42);
	ft_printf("20) Mon PRINTF  : |%-+.10lld|\n", (long long)42);
	printf("21) Vrai PRINTF : |%lld|\n", (long long)-42);
	ft_printf("21) Mon PRINTF  : |%lld|\n", (long long)-42);
	printf("22) Vrai PRINTF : |%10lld|\n", (long long)-42);
	ft_printf("22) Mon PRINTF  : |%10lld|\n", (long long)-42);
	printf("23) Vrai PRINTF : |%.10lld|\n", (long long)-42);
	ft_printf("23) Mon PRINTF  : |%.10lld|\n", (long long)-42);
	printf("24) Vrai PRINTF : |%+lld|\n", (long long)-10);
	ft_printf("24) Mon PRINTF  : |%+lld|\n", (long long)-10);
	printf("25) Vrai PRINTF : |%10.5lld|\n", (long long)-16);
	ft_printf("25) Mon PRINTF  : |%10.5lld|\n", (long long)-16);
	printf("26) Vrai PRINTF : |%5.10lld|\n", (long long)-16);
	ft_printf("26) Mon PRINTF  : |%5.10lld|\n", (long long)-16);
	printf("27) Vrai PRINTF : |%1.1lld|\n", (long long)-20);
	ft_printf("27) Mon PRINTF  : |%1.1lld|\n", (long long)-20);
	printf("28) Vrai PRINTF : |%-10lld|\n", (long long)-50);
	ft_printf("29) Mon PRINTF  : |%-10lld|\n", (long long)-50);
	printf("30) Vrai PRINTF : |%++++++++++lld|\n", (long long)69);
	ft_printf("30) Mon PRINTF  : |%++++++++++lld|\n", (long long)69);
	printf("31) Vrai PRINTF : |%+10lld|\n", (long long)-64);
	ft_printf("31) Mon PRINTF  : |%+10lld|\n", (long long)-64);
	printf("32) Vrai PRINTF : |%+.10lld|\n", (long long)-64);
	ft_printf("32) Mon PRINTF  : |%+.10lld|\n", (long long)-64);
	printf("33) Vrai PRINTF : |%2lld|\n", (long long)-20);
	ft_printf("33) Mon PRINTF  : |%2lld|\n", (long long)-20);
	printf("34) Vrai PRINTF : |%.2lld|\n", (long long)-20);
	ft_printf("34) Mon PRINTF  : |%.2lld|\n", (long long)-20);
	printf("35) Vrai PRINTF : |%2lld|\n", (long long)-1);
	ft_printf("35) Mon PRINTF  : |%2lld|\n", (long long)-1);
	printf("36) Vrai PRINTF : |%.2lld|\n", (long long)-1);
	ft_printf("36) Mon PRINTF  : |%.2lld|\n", (long long)-1);
	printf("37) Vrai PRINTF : |%-10lld|\n", (long long)-80);
	ft_printf("37) Mon PRINTF  : |%-10lld|\n", (long long)-80);
	printf("38) Vrai PRINTF : |%-.10lld|\n", (long long)-80);
	ft_printf("38) Mon PRINTF  : |%-.10lld|\n", (long long)-80);
	printf("39) Vrai PRINTF : |%06lld|\n", (long long)35);
	ft_printf("39) Mon PRINTF  : |%06lld|\n", (long long)35);
	printf("40) Vrai PRINTF : |%06lld|\n", (long long)-35);
	ft_printf("40) Mon PRINTF  : |%06lld|\n", (long long)-35);
	printf("41) Vrai PRINTF : |%-+10lld|\n", (long long)-40);
	ft_printf("41) Mon PRINTF  : |%-+10lld|\n", (long long)-40);
	printf("42) Vrai PRINTF : |%+-10lld|\n", (long long)-40);
	ft_printf("42) Mon PRINTF  : |%+-10lld|\n", (long long)-40);
	printf("43) Vrai PRINTF : |%05.3lld|\n", (long long)5);
	ft_printf("43) Mon PRINTF  : |%05.3lld|\n", (long long)5);
	printf("44) Vrai PRINTF : |%03.5lld|\n", (long long)5);
	ft_printf("44) Mon PRINTF  : |%03.5lld|\n", (long long)5);
	printf("45) Vrai PRINTF : |%05.3lld|\n", (long long)-5);
	ft_printf("45) Mon PRINTF  : |%05.3lld|\n", (long long)-5);
	printf("46) Vrai PRINTF : |%03.5lld|\n", (long long)-5);
	ft_printf("46) Mon PRINTF  : |%03.5lld|\n", (long long)-5);
	printf("47) Vrai PRINTF : |%lld| |%lld|\n", (long long)LLONG_MAX, (long long)LLONG_MIN);
	ft_printf("47) Mon PRINTF  : |%lld| |%lld|\n", (long long)LLONG_MAX, (long long)LLONG_MIN);
	printf("48) Vrai PRINTF : |%lld| |%lld|\n", (long long)LLONG_MAX + 1, (long long)LLONG_MIN - 1);
	ft_printf("48) Mon PRINTF  : |%lld| |%lld|\n", (long long)LLONG_MAX + 1, (long long)LLONG_MIN - 1);
	printf("49) Vrai PRINTF : |%.lld|\n", (long long)0);
	ft_printf("49) Mon PRINTF  : |%.lld|\n", (long long)0);
	printf("50) Vrai PRINTF : |%.lld|\n", (long long)100);
	ft_printf("50) Mon PRINTF  : |%.lld|\n", (long long)100);
	ft_printf("--------------------%%f--------------------\n");
	printf("01) Vrai PRINTF	: |%.10Lf|\n", (long double)243.5);
	ft_printf("01) Mon PRINTF	: |%.10Lf|\n", (long double)243.5);
	printf("02) Vrai PRINTF	: |%f|\n", 3.55);
	ft_printf("02) Mon PRINTF	: |%f|\n", 3.55);
	printf("03) Vrai PRINTF	: |%5f|\n", 9877893.5123109);
	ft_printf("03) Mon PRINTF	: |%5f|\n", 9877893.5123109);
	printf("04) Vrai PRINTF	: |%5Lf|\n", (long double)9877893.5123109);
	ft_printf("04) Mon PRINTF	: |%5Lf|\n", (long double)9877893.5123109);
	printf("05) Vrai PRINTF	: |%10.1f|\n", 243.59);
	ft_printf("05) Mon PRINTF	: |%10.1f|\n", 243.59);
	printf("06) Vrai PRINTF	: |%.4Lf|\n", (long double)243.5);
	ft_printf("06) Mon PRINTF	: |%.4Lf|\n", (long double)243.5);
	printf("07) Vrai PRINTF	: |%lf|\n", 243.5);
	ft_printf("07) Mon PRINTF	: |%lf|\n", 243.5);
	printf("08) Vrai PRINTF	: |%.5f|\n", 3.5);
	ft_printf("08) Mon PRINTF	: |%.5f|\n", 3.5);
	printf("09) Vrai PRINTF	: |%Lf|\n", (long double)243.5);
	ft_printf("09) Mon PRINTF	: |%Lf|\n", (long double)243.5);
	printf("10) Vrai PRINTF	: |%f|\n", -10.011012365432);
	ft_printf("10) Mon PRINTF	: |%f|\n", -10.011012365432);
	printf("11) Vrai PRINTF	: |%4Lf|\n", (long double)243.59);
	ft_printf("11) Mon PRINTF	: |%4Lf|\n", (long double)243.59);
	printf("12) Vrai PRINTF	: |%1f|\n", 243.59);
	ft_printf("12) Mon PRINTF	: |%1f|\n", 243.59);
	ft_printf("--------------------%%o--------------------\n");		//perfect
	printf("01) Vrai PRINTF : |%o|\n", 34);
	ft_printf("01) Mon PRINTF  : |%o|\n", 34);
	printf("02) Vrai PRINTF : |%o|\n", -34);
	ft_printf("02) Mon PRINTF  : |%o|\n", -34);
	printf("03) Vrai PRINTF : |%-o|\n", 50);
	ft_printf("03) Mon PRINTF  : |%-o|\n", 50);
	printf("04) Vrai PRINTF : |%10o|\n", 90);
	ft_printf("04) Mon PRINTF  : |%10o|\n", 90);
	printf("05) Vrai PRINTF : |%.10o|\n", 90);
	ft_printf("05) Mon PRINTF  : |%.10o|\n", 90);
	printf("06) Vrai PRINTF : |%15o|\n", -100);
	ft_printf("06) Mon PRINTF  : |%15o|\n", -100);
	printf("07) Vrai PRINTF : |%.15o|\n", -100);
	ft_printf("07) Mon PRINTF  : |%.15o|\n", -100);
	printf("08) Vrai PRINTF : |%10.5o|\n", 52);
	ft_printf("08) Mon PRINTF  : |%10.5o|\n", 52);
	printf("09) Vrai PRINTF : |%5.10o|\n", 52);
	ft_printf("09) Mon PRINTF  : |%5.10o|\n", 52);
	printf("10) Vrai PRINTF : |%20.15o|\n", -100000);
	ft_printf("10) Mon PRINTF  : |%20.15o|\n", -100000);
	printf("11) Vrai PRINTF : |%15.20o|\n", -100000);
	ft_printf("11) Mon PRINTF  : |%15.20o|\n", -100000);
	printf("12) Vrai PRINTF : |%-10o|\n", 144);
	ft_printf("12) Mon PRINTF  : |%-10o|\n", 144);
	printf("13) Vrai PRINTF : |%-.10o|\n", 144);
	ft_printf("13) Mon PRINTF  : |%-.10o|\n", 144);
	printf("14) Vrai PRINTF : |%-20o|\n", -20000000);
	ft_printf("14) Mon PRINTF  : |%-20o|\n", -20000000);
	printf("15) Vrai PRINTF : |%08o|\n", 64);
	ft_printf("15) Mon PRINTF  : |%08o|\n", 64);
	printf("16) Vrai PRINTF : |%03.4o|\n", 10);
	ft_printf("16) Mon PRINTF  : |%03.4o|\n", 10);
	printf("17) Vrai PRINTF : |%#o|\n", 34);
	ft_printf("17) Mon PRINTF  : |%#o|\n", 34);
	printf("18) Vrai PRINTF : |%#.5o|\n", 34);
	ft_printf("18) Mon PRINTF  : |%#.5o|\n", 34);
	printf("19) Vrai PRINTF : |%#5o|\n", 86);
	ft_printf("19) Mon PRINTF  : |%#5o|\n", 86);
	printf("20) Vrai PRINTF : |%#10.5o|\n", 70);
	ft_printf("20) Mon PRINTF  : |%#10.5o|\n", 70);
	printf("21) Vrai PRINTF : |%#o|\n", 0);
	ft_printf("21) Mon PRINTF  : |%#o|\n", 0);
	printf("22) Vrai PRINTF : |%#.o|\n", 0);
	ft_printf("22) Mon PRINTF  : |%#.o|\n", 0);
	printf("23) Vrai PRINTF : |%.o|\n", 0);
	ft_printf("23) Mon PRINTF  : |%.o|\n", 0);
	printf("24) Vrai PRINTF : |%.o|\n", 88);
	ft_printf("24) Mon PRINTF  : |%.o|\n", 88);
	printf("25) Vrai PRINTF : |%#.o|\n", 88);
	ft_printf("25) Mon PRINTF  : |%#.o|\n", 88);
	printf("26) Vrai PRINTF : |%o|\n", UINT_MAX);
	ft_printf("26) Mon PRINTF  : |%o|\n", UINT_MAX);
	printf("27) Vrai PRINTF : |%#o|\n", UINT_MAX);
	ft_printf("27) Mon PRINTF  : |%#o|\n", UINT_MAX);
	printf("28) Vrai PRINTF : |%#o| |%#o|\n", (unsigned int)-1, UINT_MAX + 1);
	ft_printf("28) Mon PRINTF  : |%#o| |%#o|\n", (unsigned int)-1, UINT_MAX + 1);
	printf("29) Vrai PRINTF : |%o| |%o|\n", (unsigned int)-1, UINT_MAX + 1);
	ft_printf("29) Mon PRINTF  : |%o| |%o|\n", (unsigned int)-1, UINT_MAX + 1);
	ft_printf("--------------------%%ho--------------------\n");	//28/29
	printf("01) Vrai PRINTF : |%ho|\n", (unsigned short)34);
	ft_printf("01) Mon PRINTF  : |%ho|\n", (unsigned short)34);
	printf("02) Vrai PRINTF : |%ho|\n", (unsigned short)-34);
	ft_printf("02) Mon PRINTF  : |%ho|\n", (unsigned short)-34);
	printf("03) Vrai PRINTF : |%-ho|\n", (unsigned short)50);
	ft_printf("03) Mon PRINTF  : |%-ho|\n", (unsigned short)50);
	printf("04) Vrai PRINTF : |%10ho|\n", (unsigned short)90);
	ft_printf("04) Mon PRINTF  : |%10ho|\n", (unsigned short)90);
	printf("05) Vrai PRINTF : |%.10ho|\n", (unsigned short)90);
	ft_printf("05) Mon PRINTF  : |%.10ho|\n", (unsigned short)90);
	printf("06) Vrai PRINTF : |%15ho|\n", (unsigned short)-100);
	ft_printf("06) Mon PRINTF  : |%15ho|\n", (unsigned short)-100);
	printf("07) Vrai PRINTF : |%.15ho|\n", (unsigned short)-100);
	ft_printf("07) Mon PRINTF  : |%.15ho|\n", (unsigned short)-100);
	printf("08) Vrai PRINTF : |%10.5ho|\n", (unsigned short)52);
	ft_printf("08) Mon PRINTF  : |%10.5ho|\n", (unsigned short)52);
	printf("09) Vrai PRINTF : |%5.10ho|\n", (unsigned short)52);
	ft_printf("09) Mon PRINTF  : |%5.10ho|\n", (unsigned short)52);
	printf("10) Vrai PRINTF : |%20.15ho|\n", (unsigned short)-10000);
	ft_printf("10) Mon PRINTF  : |%20.15ho|\n", (unsigned short)-10000);
	printf("11) Vrai PRINTF : |%15.20ho|\n", (unsigned short)-10000);
	ft_printf("11) Mon PRINTF  : |%15.20ho|\n", (unsigned short)-10000);
	printf("12) Vrai PRINTF : |%-10ho|\n", (unsigned short)144);
	ft_printf("12) Mon PRINTF  : |%-10ho|\n", (unsigned short)144);
	printf("13) Vrai PRINTF : |%-.10ho|\n", (unsigned short)144);
	ft_printf("13) Mon PRINTF  : |%-.10ho|\n", (unsigned short)144);
	printf("14) Vrai PRINTF : |%-20ho|\n", (unsigned short)-20000);
	ft_printf("14) Mon PRINTF  : |%-20ho|\n", (unsigned short)-20000);
	printf("15) Vrai PRINTF : |%08ho|\n", (unsigned short)64);
	ft_printf("15) Mon PRINTF  : |%08ho|\n", (unsigned short)64);
	printf("16) Vrai PRINTF : |%03.4ho|\n", (unsigned short)10);
	ft_printf("16) Mon PRINTF  : |%03.4ho|\n", (unsigned short)10);
	printf("17) Vrai PRINTF : |%#ho|\n", (unsigned short)34);
	ft_printf("17) Mon PRINTF  : |%#ho|\n", (unsigned short)34);
	printf("18) Vrai PRINTF : |%#.5ho|\n", (unsigned short)34);
	ft_printf("18) Mon PRINTF  : |%#.5ho|\n", (unsigned short)34);
	printf("19) Vrai PRINTF : |%#5ho|\n", (unsigned short)86);
	ft_printf("19) Mon PRINTF  : |%#5ho|\n", (unsigned short)86);
	printf("20) Vrai PRINTF : |%#10.5ho|\n", (unsigned short)70);
	ft_printf("20) Mon PRINTF  : |%#10.5ho|\n", (unsigned short)70);
	printf("21) Vrai PRINTF : |%#ho|\n", (unsigned short)0);
	ft_printf("21) Mon PRINTF  : |%#ho|\n", (unsigned short)0);
	printf("22) Vrai PRINTF : |%#.ho|\n", (unsigned short)0);
	ft_printf("22) Mon PRINTF  : |%#.ho|\n", (unsigned short)0);
	printf("23) Vrai PRINTF : |%.ho|\n", (unsigned short)0);
	ft_printf("23) Mon PRINTF  : |%.ho|\n", (unsigned short)0);
	printf("24) Vrai PRINTF : |%.ho|\n", (unsigned short)88);
	ft_printf("24) Mon PRINTF  : |%.ho|\n", (unsigned short)88);
	printf("25) Vrai PRINTF : |%#.ho|\n", (unsigned short)88);
	ft_printf("25) Mon PRINTF  : |%#.ho|\n", (unsigned short)88);
	printf("26) Vrai PRINTF : |%ho|\n", (unsigned short)USHRT_MAX);
	ft_printf("26) Mon PRINTF  : |%ho|\n", (unsigned short)USHRT_MAX);
	printf("27) Vrai PRINTF : |%#ho|\n", (unsigned short)USHRT_MAX);
	ft_printf("27) Mon PRINTF  : |%#ho|\n", (unsigned short)USHRT_MAX);
	printf("28) Vrai PRINTF : |%#ho| |%#ho|\n", (unsigned short)-1, (unsigned short)65536);
	ft_printf("28) Mon PRINTF  : |%#ho| |%#ho|\n", (unsigned short)-1, (unsigned short)65536);
	printf("29) Vrai PRINTF : |%ho| |%ho|\n", (unsigned short)-1, (unsigned short)65536);
	ft_printf("29) Mon PRINTF  : |%ho| |%ho|\n", (unsigned short)-1, (unsigned short)65536);
	ft_printf("--------------------%%hho--------------------\n");
	printf("01) Vrai PRINTF : |%hho|\n", (unsigned char)34);
	ft_printf("01) Mon PRINTF  : |%hho|\n", (unsigned char)34);
	printf("02) Vrai PRINTF : |%hho|\n", (unsigned char)-34);
	ft_printf("02) Mon PRINTF  : |%hho|\n", (unsigned char)-34);
	printf("03) Vrai PRINTF : |%-hho|\n", (unsigned char)50);
	ft_printf("03) Mon PRINTF  : |%-hho|\n", (unsigned char)50);
	printf("04) Vrai PRINTF : |%10hho|\n", (unsigned char)90);
	ft_printf("04) Mon PRINTF  : |%10hho|\n", (unsigned char)90);
	printf("05) Vrai PRINTF : |%.10hho|\n", (unsigned char)90);
	ft_printf("05) Mon PRINTF  : |%.10hho|\n", (unsigned char)90);
	printf("06) Vrai PRINTF : |%15hho|\n", (unsigned char)-100);
	ft_printf("06) Mon PRINTF  : |%15hho|\n", (unsigned char)-100);
	printf("07) Vrai PRINTF : |%.15hho|\n", (unsigned char)-100);
	ft_printf("07) Mon PRINTF  : |%.15hho|\n", (unsigned char)-100);
	printf("08) Vrai PRINTF : |%10.5hho|\n", (unsigned char)52);
	ft_printf("08) Mon PRINTF  : |%10.5hho|\n", (unsigned char)52);
	printf("09) Vrai PRINTF : |%5.10hho|\n", (unsigned char)52);
	ft_printf("09) Mon PRINTF  : |%5.10hho|\n", (unsigned char)52);
	printf("10) Vrai PRINTF : |%20.15hho|\n", (unsigned char)-10000);
	ft_printf("10) Mon PRINTF  : |%20.15hho|\n", (unsigned char)-10000);
	printf("11) Vrai PRINTF : |%15.20hho|\n", (unsigned char)-10000);
	ft_printf("11) Mon PRINTF  : |%15.20hho|\n", (unsigned char)-10000);
	printf("12) Vrai PRINTF : |%-10hho|\n", (unsigned char)144);
	ft_printf("12) Mon PRINTF  : |%-10hho|\n", (unsigned char)144);
	printf("13) Vrai PRINTF : |%-.10hho|\n", (unsigned char)144);
	ft_printf("13) Mon PRINTF  : |%-.10hho|\n", (unsigned char)144);
	printf("14) Vrai PRINTF : |%-20hho|\n", (unsigned char)-20000);
	ft_printf("14) Mon PRINTF  : |%-20hho|\n", (unsigned char)-20000);
	printf("15) Vrai PRINTF : |%08hho|\n", (unsigned char)64);
	ft_printf("15) Mon PRINTF  : |%08hho|\n", (unsigned char)64);
	printf("16) Vrai PRINTF : |%03.4hho|\n", (unsigned char)10);
	ft_printf("16) Mon PRINTF  : |%03.4hho|\n", (unsigned char)10);
	printf("17) Vrai PRINTF : |%#hho|\n", (unsigned char)34);
	ft_printf("17) Mon PRINTF  : |%#hho|\n", (unsigned char)34);
	printf("18) Vrai PRINTF : |%#.5hho|\n", (unsigned char)34);
	ft_printf("18) Mon PRINTF  : |%#.5hho|\n", (unsigned char)34);
	printf("19) Vrai PRINTF : |%#5hho|\n", (unsigned char)86);
	ft_printf("19) Mon PRINTF  : |%#5hho|\n", (unsigned char)86);
	printf("20) Vrai PRINTF : |%#10.5hho|\n", (unsigned char)70);
	ft_printf("20) Mon PRINTF  : |%#10.5hho|\n", (unsigned char)70);
	printf("21) Vrai PRINTF : |%#hho|\n", (unsigned char)0);
	ft_printf("21) Mon PRINTF  : |%#hho|\n", (unsigned char)0);
	printf("22) Vrai PRINTF : |%#.hho|\n", (unsigned char)0);
	ft_printf("22) Mon PRINTF  : |%#.hho|\n", (unsigned char)0);
	printf("23) Vrai PRINTF : |%.hho|\n", (unsigned char)0);
	ft_printf("23) Mon PRINTF  : |%.hho|\n", (unsigned char)0);
	printf("24) Vrai PRINTF : |%.hho|\n", (unsigned char)88);
	ft_printf("24) Mon PRINTF  : |%.hho|\n", (unsigned char)88);
	printf("25) Vrai PRINTF : |%#.hho|\n", (unsigned char)88);
	ft_printf("25) Mon PRINTF  : |%#.hho|\n", (unsigned char)88);
	printf("26) Vrai PRINTF : |%hho|\n", (unsigned char)255);
	ft_printf("26) Mon PRINTF  : |%hho|\n", (unsigned char)255);
	printf("27) Vrai PRINTF : |%#hho|\n", (unsigned char)255);
	ft_printf("27) Mon PRINTF  : |%#hho|\n", (unsigned char)255);
	printf("28) Vrai PRINTF : |%#hho| |%#hho|\n", (unsigned char)-1, (unsigned char)256);
	ft_printf("28) Mon PRINTF  : |%#hho| |%#hho|\n", (unsigned char)-1, (unsigned char) 256);
	ft_printf("--------------------%%lo--------------------\n");
	printf("01) Vrai PRINTF : |%lo|\n",(unsigned long)34);
	ft_printf("01) Mon PRINTF  : |%lo|\n", (unsigned long)34);
	printf("02) Vrai PRINTF : |%lo|\n", (unsigned long)-34);
	ft_printf("02) Mon PRINTF  : |%lo|\n", (unsigned long)-34);
	printf("03) Vrai PRINTF : |%-lo|\n", (unsigned long)50);
	ft_printf("03) Mon PRINTF  : |%-lo|\n", (unsigned long)50);
	printf("04) Vrai PRINTF : |%10lo|\n", (unsigned long)90);
	ft_printf("04) Mon PRINTF  : |%10lo|\n", (unsigned long)90);
	printf("05) Vrai PRINTF : |%.10lo|\n", (unsigned long)90);
	ft_printf("05) Mon PRINTF  : |%.10lo|\n", (unsigned long)90);
	printf("06) Vrai PRINTF : |%15lo|\n", (unsigned long)-100);
	ft_printf("06) Mon PRINTF  : |%15lo|\n", (unsigned long)-100);
	printf("07) Vrai PRINTF : |%.15lo|\n", (unsigned long)-100);
	ft_printf("07) Mon PRINTF  : |%.15lo|\n", (unsigned long)-100);
	printf("08) Vrai PRINTF : |%10.5lo|\n", (unsigned long)52);
	ft_printf("08) Mon PRINTF  : |%10.5lo|\n", (unsigned long)52);
	printf("09) Vrai PRINTF : |%5.10lo|\n", (unsigned long)52);
	ft_printf("09) Mon PRINTF  : |%5.10lo|\n", (unsigned long)52);
	printf("10) Vrai PRINTF : |%20.15lo|\n", (unsigned long)-100000);
	ft_printf("10) Mon PRINTF  : |%20.15lo|\n", (unsigned long)-100000);
	printf("11) Vrai PRINTF : |%15.20lo|\n", (unsigned long)-100000);
	ft_printf("11) Mon PRINTF  : |%15.20lo|\n", (unsigned long)-100000);
	printf("12) Vrai PRINTF : |%-10lo|\n", (unsigned long)144);
	ft_printf("12) Mon PRINTF  : |%-10lo|\n", (unsigned long)144);
	printf("13) Vrai PRINTF : |%-.10lo|\n", (unsigned long)144);
	ft_printf("13) Mon PRINTF  : |%-.10lo|\n", (unsigned long)144);
	printf("14) Vrai PRINTF : |%-20lo|\n", (unsigned long)-20000000);
	ft_printf("14) Mon PRINTF  : |%-20lo|\n", (unsigned long)-20000000);
	printf("15) Vrai PRINTF : |%08lo|\n", (unsigned long)64);
	ft_printf("15) Mon PRINTF  : |%08lo|\n", (unsigned long)64);
	printf("16) Vrai PRINTF : |%03.4lo|\n", (unsigned long)10);
	ft_printf("16) Mon PRINTF  : |%03.4lo|\n", (unsigned long)10);
	printf("17) Vrai PRINTF : |%#lo|\n", (unsigned long)34);
	ft_printf("17) Mon PRINTF  : |%#lo|\n", (unsigned long)34);
	printf("18) Vrai PRINTF : |%#.5lo|\n", (unsigned long)34);
	ft_printf("18) Mon PRINTF  : |%#.5lo|\n", (unsigned long)34);
	printf("19) Vrai PRINTF : |%#5lo|\n", (unsigned long)86);
	ft_printf("19) Mon PRINTF  : |%#5lo|\n", (unsigned long)86);
	printf("20) Vrai PRINTF : |%#10.5lo|\n", (unsigned long)70);
	ft_printf("20) Mon PRINTF  : |%#10.5lo|\n", (unsigned long)70);
	printf("21) Vrai PRINTF : |%#lo|\n", (unsigned long)0);
	ft_printf("21) Mon PRINTF  : |%#lo|\n", (unsigned long)0);
	printf("22) Vrai PRINTF : |%#.lo|\n", (unsigned long)0);
	ft_printf("22) Mon PRINTF  : |%#.lo|\n", (unsigned long)0);
	printf("23) Vrai PRINTF : |%.lo|\n", (unsigned long)0);
	ft_printf("23) Mon PRINTF  : |%.lo|\n", (unsigned long)0);
	printf("24) Vrai PRINTF : |%.lo|\n", (unsigned long)88);
	ft_printf("24) Mon PRINTF  : |%.lo|\n", (unsigned long)88);
	printf("25) Vrai PRINTF : |%#.lo|\n", (unsigned long)88);
	ft_printf("25) Mon PRINTF  : |%#.lo|\n", (unsigned long)88);
	printf("26) Vrai PRINTF : |%lo|\n", (unsigned long)UINT_MAX);
	ft_printf("26) Mon PRINTF  : |%lo|\n", (unsigned long)UINT_MAX);
	printf("27) Vrai PRINTF : |%#lo|\n", (unsigned long)-1, ULONG_MAX);
	ft_printf("27) Mon PRINTF  : |%#lo|\n", (unsigned long)-1, ULONG_MAX);
	printf("28) Vrai PRINTF : |%#lo| |%#lo|\n", (unsigned long)-1, ULONG_MAX + 1);
	ft_printf("28) Mon PRINTF  : |%#lo| |%#lo|\n", (unsigned long)-1, ULONG_MAX + 1);
	ft_printf("--------------------%%llo--------------------\n");
	printf("01) Vrai PRINTF : |%llo|\n",(unsigned long long)34);
	ft_printf("01) Mon PRINTF  : |%llo|\n", (unsigned long long)34);
	printf("02) Vrai PRINTF : |%llo|\n", (unsigned long long)-34);
	ft_printf("02) Mon PRINTF  : |%llo|\n", (unsigned long long)-34);
	printf("03) Vrai PRINTF : |%-llo|\n", (unsigned long long)50);
	ft_printf("03) Mon PRINTF  : |%-llo|\n", (unsigned long long)50);
	printf("04) Vrai PRINTF : |%10llo|\n", (unsigned long long)90);
	ft_printf("04) Mon PRINTF  : |%10llo|\n", (unsigned long long)90);
	printf("05) Vrai PRINTF : |%.10llo|\n", (unsigned long long)90);
	ft_printf("05) Mon PRINTF  : |%.10llo|\n", (unsigned long long)90);
	printf("06) Vrai PRINTF : |%15llo|\n", (unsigned long long)-100);
	ft_printf("06) Mon PRINTF  : |%15llo|\n", (unsigned long long)-100);
	printf("07) Vrai PRINTF : |%.15llo|\n", (unsigned long long)-100);
	ft_printf("07) Mon PRINTF  : |%.15llo|\n", (unsigned long long)-100);
	printf("08) Vrai PRINTF : |%10.5llo|\n", (unsigned long long)52);
	ft_printf("08) Mon PRINTF  : |%10.5llo|\n", (unsigned long long)52);
	printf("09) Vrai PRINTF : |%5.10llo|\n", (unsigned long long)52);
	ft_printf("09) Mon PRINTF  : |%5.10llo|\n", (unsigned long long)52);
	printf("10) Vrai PRINTF : |%20.15llo|\n", (unsigned long long)-100000);
	ft_printf("10) Mon PRINTF  : |%20.15llo|\n", (unsigned long long)-100000);
	printf("11) Vrai PRINTF : |%15.20llo|\n", (unsigned long long)-100000);
	ft_printf("11) Mon PRINTF  : |%15.20llo|\n", (unsigned long long)-100000);
	printf("12) Vrai PRINTF : |%-10llo|\n", (unsigned long long)144);
	ft_printf("12) Mon PRINTF  : |%-10llo|\n", (unsigned long long)144);
	printf("13) Vrai PRINTF : |%-.10llo|\n", (unsigned long long)144);
	ft_printf("13) Mon PRINTF  : |%-.10llo|\n", (unsigned long long)144);
	printf("14) Vrai PRINTF : |%-20llo|\n", (unsigned long long)-20000000);
	ft_printf("14) Mon PRINTF  : |%-20llo|\n", (unsigned long long)-20000000);
	printf("15) Vrai PRINTF : |%08llo|\n", (unsigned long long)64);
	ft_printf("15) Mon PRINTF  : |%08llo|\n", (unsigned long long)64);
	printf("16) Vrai PRINTF : |%03.4llo|\n", (unsigned long long)10);
	ft_printf("16) Mon PRINTF  : |%03.4llo|\n", (unsigned long long)10);
	printf("17) Vrai PRINTF : |%#llo|\n", (unsigned long long)34);
	ft_printf("17) Mon PRINTF  : |%#llo|\n", (unsigned long long)34);
	printf("18) Vrai PRINTF : |%#.5llo|\n", (unsigned long long)34);
	ft_printf("18) Mon PRINTF  : |%#.5llo|\n", (unsigned long long)34);
	printf("19) Vrai PRINTF : |%#5llo|\n", (unsigned long long)86);
	ft_printf("19) Mon PRINTF  : |%#5llo|\n", (unsigned long long)86);
	printf("20) Vrai PRINTF : |%#10.5llo|\n", (unsigned long long)70);
	ft_printf("20) Mon PRINTF  : |%#10.5llo|\n", (unsigned long long)70);
	printf("21) Vrai PRINTF : |%#llo|\n", (unsigned long long)0);
	ft_printf("21) Mon PRINTF  : |%#llo|\n", (unsigned long long)0);
	printf("22) Vrai PRINTF : |%#.llo|\n", (unsigned long long)0);
	ft_printf("22) Mon PRINTF  : |%#.llo|\n", (unsigned long long)0);
	printf("23) Vrai PRINTF : |%.llo|\n", (unsigned long long)0);
	ft_printf("23) Mon PRINTF  : |%.llo|\n", (unsigned long long)0);
	printf("24) Vrai PRINTF : |%.llo|\n", (unsigned long long)88);
	ft_printf("24) Mon PRINTF  : |%.llo|\n", (unsigned long long)88);
	printf("25) Vrai PRINTF : |%#.llo|\n", (unsigned long long)88);
	ft_printf("25) Mon PRINTF  : |%#.llo|\n", (unsigned long long)88);
	printf("26) Vrai PRINTF : |%llo|\n", (unsigned long long)ULLONG_MAX);
	ft_printf("26) Mon PRINTF  : |%llo|\n", (unsigned long long)ULLONG_MAX);
	printf("27) Vrai PRINTF : |%#llo|\n", (unsigned long long)-1, ULLONG_MAX);
	ft_printf("27) Mon PRINTF  : |%#llo|\n", (unsigned long long)-1, ULLONG_MAX);
	printf("28) Vrai PRINTF : |%#llo| |%#llo|\n", (unsigned long long)-1, ULLONG_MAX + 1);
	ft_printf("28) Mon PRINTF  : |%#llo| |%#llo|\n", (unsigned long long)-1, ULLONG_MAX + 1);
	ft_printf("--------------------%%x--------------------\n");		//29/29
	printf("01) Vrai PRINTF : |%x|\n", 34);
	ft_printf("01) Mon PRINTF  : |%x|\n", 34);
	printf("02) Vrai PRINTF : |%x|\n", -34);
	ft_printf("02) Mon PRINTF  : |%x|\n", -34);
	printf("03) Vrai PRINTF : |%-x|\n", 50);
	ft_printf("03) Mon PRINTF  : |%-x|\n", 50);
	printf("04) Vrai PRINTF : |%10x|\n", 90);
	ft_printf("04) Mon PRINTF  : |%10x|\n", 90);
	printf("05) Vrai PRINTF : |%.10x|\n", 90);
	ft_printf("05) Mon PRINTF  : |%.10x|\n", 90);
	printf("06) Vrai PRINTF : |%15x|\n", -100);
	ft_printf("06) Mon PRINTF  : |%15x|\n", -100);
	printf("07) Vrai PRINTF : |%.15x|\n", -100);
	ft_printf("07) Mon PRINTF  : |%.15x|\n", -100);
	printf("08) Vrai PRINTF : |%10.5x|\n", 52);
	ft_printf("08) Mon PRINTF  : |%10.5x|\n", 52);
	printf("09) Vrai PRINTF : |%5.10x|\n", 52);
	ft_printf("09) Mon PRINTF  : |%5.10x|\n", 52);
	printf("10) Vrai PRINTF : |%20.15x|\n", -100000);
	ft_printf("10) Mon PRINTF  : |%20.15x|\n", -100000);
	printf("11) Vrai PRINTF : |%15.20x|\n", -100000);
	ft_printf("11) Mon PRINTF  : |%15.20x|\n", -100000);
	printf("12) Vrai PRINTF : |%-10x|\n", 144);
	ft_printf("12) Mon PRINTF  : |%-10x|\n", 144);
	printf("13) Vrai PRINTF : |%-.10x|\n", 144);
	ft_printf("13) Mon PRINTF  : |%-.10x|\n", 144);
	printf("14) Vrai PRINTF : |%-20x|\n", -20000000);
	ft_printf("14) Mon PRINTF  : |%-20x|\n", -20000000);
	printf("15) Vrai PRINTF : |%08x|\n", 64);
	ft_printf("15) Mon PRINTF  : |%08x|\n", 64);
	printf("16) Vrai PRINTF : |%03.4x|\n", 10);
	ft_printf("16) Mon PRINTF  : |%03.4x|\n", 10);
	printf("17) Vrai PRINTF : |%#x|\n", 34);
	ft_printf("17) Mon PRINTF  : |%#x|\n", 34);
	printf("18) Vrai PRINTF : |%#.5x|\n", 34);
	ft_printf("18) Mon PRINTF  : |%#.5x|\n", 34);
	printf("19) Vrai PRINTF : |%#5x|\n", 86);
	ft_printf("19) Mon PRINTF  : |%#5x|\n", 86);
	printf("20) Vrai PRINTF : |%#10.5x|\n", 70);
	ft_printf("20) Mon PRINTF  : |%#10.5x|\n", 70);
	printf("21) Vrai PRINTF : |%#x|\n", 0);
	ft_printf("21) Mon PRINTF  : |%#x|\n", 0);
	printf("22) Vrai PRINTF : |%#.x|\n", 0);
	ft_printf("22) Mon PRINTF  : |%#.x|\n", 0);
	printf("23) Vrai PRINTF : |%.x|\n", 0);
	ft_printf("23) Mon PRINTF  : |%.x|\n", 0);
	printf("24) Vrai PRINTF : |%.x|\n", 88);
	ft_printf("24) Mon PRINTF  : |%.x|\n", 88);
	printf("25) Vrai PRINTF : |%#.x|\n", 88);
	ft_printf("25) Mon PRINTF  : |%#.x|\n", 88);
	printf("26) Vrai PRINTF : |%x|\n", UINT_MAX);
	ft_printf("26) Mon PRINT   : |%x|\n", UINT_MAX);
	printf("27) Vrai PRINTF : |%#x|\n", UINT_MAX);
	ft_printf("27) Mon PRINTF  : |%#x|\n", UINT_MAX);
	printf("28) Vrai PRINTF : |%#x| |%#x|\n", (unsigned int)-1, UINT_MAX + 1);
	ft_printf("28) Mon PRINTF  : |%#x| |%#x|\n", (unsigned int)-1, UINT_MAX + 1);
	printf("29) Vrai PRINTF : |%x| |%x|\n", (unsigned int)-1, UINT_MAX + 1);
	ft_printf("29) Mon PRINTF  : |%x| |%x|\n", (unsigned int)-1, UINT_MAX + 1);
	ft_printf("--------------------%%hx--------------------\n");
	printf("01) Vrai PRINTF : |%hx|\n", (unsigned short)34);
	ft_printf("01) Mon PRINTF  : |%hx|\n", (unsigned short)34);
	printf("02) Vrai PRINTF : |%hx|\n", (unsigned short)-34);
	ft_printf("02) Mon PRINTF  : |%hx|\n", (unsigned short)-34);
	printf("03) Vrai PRINTF : |%-hx|\n", (unsigned short)50);
	ft_printf("03) Mon PRINTF  : |%-hx|\n", (unsigned short)50);
	printf("04) Vrai PRINTF : |%10hx|\n", (unsigned short)90);
	ft_printf("04) Mon PRINTF  : |%10hx|\n", (unsigned short)90);
	printf("05) Vrai PRINTF : |%.10hx|\n", (unsigned short)90);
	ft_printf("05) Mon PRINTF  : |%.10hx|\n", (unsigned short)90);
	printf("06) Vrai PRINTF : |%15hx|\n", (unsigned short)-100);
	ft_printf("06) Mon PRINTF  : |%15hx|\n", (unsigned short)-100);
	printf("07) Vrai PRINTF : |%.15hx|\n", (unsigned short)-100);
	ft_printf("07) Mon PRINTF  : |%.15hx|\n", (unsigned short)-100);
	printf("08) Vrai PRINTF : |%10.5hx|\n", (unsigned short)52);
	ft_printf("08) Mon PRINTF  : |%10.5hx|\n", (unsigned short)52);
	printf("09) Vrai PRINTF : |%5.10hx|\n", (unsigned short)52);
	ft_printf("09) Mon PRINTF  : |%5.10hx|\n", (unsigned short)52);
	printf("10) Vrai PRINTF : |%20.15hx|\n", (unsigned short)-10000);
	ft_printf("10) Mon PRINTF  : |%20.15hx|\n", (unsigned short)-10000);
	printf("11) Vrai PRINTF : |%15.20hx|\n", (unsigned short)-10000);
	ft_printf("11) Mon PRINTF  : |%15.20hx|\n", (unsigned short)-10000);
	printf("12) Vrai PRINTF : |%-10hx|\n", (unsigned short)144);
	ft_printf("12) Mon PRINTF  : |%-10hx|\n", (unsigned short)144);
	printf("13) Vrai PRINTF : |%-.10hx|\n", (unsigned short)144);
	ft_printf("13) Mon PRINTF  : |%-.10hx|\n", (unsigned short)144);
	printf("14) Vrai PRINTF : |%-20hx|\n", (unsigned short)-20000);
	ft_printf("14) Mon PRINTF  : |%-20hx|\n", (unsigned short)-20000);
	printf("15) Vrai PRINTF : |%08hx|\n", (unsigned short)64);
	ft_printf("15) Mon PRINTF  : |%08hx|\n", (unsigned short)64);
	printf("16) Vrai PRINTF : |%03.4hx|\n", (unsigned short)10);
	ft_printf("16) Mon PRINTF  : |%03.4hx|\n", (unsigned short)10);
	printf("17) Vrai PRINTF : |%#hx|\n", (unsigned short)34);
	ft_printf("17) Mon PRINTF  : |%#hx|\n", (unsigned short)34);
	printf("18) Vrai PRINTF : |%#.5hx|\n", (unsigned short)34);
	ft_printf("18) Mon PRINTF  : |%#.5hx|\n", (unsigned short)34);
	printf("19) Vrai PRINTF : |%#5hx|\n", (unsigned short)86);
	ft_printf("19) Mon PRINTF  : |%#5hx|\n", (unsigned short)86);
	printf("20) Vrai PRINTF : |%#10.5hx|\n", (unsigned short)70);
	ft_printf("20) Mon PRINTF  : |%#10.5hx|\n", (unsigned short)70);
	printf("21) Vrai PRINTF : |%#hx|\n", (unsigned short)0);
	ft_printf("21) Mon PRINTF  : |%#hx|\n", (unsigned short)0);
	printf("22) Vrai PRINTF : |%#.hx|\n", (unsigned short)0);
	ft_printf("22) Mon PRINTF  : |%#.hx|\n", (unsigned short)0);
	printf("23) Vrai PRINTF : |%.hx|\n", (unsigned short)0);
	ft_printf("23) Mon PRINTF  : |%.hx|\n", (unsigned short)0);
	printf("24) Vrai PRINTF : |%.hx|\n", (unsigned short)88);
	ft_printf("24) Mon PRINTF  : |%.hx|\n", (unsigned short)88);
	printf("25) Vrai PRINTF : |%#.hx|\n", (unsigned short)88);
	ft_printf("25) Mon PRINTF  : |%#.hx|\n", (unsigned short)88);
	printf("26) Vrai PRINTF : |%hx|\n", (unsigned short)USHRT_MAX);
	ft_printf("26) Mon PRINTF  : |%hx|\n", (unsigned short)USHRT_MAX);
	printf("27) Vrai PRINTF : |%#hx|\n", (unsigned short)USHRT_MAX);
	ft_printf("27) Mon PRINTF  : |%#hx|\n", (unsigned short)USHRT_MAX);
	printf("28) Vrai PRINTF : |%#hx| |%#hx|\n", (unsigned short)-1, (unsigned short)65536);
	ft_printf("28) Mon PRINTF  : |%#hx| |%#hx|\n", (unsigned short)-1, (unsigned short)65536);
	ft_printf("--------------------%%hhx--------------------\n");
	printf("01) Vrai PRINTF : |%hhx|\n", (unsigned char)34);
	ft_printf("01) Mon PRINTF  : |%hhx|\n", (unsigned char)34);
	printf("02) Vrai PRINTF : |%hhx|\n", (unsigned char)-34);
	ft_printf("02) Mon PRINTF  : |%hhx|\n", (unsigned char)-34);
	printf("03) Vrai PRINTF : |%-hhx|\n", (unsigned char)50);
	ft_printf("03) Mon PRINTF  : |%-hhx|\n", (unsigned char)50);
	printf("04) Vrai PRINTF : |%10hhx|\n", (unsigned char)90);
	ft_printf("04) Mon PRINTF  : |%10hhx|\n", (unsigned char)90);
	printf("05) Vrai PRINTF : |%.10hhx|\n", (unsigned char)90);
	ft_printf("05) Mon PRINTF  : |%.10hhx|\n", (unsigned char)90);
	printf("06) Vrai PRINTF : |%15hhx|\n", (unsigned char)-100);
	ft_printf("06) Mon PRINTF  : |%15hhx|\n", (unsigned char)-100);
	printf("07) Vrai PRINTF : |%.15hhx|\n", (unsigned char)-100);
	ft_printf("07) Mon PRINTF  : |%.15hhx|\n", (unsigned char)-100);
	printf("08) Vrai PRINTF : |%10.5hhx|\n", (unsigned char)52);
	ft_printf("08) Mon PRINTF  : |%10.5hhx|\n", (unsigned char)52);
	printf("09) Vrai PRINTF : |%5.10hhx|\n", (unsigned char)52);
	ft_printf("09) Mon PRINTF  : |%5.10hhx|\n", (unsigned char)52);
	printf("10) Vrai PRINTF : |%20.15hhx|\n", (unsigned char)-10000);
	ft_printf("10) Mon PRINTF  : |%20.15hhx|\n", (unsigned char)-10000);
	printf("11) Vrai PRINTF : |%15.20hhx|\n", (unsigned char)-10000);
	ft_printf("11) Mon PRINTF  : |%15.20hhx|\n", (unsigned char)-10000);
	printf("12) Vrai PRINTF : |%-10hhx|\n", (unsigned char)144);
	ft_printf("12) Mon PRINTF  : |%-10hhx|\n", (unsigned char)144);
	printf("13) Vrai PRINTF : |%-.10hhx|\n", (unsigned char)144);
	ft_printf("13) Mon PRINTF  : |%-.10hhx|\n", (unsigned char)144);
	printf("14) Vrai PRINTF : |%-20hhx|\n", (unsigned char)-20000);
	ft_printf("14) Mon PRINTF  : |%-20hhx|\n", (unsigned char)-20000);
	printf("15) Vrai PRINTF : |%08hhx|\n", (unsigned char)64);
	ft_printf("15) Mon PRINTF  : |%08hhx|\n", (unsigned char)64);
	printf("16) Vrai PRINTF : |%03.4hhx|\n", (unsigned char)10);
	ft_printf("16) Mon PRINTF  : |%03.4hhx|\n", (unsigned char)10);
	printf("17) Vrai PRINTF : |%#hhx|\n", (unsigned char)34);
	ft_printf("17) Mon PRINTF  : |%#hhx|\n", (unsigned char)34);
	printf("18) Vrai PRINTF : |%#.5hhx|\n", (unsigned char)34);
	ft_printf("18) Mon PRINTF  : |%#.5hhx|\n", (unsigned char)34);
	printf("19) Vrai PRINTF : |%#5hhx|\n", (unsigned char)86);
	ft_printf("19) Mon PRINTF  : |%#5hhx|\n", (unsigned char)86);
	printf("20) Vrai PRINTF : |%#10.5hhx|\n", (unsigned char)70);
	ft_printf("20) Mon PRINTF  : |%#10.5hhx|\n", (unsigned char)70);
	printf("21) Vrai PRINTF : |%#hhx|\n", (unsigned char)0);
	ft_printf("21) Mon PRINTF  : |%#hhx|\n", (unsigned char)0);
	printf("22) Vrai PRINTF : |%#.hhx|\n", (unsigned char)0);
	ft_printf("22) Mon PRINTF  : |%#.hhx|\n", (unsigned char)0);
	printf("23) Vrai PRINTF : |%.hhx|\n", (unsigned char)0);
	ft_printf("23) Mon PRINTF  : |%.hhx|\n", (unsigned char)0);
	printf("24) Vrai PRINTF : |%.hhx|\n", (unsigned char)88);
	ft_printf("24) Mon PRINTF  : |%.hhx|\n", (unsigned char)88);
	printf("25) Vrai PRINTF : |%#.hhx|\n", (unsigned char)88);
	ft_printf("25) Mon PRINTF  : |%#.hhx|\n", (unsigned char)88);
	printf("26) Vrai PRINTF : |%hhx|\n", (unsigned char)255);
	ft_printf("26) Mon PRINTF  : |%hhx|\n", (unsigned char)255);
	printf("27) Vrai PRINTF : |%#hhx|\n", (unsigned char)255);
	ft_printf("27) Mon PRINTF  : |%#hhx|\n", (unsigned char)255);
	printf("28) Vrai PRINTF : |%#hhx| |%#hhx|\n", (unsigned char)-1, (unsigned char)256);
	ft_printf("28) Mon PRINTF  : |%#hhx| |%#hhx|\n", (unsigned char)-1, (unsigned char) 256);
	ft_printf("--------------------%%lx--------------------\n");
	printf("01) Vrai PRINTF : |%lx|\n",(unsigned long)34);
	ft_printf("01) Mon PRINTF  : |%lx|\n", (unsigned long)34);
	printf("02) Vrai PRINTF : |%lx|\n", (unsigned long)-34);
	ft_printf("02) Mon PRINTF  : |%lx|\n", (unsigned long)-34);
	printf("03) Vrai PRINTF : |%-lx|\n", (unsigned long)50);
	ft_printf("03) Mon PRINTF  : |%-lx|\n", (unsigned long)50);
	printf("04) Vrai PRINTF : |%10lx|\n", (unsigned long)90);
	ft_printf("04) Mon PRINTF  : |%10lx|\n", (unsigned long)90);
	printf("05) Vrai PRINTF : |%.10lx|\n", (unsigned long)90);
	ft_printf("05) Mon PRINTF  : |%.10lx|\n", (unsigned long)90);
	printf("06) Vrai PRINTF : |%15lx|\n", (unsigned long)-100);
	ft_printf("06) Mon PRINTF  : |%15lx|\n", (unsigned long)-100);
	printf("07) Vrai PRINTF : |%.15lx|\n", (unsigned long)-100);
	ft_printf("07) Mon PRINTF  : |%.15lx|\n", (unsigned long)-100);
	printf("08) Vrai PRINTF : |%10.5lx|\n", (unsigned long)52);
	ft_printf("08) Mon PRINTF  : |%10.5lx|\n", (unsigned long)52);
	printf("09) Vrai PRINTF : |%5.10lx|\n", (unsigned long)52);
	ft_printf("09) Mon PRINTF  : |%5.10lx|\n", (unsigned long)52);
	printf("10) Vrai PRINTF : |%20.15lx|\n", (unsigned long)-100000);
	ft_printf("10) Mon PRINTF  : |%20.15lx|\n", (unsigned long)-100000);
	printf("11) Vrai PRINTF : |%15.20lx|\n", (unsigned long)-100000);
	ft_printf("11) Mon PRINTF  : |%15.20lx|\n", (unsigned long)-100000);
	printf("12) Vrai PRINTF : |%-10lx|\n", (unsigned long)144);
	ft_printf("12) Mon PRINTF  : |%-10lx|\n", (unsigned long)144);
	printf("13) Vrai PRINTF : |%-.10lx|\n", (unsigned long)144);
	ft_printf("13) Mon PRINTF  : |%-.10lx|\n", (unsigned long)144);
	printf("14) Vrai PRINTF : |%-20lx|\n", (unsigned long)-20000000);
	ft_printf("14) Mon PRINTF  : |%-20lx|\n", (unsigned long)-20000000);
	printf("15) Vrai PRINTF : |%08lx|\n", (unsigned long)64);
	ft_printf("15) Mon PRINTF  : |%08lx|\n", (unsigned long)64);
	printf("16) Vrai PRINTF : |%03.4lx|\n", (unsigned long)10);
	ft_printf("16) Mon PRINTF  : |%03.4lx|\n", (unsigned long)10);
	printf("17) Vrai PRINTF : |%#lx|\n", (unsigned long)34);
	ft_printf("17) Mon PRINTF  : |%#lx|\n", (unsigned long)34);
	printf("18) Vrai PRINTF : |%#.5lx|\n", (unsigned long)34);
	ft_printf("18) Mon PRINTF  : |%#.5lx|\n", (unsigned long)34);
	printf("19) Vrai PRINTF : |%#5lx|\n", (unsigned long)86);
	ft_printf("19) Mon PRINTF  : |%#5lx|\n", (unsigned long)86);
	printf("20) Vrai PRINTF : |%#10.5lx|\n", (unsigned long)70);
	ft_printf("20) Mon PRINTF  : |%#10.5lx|\n", (unsigned long)70);
	printf("21) Vrai PRINTF : |%#lx|\n", (unsigned long)0);
	ft_printf("21) Mon PRINTF  : |%#lx|\n", (unsigned long)0);
	printf("22) Vrai PRINTF : |%#.lx|\n", (unsigned long)0);
	ft_printf("22) Mon PRINTF  : |%#.lx|\n", (unsigned long)0);
	printf("23) Vrai PRINTF : |%.lx|\n", (unsigned long)0);
	ft_printf("23) Mon PRINTF  : |%.lx|\n", (unsigned long)0);
	printf("24) Vrai PRINTF : |%.lx|\n", (unsigned long)88);
	ft_printf("24) Mon PRINTF  : |%.lx|\n", (unsigned long)88);
	printf("25) Vrai PRINTF : |%#.lx|\n", (unsigned long)88);
	ft_printf("25) Mon PRINTF  : |%#.lx|\n", (unsigned long)88);
	printf("26) Vrai PRINTF : |%lx|\n", (unsigned long)UINT_MAX);
	ft_printf("26) Mon PRINTF  : |%lx|\n", (unsigned long)UINT_MAX);
	printf("27) Vrai PRINTF : |%#lx|\n", (unsigned long)-1, ULONG_MAX);
	ft_printf("27) Mon PRINTF  : |%#lx|\n", (unsigned long)-1, ULONG_MAX);
	printf("28) Vrai PRINTF : |%#lx| |%#lx|\n", (unsigned long)-1, ULONG_MAX + 1);
	ft_printf("28) Mon PRINTF  : |%#lx| |%#lx|\n", (unsigned long)-1, ULONG_MAX + 1);
	ft_printf("--------------------%%llx--------------------\n");
	printf("01) Vrai PRINTF : |%llx|\n",(unsigned long long)34);
	ft_printf("01) Mon PRINTF  : |%llx|\n", (unsigned long long)34);
	printf("02) Vrai PRINTF : |%llx|\n", (unsigned long long)-34);
	ft_printf("02) Mon PRINTF  : |%llx|\n", (unsigned long long)-34);
	printf("03) Vrai PRINTF : |%-llx|\n", (unsigned long long)50);
	ft_printf("03) Mon PRINTF  : |%-llx|\n", (unsigned long long)50);
	printf("04) Vrai PRINTF : |%10llx|\n", (unsigned long long)90);
	ft_printf("04) Mon PRINTF  : |%10llx|\n", (unsigned long long)90);
	printf("05) Vrai PRINTF : |%.10llx|\n", (unsigned long long)90);
	ft_printf("05) Mon PRINTF  : |%.10llx|\n", (unsigned long long)90);
	printf("06) Vrai PRINTF : |%15llx|\n", (unsigned long long)-100);
	ft_printf("06) Mon PRINTF  : |%15llx|\n", (unsigned long long)-100);
	printf("07) Vrai PRINTF : |%.15llx|\n", (unsigned long long)-100);
	ft_printf("07) Mon PRINTF  : |%.15llx|\n", (unsigned long long)-100);
	printf("08) Vrai PRINTF : |%10.5llx|\n", (unsigned long long)52);
	ft_printf("08) Mon PRINTF  : |%10.5llx|\n", (unsigned long long)52);
	printf("09) Vrai PRINTF : |%5.10llx|\n", (unsigned long long)52);
	ft_printf("09) Mon PRINTF  : |%5.10llx|\n", (unsigned long long)52);
	printf("10) Vrai PRINTF : |%20.15llx|\n", (unsigned long long)-100000);
	ft_printf("10) Mon PRINTF  : |%20.15llx|\n", (unsigned long long)-100000);
	printf("11) Vrai PRINTF : |%15.20llx|\n", (unsigned long long)-100000);
	ft_printf("11) Mon PRINTF  : |%15.20llx|\n", (unsigned long long)-100000);
	printf("12) Vrai PRINTF : |%-10llx|\n", (unsigned long long)144);
	ft_printf("12) Mon PRINTF  : |%-10llx|\n", (unsigned long long)144);
	printf("13) Vrai PRINTF : |%-.10llx|\n", (unsigned long long)144);
	ft_printf("13) Mon PRINTF  : |%-.10llx|\n", (unsigned long long)144);
	printf("14) Vrai PRINTF : |%-20llx|\n", (unsigned long long)-20000000);
	ft_printf("14) Mon PRINTF  : |%-20llx|\n", (unsigned long long)-20000000);
	printf("15) Vrai PRINTF : |%08llx|\n", (unsigned long long)64);
	ft_printf("15) Mon PRINTF  : |%08llx|\n", (unsigned long long)64);
	printf("16) Vrai PRINTF : |%03.4llx|\n", (unsigned long long)10);
	ft_printf("16) Mon PRINTF  : |%03.4llx|\n", (unsigned long long)10);
	printf("17) Vrai PRINTF : |%#llx|\n", (unsigned long long)34);
	ft_printf("17) Mon PRINTF  : |%#llx|\n", (unsigned long long)34);
	printf("18) Vrai PRINTF : |%#.5llx|\n", (unsigned long long)34);
	ft_printf("18) Mon PRINTF  : |%#.5llx|\n", (unsigned long long)34);
	printf("19) Vrai PRINTF : |%#5llx|\n", (unsigned long long)86);
	ft_printf("19) Mon PRINTF  : |%#5llx|\n", (unsigned long long)86);
	printf("20) Vrai PRINTF : |%#10.5llx|\n", (unsigned long long)70);
	ft_printf("20) Mon PRINTF  : |%#10.5llx|\n", (unsigned long long)70);
	printf("21) Vrai PRINTF : |%#llx|\n", (unsigned long long)0);
	ft_printf("21) Mon PRINTF  : |%#llx|\n", (unsigned long long)0);
	printf("22) Vrai PRINTF : |%#.llx|\n", (unsigned long long)0);
	ft_printf("22) Mon PRINTF  : |%#.llx|\n", (unsigned long long)0);
	printf("23) Vrai PRINTF : |%.llx|\n", (unsigned long long)0);
	ft_printf("23) Mon PRINTF  : |%.llx|\n", (unsigned long long)0);
	printf("24) Vrai PRINTF : |%.llx|\n", (unsigned long long)88);
	ft_printf("24) Mon PRINTF  : |%.llx|\n", (unsigned long long)88);
	printf("25) Vrai PRINTF : |%#.llx|\n", (unsigned long long)88);
	ft_printf("25) Mon PRINTF  : |%#.llx|\n", (unsigned long long)88);
	printf("26) Vrai PRINTF : |%llx|\n", (unsigned long long)UINT_MAX);
	ft_printf("26) Mon PRINTF  : |%llx|\n", (unsigned long long)UINT_MAX);
	printf("27) Vrai PRINTF : |%#llx|\n", (unsigned long long)-1, ULLONG_MAX);
	ft_printf("27) Mon PRINTF  : |%#llx|\n", (unsigned long long)-1, ULLONG_MAX);
	printf("28) Vrai PRINTF : |%#llx| |%#llx|\n", (unsigned long long)-1, ULLONG_MAX + 1);
	ft_printf("28) Mon PRINTF  : |%#llx| |%#llx|\n", (unsigned long long)-1, ULLONG_MAX + 1);
	ft_printf("--------------------%%X--------------------\n");
	printf("01) Vrai PRINTF : |%X|\n", 34);
	ft_printf("01) Mon PRINTF  : |%X|\n", 34);
	printf("02) Vrai PRINTF : |%X|\n", -34);
	ft_printf("02) Mon PRINTF  : |%X|\n", -34);
	printf("03) Vrai PRINTF : |%-X|\n", 50);
	ft_printf("03) Mon PRINTF  : |%-X|\n", 50);
	printf("04) Vrai PRINTF : |%10X|\n", 90);
	ft_printf("04) Mon PRINTF  : |%10X|\n", 90);
	printf("05) Vrai PRINTF : |%.10X|\n", 90);
	ft_printf("05) Mon PRINTF  : |%.10X|\n", 90);
	printf("06) Vrai PRINTF : |%15X|\n", -100);
	ft_printf("06) Mon PRINTF  : |%15X|\n", -100);
	printf("07) Vrai PRINTF : |%.15X|\n", -100);
	ft_printf("07) Mon PRINTF  : |%.15X|\n", -100);
	printf("08) Vrai PRINTF : |%10.5X|\n", 52);
	ft_printf("08) Mon PRINTF  : |%10.5X|\n", 52);
	printf("09) Vrai PRINTF : |%5.10X|\n", 52);
	ft_printf("09) Mon PRINTF  : |%5.10X|\n", 52);
	printf("10) Vrai PRINTF : |%20.15X|\n", -100000);
	ft_printf("10) Mon PRINTF  : |%20.15X|\n", -100000);
	printf("11) Vrai PRINTF : |%15.20X|\n", -100000);
	ft_printf("11) Mon PRINTF  : |%15.20X|\n", -100000);
	printf("12) Vrai PRINTF : |%-10X|\n", 144);
	ft_printf("12) Mon PRINTF  : |%-10X|\n", 144);
	printf("13) Vrai PRINTF : |%-.10X|\n", 144);
	ft_printf("13) Mon PRINTF  : |%-.10X|\n", 144);
	printf("14) Vrai PRINTF : |%-20X|\n", -20000000);
	ft_printf("14) Mon PRINTF  : |%-20X|\n", -20000000);
	printf("15) Vrai PRINTF : |%08X|\n", 64);
	ft_printf("15) Mon PRINTF  : |%08X|\n", 64);
	printf("16) Vrai PRINTF : |%03.4X|\n", 10);
	ft_printf("16) Mon PRINTF  : |%03.4X|\n", 10);
	printf("17) Vrai PRINTF : |%#X|\n", 34);
	ft_printf("17) Mon PRINTF  : |%#X|\n", 34);
	printf("18) Vrai PRINTF : |%#.5X|\n", 34);
	ft_printf("18) Mon PRINTF  : |%#.5X|\n", 34);
	printf("19) Vrai PRINTF : |%#5X|\n", 86);
	ft_printf("19) Mon PRINTF  : |%#5X|\n", 86);
	printf("20) Vrai PRINTF : |%#10.5X|\n", 70);
	ft_printf("20) Mon PRINTF  : |%#10.5X|\n", 70);
	printf("21) Vrai PRINTF : |%#X|\n", 0);
	ft_printf("21) Mon PRINTF  : |%#X|\n", 0);
	printf("22) Vrai PRINTF : |%#.X|\n", 0);
	ft_printf("22) Mon PRINTF  : |%#.X|\n", 0);
	printf("23) Vrai PRINTF : |%.X|\n", 0);
	ft_printf("23) Mon PRINTF  : |%.X|\n", 0);
	printf("24) Vrai PRINTF : |%.X|\n", 88);
	ft_printf("24) Mon PRINTF  : |%.X|\n", 88);
	printf("25) Vrai PRINTF : |%#.X|\n", 88);
	ft_printf("25) Mon PRINTF  : |%#.X|\n", 88);
	printf("26) Vrai PRINTF : |%X|\n", UINT_MAX);
	ft_printf("26) Mon PRINT   : |%X|\n", UINT_MAX);
	printf("27) Vrai PRINTF : |%#X|\n", UINT_MAX);
	ft_printf("27) Mon PRINTF  : |%#X|\n", UINT_MAX);
	printf("28) Vrai PRINTF : |%#X| |%#X|\n", (unsigned int)-1, UINT_MAX + 1);
	ft_printf("28) Mon PRINTF  : |%#X| |%#X|\n", (unsigned int)-1, UINT_MAX + 1);
	ft_printf("--------------------%%hX--------------------\n");
	printf("01) Vrai PRINTF : |%hX|\n", (unsigned short)34);
	ft_printf("01) Mon PRINTF  : |%hX|\n", (unsigned short)34);
	printf("02) Vrai PRINTF : |%hX|\n", (unsigned short)-34);
	ft_printf("02) Mon PRINTF  : |%hX|\n", (unsigned short)-34);
	printf("03) Vrai PRINTF : |%-hX|\n", (unsigned short)50);
	ft_printf("03) Mon PRINTF  : |%-hX|\n", (unsigned short)50);
	printf("04) Vrai PRINTF : |%10hX|\n", (unsigned short)90);
	ft_printf("04) Mon PRINTF  : |%10hX|\n", (unsigned short)90);
	printf("05) Vrai PRINTF : |%.10hX|\n", (unsigned short)90);
	ft_printf("05) Mon PRINTF  : |%.10hX|\n", (unsigned short)90);
	printf("06) Vrai PRINTF : |%15hX|\n", (unsigned short)-100);
	ft_printf("06) Mon PRINTF  : |%15hX|\n", (unsigned short)-100);
	printf("07) Vrai PRINTF : |%.15hX|\n", (unsigned short)-100);
	ft_printf("07) Mon PRINTF  : |%.15hX|\n", (unsigned short)-100);
	printf("08) Vrai PRINTF : |%10.5hX|\n", (unsigned short)52);
	ft_printf("08) Mon PRINTF  : |%10.5hX|\n", (unsigned short)52);
	printf("09) Vrai PRINTF : |%5.10hX|\n", (unsigned short)52);
	ft_printf("09) Mon PRINTF  : |%5.10hX|\n", (unsigned short)52);
	printf("10) Vrai PRINTF : |%20.15hX|\n", (unsigned short)-10000);
	ft_printf("10) Mon PRINTF  : |%20.15hX|\n", (unsigned short)-10000);
	printf("11) Vrai PRINTF : |%15.20hX|\n", (unsigned short)-10000);
	ft_printf("11) Mon PRINTF  : |%15.20hX|\n", (unsigned short)-10000);
	printf("12) Vrai PRINTF : |%-10hX|\n", (unsigned short)144);
	ft_printf("12) Mon PRINTF  : |%-10hX|\n", (unsigned short)144);
	printf("13) Vrai PRINTF : |%-.10hX|\n", (unsigned short)144);
	ft_printf("13) Mon PRINTF  : |%-.10hX|\n", (unsigned short)144);
	printf("14) Vrai PRINTF : |%-20hX|\n", (unsigned short)-20000);
	ft_printf("14) Mon PRINTF  : |%-20hX|\n", (unsigned short)-20000);
	printf("15) Vrai PRINTF : |%08hX|\n", (unsigned short)64);
	ft_printf("15) Mon PRINTF  : |%08hX|\n", (unsigned short)64);
	printf("16) Vrai PRINTF : |%03.4hX|\n", (unsigned short)10);
	ft_printf("16) Mon PRINTF  : |%03.4hX|\n", (unsigned short)10);
	printf("17) Vrai PRINTF : |%#hX|\n", (unsigned short)34);
	ft_printf("17) Mon PRINTF  : |%#hX|\n", (unsigned short)34);
	printf("18) Vrai PRINTF : |%#.5hX|\n", (unsigned short)34);
	ft_printf("18) Mon PRINTF  : |%#.5hX|\n", (unsigned short)34);
	printf("19) Vrai PRINTF : |%#5hX|\n", (unsigned short)86);
	ft_printf("19) Mon PRINTF  : |%#5hX|\n", (unsigned short)86);
	printf("20) Vrai PRINTF : |%#10.5hX|\n", (unsigned short)70);
	ft_printf("20) Mon PRINTF  : |%#10.5hX|\n", (unsigned short)70);
	printf("21) Vrai PRINTF : |%#hX|\n", (unsigned short)0);
	ft_printf("21) Mon PRINTF  : |%#hX|\n", (unsigned short)0);
	printf("22) Vrai PRINTF : |%#.hX|\n", (unsigned short)0);
	ft_printf("22) Mon PRINTF  : |%#.hX|\n", (unsigned short)0);
	printf("23) Vrai PRINTF : |%.hX|\n", (unsigned short)0);
	ft_printf("23) Mon PRINTF  : |%.hX|\n", (unsigned short)0);
	printf("24) Vrai PRINTF : |%.hX|\n", (unsigned short)88);
	ft_printf("24) Mon PRINTF  : |%.hX|\n", (unsigned short)88);
	printf("25) Vrai PRINTF : |%#.hX|\n", (unsigned short)88);
	ft_printf("25) Mon PRINTF  : |%#.hX|\n", (unsigned short)88);
	printf("26) Vrai PRINTF : |%hX|\n", (unsigned short)USHRT_MAX);
	ft_printf("26) Mon PRINTF  : |%hX|\n", (unsigned short)USHRT_MAX);
	printf("27) Vrai PRINTF : |%#hX|\n", (unsigned short)USHRT_MAX);
	ft_printf("27) Mon PRINTF  : |%#hX|\n", (unsigned short)USHRT_MAX);
	printf("28) Vrai PRINTF : |%#hX| |%#hX|\n", (unsigned short)-1, (unsigned short)65536);
	ft_printf("28) Mon PRINTF  : |%#hX| |%#hX|\n", (unsigned short)-1, (unsigned short)65536);
	ft_printf("--------------------%%hhX--------------------\n");
	printf("01) Vrai PRINTF : |%hhX|\n", (unsigned char)34);
	ft_printf("01) Mon PRINTF  : |%hhX|\n", (unsigned char)34);
	printf("02) Vrai PRINTF : |%hhX|\n", (unsigned char)-34);
	ft_printf("02) Mon PRINTF  : |%hhX|\n", (unsigned char)-34);
	printf("03) Vrai PRINTF : |%-hhX|\n", (unsigned char)50);
	ft_printf("03) Mon PRINTF  : |%-hhX|\n", (unsigned char)50);
	printf("04) Vrai PRINTF : |%10hhX|\n", (unsigned char)90);
	ft_printf("04) Mon PRINTF  : |%10hhX|\n", (unsigned char)90);
	printf("05) Vrai PRINTF : |%.10hhX|\n", (unsigned char)90);
	ft_printf("05) Mon PRINTF  : |%.10hhX|\n", (unsigned char)90);
	printf("06) Vrai PRINTF : |%15hhX|\n", (unsigned char)-100);
	ft_printf("06) Mon PRINTF  : |%15hhX|\n", (unsigned char)-100);
	printf("07) Vrai PRINTF : |%.15hhX|\n", (unsigned char)-100);
	ft_printf("07) Mon PRINTF  : |%.15hhX|\n", (unsigned char)-100);
	printf("08) Vrai PRINTF : |%10.5hhX|\n", (unsigned char)52);
	ft_printf("08) Mon PRINTF  : |%10.5hhX|\n", (unsigned char)52);
	printf("09) Vrai PRINTF : |%5.10hhX|\n", (unsigned char)52);
	ft_printf("09) Mon PRINTF  : |%5.10hhX|\n", (unsigned char)52);
	printf("10) Vrai PRINTF : |%20.15hhX|\n", (unsigned char)-10000);
	ft_printf("10) Mon PRINTF  : |%20.15hhX|\n", (unsigned char)-10000);
	printf("11) Vrai PRINTF : |%15.20hhX|\n", (unsigned char)-10000);
	ft_printf("11) Mon PRINTF  : |%15.20hhX|\n", (unsigned char)-10000);
	printf("12) Vrai PRINTF : |%-10hhX|\n", (unsigned char)144);
	ft_printf("12) Mon PRINTF  : |%-10hhX|\n", (unsigned char)144);
	printf("13) Vrai PRINTF : |%-.10hhX|\n", (unsigned char)144);
	ft_printf("13) Mon PRINTF  : |%-.10hhX|\n", (unsigned char)144);
	printf("14) Vrai PRINTF : |%-20hhX|\n", (unsigned char)-20000);
	ft_printf("14) Mon PRINTF  : |%-20hhX|\n", (unsigned char)-20000);
	printf("15) Vrai PRINTF : |%08hhX|\n", (unsigned char)64);
	ft_printf("15) Mon PRINTF  : |%08hhX|\n", (unsigned char)64);
	printf("16) Vrai PRINTF : |%03.4hhX|\n", (unsigned char)10);
	ft_printf("16) Mon PRINTF  : |%03.4hhX|\n", (unsigned char)10);
	printf("17) Vrai PRINTF : |%#hhX|\n", (unsigned char)34);
	ft_printf("17) Mon PRINTF  : |%#hhX|\n", (unsigned char)34);
	printf("18) Vrai PRINTF : |%#.5hhX|\n", (unsigned char)34);
	ft_printf("18) Mon PRINTF  : |%#.5hhX|\n", (unsigned char)34);
	printf("19) Vrai PRINTF : |%#5hhX|\n", (unsigned char)86);
	ft_printf("19) Mon PRINTF  : |%#5hhX|\n", (unsigned char)86);
	printf("20) Vrai PRINTF : |%#10.5hhX|\n", (unsigned char)70);
	ft_printf("20) Mon PRINTF  : |%#10.5hhX|\n", (unsigned char)70);
	printf("21) Vrai PRINTF : |%#hhX|\n", (unsigned char)0);
	ft_printf("21) Mon PRINTF  : |%#hhX|\n", (unsigned char)0);
	printf("22) Vrai PRINTF : |%#.hhX|\n", (unsigned char)0);
	ft_printf("22) Mon PRINTF  : |%#.hhX|\n", (unsigned char)0);
	printf("23) Vrai PRINTF : |%.hhX|\n", (unsigned char)0);
	ft_printf("23) Mon PRINTF  : |%.hhX|\n", (unsigned char)0);
	printf("24) Vrai PRINTF : |%.hhX|\n", (unsigned char)88);
	ft_printf("24) Mon PRINTF  : |%.hhX|\n", (unsigned char)88);
	printf("25) Vrai PRINTF : |%#.hhX|\n", (unsigned char)88);
	ft_printf("25) Mon PRINTF  : |%#.hhX|\n", (unsigned char)88);
	printf("26) Vrai PRINTF : |%hhX|\n", (unsigned char)255);
	ft_printf("26) Mon PRINTF  : |%hhX|\n", (unsigned char)255);
	printf("27) Vrai PRINTF : |%#hhX|\n", (unsigned char)255);
	ft_printf("27) Mon PRINTF  : |%#hhX|\n", (unsigned char)255);
	printf("28) Vrai PRINTF : |%#hhX| |%#hhX|\n", (unsigned char)-1, (unsigned char)256);
	ft_printf("28) Mon PRINTF  : |%#hhX| |%#hhX|\n", (unsigned char)-1, (unsigned char) 256);
	ft_printf("--------------------%%lX--------------------\n");
	printf("01) Vrai PRINTF : |%lX|\n",(unsigned long)34);
	ft_printf("01) Mon PRINTF  : |%lX|\n", (unsigned long)34);
	printf("02) Vrai PRINTF : |%lX|\n", (unsigned long)-34);
	ft_printf("02) Mon PRINTF  : |%lX|\n", (unsigned long)-34);
	printf("03) Vrai PRINTF : |%-lX|\n", (unsigned long)50);
	ft_printf("03) Mon PRINTF  : |%-lX|\n", (unsigned long)50);
	printf("04) Vrai PRINTF : |%10lX|\n", (unsigned long)90);
	ft_printf("04) Mon PRINTF  : |%10lX|\n", (unsigned long)90);
	printf("05) Vrai PRINTF : |%.10lX|\n", (unsigned long)90);
	ft_printf("05) Mon PRINTF  : |%.10lX|\n", (unsigned long)90);
	printf("06) Vrai PRINTF : |%15lX|\n", (unsigned long)-100);
	ft_printf("06) Mon PRINTF  : |%15lX|\n", (unsigned long)-100);
	printf("07) Vrai PRINTF : |%.15lX|\n", (unsigned long)-100);
	ft_printf("07) Mon PRINTF  : |%.15lX|\n", (unsigned long)-100);
	printf("08) Vrai PRINTF : |%10.5lX|\n", (unsigned long)52);
	ft_printf("08) Mon PRINTF  : |%10.5lX|\n", (unsigned long)52);
	printf("09) Vrai PRINTF : |%5.10lX|\n", (unsigned long)52);
	ft_printf("09) Mon PRINTF  : |%5.10lX|\n", (unsigned long)52);
	printf("10) Vrai PRINTF : |%20.15lX|\n", (unsigned long)-100000);
	ft_printf("10) Mon PRINTF  : |%20.15lX|\n", (unsigned long)-100000);
	printf("11) Vrai PRINTF : |%15.20lX|\n", (unsigned long)-100000);
	ft_printf("11) Mon PRINTF  : |%15.20lX|\n", (unsigned long)-100000);
	printf("12) Vrai PRINTF : |%-10lX|\n", (unsigned long)144);
	ft_printf("12) Mon PRINTF  : |%-10lX|\n", (unsigned long)144);
	printf("13) Vrai PRINTF : |%-.10lX|\n", (unsigned long)144);
	ft_printf("13) Mon PRINTF  : |%-.10lX|\n", (unsigned long)144);
	printf("14) Vrai PRINTF : |%-20lX|\n", (unsigned long)-20000000);
	ft_printf("14) Mon PRINTF  : |%-20lX|\n", (unsigned long)-20000000);
	printf("15) Vrai PRINTF : |%08lX|\n", (unsigned long)64);
	ft_printf("15) Mon PRINTF  : |%08lX|\n", (unsigned long)64);
	printf("16) Vrai PRINTF : |%03.4lX|\n", (unsigned long)10);
	ft_printf("16) Mon PRINTF  : |%03.4lX|\n", (unsigned long)10);
	printf("17) Vrai PRINTF : |%#lX|\n", (unsigned long)34);
	ft_printf("17) Mon PRINTF  : |%#lX|\n", (unsigned long)34);
	printf("18) Vrai PRINTF : |%#.5lX|\n", (unsigned long)34);
	ft_printf("18) Mon PRINTF  : |%#.5lX|\n", (unsigned long)34);
	printf("19) Vrai PRINTF : |%#5lX|\n", (unsigned long)86);
	ft_printf("19) Mon PRINTF  : |%#5lX|\n", (unsigned long)86);
	printf("20) Vrai PRINTF : |%#10.5lX|\n", (unsigned long)70);
	ft_printf("20) Mon PRINTF  : |%#10.5lX|\n", (unsigned long)70);
	printf("21) Vrai PRINTF : |%#lX|\n", (unsigned long)0);
	ft_printf("21) Mon PRINTF  : |%#lX|\n", (unsigned long)0);
	printf("22) Vrai PRINTF : |%#.lX|\n", (unsigned long)0);
	ft_printf("22) Mon PRINTF  : |%#.lX|\n", (unsigned long)0);
	printf("23) Vrai PRINTF : |%.lX|\n", (unsigned long)0);
	ft_printf("23) Mon PRINTF  : |%.lX|\n", (unsigned long)0);
	printf("24) Vrai PRINTF : |%.lX|\n", (unsigned long)88);
	ft_printf("24) Mon PRINTF  : |%.lX|\n", (unsigned long)88);
	printf("25) Vrai PRINTF : |%#.lX|\n", (unsigned long)88);
	ft_printf("25) Mon PRINTF  : |%#.lX|\n", (unsigned long)88);
	printf("26) Vrai PRINTF : |%lX|\n", (unsigned long)UINT_MAX);
	ft_printf("26) Mon PRINTF  : |%lX|\n", (unsigned long)UINT_MAX);
	printf("27) Vrai PRINTF : |%#lX|\n", (unsigned long)-1, ULONG_MAX);
	ft_printf("27) Mon PRINTF  : |%#lX|\n", (unsigned long)-1, ULONG_MAX);
	printf("28) Vrai PRINTF : |%#lX| |%#lX|\n", (unsigned long)-1, ULONG_MAX + 1);
	ft_printf("28) Mon PRINTF  : |%#lX| |%#lX|\n", (unsigned long)-1, ULONG_MAX + 1);
	ft_printf("--------------------%%llX--------------------\n");
	printf("01) Vrai PRINTF : |%llX|\n",(unsigned long long)34);
	ft_printf("01) Mon PRINTF  : |%llX|\n", (unsigned long long)34);
	printf("02) Vrai PRINTF : |%llX|\n", (unsigned long long)-34);
	ft_printf("02) Mon PRINTF  : |%llX|\n", (unsigned long long)-34);
	printf("03) Vrai PRINTF : |%-llX|\n", (unsigned long long)50);
	ft_printf("03) Mon PRINTF  : |%-llX|\n", (unsigned long long)50);
	printf("04) Vrai PRINTF : |%10llX|\n", (unsigned long long)90);
	ft_printf("04) Mon PRINTF  : |%10llX|\n", (unsigned long long)90);
	printf("05) Vrai PRINTF : |%.10llX|\n", (unsigned long long)90);
	ft_printf("05) Mon PRINTF  : |%.10llX|\n", (unsigned long long)90);
	printf("06) Vrai PRINTF : |%15llX|\n", (unsigned long long)-100);
	ft_printf("06) Mon PRINTF  : |%15llX|\n", (unsigned long long)-100);
	printf("07) Vrai PRINTF : |%.15llX|\n", (unsigned long long)-100);
	ft_printf("07) Mon PRINTF  : |%.15llX|\n", (unsigned long long)-100);
	printf("08) Vrai PRINTF : |%10.5llX|\n", (unsigned long long)52);
	ft_printf("08) Mon PRINTF  : |%10.5llX|\n", (unsigned long long)52);
	printf("09) Vrai PRINTF : |%5.10llX|\n", (unsigned long long)52);
	ft_printf("09) Mon PRINTF  : |%5.10llX|\n", (unsigned long long)52);
	printf("10) Vrai PRINTF : |%20.15llX|\n", (unsigned long long)-100000);
	ft_printf("10) Mon PRINTF  : |%20.15llX|\n", (unsigned long long)-100000);
	printf("11) Vrai PRINTF : |%15.20llX|\n", (unsigned long long)-100000);
	ft_printf("11) Mon PRINTF  : |%15.20llX|\n", (unsigned long long)-100000);
	printf("12) Vrai PRINTF : |%-10llX|\n", (unsigned long long)144);
	ft_printf("12) Mon PRINTF  : |%-10llX|\n", (unsigned long long)144);
	printf("13) Vrai PRINTF : |%-.10llX|\n", (unsigned long long)144);
	ft_printf("13) Mon PRINTF  : |%-.10llX|\n", (unsigned long long)144);
	printf("14) Vrai PRINTF : |%-20llX|\n", (unsigned long long)-20000000);
	ft_printf("14) Mon PRINTF  : |%-20llX|\n", (unsigned long long)-20000000);
	printf("15) Vrai PRINTF : |%08llX|\n", (unsigned long long)64);
	ft_printf("15) Mon PRINTF  : |%08llX|\n", (unsigned long long)64);
	printf("16) Vrai PRINTF : |%03.4llX|\n", (unsigned long long)10);
	ft_printf("16) Mon PRINTF  : |%03.4llX|\n", (unsigned long long)10);
	printf("17) Vrai PRINTF : |%#llX|\n", (unsigned long long)34);
	ft_printf("17) Mon PRINTF  : |%#llX|\n", (unsigned long long)34);
	printf("18) Vrai PRINTF : |%#.5llX|\n", (unsigned long long)34);
	ft_printf("18) Mon PRINTF  : |%#.5llX|\n", (unsigned long long)34);
	printf("19) Vrai PRINTF : |%#5llX|\n", (unsigned long long)86);
	ft_printf("19) Mon PRINTF  : |%#5llX|\n", (unsigned long long)86);
	printf("20) Vrai PRINTF : |%#10.5llX|\n", (unsigned long long)70);
	ft_printf("20) Mon PRINTF  : |%#10.5llX|\n", (unsigned long long)70);
	printf("21) Vrai PRINTF : |%#llX|\n", (unsigned long long)0);
	ft_printf("21) Mon PRINTF  : |%#llX|\n", (unsigned long long)0);
	printf("22) Vrai PRINTF : |%#.llX|\n", (unsigned long long)0);
	ft_printf("22) Mon PRINTF  : |%#.llX|\n", (unsigned long long)0);
	printf("23) Vrai PRINTF : |%.llX|\n", (unsigned long long)0);
	ft_printf("23) Mon PRINTF  : |%.llX|\n", (unsigned long long)0);
	printf("24) Vrai PRINTF : |%.llX|\n", (unsigned long long)88);
	ft_printf("24) Mon PRINTF  : |%.llX|\n", (unsigned long long)88);
	printf("25) Vrai PRINTF : |%#.llX|\n", (unsigned long long)88);
	ft_printf("25) Mon PRINTF  : |%#.llX|\n", (unsigned long long)88);
	printf("26) Vrai PRINTF : |%llX|\n", (unsigned long long)UINT_MAX);
	ft_printf("26) Mon PRINTF  : |%llX|\n", (unsigned long long)UINT_MAX);
	printf("27) Vrai PRINTF : |%#llX|\n", (unsigned long long)-1, ULLONG_MAX);
	ft_printf("27) Mon PRINTF  : |%#llX|\n", (unsigned long long)-1, ULLONG_MAX);
	printf("28) Vrai PRINTF : |%#llX| |%#llX|\n", (unsigned long long)-1, ULLONG_MAX + 1);
	ft_printf("28) Mon PRINTF  : |%#llX| |%#llX|\n", (unsigned long long)-1, ULLONG_MAX + 1);
	ft_printf("--------------------%%u--------------------\n");		//19/20
	printf("01) Vrai PRINTF : |%u|\n", 34);
	ft_printf("01) Mon PRINTF  : |%u|\n", 34);
	printf("02) Vrai PRINTF : |%u|\n", -34);
	ft_printf("02) Mon PRINTF  : |%u|\n", -34);
	printf("03) Vrai PRINTF : |%-u|\n", 50);
	ft_printf("03) Mon PRINTF  : |%-u|\n", 50);
	printf("04) Vrai PRINTF : |%10u|\n", 90);
	ft_printf("04) Mon PRINTF  : |%10u|\n", 90);
	printf("05) Vrai PRINTF : |%.10u|\n", 90);
	ft_printf("05) Mon PRINTF  : |%.10u|\n", 90);
	printf("06) Vrai PRINTF : |%15u|\n", -100);
	ft_printf("06) Mon PRINTF  : |%15u|\n", -100);
	printf("07) Vrai PRINTF : |%.15u|\n", -100);
	ft_printf("07) Mon PRINTF  : |%.15u|\n", -100);
	printf("08) Vrai PRINTF : |%10.5u|\n", 52);
	ft_printf("08) Mon PRINTF  : |%10.5u|\n", 52);
	printf("09) Vrai PRINTF : |%5.10u|\n", 52);
	ft_printf("09) Mon PRINTF  : |%5.10u|\n", 52);
	printf("10) Vrai PRINTF : |%20.15u|\n", -100000);
	ft_printf("10) Mon PRINTF  : |%20.15u|\n", -100000);
	printf("11) Vrai PRINTF : |%15.20u|\n", -100000);
	ft_printf("11) Mon PRINTF  : |%15.20u|\n", -100000);
	printf("12) Vrai PRINTF : |%-10u|\n", 144);
	ft_printf("12) Mon PRINTF  : |%-10u|\n", 144);
	printf("13) Vrai PRINTF : |%-.10u|\n", 144);
	ft_printf("13) Mon PRINTF  : |%-.10u|\n", 144);
	printf("14) Vrai PRINTF : |%-20u|\n", -20000000);
	ft_printf("14) Mon PRINTF  : |%-20u|\n", -20000000);
	printf("15) Vrai PRINTF : |%08u|\n", 64);
	ft_printf("15) Mon PRINTF  : |%08u|\n", 64);
	printf("16) Vrai PRINTF : |%03.4u|\n", 10);
	ft_printf("16) Mon PRINTF  : |%03.4u|\n", 10);
	printf("17) Vrai PRINTF : |%u|\n", 0);
	ft_printf("17) Mon PRINTF  : |%u|\n", 0);
	printf("18) Vrai PRINTF : |%.u|\n", 0);
	ft_printf("18) Mon PRINTF  : |%.u|\n", 0);
	printf("19) Vrai PRINTF : |%10u|\n", 0);
	ft_printf("19) Mon PRINTF  : |%10u|\n", 0);
	printf("20) Vrai PRINTF : |%.u|\n", 88);
	ft_printf("20) Mon PRINTF  : |%.u|\n", 88);
	printf("21) Vrai PRINTF : |%u|\n", UINT_MAX);
	ft_printf("21) Mon PRINTF  : |%u|\n", UINT_MAX);
	printf("22) Vrai PRINTF : |%u| |%u|\n", (unsigned int)-1, UINT_MAX + 1);
	ft_printf("22) Mon PRINTF  : |%u| |%u|\n", (unsigned int)-1, UINT_MAX + 1);
	ft_printf("--------------------%%hu--------------------\n");
	printf("01) Vrai PRINTF : |%hu|\n", (unsigned short)34);
	ft_printf("01) Mon PRINTF  : |%hu|\n", (unsigned short)34);
	printf("02) Vrai PRINTF : |%hu|\n", (unsigned short)-34);
	ft_printf("02) Mon PRINTF  : |%hu|\n", (unsigned short)-34);
	printf("03) Vrai PRINTF : |%-hu|\n", (unsigned short)50);
	ft_printf("03) Mon PRINTF  : |%-hu|\n", (unsigned short)50);
	printf("04) Vrai PRINTF : |%10hu|\n", (unsigned short)90);
	ft_printf("04) Mon PRINTF  : |%10hu|\n", (unsigned short)90);
	printf("05) Vrai PRINTF : |%.10hu|\n", (unsigned short)90);
	ft_printf("05) Mon PRINTF  : |%.10hu|\n", (unsigned short)90);
	printf("06) Vrai PRINTF : |%15hu|\n", (unsigned short)-100);
	ft_printf("06) Mon PRINTF  : |%15hu|\n", (unsigned short)-100);
	printf("07) Vrai PRINTF : |%.15hu|\n", (unsigned short)-100);
	ft_printf("07) Mon PRINTF  : |%.15hu|\n", (unsigned short)-100);
	printf("08) Vrai PRINTF : |%10.5hu|\n", (unsigned short)52);
	ft_printf("08) Mon PRINTF  : |%10.5hu|\n", (unsigned short)52);
	printf("09) Vrai PRINTF : |%5.10hu|\n", (unsigned short)52);
	ft_printf("09) Mon PRINTF  : |%5.10hu|\n", (unsigned short)52);
	printf("10) Vrai PRINTF : |%20.15hu|\n", (unsigned short)-10000);
	ft_printf("10) Mon PRINTF  : |%20.15hu|\n", (unsigned short)-10000);
	printf("11) Vrai PRINTF : |%15.20hu|\n", (unsigned short)-10000);
	ft_printf("11) Mon PRINTF  : |%15.20hu|\n", (unsigned short)-10000);
	printf("12) Vrai PRINTF : |%-10hu|\n", (unsigned short)144);
	ft_printf("12) Mon PRINTF  : |%-10hu|\n", (unsigned short)144);
	printf("13) Vrai PRINTF : |%-.10hu|\n", (unsigned short)144);
	ft_printf("13) Mon PRINTF  : |%-.10hu|\n", (unsigned short)144);
	printf("14) Vrai PRINTF : |%-20hu|\n", (unsigned short)-20000);
	ft_printf("14) Mon PRINTF  : |%-20hu|\n", (unsigned short)-20000);
	printf("15) Vrai PRINTF : |%08hu|\n", (unsigned short)64);
	ft_printf("15) Mon PRINTF  : |%08hu|\n", (unsigned short)64);
	printf("16) Vrai PRINTF : |%03.4hu|\n", (unsigned short)10);
	ft_printf("16) Mon PRINTF  : |%03.4hu|\n", (unsigned short)10);
	printf("17) Vrai PRINTF : |%.hu|\n", (unsigned short)0);
	ft_printf("17) Mon PRINTF  : |%.hu|\n", (unsigned short)0);
	printf("18) Vrai PRINTF : |%.hu|\n", (unsigned short)88);
	ft_printf("18) Mon PRINTF  : |%.hu|\n", (unsigned short)88);
	printf("19) Vrai PRINTF : |%hu|\n", (unsigned short)USHRT_MAX);
	ft_printf("19) Mon PRINTF  : |%hu|\n", (unsigned short)USHRT_MAX);
	printf("20) Vrai PRINTF : |%hu| |%hu|\n", (unsigned short)-1, (unsigned short)65536);
	ft_printf("20) Mon PRINTF  : |%hu| |%hu|\n", (unsigned short)-1, (unsigned short)65536);
	ft_printf("--------------------%%hhu--------------------\n");
	printf("01) Vrai PRINTF : |%hhu|\n", (unsigned char)34);
	ft_printf("01) Mon PRINTF  : |%hhu|\n", (unsigned char)34);
	printf("02) Vrai PRINTF : |%hhu|\n", (unsigned char)-34);
	ft_printf("02) Mon PRINTF  : |%hhu|\n", (unsigned char)-34);
	printf("03) Vrai PRINTF : |%-hhu|\n", (unsigned char)50);
	ft_printf("03) Mon PRINTF  : |%-hhu|\n", (unsigned char)50);
	printf("04) Vrai PRINTF : |%10hhu|\n", (unsigned char)90);
	ft_printf("04) Mon PRINTF  : |%10hhu|\n", (unsigned char)90);
	printf("05) Vrai PRINTF : |%.10hhu|\n", (unsigned char)90);
	ft_printf("05) Mon PRINTF  : |%.10hhu|\n", (unsigned char)90);
	printf("06) Vrai PRINTF : |%15hhu|\n", (unsigned char)-100);
	ft_printf("06) Mon PRINTF  : |%15hhu|\n", (unsigned char)-100);
	printf("07) Vrai PRINTF : |%.15hhu|\n", (unsigned char)-100);
	ft_printf("07) Mon PRINTF  : |%.15hhu|\n", (unsigned char)-100);
	printf("08) Vrai PRINTF : |%10.5hhu|\n", (unsigned char)52);
	ft_printf("08) Mon PRINTF  : |%10.5hhu|\n", (unsigned char)52);
	printf("09) Vrai PRINTF : |%5.10hhu|\n", (unsigned char)52);
	ft_printf("09) Mon PRINTF  : |%5.10hhu|\n", (unsigned char)52);
	printf("10) Vrai PRINTF : |%20.15hhu|\n", (unsigned char)-100);
	ft_printf("10) Mon PRINTF  : |%20.15hhu|\n", (unsigned char)-100);
	printf("11) Vrai PRINTF : |%15.20hhu|\n", (unsigned char)-100);
	ft_printf("11) Mon PRINTF  : |%15.20hhu|\n", (unsigned char)-100);
	printf("12) Vrai PRINTF : |%-10hhu|\n", (unsigned char)144);
	ft_printf("12) Mon PRINTF  : |%-10hhu|\n", (unsigned char)144);
	printf("13) Vrai PRINTF : |%-.10hhu|\n", (unsigned char)144);
	ft_printf("13) Mon PRINTF  : |%-.10hhu|\n", (unsigned char)144);
	printf("14) Vrai PRINTF : |%-20hhu|\n", (unsigned char)-20);
	ft_printf("14) Mon PRINTF  : |%-20hhu|\n", (unsigned char)-20);
	printf("15) Vrai PRINTF : |%08hhu|\n", (unsigned char)64);
	ft_printf("15) Mon PRINTF  : |%08hhu|\n", (unsigned char)64);
	printf("16) Vrai PRINTF : |%03.4hhu|\n", (unsigned char)10);
	ft_printf("16) Mon PRINTF  : |%03.4hhu|\n", (unsigned char)10);
	printf("17) Vrai PRINTF : |%.hhu|\n", (unsigned char)0);
	ft_printf("17) Mon PRINTF  : |%.hhu|\n", (unsigned char)0);
	printf("18) Vrai PRINTF : |%.hhu|\n", (unsigned char)88);
	ft_printf("18) Mon PRINTF  : |%.hhu|\n", (unsigned char)88);
	printf("19) Vrai PRINTF : |%hhu|\n", (unsigned char)127);
	ft_printf("19) Mon PRINTF  : |%hhu|\n", (unsigned char)127);
	printf("20) Vrai PRINTF : |%hhu| |%hhu|\n", (unsigned char)-1, (unsigned char)128);
	ft_printf("20) Mon PRINTF  : |%hhu| |%hhu|\n", (unsigned char)-1, (unsigned char)128);
	ft_printf("--------------------%%lu--------------------\n");
	printf("01) Vrai PRINTF : |%lu|\n",(unsigned long)34);
	ft_printf("01) Mon PRINTF  : |%lu|\n", (unsigned long)34);
	printf("02) Vrai PRINTF : |%lu|\n", (unsigned long)-34);
	ft_printf("02) Mon PRINTF  : |%lu|\n", (unsigned long)-34);
	printf("03) Vrai PRINTF : |%-lu|\n", (unsigned long)50);
	ft_printf("03) Mon PRINTF  : |%-lu|\n", (unsigned long)50);
	printf("04) Vrai PRINTF : |%10lu|\n", (unsigned long)90);
	ft_printf("04) Mon PRINTF  : |%10lu|\n", (unsigned long)90);
	printf("05) Vrai PRINTF : |%.10lu|\n", (unsigned long)90);
	ft_printf("05) Mon PRINTF  : |%.10lu|\n", (unsigned long)90);
	printf("06) Vrai PRINTF : |%15lu|\n", (unsigned long)-100);
	ft_printf("06) Mon PRINTF  : |%15lu|\n", (unsigned long)-100);
	printf("07) Vrai PRINTF : |%.15lu|\n", (unsigned long)-100);
	ft_printf("07) Mon PRINTF  : |%.15lu|\n", (unsigned long)-100);
	printf("08) Vrai PRINTF : |%10.5lu|\n", (unsigned long)52);
	ft_printf("08) Mon PRINTF  : |%10.5lu|\n", (unsigned long)52);
	printf("09) Vrai PRINTF : |%5.10lu|\n", (unsigned long)52);
	ft_printf("09) Mon PRINTF  : |%5.10lu|\n", (unsigned long)52);
	printf("10) Vrai PRINTF : |%20.15lu|\n", (unsigned long)-100000);
	ft_printf("10) Mon PRINTF  : |%20.15lu|\n", (unsigned long)-100000);
	printf("11) Vrai PRINTF : |%15.20lu|\n", (unsigned long)-100000);
	ft_printf("11) Mon PRINTF  : |%15.20lu|\n", (unsigned long)-100000);
	printf("12) Vrai PRINTF : |%-10lu|\n", (unsigned long)144);
	ft_printf("12) Mon PRINTF  : |%-10lu|\n", (unsigned long)144);
	printf("13) Vrai PRINTF : |%-.10lu|\n", (unsigned long)144);
	ft_printf("13) Mon PRINTF  : |%-.10lu|\n", (unsigned long)144);
	printf("14) Vrai PRINTF : |%-20lu|\n", (unsigned long)-20000000);
	ft_printf("14) Mon PRINTF  : |%-20lu|\n", (unsigned long)-20000000);
	printf("15) Vrai PRINTF : |%08lu|\n", (unsigned long)64);
	ft_printf("15) Mon PRINTF  : |%08lu|\n", (unsigned long)64);
	printf("16) Vrai PRINTF : |%03.4lu|\n", (unsigned long)10);
	ft_printf("16) Mon PRINTF  : |%03.4lu|\n", (unsigned long)10);
	printf("17) Vrai PRINTF : |%.lu|\n", (unsigned long)0);
	ft_printf("17) Mon PRINTF  : |%.lu|\n", (unsigned long)0);
	printf("18) Vrai PRINTF : |%.lu|\n", (unsigned long)88);
	ft_printf("18) Mon PRINTF  : |%.lu|\n", (unsigned long)88);
	printf("19) Vrai PRINTF : |%lu|\n", (unsigned long)ULONG_MAX);
	ft_printf("19) Mon PRINTF  : |%lu|\n", (unsigned long)ULONG_MAX);
	printf("20) Vrai PRINTF : |%lu| |%lu|\n", (unsigned long)-1, (unsigned long)ULONG_MAX + 1);
	ft_printf("20) Mon PRINTF  : |%lu| |%lu|\n", (unsigned long)-1, (unsigned long)ULONG_MAX + 1);
	ft_printf("--------------------%%llu--------------------\n");
	printf("01) Vrai PRINTF : |%llu|\n",(unsigned long long)34);
	ft_printf("01) Mon PRINTF  : |%llu|\n", (unsigned long long)34);
	printf("02) Vrai PRINTF : |%llu|\n", (unsigned long long)-34);
	ft_printf("02) Mon PRINTF  : |%llu|\n", (unsigned long long)-34);
	printf("03) Vrai PRINTF : |%-llu|\n", (unsigned long long)50);
	ft_printf("03) Mon PRINTF  : |%-llu|\n", (unsigned long long)50);
	printf("04) Vrai PRINTF : |%10llu|\n", (unsigned long long)90);
	ft_printf("04) Mon PRINTF  : |%10llu|\n", (unsigned long long)90);
	printf("05) Vrai PRINTF : |%.10llu|\n", (unsigned long long)90);
	ft_printf("05) Mon PRINTF  : |%.10llu|\n", (unsigned long long)90);
	printf("06) Vrai PRINTF : |%15llu|\n", (unsigned long long)-100);
	ft_printf("06) Mon PRINTF  : |%15llu|\n", (unsigned long long)-100);
	printf("07) Vrai PRINTF : |%.15llu|\n", (unsigned long long)-100);
	ft_printf("07) Mon PRINTF  : |%.15llu|\n", (unsigned long long)-100);
	printf("08) Vrai PRINTF : |%10.5llu|\n", (unsigned long long)52);
	ft_printf("08) Mon PRINTF  : |%10.5llu|\n", (unsigned long long)52);
	printf("09) Vrai PRINTF : |%5.10llu|\n", (unsigned long long)52);
	ft_printf("09) Mon PRINTF  : |%5.10llu|\n", (unsigned long long)52);
	printf("10) Vrai PRINTF : |%20.15llu|\n", (unsigned long long)-100000);
	ft_printf("10) Mon PRINTF  : |%20.15llu|\n", (unsigned long long)-100000);
	printf("11) Vrai PRINTF : |%15.20llu|\n", (unsigned long long)-100000);
	ft_printf("11) Mon PRINTF  : |%15.20llu|\n", (unsigned long long)-100000);
	printf("12) Vrai PRINTF : |%-10llu|\n", (unsigned long long)144);
	ft_printf("12) Mon PRINTF  : |%-10llu|\n", (unsigned long long)144);
	printf("13) Vrai PRINTF : |%-.10llu|\n", (unsigned long long)144);
	ft_printf("13) Mon PRINTF  : |%-.10llu|\n", (unsigned long long)144);
	printf("14) Vrai PRINTF : |%-20llu|\n", (unsigned long long)-20000000);
	ft_printf("14) Mon PRINTF  : |%-20llu|\n", (unsigned long long)-20000000);
	printf("15) Vrai PRINTF : |%08llu|\n", (unsigned long long)64);
	ft_printf("15) Mon PRINTF  : |%08llu|\n", (unsigned long long)64);
	printf("16) Vrai PRINTF : |%03.4llu|\n", (unsigned long long)10);
	ft_printf("16) Mon PRINTF  : |%03.4llu|\n", (unsigned long long)10);
	// printf("17) Vrai PRINTF : |%.llu|\n", (unsigned long long)0);
	// ft_printf("17) Mon PRINTF  : |%.llu|\n", (unsigned long long)0);
	printf("18) Vrai PRINTF : |%.llu|\n", (unsigned long long)88);
	ft_printf("18) Mon PRINTF  : |%.llu|\n", (unsigned long long)88);
	printf("19) Vrai PRINTF : |%llu|\n", (unsigned long long)ULLONG_MAX);
	ft_printf("19) Mon PRINTF  : |%llu|\n", (unsigned long long)ULLONG_MAX);
	printf("20) Vrai PRINTF : |%llu| |%llu|\n", (unsigned long long)-1, (unsigned long long)ULLONG_MAX + 1);
	ft_printf("20) Mon PRINTF  : |%llu| |%llu|\n", (unsigned long long)-1, (unsigned long long)ULLONG_MAX + 1);
}

void rest(void)
{
	int		*tab = malloc(sizeof(int) * 10);
	int		*tab2 = malloc(0);
	
	ft_printf("--------------------%%p--------------------\n");			//perfect
	printf("%4.2s %-1.s\n" , "coco", NULL);
	ft_printf("%4.2s %-1.s\n" , "coco", NULL);
	ft_printf("--------------------%%p--------------------\n");			//perfect
	printf("Coucou %.0s\n%s%---12s\n", "hi", "coco", NULL);
	ft_printf("Coucou %.0s\n%s%---12s\n", "hi", "coco", NULL);
	ft_printf("--------------------%%p--------------------\n");			//perfect
	printf("test %-7C %007d%-10.2ls!!\n", 0xd777, 0x45, "L〻");
	// ft_printf("test %-7C %007d%-10.2ls!!\n", 0xd777, 0x45, "L〻");
	ft_printf("--------------------%%p--------------------\n");			//perfect
	printf("%+%\n");
	ft_printf("%+%\n");
	ft_printf("--------------------%%p--------------------\n");			//perfect
	printf("titi % +---12.5% et%%%0004% et %+1%\n");
	ft_printf("titi % +---12.5% et%%%0004% et %+1%\n");
	ft_printf("--------------------%%p--------------------\n");			//perfect
	printf("|%1.4s| et |%-6.8s| et |%4.2s|\n", "tuuu", "12345", "hu");
	ft_printf("|%1.4s| et |%-6.8s| et |%4.2s|\n", "tuuu", "12345", "hu");
	ft_printf("--------------------%%p--------------------\n");			//perfect
	printf("hello ca%----4c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0);
	ft_printf("hello ca%----4c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0);
	ft_printf("--------------------%%p--------------------\n");			//perfect
	printf("01) Vrai PRINTF : |%p|\n", "salut");
	ft_printf("01) Mon PRINTF  : |%p|\n", "salut");
	printf("02) Vrai PRINTF : |%-p|\n", tab2);
	ft_printf("02) Mon PRINTF  : |%-p|\n", tab2);
	printf("03) Vrai PRINTF : |%---------p|\n", "test2");
	ft_printf("03) Mon PRINTF  : |%----------p|\n", "test2");
	printf("04) Vrai PRINTF : |%10p|\n", "42");
	ft_printf("04) Mon PRINTF  : |%10p|\n", "42");
	printf("05) Vrai PRINTF : |%-10p|\n", "42");
	ft_printf("05) Mon PRINTF  : |%-10p|\n", "42");
	printf("06) Vrai PRINTF : |%2p|\n", tab);
	ft_printf("06) Mon PRINTF  : |%2p|\n", tab);
	printf("07) Vrai PRINTF : |%-2p|\n", tab);
	ft_printf("07) Mon PRINTF  : |%-2p|\n", tab);
	printf("11) Vrai PRINTF : |%p|\n", "\0\0\0\0\0");
	ft_printf("11) Mon PRINTF  : |%p|\n", "\0\0\0\0\0");
	printf("12) Vrai PRINTF : |%20p|\n", "\0\0\0\0\0");
	ft_printf("12) Mon PRINTF  : |%20p|\n", "\0\0\0\0\0");
	printf("13) Vrai PRINTF : |%p|\n", "");
	ft_printf("13) Mon PRINTF  : |%p|\n", "");
	printf("14) Vrai PRINTF : |%p|\n", NULL);
	ft_printf("14) Mon PRINTF  : |%p|\n", NULL);
	printf("15) Vrai PRINTF : |%10p|\n", NULL);
	ft_printf("15) Mon PRINTF  : |%10p|\n", NULL);
	printf("16) Vrai PRINTF : |%-10p|\n", NULL);
	ft_printf("16) Mon PRINTF  : |%-10p|\n", NULL);
	free(tab);
	free(tab2);
}
*/
void s(void)
{
ft_printf("--------------------%%s--------------------\n");			//Perfect
	printf("01) Vrai PRINTF : |%s|\n", "salut");
	ft_printf("01) Mon PRINTF  : |%s|\n", "salut");
	printf("02) Vrai PRINTF : |%-s|\n", "test");
	ft_printf("02) Mon PRINTF  : |%-s|\n", "test");
	printf("03) Vrai PRINTF : |%---------s|\n", "test2");
	ft_printf("03) Mon PRINTF  : |%----------s|\n", "test2");
	printf("04) Vrai PRINTF : |%10s|\n", "42");
	ft_printf("04) Mon PRINTF  : |%10s|\n", "42");
	printf("05) Vrai PRINTF : |%-10s|\n", "42");
	ft_printf("05) Mon PRINTF  : |%-10s|\n", "42");
	printf("06) Vrai PRINTF : |%2s|\n", "string");
	ft_printf("06) Mon PRINTF  : |%2s|\n", "string");
	printf("07) Vrai PRINTF : |%-2s|\n", "string");
	ft_printf("07) Mon PRINTF  : |%-2s|\n", "string");
	printf("08) Vrai PRINTF : |%.15s|\n", "precision");
	ft_printf("08) Mon PRINTF  : |%.15s|\n", "precision");
	printf("09) Vrai PRINTF : |%.4s|\n", "precision");
	ft_printf("09) Mon PRINTF  : |%.4s|\n", "precision");
	printf("10) Vrai PRINTF : |%.0s|\n", "precision");
	ft_printf("10) Mon PRINTF  : |%.0s|\n", "precision");
	printf("11) Vrai PRINTF : |%s|\n", "\0\0\0\0\0");
	ft_printf("11) Mon PRINTF  : |%s|\n", "\0\0\0\0\0");
	printf("12) Vrai PRINTF : |%10s|\n", "\0\0\0\0\0");
	ft_printf("12) Mon PRINTF  : |%10s|\n", "\0\0\0\0\0");
	printf("13) Vrai PRINTF : |%s|\n", "");
	ft_printf("13) Mon PRINTF  : |%s|\n", "");
	printf("14) Vrai PRINTF : |%-.2s|\n", "boom");
	ft_printf("14) Mon PRINTF  : |%-.2s|\n", "boom");
	printf("15) Vrai PRINTF : |%10.8s|\n", "google");
	ft_printf("15) Mon PRINTF  : |%10.8s|\n", "google");
	printf("16) Vrai PRINTF : |%10.2s|\n", "twitter");
	ft_printf("16) Mon PRINTF  : |%10.2s|\n", "twitter");
	printf("17) Vrai PRINTF : |%2.10s|\n", "samsung");
	ft_printf("17) Mon PRINTF  : |%2.10s|\n", "samsung");
	printf("18) Vrai PRINTF : |%2.5s|\n", "printf");
	ft_printf("18) Mon PRINTF  : |%2.5s|\n", "printf");
	printf("19) Vrai PRINTF : |%-10.2s|\n", "424242424242");
	ft_printf("19) Mon PRINTF  : |%-10.2s|\n", "424242424242");
	printf("20) Vrai PRINTF : |%1.0s|\n", "123456789");
	ft_printf("20) Mon PRINTF  : |%1.0s|\n", "123456789");
	printf("20) Vrai PRINTF : |%-1.0s|\n", "123456789");
	ft_printf("20) Mon PRINTF  : |%-1.0s|\n", "123456789");
	printf("21) Vrai PRINTF : |%s|\n", NULL);
	ft_printf("21) Mon PRINTF  : |%s|\n", NULL);
	printf("22) Vrai PRINTF : |%10s|\n", NULL);
	ft_printf("22) Mon PRINTF  : |%10s|\n", NULL);
	printf("23) Vrai PRINTF : |%-10s|\n", NULL);
	ft_printf("23) Mon PRINTF  : |%-10s|\n", NULL);
	printf("24) Vrai PRINTF : |%.2s|\n", NULL);
	ft_printf("24) Mon PRINTF  : |%.2s|\n", NULL);
	printf("25) Vrai PRINTF : |%10.8s|\n", NULL);
	ft_printf("25) Mon PRINTF  : |%10.8s|\n", NULL);
	printf("26) Vrai PRINTF : |%10.2s|\n", NULL);
	ft_printf("26) Mon PRINTF  : |%10.2s|\n", NULL);
	printf("27) Vrai PRINTF : |%2.10s|\n", NULL);
	ft_printf("27) Mon PRINTF  : |%2.10s|\n", NULL);
	printf("28) Vrai PRINTF : |%2.5s|\n", NULL);
	ft_printf("28) Mon PRINTF  : |%2.5s|\n", NULL);
	printf("29) Vrai PRINTF : |%-10.2s|\n", NULL);
	ft_printf("29) Mon PRINTF  : |%-10.2s|\n", NULL);
	printf("30) Vrai PRINTF : |%1.0s|\n", NULL);
	ft_printf("30) Mon PRINTF  : |%1.0s|\n", NULL);
	printf("31) Vrai PRINTF : |%-1.s|\n", NULL);
	ft_printf("31) Mon PRINTF  : |%-1.s|\n", NULL);	
}

void c(void)
{
ft_printf("--------------------%%c--------------------\n");		//Perfect
	printf("01) Vrai PRINTF : |%c|\n", 'a');
	ft_printf("01) Mon PRINTF  : |%c|\n", 'a');
	printf("02) Vrai PRINTF : |%-c|\n", 'z');
	ft_printf("02) Mon PRINTF  : |%-c|\n", 'z');
	printf("03) Vrai PRINTF : |%-----c|\n", '!');
	ft_printf("03) Mon PRINTF  : |%-----c|\n", '!');
	printf("04) Vrai PRINTF : |%5c|\n", 'R');
	ft_printf("04) Mon PRINTF  : |%5c|\n", 'R');
	printf("05) Vrai PRINTF : |%-5c|\n", 'R');
	ft_printf("05) Mon PRINTF  : |%-5c|\n", 'R');
	printf("06) Vrai PRINTF : |%1c|\n", '3');
	ft_printf("06) Mon PRINTF  : |%1c|\n", '3');
	printf("07) Vrai PRINTF : |%c|\n", '\0');
	ft_printf("07) Mon PRINTF  : |%c|\n", '\0');
	printf("08) Vrai PRINTF : |%5c|\n", '\0');
	ft_printf("08) Mon PRINTF  : |%5c|\n", '\0');
	printf("09) Vrai PRINTF : |%-5c|\n", '\0');
	ft_printf("09) Mon PRINTF  : |%-5c|\n", '\0');
	printf("10) Vrai PRINTF : |%1c|\n", '\0');
	ft_printf("10} Mon PRINTF  : |%1c|\n", '\0');
}

int		main(void)
{

# 0012 (int)
  ft_printf("%x", 42);
  1. (    1) -->x<--
  2. (    2) -->2a<--

# 0013 (int)
  ft_printf("%X", 42);
  1. (    1) -->X<--
  2. (    2) -->2A<--

# 0014 (int)
  ft_printf("%x", 0);
  1. (    1) -->x<--
  2. (    1) -->0<--

# 0015 (int)
  ft_printf("%X", 0);
  1. (    1) -->X<--
  2. (    1) -->0<--

# 0016 (int)
  ft_printf("%x", -42);
  1. (    1) -->x<--
  2. (    8) -->ffffffd6<--

# 0017 (int)
  ft_printf("%X", -42);
  1. (    1) -->X<--
  2. (    8) -->FFFFFFD6<--

# 0018 (int)
  ft_printf("%x", 4294967296);
  1. (    1) -->x<--
  2. (    1) -->0<--

# 0019 (int)
  ft_printf("%X", 4294967296);
  1. (    1) -->X<--
  2. (    1) -->0<--

# 0020 (int)
  ft_printf("%x", test);
  1. (    1) -->x<--
  2. (    1) -->0<--

# 0021 (int)
  ft_printf("%10x", 42);
  1. (   10) -->         x<--
  2. (   10) -->        2a<--

# 0022 (int)
  ft_printf("%-10x", 42);
  1. (   10) -->x         <--
  2. (   10) -->2a        <--

# 0023 (int)
  ft_printf("%lx", 4294967296);
  1. (    2) -->lx<--
  2. (    9) -->100000000<--

# 0024 (int)
  ft_printf("%llX", 4294967296);
  1. (    3) -->llX<--
  2. (    9) -->100000000<--

# 0025 (int)
  ft_printf("%hx", 4294967296);
  1. (    2) -->hx<--
  2. (    1) -->0<--

# 0026 (int)
  ft_printf("%hhX", 4294967296);
  1. (    3) -->hhX<--
  2. (    1) -->0<--

# 0027 (int)
  ft_printf("%llx", 9223372036854775807);
  1. (    3) -->llx<--
  2. (   16) -->7fffffffffffffff<--

# 0028 (int)
  ft_printf("%llx", 9223372036854775808);
  1. (    3) -->llx<--
  2. (   16) -->7fffffffffffffff<--

# 0029 (int)
  ft_printf("%010x", 542);
  1. (   10) -->000000000x<--
  2. (   10) -->000000021e<--

# 0030 (int)
  ft_printf("%-15x", 542);
  1. (   15) -->x              <--
  2. (   15) -->21e            <--

# 0031 (int)
  ft_printf("%2x", 542);
  1. (    2) --> x<--
  2. (    3) -->21e<--

# 0032 (int)
  ft_printf("%.2x", 5427);
  1. (    2) --> x<--
  2. (    4) -->1533<--

# 0033 (int)
  ft_printf("%5.2x", 5427);
  1. (    2) --> x<--
  2. (    5) --> 1533<--

# 0034 (int)
  ft_printf("%#x", 42);
  1. (    1) -->x<--
  2. (    4) -->0x2a<--

# 0035 (int)
  ft_printf("%#llx", 9223372036854775807);
  1. (    3) -->llx<--
  2. (   18) -->0x7fffffffffffffff<--

# 0036 (int)
  ft_printf("%#x", 0);
  1. (    1) -->x<--
  2. (    1) -->0<--

# 0037 (int)
  ft_printf("%#x", 42);
  1. (    1) -->x<--
  2. (    4) -->0x2a<--

# 0038 (int)
  ft_printf("%#X", 42);
  1. (    1) -->X<--
  2. (    4) -->0X2A<--

# 0039 (int)
  ft_printf("%#8x", 42);
  1. (    8) -->       x<--
  2. (    8) -->    0x2a<--

# 0040 (int)
  ft_printf("%#08x", 42);
  1. (    8) -->0000000x<--
  2. (    8) -->0x00002a<--

# 0041 (int)
  ft_printf("%#-08x", 42);
  1. (    8) -->x0000000<--
  2. (    8) -->0x2a    <--

# 0042 (int)
  ft_printf("@moulitest: %#.x %#.0x", 0, 0);
  1. (   15) -->@moulitest: x x<--
  2. (   13) -->@moulitest:  <--

# 0043 (int)
  ft_printf("@moulitest: %.x %.0x", 0, 0);
  1. (   15) -->@moulitest: x x<--
  2. (   13) -->@moulitest:  <--

# 0044 (int)
  ft_printf("@moulitest: %5.x %5.0x", 0, 0);
  1. (   19) -->@moulitest:     x x<--
  2. (   23) -->@moulitest:            <--

# 0045 (char *)
  ft_printf("%s", "abc");
  1. (    1) -->s<--
  2. (    3) -->abc<--

# 0046 (char *)
  ft_printf("%s", "this is a string");
  1. (    1) -->s<--
  2. (   16) -->this is a string<--

# 0047 (char *)
  ft_printf("%s ", "this is a string");
  1. (    2) -->s <--
  2. (   17) -->this is a string <--

# 0048 (char *)
  ft_printf("%s  ", "this is a string");
  1. (    3) -->s  <--
  2. (   18) -->this is a string  <--

# 0049 (char *)
  ft_printf("this is a %s", "string");
  1. (   11) -->this is a s<--
  2. (   16) -->this is a string<--

# 0050 (char *)
  ft_printf("%s is a string", "this");
  1. (   13) -->s is a string<--
  2. (   16) -->this is a string<--

# 0051 (char *)
  ft_printf("Line Feed %s", "\n");
  1. (   11) -->Line Feed s<--
  2. (   11) -->Line Feed $\n<--

# 0052 (char *)
  ft_printf("%10s is a string", "this");
  1. (   13) -->s is a string<--
  2. (   22) -->      this is a string<--

# 0053 (char *)
  ft_printf("%.2s is a string", "this");
  1. (   13) -->s is a string<--
  2. (   14) -->th is a string<--

# 0054 (char *)
  ft_printf("%5.2s is a string", "this");
  1. (   13) -->s is a string<--
  2. (   17) -->   th is a string<--

# 0055 (char *)
  ft_printf("%10s is a string", "");
  1. (   13) -->s is a string<--
  2. (   22) -->           is a string<--

# 0056 (char *)
  ft_printf("%.2s is a string", "");
  1. (   13) -->s is a string<--
  2. (   12) --> is a string<--

# 0057 (char *)
  ft_printf("%5.2s is a string", "");
  1. (   13) -->s is a string<--
  2. (   17) -->      is a string<--

# 0058 (char *)
  ft_printf("%-10s is a string", "this");
  1. (   13) -->s is a string<--
  2. (   22) -->this       is a string<--

# 0059 (char *)
  ft_printf("%-.2s is a string", "this");
  1. (   13) -->s is a string<--
  2. (   14) -->th is a string<--

# 0060 (char *)
  ft_printf("%-5.2s is a string", "this");
  1. (   13) -->s is a string<--
  2. (   17) -->th    is a string<--

# 0061 (char *)
  ft_printf("%-10s is a string", "");
  1. (   13) -->s is a string<--
  2. (   22) -->           is a string<--

# 0062 (char *)
  ft_printf("%-.2s is a string", "");
  1. (   13) -->s is a string<--
  2. (   12) --> is a string<--

# 0063 (char *)
  ft_printf("%-5.2s is a string", "");
  1. (   13) -->s is a string<--
  2. (   17) -->      is a string<--

# 0064 (char *)
  ft_printf("%s %s", "this", "is");
  1. (    3) -->s s<--
  2. (    7) -->this is<--

# 0065 (char *)
  ft_printf("%s %s %s", "this", "is", "a");
  1. (    5) -->s s s<--
  2. (    9) -->this is a<--

# 0066 (char *)
  ft_printf("%s %s %s %s", "this", "is", "a", "multi");
  1. (    7) -->s s s s<--
  2. (   15) -->this is a multi<--

# 0067 (char *)
  ft_printf("%s %s %s %s string. gg!", "this", "is", "a", "multi", "string");
  1. (   19) -->s s s s string. gg!<--
  2. (   27) -->this is a multi string. gg!<--

# 0068 (char *)
  ft_printf("%s%s%s%s%s", "this", "is", "a", "multi", "string");
  1. (    5) -->sssss<--
  2. (   18) -->thisisamultistring<--

# 0069 (NULL)
  ft_printf("@moulitest: %s", NULL);
  1. (   13) -->@moulitest: s<--
  2. (   18) -->@moulitest: (null)<--

# 0070 (NULL)
  ft_printf("%.2c", NULL);
  1. (    2) --> ^@<--
  2. (    1) -->^@<--

# 0071 (NULL)
  ft_printf("%s %s", NULL, string);
  1. (    3) -->s s<--
  2. (   13) -->(null) string<--

# 0079 (int)
  ft_printf("%o", 40);
  1. (    1) -->o<--
  2. (    2) -->50<--

# 0080 (int)
  ft_printf("%5o", 41);
  1. (    5) -->    o<--
  2. (    5) -->   51<--

# 0081 (int)
  ft_printf("%05o", 42);
  1. (    5) -->0000o<--
  2. (    5) -->00052<--

# 0082 (int)
  ft_printf("%-5o", 2500);
  1. (    5) -->o    <--
  2. (    5) -->4704 <--

# 0083 (int)
  ft_printf("%#6o", 2500);
  1. (    6) -->     o<--
  2. (    6) --> 04704<--

# 0084 (int)
  ft_printf("%-#6o", 2500);
  1. (    6) -->o     <--
  2. (    6) -->04704 <--

# 0085 (int)
  ft_printf("%-05o", 2500);
  1. (    5) -->o0000<--
  2. (    5) -->4704 <--

# 0086 (int)
  ft_printf("%-5.10o", 2500);
  1. (   10) -->o         <--
  2. (   10) -->0000004704<--

# 0087 (int)
  ft_printf("%-10.5o", 2500);
  1. (    5) -->o    <--
  2. (   10) -->04704     <--

# 0088 (int)
  ft_printf("@moulitest: %o", 0);
  1. (   13) -->@moulitest: o<--
  2. (   13) -->@moulitest: 0<--

# 0089 (int)
  ft_printf("@moulitest: %.o %.0o", 0, 0);
  1. (   15) -->@moulitest: o o<--
  2. (   13) -->@moulitest:  <--

# 0090 (int)
  ft_printf("@moulitest: %5.o %5.0o", 0, 0);
  1. (   19) -->@moulitest:     o o<--
  2. (   23) -->@moulitest:            <--

# 0091 (int)
  ft_printf("@moulitest: %#.o %#.0o", 0, 0);
  1. (   15) -->@moulitest: o o<--
  2. (   15) -->@moulitest: 0 0<--

# 0092 (int)
  ft_printf("@moulitest: %.10o", 42);
  1. (   22) -->@moulitest:          o<--
  2. (   22) -->@moulitest: 0000000052<--

# 0093 (int)
  ft_printf("%d", 1);
  1. (    1) -->d<--
  2. (    1) -->1<--

# 0094 (int)
  ft_printf("the %d", 1);
  1. (    5) -->the d<--
  2. (    5) -->the 1<--

# 0095 (int)
  ft_printf("%d is one", 1);
  1. (    8) -->d is one<--
  2. (    8) -->1 is one<--

# 0096 (int)
  ft_printf("%d", -1);
  1. (    1) -->d<--
  2. (    2) -->-1<--

# 0097 (int)
  ft_printf("%d", 4242);
  1. (    1) -->d<--
  2. (    4) -->4242<--

# 0098 (int)
  ft_printf("%d", -4242);
  1. (    1) -->d<--
  2. (    5) -->-4242<--

# 0099 (int)
  ft_printf("%d", 2147483647);
  1. (    1) -->d<--
  2. (   10) -->2147483647<--

# 0100 (int)
  ft_printf("%d", 2147483648);
  1. (    1) -->d<--
  2. (   11) -->-2147483648<--

# 0101 (int)
  ft_printf("%d", -2147483648);
  1. (    1) -->d<--
  2. (   11) -->-2147483648<--

# 0102 (int)
  ft_printf("%d", -2147483649);
  1. (    1) -->d<--
  2. (   10) -->2147483647<--

# 0103 (int)
  ft_printf("% d", 42);
  1. (    1) -->d<--
  2. (    3) --> 42<--

# 0104 (int)
  ft_printf("% d", -42);
  1. (    1) -->d<--
  2. (    3) -->-42<--

# 0105 (int)
  ft_printf("%+d", 42);
  1. (    1) -->d<--
  2. (    3) -->+42<--

# 0106 (int)
  ft_printf("%+d", -42);
  1. (    1) -->d<--
  2. (    3) -->-42<--

# 0107 (int)
  ft_printf("%+d", 0);
  1. (    1) -->d<--
  2. (    2) -->+0<--

# 0108 (int)
  ft_printf("%+d", 4242424242424242424242);
  1. (    1) -->d<--
  2. (    2) -->-1<--

# 0109 (int)
  ft_printf("% +d", 42);
  1. (    1) -->d<--
  2. (    3) -->+42<--

# 0110 (int)
  ft_printf("% +d", -42);
  1. (    1) -->d<--
  2. (    3) -->-42<--

# 0111 (int)
  ft_printf("%+ d", 42);
  1. (    1) -->d<--
  2. (    3) -->+42<--

# 0112 (int)
  ft_printf("%+ d", -42);
  1. (    1) -->d<--
  2. (    3) -->-42<--

# 0113 (int)
  ft_printf("%  +d", 42);
  1. (    1) -->d<--
  2. (    3) -->+42<--

# 0114 (int)
  ft_printf("%  +d", -42);
  1. (    1) -->d<--
  2. (    3) -->-42<--

# 0115 (int)
  ft_printf("%+  d", 42);
  1. (    1) -->d<--
  2. (    3) -->+42<--

# 0116 (int)
  ft_printf("%+  d", -42);
  1. (    1) -->d<--
  2. (    3) -->-42<--

# 0117 (int)
  ft_printf("% ++d", 42);
  1. (    1) -->d<--
  2. (    3) -->+42<--

# 0118 (int)
  ft_printf("% ++d", -42);
  1. (    1) -->d<--
  2. (    3) -->-42<--

# 0119 (int)
  ft_printf("%++ d", 42);
  1. (    1) -->d<--
  2. (    3) -->+42<--

# 0120 (int)
  ft_printf("%++ d", -42);
  1. (    1) -->d<--
  2. (    3) -->-42<--

# 0121 (int)
  ft_printf("%0d", -42);
  1. (    1) -->d<--
  2. (    3) -->-42<--

# 0122 (int)
  ft_printf("%00d", -42);
  1. (    1) -->d<--
  2. (    3) -->-42<--

# 0123 (int)
  ft_printf("%5d", 42);
  1. (    5) -->    d<--
  2. (    5) -->   42<--

# 0124 (int)
  ft_printf("%05d", 42);
  1. (    5) -->0000d<--
  2. (    5) -->00042<--

# 0125 (int)
  ft_printf("%0+5d", 42);
  1. (    5) -->0000d<--
  2. (    5) -->+0042<--

# 0126 (int)
  ft_printf("%5d", -42);
  1. (    5) -->    d<--
  2. (    5) -->  -42<--

# 0127 (int)
  ft_printf("%05d", -42);
  1. (    5) -->0000d<--
  2. (    5) -->-0042<--

# 0128 (int)
  ft_printf("%0+5d", -42);
  1. (    5) -->0000d<--
  2. (    5) -->-0042<--

# 0129 (int)
  ft_printf("%-5d", 42);
  1. (    5) -->d    <--
  2. (    5) -->42   <--

# 0130 (int)
  ft_printf("%-05d", 42);
  1. (    5) -->d0000<--
  2. (    5) -->42   <--

# 0131 (int)
  ft_printf("%-5d", -42);
  1. (    5) -->d    <--
  2. (    5) -->-42  <--

# 0132 (int)
  ft_printf("%-05d", -42);
  1. (    5) -->d0000<--
  2. (    5) -->-42  <--

# 0133 (short)
  ft_printf("%hd", 32767);
  1. (    2) -->hd<--
  2. (    5) -->32767<--

# 0134 (short)
  ft_printf("%hd", −32768);
  1. (    2) -->hd<--
  2. (    1) -->0<--

# 0135 (short)
  ft_printf("%hd", 32768);
  1. (    2) -->hd<--
  2. (    6) -->-32768<--

# 0136 (short)
  ft_printf("%hd", −32769);
  1. (    2) -->hd<--
  2. (    1) -->0<--

# 0137 (signed char)
  ft_printf("%hhd", 127);
  1. (    3) -->hhd<--
  2. (    3) -->127<--

# 0138 (signed char)
  ft_printf("%hhd", 128);
  1. (    3) -->hhd<--
  2. (    4) -->-128<--

# 0139 (signed char)
  ft_printf("%hhd", -128);
  1. (    3) -->hhd<--
  2. (    4) -->-128<--

# 0140 (signed char)
  ft_printf("%hhd", -129);
  1. (    3) -->hhd<--
  2. (    3) -->127<--

# 0141 (long)
  ft_printf("%ld", 2147483647);
  1. (    2) -->ld<--
  2. (   10) -->2147483647<--

# 0142 (long)
  ft_printf("%ld", -2147483648);
  1. (    2) -->ld<--
  2. (   11) -->-2147483648<--

# 0143 (long)
  ft_printf("%ld", 2147483648);
  1. (    2) -->ld<--
  2. (   10) -->2147483648<--

# 0144 (long)
  ft_printf("%ld", -2147483649);
  1. (    2) -->ld<--
  2. (   11) -->-2147483649<--

# 0145 (long long)
  ft_printf("%lld", 9223372036854775807);
  1. (    3) -->lld<--
  2. (   19) -->9223372036854775807<--

# 0146 (long long)
  ft_printf("%lld", -9223372036854775808);
  1. (    3) -->lld<--
  2. (   20) -->-9223372036854775808<--

# 0147 (int)
  ft_printf("%d", 1);
  1. (    1) -->d<--
  2. (    1) -->1<--

# 0148 (int)
  ft_printf("%d %d", 1, -2);
  1. (    3) -->d d<--
  2. (    4) -->1 -2<--

# 0149 (int)
  ft_printf("%d %d %d", 1, -2, 33);
  1. (    5) -->d d d<--
  2. (    7) -->1 -2 33<--

# 0150 (int)
  ft_printf("%d %d %d %d", 1, -2, 33, 42);
  1. (    7) -->d d d d<--
  2. (   10) -->1 -2 33 42<--

# 0151 (int)
  ft_printf("%d %d %d %d gg!", 1, -2, 33, 42, 0);
  1. (   11) -->d d d d gg!<--
  2. (   14) -->1 -2 33 42 gg!<--

# 0152 (int)
  ft_printf("%4.15d", 42);
  1. (   15) -->              d<--
  2. (   15) -->000000000000042<--

# 0153 (int)
  ft_printf("%.2d", 4242);
  1. (    2) --> d<--
  2. (    4) -->4242<--

# 0154 (int)
  ft_printf("%.10d", 4242);
  1. (   10) -->         d<--
  2. (   10) -->0000004242<--

# 0155 (int)
  ft_printf("%10.5d", 4242);
  1. (    5) -->    d<--
  2. (   10) -->     04242<--

# 0156 (int)
  ft_printf("%-10.5d", 4242);
  1. (    5) -->d    <--
  2. (   10) -->04242     <--

# 0157 (int)
  ft_printf("% 10.5d", 4242);
  1. (    5) -->    d<--
  2. (   10) -->     04242<--

# 0158 (int)
  ft_printf("%+10.5d", 4242);
  1. (    5) -->    d<--
  2. (   10) -->    +04242<--

# 0159 (int)
  ft_printf("%-+10.5d", 4242);
  1. (    5) -->d    <--
  2. (   10) -->+04242    <--

# 0160 (int)
  ft_printf("%03.2d", 0);
  1. (    2) -->0d<--
  2. (    3) --> 00<--

# 0161 (int)
  ft_printf("%03.2d", 1);
  1. (    2) -->0d<--
  2. (    3) --> 01<--

# 0162 (int)
  ft_printf("%03.2d", -1);
  1. (    2) -->0d<--
  2. (    3) -->-01<--

# 0163 (int)
  ft_printf("@moulitest: %.10d", -42);
  1. (   22) -->@moulitest:          d<--
  2. (   23) -->@moulitest: -0000000042<--

# 0164 (int)
  ft_printf("@moulitest: %.d %.0d", 42, 43);
  1. (   15) -->@moulitest: d d<--
  2. (   17) -->@moulitest: 42 43<--

# 0165 (int)
  ft_printf("@moulitest: %.d %.0d", 0, 0);
  1. (   15) -->@moulitest: d d<--
  2. (   13) -->@moulitest:  <--

# 0166 (int)
  ft_printf("@moulitest: %5.d %5.0d", 0, 0);
  1. (   19) -->@moulitest:     d d<--
  2. (   23) -->@moulitest:            <--

# 0167 (unsigned int)
  ft_printf("%u", 0);
  1. (    1) -->u<--
  2. (    1) -->0<--

# 0168 (unsigned int)
  ft_printf("%u", 1);
  1. (    1) -->u<--
  2. (    1) -->1<--

# 0169 (unsigned int)
  ft_printf("%u", -1);
  1. (    1) -->u<--
  2. (   10) -->4294967295<--

# 0170 (unsigned int)
  ft_printf("%u", 4294967295);
  1. (    1) -->u<--
  2. (   10) -->4294967295<--

# 0171 (unsigned int)
  ft_printf("%u", 4294967296);
  1. (    1) -->u<--
  2. (    1) -->0<--

# 0172 (unsigned int)
  ft_printf("%5u", 4294967295);
  1. (    5) -->    u<--
  2. (   10) -->4294967295<--

# 0173 (unsigned int)
  ft_printf("%15u", 4294967295);
  1. (   15) -->              u<--
  2. (   15) -->     4294967295<--

# 0174 (unsigned int)
  ft_printf("%-15u", 4294967295);
  1. (   15) -->u              <--
  2. (   15) -->4294967295     <--

# 0175 (unsigned int)
  ft_printf("%015u", 4294967295);
  1. (   15) -->00000000000000u<--
  2. (   15) -->000004294967295<--

# 0176 (unsigned int)
  ft_printf("% u", 4294967295);
  1. (    1) -->u<--
  2. (   10) -->4294967295<--

# 0177 (unsigned int)
  ft_printf("%+u", 4294967295);
  1. (    1) -->u<--
  2. (   10) -->4294967295<--

# 0178 (unsigned long)
  ft_printf("%lu", 4294967295);
  1. (    2) -->lu<--
  2. (   10) -->4294967295<--

# 0179 (unsigned long)
  ft_printf("%lu", 4294967296);
  1. (    2) -->lu<--
  2. (   10) -->4294967296<--

# 0180 (unsigned long)
  ft_printf("%lu", -42);
  1. (    2) -->lu<--
  2. (   20) -->18446744073709551574<--

# 0181 (unsigned long long)
  ft_printf("%llu", 4999999999);
  1. (    3) -->llu<--
  2. (   10) -->4999999999<--

# 0182 (unsigned int)
  ft_printf("@moulitest: %.5u", 42);
  1. (   17) -->@moulitest:     u<--
  2. (   17) -->@moulitest: 00042<--
	return (0);
}