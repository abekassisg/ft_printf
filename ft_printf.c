/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaabekas <gaabekas@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:32:58 by gaabekas          #+#    #+#             */
/*   Updated: 2025/12/03 10:39:39 by gaabekas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_options(const char *specifier, va_list *args)
{
	int		length;
	char	perc;

	length = 0;
	if (*specifier == 'c')
		length = ft_letter(args);
	else if (*specifier == 's')
		length = ft_sentence(args);
	else if (*specifier == 'p')
		length = ft_pointer(args);
	else if (*specifier == 'i' || *specifier == 'd')
		length = ft_i_or_d(args);
	else if (*specifier == 'u')
		length = ft_unsigned_int(args);
	else if (*specifier == 'x')
		length = ft_lowercase_hexadecimal(args);
	else if (*specifier == 'X')
		length = ft_uppercase_hexadecimal(args);
	else if (*specifier == '%')
	{
		perc = '%';
		write(1, &perc, 1);
		length = 1;
	}
	return (length);
}

int	ft_is_specifier(const char c)
{
	if (c != 'c' && c != 's' && c != 'p' && c != 'i' && c != 'd'
		&& c != 'u' && c != 'x' && c != 'X' && c != '%')
		return (1);
	return (0);
}

int	ft_helper(va_list *args, const char **str)
{
	char	perc;
	int		count_chars;

	count_chars = 0;
	if ((*str)[1] == '%')
	{
		perc = '%';
		write(1, &perc, 1);
		*str += 2;
		return (1);
	}
	else if (ft_is_specifier((*str)[1]) == 1)
	{
		write(1, *str, 1);
		count_chars += 1;
		(*str)++;
	}
	else
	{
		(*str)++;
		count_chars += ft_options(*str, args);
		(*str)++;
	}
	return (count_chars);
}

int	ft_printf(const char *str, ...)
{
	int		count_chars;
	va_list	args;

	count_chars = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			count_chars += ft_helper(&args, &str);
		else
		{
			write(1, str, 1);
			str++;
			count_chars++;
		}
	}
	va_end(args);
	return (count_chars);
}

// int	main(void)
// {
// 	int	i  = 1;
// 	int	d = 2;
// 	int	u = -3;
// 	char	c	= 'a';
// 	char	*sentence = "sentence";
// 	int	l_h = 4;
// 	int	u_h = 5;
// 	int	p = 6;
// 	int	mine_len;
// 	int	standard_len;

// 	mine_len = ft_printf("integer 1: %i, decimal 2: %d, unsigned int -3: %u,
// 		char a: %c, string sentence: %s, lower hexadecimal 4: %x,
// 		upper hexadecimal 5: %X, memory address: %p, percentage: %%\n",
// 		i, d, u, c, sentence, l_h, u_h, &p);
// 	ft_printf("no percentage\n");
// 	standard_len = printf("integer 1: %i, decimal 2: %d, unsigned int -3: %u,
// 		char a: %c, string sentence: %s, lower hexadecimal 4: %x,
// 		upper hexadecimal 5: %X, memory address: %p, percentage: %%\n",
// 		i, d, u, c, sentence, l_h, u_h, &p);
// 	printf("no percentage\n");
// 	printf("length: %i\n", mine_len);
// 	printf("length: %i\n", standard_len);
// }