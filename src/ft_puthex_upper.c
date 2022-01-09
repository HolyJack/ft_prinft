/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:54:51 by ejafer            #+#    #+#             */
/*   Updated: 2022/01/08 20:41:30 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_puthex_upper(unsigned int unbr)
{
	const int	maxlen = 8;
	const char	letters[16] = "0123456789ABCDEF";
	char		*hnbr;
	int			len;

	len = 1;
	hnbr = malloc(sizeof(char) * 9);
	if (!hnbr)
		return (-1);
	hnbr[8] = '\0';
	hnbr[maxlen - len] = letters[unbr % 16];
	unbr /= 16;
	while (unbr > 0)
	{
		len++;
		hnbr[maxlen - len] = letters[unbr % 16];
		unbr /= 16;
	}
	ft_putstr_fd(hnbr + maxlen - len, 1);
	free(hnbr);
	return (len);
}
