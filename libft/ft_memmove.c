/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaabekas <gaabekas@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:03:07 by gaabekas          #+#    #+#             */
/*   Updated: 2025/11/06 11:32:22 by gaabekas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*tmp_d;
	unsigned char const	*tmp_s;
	size_t				i;

	tmp_d = (unsigned char *)dest;
	tmp_s = (unsigned char *)src;
	if (src == NULL && dest == NULL)
		return (NULL);
	if (tmp_d > tmp_s)
	{
		while (n--)
			tmp_d[n] = tmp_s[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			tmp_d[i] = tmp_s[i];
			i++;
		}
	}
	return (dest);
}
