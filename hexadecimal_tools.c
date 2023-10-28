#include "libft/libft.h"
#include <stdlib.h>

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
