/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaabekas <gaabekas@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:48:06 by gaabekas          #+#    #+#             */
/*   Updated: 2025/12/03 10:36:01 by gaabekas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_writing_and_length(int length, int i, unsigned int *numbers)
{
	char	letter;

	length = i;
	i = i - 1;
	while (i >= 0)
	{
		letter = numbers[i] + '0';
		write(1, &letter, 1);
		i--;
	}
	return (length);
}

int	ft_unsigned_int(va_list *args)
{
	char			zero;
	unsigned int	number;
	unsigned int	digit;
	unsigned int	numbers[10];
	int				i[2];

	number = va_arg(*args, unsigned int);
	i[0] = 0;
	zero = '0';
	if (number == 0)
	{
		write(1, &zero, 1);
		return (1);
	}
	while (number > 0)
	{
		digit = number % 10;
		numbers[i[0]] = digit;
		number = number / 10;
		i[0]++;
	}
	i[1] = 0;
	i[1] = ft_writing_and_length(i[1], i[0], numbers);
	return (i[0]);
}
