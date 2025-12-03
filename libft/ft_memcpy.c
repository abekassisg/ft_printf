/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaabekas <gaabekas@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:13:56 by gaabekas          #+#    #+#             */
/*   Updated: 2025/11/06 12:18:22 by gaabekas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dest, const void	*src, size_t	n)
{
	const char		*temp_s;
	unsigned char	*tmp_d;
	size_t			i;

	tmp_d = dest;
	temp_s = src;
	i = 0;
	if (src == dest)
		return (dest);
	while (i < n)
	{
		tmp_d[i] = temp_s[i];
		i++;
	}
	return (dest);
}
