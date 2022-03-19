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
# include "libft.h"

typedef struct s_data
{
	va_list		args;
	int			wdt;
	int			prc;
	int			ptr;
	const char	*format;
	int			i;
	char		*result;
} t_data;

int		ft_printf(const char *format, ...);
char	*ft_format_str(t_data *data, char *str);
char	*ft_format_int(t_data *data, long nbr);
char	*ft_format_hex(t_data *data, unsigned int unbr);
char	*ft_unbr_to_base(unsigned int unbr, char *base);
char	*ft_add_width(char *str, int widh);
char	*ft_add_precision_nbr(char *str, int precision);

#endif
