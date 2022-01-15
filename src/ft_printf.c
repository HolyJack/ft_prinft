/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:36:58 by ejafer            #+#    #+#             */
/*   Updated: 2022/01/08 20:41:43 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_print *ft_init_print(t_print *tab)
{
	tab->prc = 0;
	tab->wdt = 0;
	tab->ptr = 0;
	return (tab);
}

void ft_print_str(t_print *tab)
{
	const char *str;
	int strlen;

	str = va_arg(tab->args, const char *);
	strlen = ft_strlen(str);
	if (tab->ptr)
		strlen = MIN(strlen, tab->prc);
	while (tab->wdt-- > strlen)
		tab->sft += write(1, " ", 1);
	tab->sft += write(1, str, strlen);
}

void ft_print_nbr(t_print *tab)
{
	char	*str;
	long	nbr;
	int		strlen;
	int		nbrlen;
	int 	sign;

	nbr = (long) va_arg(tab->args, int);
	if (tab->ptr && !tab->prc && !nbr)
		return ;
	sign = 0;
	if (nbr < 0)
	{
		sign = 1;
		nbr = -nbr;
	}
	nbrlen = ft_nbrlen(nbr);
	strlen = nbrlen;
	if (tab->ptr)
		strlen = MAX(nbrlen, tab->prc);
	while (tab->wdt-- > strlen + sign)
		tab->sft += write(1, " ", 1);
	if (sign)
		tab->sft += write(1, "-", 1);
	str = malloc (sizeof(char) * (strlen + 1));
	str[strlen] = 0;
	ft_memset(str, '0', strlen);
	while (nbrlen--)
	{
		str[--strlen] += nbr % 10;
		nbr /= 10;
	}
	tab->sft += write(1, str, ft_strlen(str));
	free(str);
}

int ft_hexlen(unsigned int nbr)
{
	int len;

	len = 1;
	while (nbr /= 16)
		len++;
	return (len);
}

void ft_print_hex(t_print *tab)
{
	char	*str;
	char	*base = "0123456789abcdef";
	unsigned int nbr;
	int hexlen;

	nbr = va_arg(tab->args, unsigned int);
	if (tab->ptr && !tab->prc && !nbr)
		return ;
	hexlen = ft_hexlen(nbr);
	if (tab->ptr)
		hexlen = MAX(hexlen, tab->prc);
	while (tab->wdt-- > hexlen)
		tab->sft += write(1, " ", 1);
	str = malloc(sizeof(char) * (hexlen + 1));
	str[hexlen] = 0;
	ft_memset(str, '0', hexlen);
	while (nbr)
	{
		str[--hexlen] = base[nbr % 16];
		nbr /= 16;
	}
	tab->sft += write(1, str, ft_strlen(str));
	free(str);
}	

int ft_parse_format(t_print *tab, const char *format, int i)
{
	ft_init_print(tab);
	while (!ft_strchr("sdx", format[i]))
	{
		if (format[i] == '.')
		{
			tab->ptr = 1;
			i++;
		}
		while (ft_strchr("0123456789", format[i]))
		{
			if (tab->ptr)
				tab->prc = tab->prc * 10 + format[i] - '0';
			else 
				tab->wdt = tab->wdt * 10 + format[i] - '0';
			i++;
		}
	}
	if (format[i] == 's')
		ft_print_str(tab);
	if (format[i] == 'd')
		ft_print_nbr(tab);
	if (format[i] == 'x')
		ft_print_hex(tab);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	t_print *tab;

	tab = malloc (sizeof(t_print) * 1);
	ft_init_print(tab);
	tab->sft = 0;
	va_start(tab->args, format);
	i = -1;
	len = 0;
	while (format[++i])
		if (format[i] == '%')
			i = ft_parse_format(tab, format, i + 1);
		else
			len += write(1, &format[i], 1);
	len += tab->sft;
	va_end(tab->args);
	free(tab);
	return (len);
}
