/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sentence.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaabekas <gaabekas@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:28:47 by gaabekas          #+#    #+#             */
/*   Updated: 2025/12/02 14:42:51 by gaabekas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_sentence(va_list *args)
{
	char	*sentence;
	int		length;

	sentence = va_arg(*args, char *);
	length = 0;
	if (sentence == NULL)
	{
		write(1, "(null)", 6);
		length = 6;
	}
	else
	{
		length = ft_strlen(sentence);
		while (*sentence)
		{
			write(1, sentence, 1);
			sentence++;
		}
	}
	return (length);
}
