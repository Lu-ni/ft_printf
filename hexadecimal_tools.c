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

	unsigned int n = (unsigned int) num; // Use unsigned int for negative numbers

	for (i = 0; i < 8; i++)
	{
		int index = n & 0xF; // Get the last 4 bits (one hex digit)
		hexString[7 - i] = hexDigits[index];
		n >>= 4; // Shift right by 4 bits to get the next digit
	}

	hexString[8] = '\0';

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

	unsigned long n = (unsigned long) num; // Use unsigned long for negative numbers

	for (i = 0; i < 16; i++)
	{
		int index = n & 0xF; // Get the last 4 bits (one hex digit)
		hexString[15 - i] = hexDigits[index];
		n >>= 4; // Shift right by 4 bits to get the next digit
	}

	hexString[16] = '\0';

	return hexString;
}
