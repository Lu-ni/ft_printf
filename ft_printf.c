#include "hexatools.h"
#include "libft/libft.h"
#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

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
int print_u(va_list *ap)
{
	(void) ap;
	return 0;
}

int ft_printf(const char *args, ...)
{
	va_list ap;
	char   *ola = ft_strdup(args);
	va_start(ap, args);
	while (*ola)
	{
		if (*ola == '%')
		{
			if (*(ola + 1) == '\0')
				return (0);
			if (*(ola + 1) == 'c')
				ft_putchar_fd(va_arg(ap, int), 1);
			else if (*(ola + 1) == 's')
				ft_putstr_fd((char *) va_arg(ap, const char *), 1);
			else if (*(ola + 1) == 'p')
				print_p(&ap);
			else if (*(ola + 1) == 'd' && *(ola + 1) == 'i')
				ft_putstr_fd(ft_itoa(va_arg(ap, int)), 1);
			else if (*(ola + 1) == 'u')
				print_u(&ap);
			else if (*(ola + 1) == 'x')
				ft_putstr_fd(ft_hextolowe(intToHex(va_arg(ap, int))), 1);
			else if (*(ola + 1) == 'X')
				ft_putstr_fd(intToHex(va_arg(ap, int)), 1);
			else if (*(ola + 1) == '%')
				ft_putchar_fd('%', 1);
			ola++;
		}
		else
			ft_putchar_fd(*ola, 1);
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
