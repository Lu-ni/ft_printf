#include "ft_u_itoa.h"
#include "hexatools.h"
#include "libft/libft.h"
#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int	print_p(va_list *ap, int *count)
{
	char	prefix[3];
	char	*str;
	int		i;

	i = 0;
	prefix[0] = '0';
	prefix[1] = 'x';
	prefix[2] = '\0';
	str = ft_hextolowe(longToHex(va_arg(*ap, long)));
	if (!str)
		return (1);
	while (str[i] == '0')
		i++;
	if (str[i] == '\0')
		i--;
	ft_putstr_fd(prefix, 1);
	ft_putstr_fd(&str[i], 1);
	*count += 2 + ft_strlen(&str[i]);
	free(str);
	return (0);
}
int	print_u(va_list *ap, int *count)
{
	char	*str;

	str = ft_u_itoa(va_arg(*ap, unsigned int));
	if (!str)
		return (1);
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
	return (0);
}
int	print_c(va_list *ap, int *count)
{
	ft_putchar_fd(va_arg(*ap, int), 1);
	*count += 1;
	return (0);
}
int	print_x(va_list *ap, int *count)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_hextolowe(intToHex(va_arg(*ap, int)));
	if (!str)
		return (1);
	while (str[i] == '0')
		i++;
	if (str[i] == '\0')
		i--;
	ft_putstr_fd(&str[i], 1);
	*count += ft_strlen(&str[i]);
	free(str);
	return (0);
}
int	print_X(va_list *ap, int *count)
{
	char	*str;
	int		i;

	i = 0;
	str = intToHex(va_arg(*ap, int));
	if (!str)
		return (1);
	while (str[i] == '0')
		i++;
	if (str[i] == '\0')
		i--;
	ft_putstr_fd(&str[i], 1);
	*count += ft_strlen(&str[i]);
	free(str);
	return (0);
}

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
