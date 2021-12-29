/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:36:58 by ejafer            #+#    #+#             */
/*   Updated: 2021/11/24 19:36:58 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_parse(const char *format, va_list *args)
{
	if (*format == '%')
		return (ft_putpercent_pf());
	if (*format == 'c')
		return (ft_putchar_pf(va_arg(*args, int)));
	if (*format == 's')
		return (ft_putstr_pf(va_arg(*args, char *)));
	if (*format == 'p')
		return (ft_puthex_pf(va_arg(*args, void *)));
	if (*format == 'd')
		return (ft_putnbr_pf(va_arg(*args, int)));
	if (*format == 'i')
		return (ft_putnbr_pf(va_arg(*args, int)));
	if (*format == 'u')
		return (ft_putunbr_pf(va_arg(*args, unsigned int)));
	if (*format == 'x')
		return (ft_puthex_lower(va_arg(*args, unsigned int)));
	if (*format == 'X')
		return (ft_puthex_upper(va_arg(*args, unsigned int)));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += ft_parse(format, &args);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (len);
}
