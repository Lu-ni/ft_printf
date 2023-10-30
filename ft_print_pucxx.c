/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pucxx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:05:08 by lnicolli          #+#    #+#             */
/*   Updated: 2023/10/30 18:53:24 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
