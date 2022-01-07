/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 08:39:27 by ejafer            #+#    #+#             */
/*   Updated: 2022/01/07 08:39:27 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_putpercent_pf(void);
int	ft_putchar_pf(char c);
int	ft_putstr_pf(char *str);
int	ft_putnbr_pf(int nbr);
int	ft_putunbr_pf(unsigned int unbr);
int	ft_puthex_lower(unsigned int nbr);
int	ft_puthex_upper(unsigned int nbr);
int	ft_puthex_pf(void *arg);

#endif