/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaabekas <gaabekas@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:07:17 by gaabekas          #+#    #+#             */
/*   Updated: 2025/11/06 11:32:41 by gaabekas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_word(int len, unsigned int tmp, int n)
{
	int		i;
	char	*word;

	word = malloc((len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	i = len - 1;
	while (tmp > 0)
	{
		word[i] = (tmp % 10) + '0';
		tmp = tmp / 10;
		i--;
	}
	if (n < 0)
		word[0] = '-';
	word[len] = '\0';
	return (word);
}

char	*ft_itoa(int n)
{
	char			*word;
	int				len;
	unsigned int	nbr;
	unsigned int	tmp;

	if (n == -2147483648 || 0)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	len = 0;
	if (n < 0)
	{
		nbr = -n;
		len++;
	}
	else
		nbr = n;
	tmp = nbr;
	while (nbr > 0)
	{
		len++;
		nbr /= 10;
	}
	word = ft_word(len, tmp, n);
	return (word);
}
