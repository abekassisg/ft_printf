/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowercase_hexadecimal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaabekas <gaabekas@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:42:38 by gaabekas          #+#    #+#             */
/*   Updated: 2025/12/02 14:36:43 by gaabekas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_writing(int index, char *hexadecimal)
{
	int	length;

	length = index;
	index = index - 1;
	while (index >= 0)
	{
		write(1, &hexadecimal[index], 1);
		index--;
	}
	return (length);
}

int	ft_lowercase_hexadecimal(va_list *args)
{
	unsigned int	number;
	unsigned int	remainder;
	char			hexadecimal[100];
	int				length;
	int				index;

	index = 0;
	number = va_arg(*args, unsigned int);
	if (number == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (number > 0)
	{
		remainder = number % 16;
		if (remainder < 10)
			hexadecimal[index++] = remainder + '0';
		else
			hexadecimal[index++] = remainder + 'a' - 10;
		number /= 16;
	}
	hexadecimal[index] = '\0';
	length = ft_writing(index, hexadecimal);
	return (length);
}
