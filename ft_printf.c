/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:04:06 by lnicolli          #+#    #+#             */
/*   Updated: 2023/10/30 18:49:39 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_u_itoa.h"
#include "ft_printf.h"
#include "libft/libft.h"
#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int	print_s(va_list *ap, int *count)
{
	char	*str;

	str = (char *)va_arg(*ap, const char *);
	if (str)
	{
		ft_putstr_fd(str, 1);
		*count += ft_strlen(str);
	}
	else
	{
		ft_putstr_fd("(null)", 1);
		*count += 6;
	}
	return (0);
}

int	print_i(va_list *ap, int *count)
{
	char	*str;

	str = ft_itoa(va_arg(*ap, int));
	if (!str)
		return (1);
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
	return (0);
}
int	ft_printf(const char *args, ...)
{
	va_list	ap;
	char	*ola;
	char	*olastart;
	int		count;

	ola = ft_strdup(args);
	olastart = ola;
	count = 0;
	va_start(ap, args);
	while (*ola)
	{
		if (*ola == '%')
		{
			if (*(ola + 1) == '\0')
				return (0); // a modifier car ca ne return pas la bonne valeur
			if (*(ola + 1) == 'c')
				print_c(&ap, &count);
			else if (*(ola + 1) == 's')
				print_s(&ap, &count);
			else if (*(ola + 1) == 'p')
				print_p(&ap, &count);
			else if (*(ola + 1) == 'd')
				print_i(&ap, &count);
			else if (*(ola + 1) == 'i')
				print_i(&ap, &count);
			else if (*(ola + 1) == 'u')
				print_u(&ap, &count);
			else if (*(ola + 1) == 'x')
				print_x(&ap, &count);
			else if (*(ola + 1) == 'X')
				print_X(&ap, &count);
			else if (*(ola + 1) == '%')
			{
				ft_putchar_fd('%', 1);
				count++;
			}
			ola++;
		}
		else
		{
			count++;
			ft_putchar_fd(*ola, 1);
		}
		ola++;
	}
	va_end(ap);
	free(olastart);
	return (count);
}
