/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaabekas <gaabekas@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:33:29 by gaabekas          #+#    #+#             */
/*   Updated: 2025/12/03 10:38:15 by gaabekas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_i_or_d(va_list *args);
int	ft_letter(va_list *args);
int	ft_lowercase_hexadecimal(va_list *args);
int	ft_pointer(va_list *args);
int	ft_sentence(va_list *args);
int	ft_unsigned_int(va_list *args);
int	ft_uppercase_hexadecimal(va_list *args);

#endif