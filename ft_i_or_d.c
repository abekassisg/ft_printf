/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_or_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaabekas <gaabekas@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 10:49:46 by gaabekas          #+#    #+#             */
/*   Updated: 2025/12/02 14:34:30 by gaabekas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_i_or_d(va_list *args)
{
	int		length;
	int		number;
	char	*result;

	number = va_arg(*args, int);
	result = ft_itoa(number);
	ft_putstr_fd(result, 1);
	length = ft_strlen(result);
	free(result);
	return (length);
}
