/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:00:49 by lnicolli          #+#    #+#             */
/*   Updated: 2023/10/30 19:03:18 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "ft_u_itoa.h"
# include "hexatools.h"
# include "libft/libft.h"
# include "libftprintf.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

int	ft_printf(const char *args, ...);
int	print_p(va_list *ap, int *count);
int	print_u(va_list *ap, int *count);
int	print_c(va_list *ap, int *count);
int	print_x(va_list *ap, int *count);
int	print_X(va_list *ap, int *count);
#endif
