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

int	ft_puthex_pf(void *ptrunbr)
{
	unsigned int	*unbr;
	const int		maxlen = 10;
	const char		letters[16] = "0123456789abcdef";
	char			*hnbr;
	int				len;

	unbr = (unsigned int *) ptrunbr;
	len = 1;
	hnbr = malloc(sizeof(char) * 11);
	hnbr[10] = '\0';
	ft_memset(hnbr, '0', 10);
	hnbr[1] = 'x';
	hnbr[maxlen - len] = letters[*unbr % 16];
	*unbr /= 16;
	while (*unbr > 0)
	{
		len++;
		hnbr[maxlen - len] = letters[*unbr % 16];
		*unbr /= 16;
	}
	ft_putstr_fd(hnbr, 1);
	free(hnbr);
	return (10);
}
