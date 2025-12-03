/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaabekas <gaabekas@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:39:49 by gaabekas          #+#    #+#             */
/*   Updated: 2025/11/06 13:50:06 by gaabekas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		i;
	int		start_ind;
	int		end_ind;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start_ind = 0;
	while (s1[start_ind] && ft_strchr(set, s1[start_ind]))
		start_ind++;
	end_ind = ft_strlen(s1) - 1;
	while (end_ind >= start_ind && ft_strchr(set, s1[end_ind]))
		end_ind--;
	trimmed = malloc((end_ind - start_ind + 2) * sizeof(char));
	if (trimmed == NULL)
		return (NULL);
	i = 0;
	while (start_ind <= end_ind)
	{
		trimmed[i] = s1[start_ind];
		start_ind++;
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
