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

int ft_puthex_lower(unsigned int unbr)
{
	const int	maxlen = 8;
	char		letters[16] = "0123456789abcdef";
	char		*hnbr;
	int			len;

	len = 1;
	hnbr = "00000000";
	hnbr[maxlen - len] = letters[unbr % 16];
	unbr /= 16;
	while (unbr > 0)
	{
		hnbr[maxlen - len] = letters[unbr % 16];
		unbr /= 16;
		len++;
	}
	ft_putstr_fd(hnbr + maxlen - len, 1);
	return (len);
}