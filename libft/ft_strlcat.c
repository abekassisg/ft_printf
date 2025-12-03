/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaabekas <gaabekas@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:00:57 by gaabekas          #+#    #+#             */
/*   Updated: 2025/11/10 13:35:35 by gaabekas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_dst;
	size_t	size_src;
	size_t	i;

	if (size == 0 && dst == NULL)
		return (ft_strlen(src));
	size_dst = 0;
	size_src = 0;
	while (size_dst < size && dst[size_dst])
		size_dst++;
	while (src[size_src])
		size_src++;
	if (size <= size_dst)
		return (size + size_src);
	i = 0;
	while (size_dst + i < size - 1 && src[i])
	{
		dst[size_dst + i] = src[i];
		i++;
	}
	dst[size_dst + i] = '\0';
	return (size_dst + size_src);
}
