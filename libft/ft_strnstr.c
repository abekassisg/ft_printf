/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaabekas <gaabekas@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:47:17 by gaabekas          #+#    #+#             */
/*   Updated: 2025/11/10 10:52:56 by gaabekas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (little[0] == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i = 0;
	while (little[i])
		i++;
	j = 0;
	while (big[j] && j < len)
	{
		k = 0;
		while ((j + k) < len && big[j + k] && big[j + k] == little[k])
			k++;
		if (little[k] == '\0')
			return ((char *)&big[j]);
		j++;
	}
	return (NULL);
}
