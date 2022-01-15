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
# define MIN(a, b) (a < b ? a: b)
# define MAX(a, b) (a > b ? a: b)

typedef struct s_print
{
	va_list args;
	int	wdt;
	int prc;
	int ptr;
	int sft;

} t_print;

int	ft_printf(const char *format, ...);

#endif
