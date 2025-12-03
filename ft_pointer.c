/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaabekas <gaabekas@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 18:51:53 by gaabekas          #+#    #+#             */
/*   Updated: 2025/12/02 14:42:12 by gaabekas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_not_null(unsigned long ptr_long, char *hexadecimal, int index)
{
	int	last_index;
	int	remainder;
	int	length;

	while (ptr_long > 0)
	{
		remainder = ptr_long % 16;
		if (remainder < 10)
			hexadecimal[index++] = remainder + '0';
		else
			hexadecimal[index++] = remainder + 'a' - 10;
		ptr_long /= 16;
	}
	hexadecimal[index] = '\0';
	last_index = index - 1;
	while (last_index >= 0)
	{
		write(1, &hexadecimal[last_index], 1);
		last_index--;
	}
	length = ft_strlen(hexadecimal);
	return (length);
}

int	ft_pointer(va_list *args)
{
	void			*ptr;
	unsigned long	ptr_long;
	char			hexadecimal[100];
	int				length;

	ptr = va_arg(*args, void *);
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else if (ptr == NULL)
	{
		write(1, "0x0", 3);
		return (3);
	}
	ptr_long = (unsigned long)ptr;
	write(1, "0x", 2);
	length = ft_not_null(ptr_long, hexadecimal, 0) + 2;
	return (length);
}
