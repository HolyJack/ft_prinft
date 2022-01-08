/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:52:55 by ejafer            #+#    #+#             */
/*   Updated: 2022/01/08 20:41:35 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putstr_pf(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
