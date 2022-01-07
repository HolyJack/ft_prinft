/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:58:37 by ejafer            #+#    #+#             */
/*   Updated: 2021/12/28 17:58:37 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_nbrlen(int nbr)
{
	int	len;

	len = 1;
	if (nbr < 0)
		len++;
	nbr /= 10;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_pf(int nbr)
{
	ft_putnbr_fd(nbr, 1);
	return (ft_nbrlen(nbr));
}
