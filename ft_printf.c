#include "libft/libft.h"
#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

char *ft_hextolowe(char *str)
{
	char *strstart;
	strstart = str;
	while (*str)
	{
		*str = ft_tolower(*str);
		str++;
	}
	return (strstart);
}
char *longToHex(long num)
{
	char *hexDigits = "0123456789ABCDEF";
	char *hexString = malloc(17); // 16 characters for hex + 1 for '\0'
	int   i = 0;

	// Handle zero explicitly to simplify the loop
	if (num == 0)
	{
		hexString[0] = '0';
		hexString[1] = '\0';
		return hexString;
	}

	while (num > 0)
	{
		long remainder = num % 16;
		hexString[i++] = hexDigits[remainder];
		num /= 16;
	}
	hexString[i] = '\0';

	// Reverse the string
	for (int start = 0, end = i - 1; start < end; start++, end--)
	{
		char temp = hexString[start];
		hexString[start] = hexString[end];
		hexString[end] = temp;
	}

	return hexString;
}

char *intToHex(int num)
{
	char *hexDigits = "0123456789ABCDEF";
	char *hexString = malloc(9); // 8 characters for hex + 1 for '\0'
	int   i = 0;

	// Handle zero explicitly to simplify the loop
	if (num == 0)
	{
		hexString[0] = '0';
		hexString[1] = '\0';
		return hexString;
	}

	while (num > 0)
	{
		int remainder = num % 16;
		hexString[i++] = hexDigits[remainder];
		num /= 16;
	}
	hexString[i] = '\0';

	// Reverse the string
	for (int start = 0, end = i - 1; start < end; start++, end--)
	{
		char temp = hexString[start];
		hexString[start] = hexString[end];
		hexString[end] = temp;
	}

	return hexString;
}

int print_p(va_list *ap)
{
	char prefix[3];
	prefix[0] = '0';
	prefix[1] = 'x';
	prefix[2] = '\0';
	ft_putstr_fd(prefix, 1);
	ft_putstr_fd(ft_hextolowe(longToHex(va_arg(*ap, long))), 1);
	return (0);
}

int ft_printf(const char *args, ...)
{
	va_list ap;
	int     i;
	char   *ola = ft_strdup(args);
	va_start(ap, args);
	while (*ola)
	{
		if (*ola == '%')
		{
			if (*(ola + 1) == '\0')
				return (0);
			if (*(ola + 1) == '%')
			{
				ft_putchar_fd('%', 1);
				ola++;
			}
			if (*(ola + 1) == 'c')
			{
				ft_putchar_fd(va_arg(ap, int), 1);
				ola++;
			}
			if (*(ola + 1) == 's')
			{
				ft_putstr_fd((char *) va_arg(ap, const char *), 1);
				ola++;
			}
			if (*(ola + 1) == 'i')
			{
				ft_putstr_fd(ft_itoa(va_arg(ap, int)), 1);
				ola++;
			}
			if (*(ola + 1) == 'X')
			{
				ft_putstr_fd(intToHex(va_arg(ap, int)), 1);
				ola++;
			}
			if (*(ola + 1) == 'x')
			{
				ft_putstr_fd(ft_hextolowe(intToHex(va_arg(ap, int))), 1);
				ola++;
			}
			if (*(ola + 1) == 'p')
			{
				print_p(&ap);
				ola++;
			}
		}
		else
		{
			ft_putchar_fd(*ola, 1);
		}
		ola++;
	}
	va_end(ap);
	return 0;
}

int main(void)
{
	char *ptr = malloc(12);
	ft_printf("%% je suis %s et j'ai %i%i%i ans %c%x%X%c%p", "lucas", 1, 2, 3, '#', 0xfa, 0xfa, '@', ptr);
	printf("         %X ptr:%p", 0xFF, ptr);
}
