/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:06:52 by ejafer            #+#    #+#             */
/*   Updated: 2022/01/10 19:47:55 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_nbrlen(unsigned int unbr)
{
	int	len;

	len = 1;
	unbr /= 10;
	while (unbr != 0)
	{
		unbr /= 10;
		len++;
	}
	return (len);
}

int	ft_putunbr_fd(unsigned int unbr, int fd)
{
	const int	nbrlen = ft_nbrlen(unbr);
	int			len;
	char		*buf;

	buf = malloc(sizeof(char) * (nbrlen + 1));
	buf[nbrlen] = 0;
	len = nbrlen;
	while (len-- > 0)
	{
		buf[len] = (unbr % 10) + '0';
		unbr /= 10;
	}
	ft_putstr_fd(buf, fd);
	free(buf);
	return (nbrlen);
}

int	ft_putunbr_pf(unsigned int unbr)
{
	return (ft_putunbr_fd(unbr, 1));
}
