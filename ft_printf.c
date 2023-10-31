/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:04:06 by lnicolli          #+#    #+#             */
/*   Updated: 2023/10/31 13:25:44 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_u_itoa.h"
#include "libft/libft.h"
#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_va_list.h>

static int	print_s(va_list *ap, int *count)
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

static int	print_i(va_list *ap, int *count)
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

static int	print_any(char *str, va_list *ap, int *count)
{
	if (*(str + 1) == '\0')
		return (1);
	if (*(str + 1) == 'c')
		print_c(ap, count);
	else if (*(str + 1) == 's')
		print_s(ap, count);
	else if (*(str + 1) == 'p')
		print_p(ap, count);
	else if (*(str + 1) == 'd')
		print_i(ap, count);
	else if (*(str + 1) == 'i')
		print_i(ap, count);
	else if (*(str + 1) == 'u')
		print_u(ap, count);
	else if (*(str + 1) == 'x')
		print_x(ap, count);
	else if (*(str + 1) == 'X')
		print_xbig(ap, count);
	else if (*(str + 1) == '%')
	{
		ft_putchar_fd('%', 1);
		*count += 1;
	}
	return (0);
}

static int	print_char(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

int	ft_printf(const char *args, ...)
{
	va_list	ap;
	char	*str;
	char	*strstart;
	int		count;

	if (!*args)
		return (0);
	str = ft_strdup(args);
	strstart = str;
	count = 0;
	va_start(ap, args);
	while (*str)
	{
		if (*str == '%')
		{
			if (print_any(str++, &ap, &count))
				str = (char *) 0;
		}
		else
			count += print_char(*str, 1);
		str++;
	}
	va_end(ap);
	free(strstart);
	return (count);
}
