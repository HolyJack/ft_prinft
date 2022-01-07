/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:28:09 by ejafer            #+#    #+#             */
/*   Updated: 2021/12/28 18:28:09 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_puthex_pf(void *arg)
{
	const int	maxlen = 16;
	const char	letters[16] = "0123456789abcdef";
	char		*hnbr;
	int			len;
	unsigned long	unbr;

	if (!arg)
		return (write(1, "(nil)", 5));
	unbr = (unsigned long) arg;
	hnbr = malloc(sizeof(char) * (maxlen + 1));
	hnbr[maxlen] = '\0';
	ft_memset(hnbr, '0', maxlen);
	len = 1;
	hnbr[maxlen - len] = letters[unbr % 16];
	unbr /= 16;
	while (unbr > 0)
	{
		len++;
		hnbr[maxlen - len] = letters[unbr % 16];
		unbr /= 16;
	}
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(hnbr + maxlen - len, 1);
	free(hnbr);
	return (len + 2);
}

