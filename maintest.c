/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:17:21 by lgaultie          #+#    #+#             */
/*   Updated: 2020/02/25 11:17:46 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include "include/ft_printf.h"

#define TEST(FMT,...)													\
	printf("Vrai PRINTF ");pf = printf(FMT,##__VA_ARGS__);						\
	ft_printf(" Mon PRINTF ");ft = ft_printf(FMT,##__VA_ARGS__);					\
	if (ft != pf)														\
	{	dprintf(2, "Fail : return value Real(%i vs %i)Yours\n", pf, ft);\
		}\

// #include "libft.h"

//leak de %-----s corrigé en mettant un free dans ft_minus....
// printf("18) Vrai PRINTF : |%.u|\n", 0);
// 

void	x(pf,ft)
{
printf("--------------------%%x--------------------\n");
	TEST("0.1) Vrai PRINTF : |%#08x|\n", 42);
	TEST("0.2)@moulitest: |%5.x. .%5.0x.|\n", 0, 0);
	TEST("01) Vrai PRINTF : |%x|\n", 34);
	TEST("02) Vrai PRINTF :25 |%x|\n", -34);
	TEST("03) Vrai PRINTF : |%-x|\n", 50);
	TEST("04) Vrai PRINTF : |%10x|\n", 90);
	TEST("05) Vrai PRINTF : |%.10x|\n", 90);
	TEST("05.2) Vrai PRINTF : |%#.10x|\n", 90);
	TEST("06) Vrai PRINTF : |%15x|\n", -100);
	TEST("07) Vrai PRINTF : |%.15x|\n", -100);
	TEST("08) Vrai PRINTF : |%10.5x|\n", 52);
	TEST("09) Vrai PRINTF : |%5.10x|\n", 52);
	TEST("10) Vrai PRINTF : |%20.15x|\n", -100000);
	TEST("11) Vrai PRINTF : |%15.20x|\n", -100000);
	TEST("12) Vrai PRINTF : |%-10x|\n", 144);
	TEST("13) Vrai PRINTF : |%-.10x|\n", 144);
	TEST("14) Vrai PRINTF : |%-20x|\n", -20000000);
	TEST("15) Vrai PRINTF : |%08x|\n", 64);
	TEST("16) Vrai PRINTF : |%03.4x|\n", 10);
	TEST("17) Vrai PRINTF : |%#x|\n", 34);
	TEST("18) Vrai PRINTF : |%#.5x|\n", 34);
	TEST("19) Vrai PRINTF : |%#5x|\n", 86);
	
	TEST("20) Vrai PRINTF : |%#10.5x|\n", 70);
	
	TEST("21.0) Vrai PRINTF : |%#10x|\n", 0);
	
	TEST("21) Vrai PRINTF : |%#x|\n", 0);
	
	TEST("22) Vrai PRINTF : |%#.x|\n", 0);
	TEST("23) Vrai PRINTF : |%.x|\n", 0);
		
	TEST("24) Vrai PRINTF : |%.x|\n", 88);
	TEST("25) Vrai PRINTF : |%#.x|\n", 88);
	
	TEST("26) Vrai PRINTF : |%x|\n", UINT_MAX);
	TEST("27) Vrai PRINTF : |%#x|\n", UINT_MAX);
	TEST("28) Vrai PRINTF : |%#x| |%#x|\n", (unsigned int)-1, UINT_MAX + 1);
	TEST("29) Vrai PRINTF : |%x| |%x|\n", (unsigned int)-1, UINT_MAX + 1);
	printf("---------------------%%hx--------------------\n");
	TEST("01) Vrai PRINTF : |%hx|\n", (unsigned short)34);
	TEST("02) Vrai PRINTF : |%hx|\n", (unsigned short)-34);
	TEST("03) Vrai PRINTF : |%-hx|\n", (unsigned short)50);
	TEST("04) Vrai PRINTF : |%10hx|\n", (unsigned short)90);
	TEST("05) Vrai PRINTF : |%.10hx|\n", (unsigned short)90);
	TEST("06) Vrai PRINTF : |%15hx|\n", (unsigned short)-100);
	TEST("07) Vrai PRINTF : |%.15hx|\n", (unsigned short)-100);
	TEST("08) Vrai PRINTF : |%10.5hx|\n", (unsigned short)52);
	TEST("09) Vrai PRINTF : |%5.10hx|\n", (unsigned short)52);
	TEST("10) Vrai PRINTF : |%20.15hx|\n", (unsigned short)-10000);
	TEST("11) Vrai PRINTF : |%15.20hx|\n", (unsigned short)-10000);
	TEST("12) Vrai PRINTF : |%-10hx|\n", (unsigned short)144);
	TEST("13) Vrai PRINTF : |%-.10hx|\n", (unsigned short)144);
	TEST("14) Vrai PRINTF : |%-20hx|\n", (unsigned short)-20000);
	TEST("15) Vrai PRINTF : |%08hx|\n", (unsigned short)64);
	TEST("16) Vrai PRINTF : |%03.4hx|\n", (unsigned short)10);
	TEST("17) Vrai PRINTF : |%#hx|\n", (unsigned short)34);
	TEST("18) Vrai PRINTF : |%#.5hx|\n", (unsigned short)34);
	TEST("19) Vrai PRINTF : |%#5hx|\n", (unsigned short)86);
	TEST("20) Vrai PRINTF : |%#10.5hx|\n", (unsigned short)70);
	TEST("21) Vrai PRINTF : |%#hx|\n", (unsigned short)0);
	TEST("22) Vrai PRINTF : |%#.hx|\n", (unsigned short)0);
	TEST("23) Vrai PRINTF : |%.hx|\n", (unsigned short)0);
	TEST("24) Vrai PRINTF : |%.hx|\n", (unsigned short)88);
	TEST("25) Vrai PRINTF : |%#.hx|\n", (unsigned short)88);
	TEST("26) Vrai PRINTF : |%hx|\n", (unsigned short)USHRT_MAX);
	TEST("27) Vrai PRINTF : |%#hx|\n", (unsigned short)USHRT_MAX);
	TEST("28) Vrai PRINTF : |%#hx| |%#hx|\n", (unsigned short)-1, (unsigned short)65536);
	printf("---------------------%%hhx--------------------\n");
	TEST("01) Vrai PRINTF : |%hhx|\n", (unsigned char)34);
	TEST("02) Vrai PRINTF : |%hhx|\n", (unsigned char)-34);
	TEST("03) Vrai PRINTF : |%-hhx|\n", (unsigned char)50);
	TEST("04) Vrai PRINTF : |%10hhx|\n", (unsigned char)90);
	TEST("05) Vrai PRINTF : |%.10hhx|\n", (unsigned char)90);
	TEST("06) Vrai PRINTF : |%15hhx|\n", (unsigned char)-100);
	TEST("07) Vrai PRINTF : |%.15hhx|\n", (unsigned char)-100);
	TEST("08) Vrai PRINTF : |%10.5hhx|\n", (unsigned char)52);
	TEST("09) Vrai PRINTF : |%5.10hhx|\n", (unsigned char)52);
	TEST("10) Vrai PRINTF : |%20.15hhx|\n", (unsigned char)-10000);
	TEST("11) Vrai PRINTF : |%15.20hhx|\n", (unsigned char)-10000);
	TEST("12) Vrai PRINTF : |%-10hhx|\n", (unsigned char)144);
	TEST("13) Vrai PRINTF : |%-.10hhx|\n", (unsigned char)144);
	TEST("14) Vrai PRINTF : |%-20hhx|\n", (unsigned char)-20000);
	TEST("15) Vrai PRINTF : |%08hhx|\n", (unsigned char)64);
	TEST("16) Vrai PRINTF : |%03.4hhx|\n", (unsigned char)10);
	TEST("17) Vrai PRINTF : |%#hhx|\n", (unsigned char)34);
	TEST("18) Vrai PRINTF : |%#.5hhx|\n", (unsigned char)34);
	TEST("19) Vrai PRINTF : |%#5hhx|\n", (unsigned char)86);
	TEST("20) Vrai PRINTF : |%#10.5hhx|\n", (unsigned char)70);
	TEST("21) Vrai PRINTF : |%#hhx|\n", (unsigned char)0);
	TEST("22) Vrai PRINTF : |%#.hhx|\n", (unsigned char)0);
	TEST("23) Vrai PRINTF : |%.hhx|\n", (unsigned char)0);
	TEST("24) Vrai PRINTF : |%.hhx|\n", (unsigned char)88);
	TEST("25) Vrai PRINTF : |%#.hhx|\n", (unsigned char)88);
	TEST("26) Vrai PRINTF : |%hhx|\n", (unsigned char)255);
	TEST("27) Vrai PRINTF : |%#hhx|\n", (unsigned char)255);
	TEST("28) Vrai PRINTF : |%#hhx| |%#hhx|\n", (unsigned char)-1, (unsigned char)256);
	printf("---------------------%%lx--------------------\n");
	TEST("01) Vrai PRINTF : |%lx|\n",(unsigned long)34);
	TEST("02) Vrai PRINTF : |%lx|\n", (unsigned long)-34);
	TEST("03) Vrai PRINTF : |%-lx|\n", (unsigned long)50);
	TEST("04) Vrai PRINTF : |%10lx|\n", (unsigned long)90);
	TEST("05) Vrai PRINTF : |%.10lx|\n", (unsigned long)90);
	TEST("06) Vrai PRINTF : |%15lx|\n", (unsigned long)-100);
	TEST("07) Vrai PRINTF : |%.15lx|\n", (unsigned long)-100);
	TEST("08) Vrai PRINTF : |%10.5lx|\n", (unsigned long)52);
	TEST("09) Vrai PRINTF : |%5.10lx|\n", (unsigned long)52);
	TEST("10) Vrai PRINTF : |%20.15lx|\n", (unsigned long)-100000);
	TEST("11) Vrai PRINTF : |%15.20lx|\n", (unsigned long)-100000);
	TEST("12) Vrai PRINTF : |%-10lx|\n", (unsigned long)144);
	TEST("13) Vrai PRINTF : |%-.10lx|\n", (unsigned long)144);
	TEST("14) Vrai PRINTF : |%-20lx|\n", (unsigned long)-20000000);
	TEST("15) Vrai PRINTF : |%08lx|\n", (unsigned long)64);
	TEST("16) Vrai PRINTF : |%03.4lx|\n", (unsigned long)10);
	TEST("17) Vrai PRINTF : |%#lx|\n", (unsigned long)34);
	TEST("18) Vrai PRINTF : |%#.5lx|\n", (unsigned long)34);
	TEST("19) Vrai PRINTF : |%#5lx|\n", (unsigned long)86);
	TEST("20) Vrai PRINTF : |%#10.5lx|\n", (unsigned long)70);
	TEST("21) Vrai PRINTF : |%#lx|\n", (unsigned long)0);
	TEST("22) Vrai PRINTF : |%#.lx|\n", (unsigned long)0);
	TEST("23) Vrai PRINTF : |%.lx|\n", (unsigned long)0);
	TEST("24) Vrai PRINTF : |%.lx|\n", (unsigned long)88);
	TEST("25) Vrai PRINTF : |%#.lx|\n", (unsigned long)88);
	TEST("26) Vrai PRINTF : |%lx|\n", (unsigned long)UINT_MAX);
	TEST("27) Vrai PRINTF : |%#lx|\n", (unsigned long)-1, ULONG_MAX);
	TEST("28) Vrai PRINTF : |%#lx| |%#lx|\n", (unsigned long)-1, ULONG_MAX + 1);
	printf("---------------------%%llx--------------------\n");
	TEST("01) Vrai PRINTF : |%llx|\n",(unsigned long long)34);
	TEST("02) Vrai PRINTF : |%llx|\n", (unsigned long long)-34);
	TEST("03) Vrai PRINTF : |%-llx|\n", (unsigned long long)50);
	TEST("04) Vrai PRINTF : |%10llx|\n", (unsigned long long)90);
	TEST("05) Vrai PRINTF : |%.10llx|\n", (unsigned long long)90);
	TEST("06) Vrai PRINTF : |%15llx|\n", (unsigned long long)-100);
	TEST("07) Vrai PRINTF : |%.15llx|\n", (unsigned long long)-100);
	TEST("08) Vrai PRINTF : |%10.5llx|\n", (unsigned long long)52);
	TEST("09) Vrai PRINTF : |%5.10llx|\n", (unsigned long long)52);
	TEST("10) Vrai PRINTF : |%20.15llx|\n", (unsigned long long)-100000);
	TEST("11) Vrai PRINTF : |%15.20llx|\n", (unsigned long long)-100000);
	TEST("12) Vrai PRINTF : |%-10llx|\n", (unsigned long long)144);
	TEST("13) Vrai PRINTF : |%-.10llx|\n", (unsigned long long)144);
	TEST("14) Vrai PRINTF : |%-20llx|\n", (unsigned long long)-20000000);
	TEST("15) Vrai PRINTF : |%08llx|\n", (unsigned long long)64);
	TEST("16) Vrai PRINTF : |%03.4llx|\n", (unsigned long long)10);
	TEST("17) Vrai PRINTF : |%#llx|\n", (unsigned long long)34);
	TEST("18) Vrai PRINTF : |%#.5llx|\n", (unsigned long long)34);
	TEST("19) Vrai PRINTF : |%#5llx|\n", (unsigned long long)86);
	TEST("20) Vrai PRINTF : |%#10.5llx|\n", (unsigned long long)70);
	TEST("21) Vrai PRINTF : |%#llx|\n", (unsigned long long)0);
	TEST("22) Vrai PRINTF : |%#.llx|\n", (unsigned long long)0);
	TEST("23) Vrai PRINTF : |%.llx|\n", (unsigned long long)0);
	TEST("24) Vrai PRINTF : |%.llx|\n", (unsigned long long)88);
	TEST("25) Vrai PRINTF : |%#.llx|\n", (unsigned long long)88);
	TEST("26) Vrai PRINTF : |%llx|\n", (unsigned long long)UINT_MAX);
	TEST("27) Vrai PRINTF : |%#llx|\n", (unsigned long long)-1, ULLONG_MAX);
	TEST("28) Vrai PRINTF : |%#llx| |%#llx|\n", (unsigned long long)-1, ULLONG_MAX + 1);
	
}

void	X(pf,ft)
{
printf("--------------------%%X--------------------\n");
	TEST("01) Vrai PRINTF : |%X|\n", 34);
	TEST("02) Vrai PRINTF : |%X|\n", -34);
	TEST("03) Vrai PRINTF : |%-X|\n", 50);
	TEST("04) Vrai PRINTF : |%10X|\n", 90);
	TEST("05) Vrai PRINTF : |%.10X|\n", 90);
	TEST("06) Vrai PRINTF : |%15X|\n", -100);
	TEST("07) Vrai PRINTF : |%.15X|\n", -100);
	TEST("08) Vrai PRINTF : |%10.5X|\n", 52);
	TEST("09) Vrai PRINTF : |%5.10X|\n", 52);
	TEST("10) Vrai PRINTF : |%20.15X|\n", -100000);
	TEST("11) Vrai PRINTF : |%15.20X|\n", -100000);
	TEST("12) Vrai PRINTF : |%-10X|\n", 144);
	TEST("13) Vrai PRINTF : |%-.10X|\n", 144);
	TEST("14) Vrai PRINTF : |%-20X|\n", -20000000);
	TEST("15) Vrai PRINTF : |%08X|\n", 64);
	TEST("16) Vrai PRINTF : |%03.4X|\n", 10);
	TEST("17) Vrai PRINTF : |%#X|\n", 34);
	TEST("18) Vrai PRINTF : |%#.5X|\n", 34);
	TEST("19) Vrai PRINTF : |%#5X|\n", 86);
	TEST("20) Vrai PRINTF : |%#10.5X|\n", 70);
	TEST("21) Vrai PRINTF : |%#X|\n", 0);
	TEST("22) Vrai PRINTF : |%#.X|\n", 0);
	TEST("23) Vrai PRINTF : |%.X|\n", 0);
	TEST("24) Vrai PRINTF : |%.X|\n", 88);
	TEST("25) Vrai PRINTF : |%#.X|\n", 88);
	TEST("26) Vrai PRINTF : |%X|\n", UINT_MAX);
	TEST("27) Vrai PRINTF : |%#X|\n", UINT_MAX);
	TEST("28) Vrai PRINTF : |%#X| |%#X|\n", (unsigned int)-1, UINT_MAX + 1);
	printf("---------------------%%hX--------------------\n");
	TEST("01) Vrai PRINTF : |%hX|\n", (unsigned short)34);
	TEST("02) Vrai PRINTF : |%hX|\n", (unsigned short)-34);
	TEST("03) Vrai PRINTF : |%-hX|\n", (unsigned short)50);
	TEST("04) Vrai PRINTF : |%10hX|\n", (unsigned short)90);
	TEST("05) Vrai PRINTF : |%.10hX|\n", (unsigned short)90);
	TEST("06) Vrai PRINTF : |%15hX|\n", (unsigned short)-100);
	TEST("07) Vrai PRINTF : |%.15hX|\n", (unsigned short)-100);
	TEST("08) Vrai PRINTF : |%10.5hX|\n", (unsigned short)52);
	TEST("09) Vrai PRINTF : |%5.10hX|\n", (unsigned short)52);
	TEST("10) Vrai PRINTF : |%20.15hX|\n", (unsigned short)-10000);
	TEST("11) Vrai PRINTF : |%15.20hX|\n", (unsigned short)-10000);
	TEST("12) Vrai PRINTF : |%-10hX|\n", (unsigned short)144);
	TEST("13) Vrai PRINTF : |%-.10hX|\n", (unsigned short)144);
	TEST("14) Vrai PRINTF : |%-20hX|\n", (unsigned short)-20000);
	TEST("15) Vrai PRINTF : |%08hX|\n", (unsigned short)64);
	TEST("16) Vrai PRINTF : |%03.4hX|\n", (unsigned short)10);
	TEST("17) Vrai PRINTF : |%#hX|\n", (unsigned short)34);
	TEST("18) Vrai PRINTF : |%#.5hX|\n", (unsigned short)34);
	TEST("19) Vrai PRINTF : |%#5hX|\n", (unsigned short)86);
	TEST("20) Vrai PRINTF : |%#10.5hX|\n", (unsigned short)70);
	TEST("21) Vrai PRINTF : |%#hX|\n", (unsigned short)0);
	TEST("22) Vrai PRINTF : |%#.hX|\n", (unsigned short)0);
	TEST("23) Vrai PRINTF : |%.hX|\n", (unsigned short)0);
	TEST("24) Vrai PRINTF : |%.hX|\n", (unsigned short)88);
	TEST("25) Vrai PRINTF : |%#.hX|\n", (unsigned short)88);
	TEST("26) Vrai PRINTF : |%hX|\n", (unsigned short)USHRT_MAX);
	TEST("27) Vrai PRINTF : |%#hX|\n", (unsigned short)USHRT_MAX);
	TEST("28) Vrai PRINTF : |%#hX| |%#hX|\n", (unsigned short)-1, (unsigned short)65536);
	printf("---------------------%%hhX--------------------\n");
	TEST("01) Vrai PRINTF : |%hhX|\n", (unsigned char)34);
	TEST("02) Vrai PRINTF : |%hhX|\n", (unsigned char)-34);
	TEST("03) Vrai PRINTF : |%-hhX|\n", (unsigned char)50);
	TEST("04) Vrai PRINTF : |%10hhX|\n", (unsigned char)90);
	TEST("05) Vrai PRINTF : |%.10hhX|\n", (unsigned char)90);
	TEST("06) Vrai PRINTF : |%15hhX|\n", (unsigned char)-100);
	TEST("07) Vrai PRINTF : |%.15hhX|\n", (unsigned char)-100);
	TEST("08) Vrai PRINTF : |%10.5hhX|\n", (unsigned char)52);
	TEST("09) Vrai PRINTF : |%5.10hhX|\n", (unsigned char)52);
	TEST("10) Vrai PRINTF : |%20.15hhX|\n", (unsigned char)-10000);
	TEST("11) Vrai PRINTF : |%15.20hhX|\n", (unsigned char)-10000);
	TEST("12) Vrai PRINTF : |%-10hhX|\n", (unsigned char)144);
	TEST("13) Vrai PRINTF : |%-.10hhX|\n", (unsigned char)144);
	TEST("14) Vrai PRINTF : |%-20hhX|\n", (unsigned char)-20000);
	TEST("15) Vrai PRINTF : |%08hhX|\n", (unsigned char)64);
	TEST("16) Vrai PRINTF : |%03.4hhX|\n", (unsigned char)10);
	TEST("17) Vrai PRINTF : |%#hhX|\n", (unsigned char)34);
	TEST("18) Vrai PRINTF : |%#.5hhX|\n", (unsigned char)34);
	TEST("19) Vrai PRINTF : |%#5hhX|\n", (unsigned char)86);
	TEST("20) Vrai PRINTF : |%#10.5hhX|\n", (unsigned char)70);
	TEST("21) Vrai PRINTF : |%#hhX|\n", (unsigned char)0);
	TEST("22) Vrai PRINTF : |%#.hhX|\n", (unsigned char)0);
	TEST("23) Vrai PRINTF : |%.hhX|\n", (unsigned char)0);
	TEST("24) Vrai PRINTF : |%.hhX|\n", (unsigned char)88);
	TEST("25) Vrai PRINTF : |%#.hhX|\n", (unsigned char)88);
	TEST("26) Vrai PRINTF : |%hhX|\n", (unsigned char)255);
	TEST("27) Vrai PRINTF : |%#hhX|\n", (unsigned char)255);
	TEST("28) Vrai PRINTF : |%#hhX| |%#hhX|\n", (unsigned char)-1, (unsigned char)256);
	printf("---------------------%%lX--------------------\n");
	TEST("01) Vrai PRINTF : |%lX|\n",(unsigned long)34);
	TEST("02) Vrai PRINTF : |%lX|\n", (unsigned long)-34);
	TEST("03) Vrai PRINTF : |%-lX|\n", (unsigned long)50);
	TEST("04) Vrai PRINTF : |%10lX|\n", (unsigned long)90);
	TEST("05) Vrai PRINTF : |%.10lX|\n", (unsigned long)90);
	TEST("06) Vrai PRINTF : |%15lX|\n", (unsigned long)-100);
	TEST("07) Vrai PRINTF : |%.15lX|\n", (unsigned long)-100);
	TEST("08) Vrai PRINTF : |%10.5lX|\n", (unsigned long)52);
	TEST("09) Vrai PRINTF : |%5.10lX|\n", (unsigned long)52);
	TEST("10) Vrai PRINTF : |%20.15lX|\n", (unsigned long)-100000);
	TEST("11) Vrai PRINTF : |%15.20lX|\n", (unsigned long)-100000);
	TEST("12) Vrai PRINTF : |%-10lX|\n", (unsigned long)144);
	TEST("13) Vrai PRINTF : |%-.10lX|\n", (unsigned long)144);
	TEST("14) Vrai PRINTF : |%-20lX|\n", (unsigned long)-20000000);
	TEST("15) Vrai PRINTF : |%08lX|\n", (unsigned long)64);
	TEST("16) Vrai PRINTF : |%03.4lX|\n", (unsigned long)10);
	TEST("17) Vrai PRINTF : |%#lX|\n", (unsigned long)34);
	TEST("18) Vrai PRINTF : |%#.5lX|\n", (unsigned long)34);
	TEST("19) Vrai PRINTF : |%#5lX|\n", (unsigned long)86);
	TEST("20) Vrai PRINTF : |%#10.5lX|\n", (unsigned long)70);
	TEST("21) Vrai PRINTF : |%#lX|\n", (unsigned long)0);
	TEST("22) Vrai PRINTF : |%#.lX|\n", (unsigned long)0);
	TEST("23) Vrai PRINTF : |%.lX|\n", (unsigned long)0);
	TEST("24) Vrai PRINTF : |%.lX|\n", (unsigned long)88);
	TEST("25) Vrai PRINTF : |%#.lX|\n", (unsigned long)88);
	TEST("26) Vrai PRINTF : |%lX|\n", (unsigned long)UINT_MAX);
	TEST("27) Vrai PRINTF : |%#lX|\n", (unsigned long)-1, ULONG_MAX);
	TEST("28) Vrai PRINTF : |%#lX| |%#lX|\n", (unsigned long)-1, ULONG_MAX + 1);
	printf("---------------------%%llX--------------------\n");
	TEST("01) Vrai PRINTF : |%llX|\n",(unsigned long long)34);
	TEST("02) Vrai PRINTF : |%llX|\n", (unsigned long long)-34);
	TEST("03) Vrai PRINTF : |%-llX|\n", (unsigned long long)50);
	TEST("04) Vrai PRINTF : |%10llX|\n", (unsigned long long)90);
	TEST("05) Vrai PRINTF : |%.10llX|\n", (unsigned long long)90);
	TEST("06) Vrai PRINTF : |%15llX|\n", (unsigned long long)-100);
	TEST("07) Vrai PRINTF : |%.15llX|\n", (unsigned long long)-100);
	TEST("08) Vrai PRINTF : |%10.5llX|\n", (unsigned long long)52);
	TEST("09) Vrai PRINTF : |%5.10llX|\n", (unsigned long long)52);
	TEST("10) Vrai PRINTF : |%20.15llX|\n", (unsigned long long)-100000);
	TEST("11) Vrai PRINTF : |%15.20llX|\n", (unsigned long long)-100000);
	TEST("12) Vrai PRINTF : |%-10llX|\n", (unsigned long long)144);
	TEST("13) Vrai PRINTF : |%-.10llX|\n", (unsigned long long)144);
	TEST("14) Vrai PRINTF : |%-20llX|\n", (unsigned long long)-20000000);
	TEST("15) Vrai PRINTF : |%08llX|\n", (unsigned long long)64);
	TEST("16) Vrai PRINTF : |%03.4llX|\n", (unsigned long long)10);
	TEST("17) Vrai PRINTF : |%#llX|\n", (unsigned long long)34);
	TEST("18) Vrai PRINTF : |%#.5llX|\n", (unsigned long long)34);
	TEST("19) Vrai PRINTF : |%#5llX|\n", (unsigned long long)86);
	TEST("20) Vrai PRINTF : |%#10.5llX|\n", (unsigned long long)70);
	TEST("21) Vrai PRINTF : |%#llX|\n", (unsigned long long)0);
	TEST("22) Vrai PRINTF : |%#.llX|\n", (unsigned long long)0);
	TEST("23) Vrai PRINTF : |%.llX|\n", (unsigned long long)0);
	TEST("24) Vrai PRINTF : |%.llX|\n", (unsigned long long)88);
	TEST("25) Vrai PRINTF : |%#.llX|\n", (unsigned long long)88);
	TEST("26) Vrai PRINTF : |%llX|\n", (unsigned long long)UINT_MAX);
	TEST("27) Vrai PRINTF : |%#llX|\n", (unsigned long long)-1, ULLONG_MAX);
	TEST("28) Vrai PRINTF : |%#llX| |%#llX|\n", (unsigned long long)-1, ULLONG_MAX + 1);
	}

void	o(pf,ft)
{
printf("--------------------%%o--------------------\n");		//perfect
	TEST("01) Vrai PRINTF : |%o|\n", 34);
	TEST("02) Vrai PRINTF : |%o|\n", -34);
	TEST("03) Vrai PRINTF : |%-o|\n", 50);
	TEST("04) Vrai PRINTF : |%10o|\n", 90);
	TEST("05) Vrai PRINTF : |%.10o|\n", 90);
	TEST("06) Vrai PRINTF : |%15o|\n", -100);
	TEST("07) Vrai PRINTF : |%.15o|\n", -100);
	TEST("08) Vrai PRINTF : |%10.5o|\n", 52);
	TEST("09) Vrai PRINTF : |%5.10o|\n", 52);
	TEST("10) Vrai PRINTF : |%20.15o|\n", -100000);
	TEST("11) Vrai PRINTF : |%15.20o|\n", -100000);
	TEST("12) Vrai PRINTF : |%-10o|\n", 144);
	TEST("13) Vrai PRINTF : |%-.10o|\n", 144);
	TEST("14) Vrai PRINTF : |%-20o|\n", -20000000);
	TEST("15) Vrai PRINTF : |%08o|\n", 64);
	TEST("16) Vrai PRINTF : |%03.4o|\n", 10);
	TEST("17) Vrai PRINTF : |%#o|\n", 34);
	TEST("18) Vrai PRINTF : |%#.5o|\n", 34);
	TEST("19) Vrai PRINTF : |%#5o|\n", 86);
	TEST("20) Vrai PRINTF : |%#10.5o|\n", 70);
	TEST("21) Vrai PRINTF : |%#o|\n", 0);
	TEST("22) Vrai PRINTF : |%#.o|\n", 0);
	TEST("23) Vrai PRINTF : |%.o|\n", 0);
	TEST("24) Vrai PRINTF : |%.o|\n", 88);
	TEST("25) Vrai PRINTF : |%#.o|\n", 88);
	TEST("26) Vrai PRINTF : |%o|\n", UINT_MAX);
	TEST("27) Vrai PRINTF : |%#o|\n", UINT_MAX);
	TEST("28) Vrai PRINTF : |%#o| |%#o|\n", (unsigned int)-1, UINT_MAX + 1);
	TEST("29) Vrai PRINTF : |%o| |%o|\n", (unsigned int)-1, UINT_MAX + 1);
	printf("---------------------%%ho--------------------\n");	//28/29
	TEST("01) Vrai PRINTF : |%ho|\n", (unsigned short)34);
	TEST("02) Vrai PRINTF : |%ho|\n", (unsigned short)-34);
	TEST("03) Vrai PRINTF : |%-ho|\n", (unsigned short)50);
	TEST("04) Vrai PRINTF : |%10ho|\n", (unsigned short)90);
	TEST("05) Vrai PRINTF : |%.10ho|\n", (unsigned short)90);
	TEST("06) Vrai PRINTF : |%15ho|\n", (unsigned short)-100);
	TEST("07) Vrai PRINTF : |%.15ho|\n", (unsigned short)-100);
	TEST("08) Vrai PRINTF : |%10.5ho|\n", (unsigned short)52);
	TEST("09) Vrai PRINTF : |%5.10ho|\n", (unsigned short)52);
	TEST("10) Vrai PRINTF : |%20.15ho|\n", (unsigned short)-10000);
	TEST("11) Vrai PRINTF : |%15.20ho|\n", (unsigned short)-10000);
	TEST("12) Vrai PRINTF : |%-10ho|\n", (unsigned short)144);
	TEST("13) Vrai PRINTF : |%-.10ho|\n", (unsigned short)144);
	TEST("14) Vrai PRINTF : |%-20ho|\n", (unsigned short)-20000);
	TEST("15) Vrai PRINTF : |%08ho|\n", (unsigned short)64);
	TEST("16) Vrai PRINTF : |%03.4ho|\n", (unsigned short)10);
	TEST("17) Vrai PRINTF : |%#ho|\n", (unsigned short)34);
	TEST("18) Vrai PRINTF : |%#.5ho|\n", (unsigned short)34);
	TEST("19) Vrai PRINTF : |%#5ho|\n", (unsigned short)86);
	TEST("20) Vrai PRINTF : |%#10.5ho|\n", (unsigned short)70);
	TEST("21) Vrai PRINTF : |%#ho|\n", (unsigned short)0);
	TEST("22) Vrai PRINTF : |%#.ho|\n", (unsigned short)0);
	TEST("23) Vrai PRINTF : |%.ho|\n", (unsigned short)0);
	TEST("24) Vrai PRINTF : |%.ho|\n", (unsigned short)88);
	TEST("25) Vrai PRINTF : |%#.ho|\n", (unsigned short)88);
	TEST("26) Vrai PRINTF : |%ho|\n", (unsigned short)USHRT_MAX);
	TEST("27) Vrai PRINTF : |%#ho|\n", (unsigned short)USHRT_MAX);
	TEST("28) Vrai PRINTF : |%#ho| |%#ho|\n", (unsigned short)-1, (unsigned short)65536);
	TEST("29) Vrai PRINTF : |%ho| |%ho|\n", (unsigned short)-1, (unsigned short)65536);
	printf("---------------------%%hho--------------------\n");
	TEST("01) Vrai PRINTF : |%hho|\n", (unsigned char)34);
	TEST("02) Vrai PRINTF : |%hho|\n", (unsigned char)-34);
	TEST("03) Vrai PRINTF : |%-hho|\n", (unsigned char)50);
	TEST("04) Vrai PRINTF : |%10hho|\n", (unsigned char)90);
	TEST("05) Vrai PRINTF : |%.10hho|\n", (unsigned char)90);
	TEST("06) Vrai PRINTF : |%15hho|\n", (unsigned char)-100);
	TEST("07) Vrai PRINTF : |%.15hho|\n", (unsigned char)-100);
	TEST("08) Vrai PRINTF : |%10.5hho|\n", (unsigned char)52);
	TEST("09) Vrai PRINTF : |%5.10hho|\n", (unsigned char)52);
	TEST("10) Vrai PRINTF : |%20.15hho|\n", (unsigned char)-10000);
	TEST("11) Vrai PRINTF : |%15.20hho|\n", (unsigned char)-10000);
	TEST("12) Vrai PRINTF : |%-10hho|\n", (unsigned char)144);
	TEST("13) Vrai PRINTF : |%-.10hho|\n", (unsigned char)144);
	TEST("14) Vrai PRINTF : |%-20hho|\n", (unsigned char)-20000);
	TEST("15) Vrai PRINTF : |%08hho|\n", (unsigned char)64);
	TEST("16) Vrai PRINTF : |%03.4hho|\n", (unsigned char)10);
	TEST("17) Vrai PRINTF : |%#hho|\n", (unsigned char)34);
	TEST("18) Vrai PRINTF : |%#.5hho|\n", (unsigned char)34);
	TEST("19) Vrai PRINTF : |%#5hho|\n", (unsigned char)86);
	TEST("20) Vrai PRINTF : |%#10.5hho|\n", (unsigned char)70);
	TEST("21) Vrai PRINTF : |%#hho|\n", (unsigned char)0);
	TEST("22) Vrai PRINTF : |%#.hho|\n", (unsigned char)0);
	TEST("23) Vrai PRINTF : |%.hho|\n", (unsigned char)0);
	TEST("24) Vrai PRINTF : |%.hho|\n", (unsigned char)88);
	TEST("25) Vrai PRINTF : |%#.hho|\n", (unsigned char)88);
	TEST("26) Vrai PRINTF : |%hho|\n", (unsigned char)255);
	TEST("27) Vrai PRINTF : |%#hho|\n", (unsigned char)255);
	TEST("28) Vrai PRINTF : |%#hho| |%#hho|\n", (unsigned char)-1, (unsigned char)256);
	printf("---------------------%%lo--------------------\n");
	TEST("01) Vrai PRINTF : |%lo|\n",(unsigned long)34);
	TEST("02) Vrai PRINTF : |%lo|\n", (unsigned long)-34);
	TEST("03) Vrai PRINTF : |%-lo|\n", (unsigned long)50);
	TEST("04) Vrai PRINTF : |%10lo|\n", (unsigned long)90);
	TEST("05) Vrai PRINTF : |%.10lo|\n", (unsigned long)90);
	TEST("06) Vrai PRINTF : |%15lo|\n", (unsigned long)-100);
	TEST("07) Vrai PRINTF : |%.15lo|\n", (unsigned long)-100);
	TEST("08) Vrai PRINTF : |%10.5lo|\n", (unsigned long)52);
	TEST("09) Vrai PRINTF : |%5.10lo|\n", (unsigned long)52);
	TEST("10) Vrai PRINTF : |%20.15lo|\n", (unsigned long)-100000);
	TEST("11) Vrai PRINTF : |%15.20lo|\n", (unsigned long)-100000);
	TEST("12) Vrai PRINTF : |%-10lo|\n", (unsigned long)144);
	TEST("13) Vrai PRINTF : |%-.10lo|\n", (unsigned long)144);
	TEST("14) Vrai PRINTF : |%-20lo|\n", (unsigned long)-20000000);
	TEST("15) Vrai PRINTF : |%08lo|\n", (unsigned long)64);
	TEST("16) Vrai PRINTF : |%03.4lo|\n", (unsigned long)10);
	TEST("17) Vrai PRINTF : |%#lo|\n", (unsigned long)34);
	TEST("18) Vrai PRINTF : |%#.5lo|\n", (unsigned long)34);
	TEST("19) Vrai PRINTF : |%#5lo|\n", (unsigned long)86);
	TEST("20) Vrai PRINTF : |%#10.5lo|\n", (unsigned long)70);
	TEST("21) Vrai PRINTF : |%#lo|\n", (unsigned long)0);
	TEST("22) Vrai PRINTF : |%#.lo|\n", (unsigned long)0);
	TEST("23) Vrai PRINTF : |%.lo|\n", (unsigned long)0);
	TEST("24) Vrai PRINTF : |%.lo|\n", (unsigned long)88);
	TEST("25) Vrai PRINTF : |%#.lo|\n", (unsigned long)88);
	TEST("26) Vrai PRINTF : |%lo|\n", (unsigned long)UINT_MAX);
	TEST("27) Vrai PRINTF : |%#lo|\n", (unsigned long)-1, ULONG_MAX);
	TEST("28) Vrai PRINTF : |%#lo| |%#lo|\n", (unsigned long)-1, ULONG_MAX + 1);
	printf("---------------------%%llo--------------------\n");
	TEST("01) Vrai PRINTF : |%llo|\n",(unsigned long long)34);
	TEST("02) Vrai PRINTF : |%llo|\n", (unsigned long long)-34);
	TEST("03) Vrai PRINTF : |%-llo|\n", (unsigned long long)50);
	TEST("04) Vrai PRINTF : |%10llo|\n", (unsigned long long)90);
	TEST("05) Vrai PRINTF : |%.10llo|\n", (unsigned long long)90);
	TEST("06) Vrai PRINTF : |%15llo|\n", (unsigned long long)-100);
	TEST("07) Vrai PRINTF : |%.15llo|\n", (unsigned long long)-100);
	TEST("08) Vrai PRINTF : |%10.5llo|\n", (unsigned long long)52);
	TEST("09) Vrai PRINTF : |%5.10llo|\n", (unsigned long long)52);
	TEST("10) Vrai PRINTF : |%20.15llo|\n", (unsigned long long)-100000);
	TEST("11) Vrai PRINTF : |%15.20llo|\n", (unsigned long long)-100000);
	TEST("12) Vrai PRINTF : |%-10llo|\n", (unsigned long long)144);
	TEST("13) Vrai PRINTF : |%-.10llo|\n", (unsigned long long)144);
	TEST("14) Vrai PRINTF : |%-20llo|\n", (unsigned long long)-20000000);
	TEST("15) Vrai PRINTF : |%08llo|\n", (unsigned long long)64);
	TEST("16) Vrai PRINTF : |%03.4llo|\n", (unsigned long long)10);
	TEST("17) Vrai PRINTF : |%#llo|\n", (unsigned long long)34);
	TEST("18) Vrai PRINTF : |%#.5llo|\n", (unsigned long long)34);
	TEST("19) Vrai PRINTF : |%#5llo|\n", (unsigned long long)86);
	TEST("20) Vrai PRINTF : |%#10.5llo|\n", (unsigned long long)70);
	TEST("21) Vrai PRINTF : |%#llo|\n", (unsigned long long)0);
	TEST("22) Vrai PRINTF : |%#.llo|\n", (unsigned long long)0);
	TEST("23) Vrai PRINTF : |%.llo|\n", (unsigned long long)0);
	TEST("24) Vrai PRINTF : |%.llo|\n", (unsigned long long)88);
	TEST("25) Vrai PRINTF : |%#.llo|\n", (unsigned long long)88);
	TEST("26) Vrai PRINTF : |%llo|\n", (unsigned long long)ULLONG_MAX);
	TEST("27) Vrai PRINTF : |%#llo|\n", (unsigned long long)-1, ULLONG_MAX);
	TEST("28) Vrai PRINTF : |%#llo| |%#llo|\n", (unsigned long long)-1, ULLONG_MAX + 1);
		
}

void diu(pf,ft)
{
printf("--------------------%%d-et-%%i--------------------\n");	//perfect
	TEST("01) Vrai PRINTF : |%d|\n", 42);
	TEST("02) Vrai PRINTF : |%i|\n", 42);
	TEST("03) Vrai PRINTF : |%+d|\n", 42);
	TEST("04) Vrai PRINTF : |%-d|\n", 42);
	TEST("05) Vrai PRINTF : |%10d|\n", 100);
	TEST("06) Vrai PRINTF : |%-10d|\n", 64);
	TEST("07) Vrai PRINTF : |%.10d|\n", 100);
	TEST("08) Vrai PRINTF : |%10.5d|\n", 100);
	TEST("09) Vrai PRINTF : |%5.10d|\n", 64);
	TEST("10) Vrai PRINTF : |%1.1d|\n", 16);
	TEST("11) Vrai PRINTF : |%+10d|\n", 50);
	TEST("12) Vrai PRINTF : |%+2d|\n", 50);
	TEST("13) Vrai PRINTF : |%+.10d|\n", 50);
	TEST("14) Vrai PRINTF : |%+.2d|\n", 50);
	TEST("15) Vrai PRINTF : |%          d|\n", 1);
	TEST("16) Vrai PRINTF : |% -d|\n", 1);
	TEST("17) Vrai PRINTF : |%-+d|\n", 32);
	TEST("18) Vrai PRINTF : |%+-d|\n", 32);
	TEST("19) Vrai PRINTF : |%-+10d|\n", 42);
	TEST("20) Vrai PRINTF : |%-+.10d|\n", 42);
	TEST("21) Vrai PRINTF : |%d|\n", -42);
	TEST("22) Vrai PRINTF : |%10d|\n", -42);
	TEST("23) Vrai PRINTF : |%.10d|\n", -42);
	TEST("24) Vrai PRINTF : |%+d|\n", -10);
	TEST("25) Vrai PRINTF : |%10.5d|\n", -16);
	TEST("26) Vrai PRINTF : |%5.10d|\n", -16);
	TEST("27) Vrai PRINTF : |%1.1d|\n", -20);
	TEST("28) Vrai PRINTF : |%-10d|\n", -50);
	TEST("30) Vrai PRINTF : |%++++++++++d|\n", 69);
	TEST("31) Vrai PRINTF : |%+10d|\n", -64);
	TEST("32) Vrai PRINTF : |%+.10d|\n", -64);
	TEST("33) Vrai PRINTF : |%2d|\n", -20);
	TEST("34) Vrai PRINTF : |%.2d|\n", -20);
	TEST("35) Vrai PRINTF : |%2d|\n", -1);
	TEST("36) Vrai PRINTF : |%.2d|\n", -1);
	TEST("37) Vrai PRINTF : |%-10d|\n", -80);
	TEST("38) Vrai PRINTF : |%-.10d|\n", -80);
	TEST("39) Vrai PRINTF : |%06d|\n", 35);
	TEST("40) Vrai PRINTF : |%06d|\n", -35);
	TEST("41) Vrai PRINTF : |%-+10d|\n", -40);
	TEST("42) Vrai PRINTF : |%+-10d|\n", -40);
	TEST("43) Vrai PRINTF : |%05.3d|\n", 5);
	TEST("44) Vrai PRINTF : |%03.5d|\n", 5);
	TEST("45) Vrai PRINTF : |%05.3d|\n", -5);
	TEST("46) Vrai PRINTF : |%03.5d|\n", -5);
	TEST("47) Vrai PRINTF : |%d| |%d|\n", INT_MAX, INT_MIN);
	TEST("48) Vrai PRINTF : |%d| |%d|\n", INT_MAX + 1, INT_MIN - 1);
	TEST("49) Vrai PRINTF : |%.d|\n", 0);
	TEST("50) Vrai PRINTF : |%.d|\n", 100);
	printf("---------------------%%hd-et-%%hi--------------------\n");	//perfect
	TEST("01) Vrai PRINTF : |%hd|\n", (short)42);
	TEST("02) Vrai PRINTF : |%hi|\n", (short)42);
	TEST("03) Vrai PRINTF : |%+hd|\n", (short)42);
	TEST("04) Vrai PRINTF : |%-hd|\n", (short)42);
	TEST("05) Vrai PRINTF : |%10hd|\n", (short)100);
	TEST("06) Vrai PRINTF : |%-10hd|\n", (short)64);
	TEST("07) Vrai PRINTF : |%.10hd|\n", (short)100);
	TEST("08) Vrai PRINTF : |%10.5hd|\n", (short)100);
	TEST("09) Vrai PRINTF : |%5.10hd|\n", (short)64);
	TEST("10) Vrai PRINTF : |%1.1hd|\n", (short)16);
	TEST("11) Vrai PRINTF : |%+10hd|\n", (short)50);
	TEST("12) Vrai PRINTF : |%+2hd|\n", (short)50);
	TEST("13) Vrai PRINTF : |%+.10hd|\n", (short)50);
	TEST("14) Vrai PRINTF : |%+.2hd|\n", (short)50);
	TEST("15) Vrai PRINTF : |%          hd|\n", (short)1);
	TEST("16) Vrai PRINTF : |% -hd|\n", (short)1);
	TEST("17) Vrai PRINTF : |%-+hd|\n", (short)32);
	TEST("18) Vrai PRINTF : |%+-hd|\n", (short)32);
	TEST("19) Vrai PRINTF : |%-+10hd|\n", (short)42);
	TEST("20) Vrai PRINTF : |%-+.10hd|\n", (short)42);
	TEST("21) Vrai PRINTF : |%hd|\n", (short)-42);
	TEST("22) Vrai PRINTF : |%10hd|\n", (short)-42);
	TEST("23) Vrai PRINTF : |%.10hd|\n", (short)-42);
	TEST("24) Vrai PRINTF : |%+hd|\n", (short)-10);
	TEST("25) Vrai PRINTF : |%10.5hd|\n", (short)-16);
	TEST("26) Vrai PRINTF : |%5.10hd|\n", (short)-16);
	TEST("27) Vrai PRINTF : |%1.1hd|\n", (short)-20);
	TEST("28) Vrai PRINTF : |%-10hd|\n", (short)-50);
	TEST("30) Vrai PRINTF : |%++++++++++hd|\n", (short)69);
	TEST("31) Vrai PRINTF : |%+10hd|\n", (short)-64);
	TEST("32) Vrai PRINTF : |%+.10hd|\n", (short)-64);
	TEST("33) Vrai PRINTF : |%2hd|\n", (short)-20);
	TEST("34) Vrai PRINTF : |%.2hd|\n", (short)-20);
	TEST("35) Vrai PRINTF : |%2hd|\n", (short)-1);
	TEST("36) Vrai PRINTF : |%.2hd|\n", (short)-1);
	TEST("37) Vrai PRINTF : |%-10hd|\n", (short)-80);
	TEST("38) Vrai PRINTF : |%-.10hd|\n", (short)-80);
	TEST("39) Vrai PRINTF : |%06hd|\n", (short)35);
	TEST("40) Vrai PRINTF : |%06hd|\n", (short)-35);
	TEST("41) Vrai PRINTF : |%-+10hd|\n", (short)-40);
	TEST("42) Vrai PRINTF : |%+-10hd|\n", (short)-40);
	TEST("43) Vrai PRINTF : |%05.3hd|\n", (short)5);
	TEST("44) Vrai PRINTF : |%03.5hd|\n", (short)5);
	TEST("45) Vrai PRINTF : |%05.3hd|\n", (short)-5);
	TEST("46) Vrai PRINTF : |%03.5hd|\n", (short)-5);
	TEST("47) Vrai PRINTF : |%hd| |%hd|\n", (short)32767, (short)-32768);
	TEST("48) Vrai PRINTF : |%hd| |%hd|\n", (short)32768, (short)-32769);
	TEST("49) Vrai PRINTF : |%.hd|\n", (short)0);
	TEST("50) Vrai PRINTF : |%.hd|\n", (short)100);
	printf("---------------------%%hhd-et-%%hhi--------------------\n");	//perfect
	TEST("01) Vrai PRINTF : |%hhd|\n", (char)42);
	TEST("02) Vrai PRINTF : |%hhi|\n", (char)42);
	TEST("03) Vrai PRINTF : |%+hhd|\n", (char)42);
	TEST("04) Vrai PRINTF : |%-hhd|\n", (char)42);
	TEST("05) Vrai PRINTF : |%10hhd|\n", (char)100);
	TEST("06) Vrai PRINTF : |%-10hhd|\n", (char)64);
	TEST("07) Vrai PRINTF : |%.10hhd|\n", (char)100);
	TEST("08) Vrai PRINTF : |%10.5hhd|\n", (char)100);
	TEST("09) Vrai PRINTF : |%5.10hhd|\n", (char)64);
	TEST("10) Vrai PRINTF : |%1.1hhd|\n", (char)16);
	TEST("11) Vrai PRINTF : |%+10hhd|\n", (char)50);
	TEST("12) Vrai PRINTF : |%+2hhd|\n", (char)50);
	TEST("13) Vrai PRINTF : |%+.10hhd|\n", (char)50);
	TEST("14) Vrai PRINTF : |%+.2hhd|\n", (char)50);
	TEST("15) Vrai PRINTF : |%          hhd|\n", (char)1);
	TEST("16) Vrai PRINTF : |% -hhd|\n", (char)1);
	TEST("17) Vrai PRINTF : |%-+hhd|\n", (char)32);
	TEST("18) Vrai PRINTF : |%+-hhd|\n", (char)32);
	TEST("19) Vrai PRINTF : |%-+10hhd|\n", (char)42);
	TEST("20) Vrai PRINTF : |%-+.10hhd|\n", (char)42);
	TEST("21) Vrai PRINTF : |%hhd|\n", (char)-42);
	TEST("22) Vrai PRINTF : |%10hhd|\n", (char)-42);
	TEST("23) Vrai PRINTF : |%.10hhd|\n", (char)-42);
	TEST("24) Vrai PRINTF : |%+hhd|\n", (char)-10);
	TEST("25) Vrai PRINTF : |%10.5hhd|\n", (char)-16);
	TEST("26) Vrai PRINTF : |%5.10hhd|\n", (char)-16);
	TEST("27) Vrai PRINTF : |%1.1hhd|\n", (char)-20);
	TEST("28) Vrai PRINTF : |%-10hhd|\n", (char)-50);
	TEST("30) Vrai PRINTF : |%++++++++++hhd|\n", (char)69);
	TEST("31) Vrai PRINTF : |%+10hhd|\n", (char)-64);
	TEST("32) Vrai PRINTF : |%+.10hhd|\n", (char)-64);
	TEST("33) Vrai PRINTF : |%2hhd|\n", (char)-20);
	TEST("34) Vrai PRINTF : |%.2hhd|\n", (char)-20);
	TEST("35) Vrai PRINTF : |%2hhd|\n", (char)-1);
	TEST("36) Vrai PRINTF : |%.2hhd|\n", (char)-1);
	TEST("37) Vrai PRINTF : |%-10hhd|\n", (char)-80);
	TEST("38) Vrai PRINTF : |%-.10hhd|\n", (char)-80);
	TEST("39) Vrai PRINTF : |%06hhd|\n", (char)35);
	TEST("40) Vrai PRINTF : |%06hhd|\n", (char)-35);
	TEST("41) Vrai PRINTF : |%-+10hhd|\n", (char)-40);
	TEST("42) Vrai PRINTF : |%+-10hhd|\n", (char)-40);
	TEST("43) Vrai PRINTF : |%05.3hhd|\n", (char)5);
	TEST("44) Vrai PRINTF : |%03.5hhd|\n", (char)5);
	TEST("45) Vrai PRINTF : |%05.3hhd|\n", (char)-5);
	TEST("46) Vrai PRINTF : |%03.5hhd|\n", (char)-5);
	TEST("47) Vrai PRINTF : |%hhd| |%hhd|\n", (char)127, (char)-128);
	TEST("48) Vrai PRINTF : |%hhd| |%hhd|\n", (char)128, (char)-129);
	TEST("49) Vrai PRINTF : |%.hhd|\n", (char)0);
	TEST("50) Vrai PRINTF : |%.hhd|\n", (char)100);
	printf("-------------------------------%%ld-et-%%li--------------------\n");	//48/50
	TEST("01) Vrai PRINTF : |%ld|\n", (long)42);
	TEST("02) Vrai PRINTF : |%li|\n", (long)42);
	TEST("03) Vrai PRINTF : |%+ld|\n", (long)42);
	TEST("04) Vrai PRINTF : |%-ld|\n", (long)42);
	TEST("05) Vrai PRINTF : |%10ld|\n", (long)100);
	TEST("06) Vrai PRINTF : |%-10ld|\n", (long)64);
	TEST("07) Vrai PRINTF : |%.10ld|\n", (long)100);
	TEST("08) Vrai PRINTF : |%10.5ld|\n", (long)100);
	TEST("09) Vrai PRINTF : |%5.10ld|\n", (long)64);
	TEST("10) Vrai PRINTF : |%1.1ld|\n", (long)16);
	TEST("11) Vrai PRINTF : |%+10ld|\n", (long)50);
	TEST("12) Vrai PRINTF : |%+2ld|\n", (long)50);
	TEST("13) Vrai PRINTF : |%+.10ld|\n", (long)50);
	TEST("14) Vrai PRINTF : |%+.2ld|\n", (long)50);
	TEST("15) Vrai PRINTF : |%          ld|\n", (long)1);
	TEST("16) Vrai PRINTF : |% -ld|\n", (long)1);
	TEST("17) Vrai PRINTF : |%-+ld|\n", (long)32);
	TEST("18) Vrai PRINTF : |%+-ld|\n", (long)32);
	TEST("19) Vrai PRINTF : |%-+10ld|\n", (long)42);
	TEST("20) Vrai PRINTF : |%-+.10ld|\n", (long)42);
	TEST("21) Vrai PRINTF : |%ld|\n", (long)-42);
	TEST("22) Vrai PRINTF : |%10ld|\n", (long)-42);
	TEST("23) Vrai PRINTF : |%.10ld|\n", (long)-42);
	TEST("24) Vrai PRINTF : |%+ld|\n", (long)-10);
	TEST("25) Vrai PRINTF : |%10.5ld|\n", (long)-16);
	TEST("26) Vrai PRINTF : |%5.10ld|\n", (long)-16);
	TEST("27) Vrai PRINTF : |%1.1ld|\n", (long)-20);
	TEST("28) Vrai PRINTF : |%-10ld|\n", (long)-50);
	TEST("30) Vrai PRINTF : |%++++++++++ld|\n", (long)69);
	TEST("31) Vrai PRINTF : |%+10ld|\n", (long)-64);
	TEST("32) Vrai PRINTF : |%+.10ld|\n", (long)-64);
	TEST("33) Vrai PRINTF : |%2ld|\n", (long)-20);
	TEST("34) Vrai PRINTF : |%.2ld|\n", (long)-20);
	TEST("35) Vrai PRINTF : |%2ld|\n", (long)-1);
	TEST("36) Vrai PRINTF : |%.2ld|\n", (long)-1);
	TEST("37) Vrai PRINTF : |%-10ld|\n", (long)-80);
	TEST("38) Vrai PRINTF : |%-.10ld|\n", (long)-80);
	TEST("39) Vrai PRINTF : |%06ld|\n", (long)35);
	TEST("40) Vrai PRINTF : |%06ld|\n", (long)-35);
	TEST("41) Vrai PRINTF : |%-+10ld|\n", (long)-40);
	TEST("42) Vrai PRINTF : |%+-10ld|\n", (long)-40);
	TEST("43) Vrai PRINTF : |%05.3ld|\n", (long)5);
	TEST("44) Vrai PRINTF : |%03.5ld|\n", (long)5);
	TEST("45) Vrai PRINTF : |%05.3ld|\n", (long)-5);
	TEST("46) Vrai PRINTF : |%03.5ld|\n", (long)-5);
	TEST("47) Vrai PRINTF : |%ld| |%ld|\n", (long)LONG_MAX, (long)LONG_MIN);
	TEST("48) Vrai PRINTF : |%ld| |%ld|\n", (long)LONG_MAX + 1, (long)LONG_MIN - 1);
	TEST("49) Vrai PRINTF : |%.ld|\n", (long)0);
	TEST("50) Vrai PRINTF : |%.ld|\n", (long)100);
	printf("---------------------%%lld-et-%%lli--------------------\n");	//perfect
	TEST("01) Vrai PRINTF : |%lld|\n", (long long)42);
	TEST("02) Vrai PRINTF : |%lli|\n", (long long)42);
	TEST("03) Vrai PRINTF : |%+lld|\n", (long long)42);
	TEST("04) Vrai PRINTF : |%-lld|\n", (long long)42);
	TEST("05) Vrai PRINTF : |%10lld|\n", (long long)100);
	TEST("06) Vrai PRINTF : |%-10lld|\n", (long long)64);
	TEST("07) Vrai PRINTF : |%.10lld|\n", (long long)100);
	TEST("08) Vrai PRINTF : |%10.5lld|\n", (long long)100);
	TEST("09) Vrai PRINTF : |%5.10lld|\n", (long long)64);
	TEST("10) Vrai PRINTF : |%1.1lld|\n", (long long)16);
	TEST("11) Vrai PRINTF : |%+10lld|\n", (long long)50);
	TEST("12) Vrai PRINTF : |%+2lld|\n", (long long)50);
	TEST("13) Vrai PRINTF : |%+.10lld|\n", (long long)50);
	TEST("14) Vrai PRINTF : |%+.2lld|\n", (long long)50);
	TEST("15) Vrai PRINTF : |%          lld|\n", (long long)1);
	TEST("16) Vrai PRINTF : |% -lld|\n", (long long)1);
	TEST("17) Vrai PRINTF : |%-+lld|\n", (long long)32);
	TEST("18) Vrai PRINTF : |%+-lld|\n", (long long)32);
	TEST("19) Vrai PRINTF : |%-+10lld|\n", (long long)42);
	TEST("20) Vrai PRINTF : |%-+.10lld|\n", (long long)42);
	TEST("21) Vrai PRINTF : |%lld|\n", (long long)-42);
	TEST("22) Vrai PRINTF : |%10lld|\n", (long long)-42);
	TEST("23) Vrai PRINTF : |%.10lld|\n", (long long)-42);
	TEST("24) Vrai PRINTF : |%+lld|\n", (long long)-10);
	TEST("25) Vrai PRINTF : |%10.5lld|\n", (long long)-16);
	TEST("26) Vrai PRINTF : |%5.10lld|\n", (long long)-16);
	TEST("27) Vrai PRINTF : |%1.1lld|\n", (long long)-20);
	TEST("28) Vrai PRINTF : |%-10lld|\n", (long long)-50);
	TEST("30) Vrai PRINTF : |%++++++++++lld|\n", (long long)69);
	TEST("31) Vrai PRINTF : |%+10lld|\n", (long long)-64);
	TEST("32) Vrai PRINTF : |%+.10lld|\n", (long long)-64);
	TEST("33) Vrai PRINTF : |%2lld|\n", (long long)-20);
	TEST("34) Vrai PRINTF : |%.2lld|\n", (long long)-20);
	TEST("35) Vrai PRINTF : |%2lld|\n", (long long)-1);
	TEST("36) Vrai PRINTF : |%.2lld|\n", (long long)-1);
	TEST("37) Vrai PRINTF : |%-10lld|\n", (long long)-80);
	TEST("38) Vrai PRINTF : |%-.10lld|\n", (long long)-80);
	TEST("39) Vrai PRINTF : |%06lld|\n", (long long)35);
	TEST("40) Vrai PRINTF : |%06lld|\n", (long long)-35);
	TEST("41) Vrai PRINTF : |%-+10lld|\n", (long long)-40);
	TEST("42) Vrai PRINTF : |%+-10lld|\n", (long long)-40);
	TEST("43) Vrai PRINTF : |%05.3lld|\n", (long long)5);
	TEST("44) Vrai PRINTF : |%03.5lld|\n", (long long)5);
	TEST("45) Vrai PRINTF : |%05.3lld|\n", (long long)-5);
	TEST("46) Vrai PRINTF : |%03.5lld|\n", (long long)-5);
	TEST("47) Vrai PRINTF : |%lld| |%lld|\n", (long long)LLONG_MAX, (long long)LLONG_MIN);
	TEST("48) Vrai PRINTF : |%lld| |%lld|\n", (long long)LLONG_MAX + 1, (long long)LLONG_MIN - 1);
	TEST("49) Vrai PRINTF : |%.lld|\n", (long long)0);
	TEST("50) Vrai PRINTF : |%.lld|\n", (long long)100);
	
printf("--------------------%%u--------------------\n");		//19/20
	TEST("01) Vrai PRINTF : |%u|\n", 34);
	TEST("02) Vrai PRINTF : |%u|\n", -34);
	TEST("03) Vrai PRINTF : |%-u|\n", 50);
	TEST("04) Vrai PRINTF : |%10u|\n", 90);
	TEST("05) Vrai PRINTF : |%.10u|\n", 90);
	TEST("06) Vrai PRINTF : |%15u|\n", -100);
	TEST("07) Vrai PRINTF : |%.15u|\n", -100);
	TEST("08) Vrai PRINTF : |%10.5u|\n", 52);
	TEST("09) Vrai PRINTF : |%5.10u|\n", 52);
	TEST("10) Vrai PRINTF : |%20.15u|\n", -100000);
	TEST("11) Vrai PRINTF : |%15.20u|\n", -100000);
	TEST("12) Vrai PRINTF : |%-10u|\n", 144);
	TEST("13) Vrai PRINTF : |%-.10u|\n", 144);
	TEST("14) Vrai PRINTF : |%-20u|\n", -20000000);
	TEST("15) Vrai PRINTF : |%08u|\n", 64);
	TEST("16) Vrai PRINTF : |%03.4u|\n", 10);
	TEST("17) Vrai PRINTF : |%u|\n", 0);
	TEST("18) Vrai PRINTF : |%.u|\n", 0);
	TEST("19) Vrai PRINTF : |%10u|\n", 0);
	TEST("20) Vrai PRINTF : |%.u|\n", 88);
	TEST("21) Vrai PRINTF : |%u|\n", UINT_MAX);
	TEST("22) Vrai PRINTF : |%u| |%u|\n", (unsigned int)-1, UINT_MAX + 1);
	printf("---------------------%%hu--------------------\n");
	TEST("01) Vrai PRINTF : |%hu|\n", (unsigned short)34);
	TEST("02) Vrai PRINTF : |%hu|\n", (unsigned short)-34);
	TEST("03) Vrai PRINTF : |%-hu|\n", (unsigned short)50);
	TEST("04) Vrai PRINTF : |%10hu|\n", (unsigned short)90);
	TEST("05) Vrai PRINTF : |%.10hu|\n", (unsigned short)90);
	TEST("06) Vrai PRINTF : |%15hu|\n", (unsigned short)-100);
	TEST("07) Vrai PRINTF : |%.15hu|\n", (unsigned short)-100);
	TEST("08) Vrai PRINTF : |%10.5hu|\n", (unsigned short)52);
	TEST("09) Vrai PRINTF : |%5.10hu|\n", (unsigned short)52);
	TEST("10) Vrai PRINTF : |%20.15hu|\n", (unsigned short)-10000);
	TEST("11) Vrai PRINTF : |%15.20hu|\n", (unsigned short)-10000);
	TEST("12) Vrai PRINTF : |%-10hu|\n", (unsigned short)144);
	TEST("13) Vrai PRINTF : |%-.10hu|\n", (unsigned short)144);
	TEST("14) Vrai PRINTF : |%-20hu|\n", (unsigned short)-20000);
	TEST("15) Vrai PRINTF : |%08hu|\n", (unsigned short)64);
	TEST("16) Vrai PRINTF : |%03.4hu|\n", (unsigned short)10);
	TEST("17) Vrai PRINTF : |%.hu|\n", (unsigned short)0);
	TEST("18) Vrai PRINTF : |%.hu|\n", (unsigned short)88);
	TEST("19) Vrai PRINTF : |%hu|\n", (unsigned short)USHRT_MAX);
	TEST("20) Vrai PRINTF : |%hu| |%hu|\n", (unsigned short)-1, (unsigned short)65536);
	printf("---------------------%%hhu--------------------\n");
	TEST("01) Vrai PRINTF : |%hhu|\n", (unsigned char)34);
	TEST("02) Vrai PRINTF : |%hhu|\n", (unsigned char)-34);
	TEST("03) Vrai PRINTF : |%-hhu|\n", (unsigned char)50);
	TEST("04) Vrai PRINTF : |%10hhu|\n", (unsigned char)90);
	TEST("05) Vrai PRINTF : |%.10hhu|\n", (unsigned char)90);
	TEST("06) Vrai PRINTF : |%15hhu|\n", (unsigned char)-100);
	TEST("07) Vrai PRINTF : |%.15hhu|\n", (unsigned char)-100);
	TEST("08) Vrai PRINTF : |%10.5hhu|\n", (unsigned char)52);
	TEST("09) Vrai PRINTF : |%5.10hhu|\n", (unsigned char)52);
	TEST("10) Vrai PRINTF : |%20.15hhu|\n", (unsigned char)-100);
	TEST("11) Vrai PRINTF : |%15.20hhu|\n", (unsigned char)-100);
	TEST("12) Vrai PRINTF : |%-10hhu|\n", (unsigned char)144);
	TEST("13) Vrai PRINTF : |%-.10hhu|\n", (unsigned char)144);
	TEST("14) Vrai PRINTF : |%-20hhu|\n", (unsigned char)-20);
	TEST("15) Vrai PRINTF : |%08hhu|\n", (unsigned char)64);
	TEST("16) Vrai PRINTF : |%03.4hhu|\n", (unsigned char)10);
	TEST("17) Vrai PRINTF : |%.hhu|\n", (unsigned char)0);
	TEST("18) Vrai PRINTF : |%.hhu|\n", (unsigned char)88);
	TEST("19) Vrai PRINTF : |%hhu|\n", (unsigned char)127);
	TEST("20) Vrai PRINTF : |%hhu| |%hhu|\n", (unsigned char)-1, (unsigned char)128);
	printf("---------------------%%lu--------------------\n");
	TEST("01) Vrai PRINTF : |%lu|\n",(unsigned long)34);
	TEST("02) Vrai PRINTF : |%lu|\n", (unsigned long)-34);
	TEST("03) Vrai PRINTF : |%-lu|\n", (unsigned long)50);
	TEST("04) Vrai PRINTF : |%10lu|\n", (unsigned long)90);
	TEST("05) Vrai PRINTF : |%.10lu|\n", (unsigned long)90);
	TEST("06) Vrai PRINTF : |%15lu|\n", (unsigned long)-100);
	TEST("07) Vrai PRINTF : |%.15lu|\n", (unsigned long)-100);
	TEST("08) Vrai PRINTF : |%10.5lu|\n", (unsigned long)52);
	TEST("09) Vrai PRINTF : |%5.10lu|\n", (unsigned long)52);
	TEST("10) Vrai PRINTF : |%20.15lu|\n", (unsigned long)-100000);
	TEST("11) Vrai PRINTF : |%15.20lu|\n", (unsigned long)-100000);
	TEST("12) Vrai PRINTF : |%-10lu|\n", (unsigned long)144);
	TEST("13) Vrai PRINTF : |%-.10lu|\n", (unsigned long)144);
	TEST("14) Vrai PRINTF : |%-20lu|\n", (unsigned long)-20000000);
	TEST("15) Vrai PRINTF : |%08lu|\n", (unsigned long)64);
	TEST("16) Vrai PRINTF : |%03.4lu|\n", (unsigned long)10);
	TEST("17) Vrai PRINTF : |%.lu|\n", (unsigned long)0);
	TEST("18) Vrai PRINTF : |%.lu|\n", (unsigned long)88);
	TEST("19) Vrai PRINTF : |%lu|\n", (unsigned long)ULONG_MAX);
	TEST("20) Vrai PRINTF : |%lu| |%lu|\n", (unsigned long)-1, (unsigned long)ULONG_MAX + 1);
	printf("---------------------%%llu--------------------\n");
	TEST("01) Vrai PRINTF : |%llu|\n",(unsigned long long)34);
	TEST("02) Vrai PRINTF : |%llu|\n", (unsigned long long)-34);
	TEST("03) Vrai PRINTF : |%-llu|\n", (unsigned long long)50);
	TEST("04) Vrai PRINTF : |%10llu|\n", (unsigned long long)90);
	TEST("05) Vrai PRINTF : |%.10llu|\n", (unsigned long long)90);
	TEST("06) Vrai PRINTF : |%15llu|\n", (unsigned long long)-100);
	TEST("07) Vrai PRINTF : |%.15llu|\n", (unsigned long long)-100);
	TEST("08) Vrai PRINTF : |%10.5llu|\n", (unsigned long long)52);
	TEST("09) Vrai PRINTF : |%5.10llu|\n", (unsigned long long)52);
	TEST("10) Vrai PRINTF : |%20.15llu|\n", (unsigned long long)-100000);
	TEST("11) Vrai PRINTF : |%15.20llu|\n", (unsigned long long)-100000);
	TEST("12) Vrai PRINTF : |%-10llu|\n", (unsigned long long)144);
	TEST("13) Vrai PRINTF : |%-.10llu|\n", (unsigned long long)144);
	TEST("14) Vrai PRINTF : |%-20llu|\n", (unsigned long long)-20000000);
	TEST("15) Vrai PRINTF : |%08llu|\n", (unsigned long long)64);
	TEST("16) Vrai PRINTF : |%03.4llu|\n", (unsigned long long)10);
		// printf("17) Vrai PRINTF : |%.llu|\n", (unsigned long long)0);
	// 	TEST("18) Vrai PRINTF : |%.llu|\n", (unsigned long long)88);
	TEST("19) Vrai PRINTF : |%llu|\n", (unsigned long long)ULLONG_MAX);
	TEST("20) Vrai PRINTF : |%llu| |%llu|\n", (unsigned long long)-1, (unsigned long long)ULLONG_MAX + 1);
	}

void	f(pf,ft)
{printf("--------------------%%f--------------------\n");
	TEST("01) Vrai PRINTF	: |%.10Lf|\n", (long double)243.5);
	TEST("02) Vrai PRINTF	: |%f|\n", 3.55);
	TEST("03) Vrai PRINTF	: |%5f|\n", 9877893.5123109);
	TEST("04) Vrai PRINTF	: |%5Lf|\n", (long double)9877893.5123109);
	TEST("05) Vrai PRINTF	: |%10.1f|\n", 243.59);
	TEST("06) Vrai PRINTF	: |%.4Lf|\n", (long double)243.5);
	TEST("07) Vrai PRINTF	: |%lf|\n", 243.5);
	TEST("08) Vrai PRINTF	: |%.5f|\n", 3.5);
	TEST("09) Vrai PRINTF	: |%Lf|\n", (long double)243.5);
	TEST("10) Vrai PRINTF	: |%f|\n", -10.011012365432);
	TEST("11) Vrai PRINTF	: |%4Lf|\n", (long double)243.59);
	TEST("12) Vrai PRINTF	: |%1f|\n", 243.59);
}

void	percent(pf,ft)
{
printf("--------------------%%--------------------\n");	
	TEST("%-03%.%%.\n");
	TEST("%03%.%%.\n");
	TEST("%-%%%\n");
	TEST("%%%%%%\n");
	TEST("PLUS%+%\n");
	TEST("titi.% +---3.5%.et%%%-0004%.et.%+1%\n");
	TEST("titi.% 0+---3.5%.et%%%-0004%.et.%+1%\n");
	TEST("titi.% 0+3.5%.et%%%-0004%.et.%+1%\n");
	TEST("titi.%0+3.5%.et%%%-0004%.et.%+1%\n");
	// %
	// printf("titi.%-0004%.\n");
	// 
}


void	p(pf,ft)
{
	// printf("--------------------%%p--------------------\n");			//perfect
	int		*tab = malloc(sizeof(int) * 10);
	int		*tab2 = malloc(0);

printf("--------------------%%p_NULL--------------------\n");			//perfect	
	TEST("%.p\n",NULL);// UB
	TEST("%p\n","\0");
	TEST("%p\n","/0");
	TEST("%p\n","");
	TEST("%p\n",NULL);
	TEST("(p) Vrai PRINTF : |%p|\n", "OK");
	TEST("02) Vrai PRINTF : |%-p|\n", tab2);
	TEST("03) Vrai PRINTF : |%---------p|\n", "test2");
	TEST("04) Vrai PRINTF : |%10p|\n", "42");
	TEST("05) Vrai PRINTF : |%-10p|\n", "42");
	TEST("06) Vrai PRINTF : |%2p|\n", tab);
	TEST("07) Vrai PRINTF : |%-2p|\n", tab);
	TEST("11) Vrai PRINTF : |%p|\n", "\0\0\0\0\0");
	TEST("12) Vrai PRINTF : |%20p|\n", "\0\0\0\0\0");
	TEST("13) Vrai PRINTF : |%p|\n", "");
	TEST("14) Vrai PRINTF : |%p|\n", NULL);
	TEST("15) Vrai PRINTF : |%10p|\n", NULL);
	TEST("16) Vrai PRINTF : |%-10p|\n", NULL);
	/*
	TEST("(+30.1p) Vrai PRINTF : |%+30.1p|\n", "K");
	TEST("(20.2p) Vrai PRINTF : |%20.2p|\n", "OK");
	TEST("(-020.p) Vrai PRINTF : |%-020.p|\n", "K");
	TEST("(-020.0p) Vrai PRINTF : |%-020.0p|\n", "K");
	TEST("(020.p) Vrai PRINTF : |%020.p|\n", "ER");
	TEST("(020.0p) Vrai PRINTF : |%020.0p|\n", "ER");
	TEST("(030.1p) Vrai PRINTF : |%030.1p|\n", "ER");
	TEST("(3.2p) Vrai PRINTF : |%3.2p|\n", "OK");
	TEST("( 30.1p) Vrai PRINTF : |% 30.1p|\n", "K");
	TEST("( 20.2p) Vrai PRINTF : |% 20.2p|\n", "OK");
	TEST("(- 020.p) Vrai PRINTF : |%- 020.p|\n", "K");
	TEST("(-#020.0p) Vrai PRINTF : |%-#020.0p|\n", "K");
	TEST("(020.0p) Vrai PRINTF : |%020.0p|\n", "ER");
	TEST("(030.1p) Vrai PRINTF : |%030.1p|\n", "ER");
	TEST("(3.2p) Vrai PRINTF : |%3.2p|\n", "OK");
	TEST("(--20.-25p) Vrai PRINTF : |%--20.-25p|\n", "ER");
	TEST("(--20.-42p) Vrai PRINTF : |%--20.-42p|\n", "ER");
	TEST("(020.-42p) Vrai PRINTF : |%020.-42p|\n", "ER");
	TEST("(020.- 42p) Vrai PRINTF : |%020.- 42p|\n", "ER");
	TEST("(020.-3p) Vrai PRINTF : |%020.-3p|\n", "ER");
	TEST("(020.p) Vrai PRINTF : |%020.p|\n", "ER");
	TEST("(020.0p) Vrai PRINTF : |%020.0p|\n", "ER");
	TEST("(015.3p) Vrai PRINTF : |%015.3p|\n", "ER");
	TEST("(015.15p) Vrai PRINTF : |%015.15p|\n", "ER");
	TEST("(015.16p) Vrai PRINTF : |%015.16p|\n", "ER");
	TEST("(--15.-16p) Vrai PRINTF : |%--15.-16p|\n", "ER");
	TEST("(015.20p) Vrai PRINTF : |%015.20p|\n", "ER");
	TEST("(025.42p) Vrai PRINTF : |%025.42p|\n", "ER");
	TEST("(--15.16p) Vrai PRINTF : |%--15.16p|\n", "ER");
	TEST("(--20.16p) Vrai PRINTF : |%--20.16p|\n", "ER");
	TEST("(15.16p) Vrai PRINTF : |%15.16p|\n", "ER");
	TEST("(20.16p) Vrai PRINTF : |%20.16p|\n", "ER");
	TEST("(-30.16p) Vrai PRINTF : |%-30.16p|\n", "ER");
	
*/
	free(tab);
	free(tab2);

	
// printf("--------------------%%p-special char-------------------\n");			//perfect
	// printf("test %-7C %007d%-10.2ls!!\n", 0xd777, 0x45, "L〻");
	// 

}

void	s(pf,ft)
{
printf("--------------------%%s--------------------\n");
	TEST("NULL:|%.2s|\n",NULL);
	TEST("01) Vrai PRINTF : |%.2s|\n", "salut");
	TEST("02) Vrai PRINTF : |%-s|\n", "test");
	TEST("03) Vrai PRINTF : |%---------s|\n", "test2");
	TEST("04) Vrai PRINTF : |%10s|\n", "42");
	TEST("05) Vrai PRINTF : |%-10s|\n", "42");
	TEST("06) Vrai PRINTF : |%2s|\n", "string");
	TEST("07) Vrai PRINTF : |%-2s|\n", "string");
	TEST("08) Vrai PRINTF : |%.15s|\n", "precision");
	TEST("09) Vrai PRINTF : |%.4s|\n", "precision");
	TEST("10) Vrai PRINTF : |%.0s|\n", "precision");
	TEST("11) Vrai PRINTF : |%s|\n", "\0\0\0\0\0");
	TEST("12) Vrai PRINTF : |%10s|\n", "\0\0\0\0\0");
	TEST("13) Vrai PRINTF : |%s|\n", "");
	TEST("14) Vrai PRINTF : |%-.2s|\n", "boom");
	TEST("15) Vrai PRINTF : |%10.8s|\n", "google");
	TEST("16) Vrai PRINTF : |%10.2s|\n", "twitter");
	TEST("17) Vrai PRINTF : |%2.10s|\n", "samsung");
	TEST("18) Vrai PRINTF : |%2.5s|\n", "printf");
	TEST("19) Vrai PRINTF : |%-10.2s|\n", "424242424242");
	TEST("20) Vrai PRINTF : |%1.0s|\n", "123456789");
	TEST("20) Vrai PRINTF : |%-1.0s|\n", "123456789");
	TEST("21) Vrai PRINTF : |%s|\n", NULL);
	TEST("22) Vrai PRINTF : |%10s|\n", NULL);
	TEST("23) Vrai PRINTF : |%-10s|\n", NULL);
	TEST("24) Vrai PRINTF : |%.2s|\n", NULL);
	TEST("25) Vrai PRINTF : |%10.8s|\n", NULL);
	TEST("26) Vrai PRINTF : |%10.2s|\n", NULL);
	TEST("27) Vrai PRINTF : |%2.10s|\n", NULL);
	TEST("28) Vrai PRINTF : |%2.5s|\n", NULL);
	TEST("29) Vrai PRINTF : |%-10.2s|\n", NULL);
	TEST("30) Vrai PRINTF : |%1.0s|\n", NULL);
	TEST("31) Vrai PRINTF : |%-1.s|\n", NULL);
printf("---------------------%%s-width_prec-------------------\n");			//Perfect	
	TEST("%-5.10s. is a string\n", "987654");
	TEST("%-6.10s. is a string\n", "987654");
	TEST("%-7.10s. is a string\n", "987654");
	TEST("%-8.10s. is a string\n", "987654");
	TEST("%-2.6s. is a string\n", "321012");
printf("---------------------mix%%s--------------------\n");			//Perfect	
	TEST("%4.2s %-1.s\n" , "coco", NULL);
	TEST("Coucou %.0s\n%s%---12s\n", "hi", "coco", NULL);
	TEST("|%1.4s| et |%-6.8s| et |%4.2s|\n", "tuuu", "12345", "hu");
	}

void	c(pf,ft)
{
printf("--------------------%%c--------------------\n");		//Perfect
	TEST("01) Vrai PRINTF : |%c|\n", 'a');
	TEST("02) Vrai PRINTF : |%-c|\n", 'z');
	TEST("03) Vrai PRINTF : |%-----c|\n", '!');
	TEST("04) Vrai PRINTF : |%5c|\n", 'R');
	TEST("05) Vrai PRINTF : |%-5c|\n", 'R');
	TEST("06) Vrai PRINTF : |%1c|\n", '3');
	TEST("07) Vrai PRINTF : |%c|\n", '\0');
	TEST("08) Vrai PRINTF : |%5c|\n", '\0');
	TEST("09) Vrai PRINTF : |%-5c|\n", '\0');
	TEST("10) Vrai PRINTF : |%1c|\n", '\0');
	TEST("hello ca%-c.\n", 'x');
	TEST("hello ca%-c.\n", 0);
	TEST("hello ca%----4c %1c va %10c%-c.??\n", '\0', '\n', (char)564, 0);
	TEST("%c\n",(char)564);
	}

void limit(pf,ft)
{
	// printf("ptf:s=%s\n","1");
	// printf("ptf:p=%p\n","1");
	// printf("ptf:lu=%lu\n",(unsigned long)"1");
	// printf("ptf:s=%s",ultoa_base((unsigned long)"1",16));
	// printf("sizeof char = %d",(int)sizeof(char));

	printf("SCHAR_MAX		:%hhd\n", (char)SCHAR_MAX);
	printf("SCHAR_MIN		:%hhd\n", (char)SCHAR_MIN);
	printf("UCHAR_MAX		:%hhd\n", (unsigned char)UCHAR_MAX);
	printf("UCHAR_MAX		:%hhu\n", (unsigned char)UCHAR_MAX);
	
	printf("Short void	printed by %%d == %%i: Signed int\n");
	printf("SHRT_MAX		:%hd\n", (short)SHRT_MAX);
	printf("SHRT_MIN		:%hd\n", (short)SHRT_MIN);
	printf("USHRT_MAX		:%d\n", (unsigned short)USHRT_MAX);
	printf("USHRT_MAX		:%hd\n", (unsigned short)USHRT_MAX);
	
	printf("USHRT_MAX		:%d\n", USHRT_MAX);
	printf("USHRT_MAX		:%d\n", (unsigned short)USHRT_MAX);
	printf("\n");
	
	printf("unsigned char printed by %%d == %%i: Signed int\n");
	printf("SHRT_MAX		:%hd\n", (short)SHRT_MAX);
	printf("SHRT_MIN		:%hd\n", (short)SHRT_MIN);
	printf("USHRT_MAX		:%hd\n", (unsigned short)USHRT_MAX);
	printf("\n");
	
	printf("%%d == %%i: Signed int\n");
	printf("INT_MAX			:%d\n", INT_MAX);
	printf("INT_MIN			:%d\n", INT_MIN);
	printf("UINT_MAX		:%d (out of range)\n", UINT_MAX);
	printf("\n");

	printf("%%i == %%d: Signed int\n");
	printf("INT_MAX			:%i\n", INT_MAX);
	printf("INT_MIN			:%i\n", INT_MIN);
	printf("UINT_MAX		:%i (out of range)\n", UINT_MAX);
	printf("\n");
	
	printf("%%u: unsigned int\n");
	printf("INT_MAX			:%u\n", INT_MAX);
	printf("INT_MIN			:%u (minus disappeared)\n", INT_MIN);
	printf("UINT_MAX		:%u\n", UINT_MAX);
	printf("\n");
	
	printf("%%ld == %%li: Signed long\n");
	printf("LONG_MAX 	:%ld\n", LONG_MAX);
	printf("LONG_MIN 	:%ld\n", LONG_MIN);
	printf("ULONG_MAX  	:%ld (out of range)\n", ULONG_MAX);
	printf("\n");

	printf("%%li == %%ld: Signed long\n");
	printf("LONG_MAX 	:%li\n", LONG_MAX);
	printf("LONG_MIN 	:%li\n", LONG_MIN);
	printf("ULONG_MAX  	:%li (out of range)\n", ULONG_MAX);
	printf("\n");

	printf("%%lu: unsigned long\n");
	printf("LONG_MAX 	:%lu\n", LONG_MAX);
	printf("LONG_MIN 	:%lu (minus disappeared)\n", LONG_MIN);
	printf("ULONG_MAX  	:%lu\n", ULONG_MAX);
	printf("\n");

	printf("%%lld == %%lli: signed long long\n");
	printf("(lld, LLONG_MAX)	:%lld\n", LLONG_MAX);
	printf("(lld, LLONG_MIN)	:%lld\n", LLONG_MIN);
	printf("(lld, ULLONG_MAX)	:%lld (out of range)\n", ULLONG_MAX);
	printf("\n");

	printf("%%lli == %%lld: signed long long\n");
	printf("(lli, LLONG_MAX)	:%lli\n", LLONG_MAX);
	printf("(lli, LLONG_MIN)	:%lli\n", LLONG_MIN);
	printf("(lli, ULLONG_MAX)	:%lli (out of range)\n", ULLONG_MAX);
	printf("\n");
	
	printf("%%llu: unsigned long long\n");
	printf("(llu, LLONG_MAX)	:%llu\n", LLONG_MAX);
	printf("(llu, LLONG_MIN)	:%llu (minus disappeared)\n", LLONG_MIN);
	printf("(llu, ULLONG_MAX)	:%llu\n", ULLONG_MAX);
	printf("\n");
}

int		main(void)
{
	// 	// 	// percent();
	int		pf;
	int		ft;
// printf("ptf:%.0p\n", NULL);
// ft_printf("mtf:%.0p\n", NULL);
// TEST("%.p", NULL);
	// o(pf,ft);
	// x(pf,ft);
	// X(pf,ft);
	// c(pf,ft);
	// s(pf,ft);
	// p(pf,ft);
	diu(pf,ft);
	
	//limit(pf,ft);

	// printf("%p",&free);
	// TEST("1=%s\n2=%p\n3=%d\n4=%d\n5=%p\n6=%s\n7=%p\n8=%p\n9=%s\n",
	// 		"a", &free, 1,     2,      &malloc, "b",    &free,  &malloc, "c")  ;
	// TEST("#2x|%#2x|\n", 0);
	// TEST("#2llx|%#2llx|\n", (unsigned long long)0);
	// TEST("#2hx|%#2hx|\n", (unsigned short)0);
	// TEST("#2hhx|%#2hhx|\n", (unsigned char)0);
	// TEST("#2lx|%#2lx|\n", (unsigned long)0);
	// TEST("#2llx|%#2llx|\n", (unsigned long long)0);
	// TEST("#.o|%#.o|\n", 0);
	// TEST(".o|%.o|\n", 0);
	

	// printf("0.1) Vrai PRINTF : |%#08x|\n", 42);
	// 	// printf("0.2)@moulitest: |%5.x.A.%5.0x.|\n", 0, 0);
	// 
	// TEST("1) Vrai PRINTF : |%0.x|\n", 30004);
	// TEST("2) Vrai PRINTF : |%0.0x|\n", 30004);
	// TEST("3) Vrai PRINTF : |%010.x|\n", 30004);
	// TEST("4) Vrai PRINTF : |%#10x|\n", 30004);
	// TEST("5) : |%-+#10x|\n", 0);
	// TEST("6) : |%-+#10X|\n", 30004);
	// TEST("7) : |% 10x|\n", 30004);

	//segmentation fault
	// ft_printf("sizeof INT=%s\n",42); 
	
	ft_printf("s=%s\nd=%d\n","42",42); 
	ft_printf("d=%d\ns=%s\n",42,"42"); 

	// ft_printf("s=%s\n",42); 
	// ft_printf("p1=%p\np2=%p",&free,&free); 
	// ft_printf("1=%s\n2=%p\n3=%d\n4=%d\n5=%p\n6=%s\n7=%p\n8=%p\n9=%s\n",
	// 		"a", &free, 1,     2,      &malloc, "b",    &free,  &malloc, "c")  ;

	// ft_printf("\n\n\n\n\n\n"); 

	// ft_printf("sizeof S=%s\n","AB"); 
	
	return (0);
}