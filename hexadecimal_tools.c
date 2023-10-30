/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:01:57 by lnicolli          #+#    #+#             */
/*   Updated: 2023/10/30 19:43:25 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>

char	*int2hex(int num)
{
	char			*hexdigits;
	int				i;
	char			*hexstring;
	unsigned int	n;
	int				index;

	hexdigits = "0123456789ABCDEF";
	hexstring = malloc(9);
	if (!hexstring)
		return (hexstring);
	i = 0;
	hexstring[0] = '0';
	hexstring[1] = '\0';
	if (num == 0)
		return (hexstring);
	n = (unsigned int)num;
	while (i < 8)
	{
		index = n & 0xF;
		hexstring[7 - i++] = hexdigits[index];
		n >>= 4;
	}
	hexstring[8] = '\0';
	return (hexstring);
}

char	*ft_hextolowe(char *str)
{
	char	*strstart;

	strstart = str;
	while (*str)
	{
		*str = ft_tolower(*str);
		str++;
	}
	return (strstart);
}

char	*long2hex(long num)
{
	char			*hexdigits;
	int				i;
	char			*hexstring;
	unsigned long	n;
	int				index;

	hexdigits = "0123456789ABCDEF";
	hexstring = malloc(17);
	if (!hexstring)
		return (hexstring);
	i = 0;
	hexstring[0] = '0';
	hexstring[1] = '\0';
	if (num == 0)
		return (hexstring);
	n = (unsigned long)num;
	while (i < 16)
	{
		index = n & 0xF;
		hexstring[15 - i++] = hexdigits[index];
		n >>= 4;
	}
	hexstring[16] = '\0';
	return (hexstring);
}
