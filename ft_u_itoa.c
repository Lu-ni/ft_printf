/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:02:02 by lnicolli          #+#    #+#             */
/*   Updated: 2023/10/30 19:00:09 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getlen(long num)
{
	int	len;

	if (num == 0)
		return (1);
	len = 0;
	if (num < 0)
		len++;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_u_itoa(unsigned int n)
{
	int		signe;
	int		len;
	char	*str;

	signe = 1;
	len = ft_getlen(n);
	if (n < 0)
		signe = -1;
	str = ft_calloc(len + 1, 1);
	if (!str)
		return (str);
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[--len] = (n % 10) * signe + '0';
		n /= 10;
	}
	if (signe == -1)
		str[0] = '-';
	return (str);
}
