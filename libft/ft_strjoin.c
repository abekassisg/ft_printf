/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaabekas <gaabekas@student.42.london.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:26:16 by gaabekas          #+#    #+#             */
/*   Updated: 2025/11/05 18:08:52 by gaabekas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concatenated;
	int		i[4];

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i[0] = ft_strlen(s1);
	i[1] = ft_strlen(s2);
	concatenated = malloc((i[0] + i[1] + 1) * sizeof(char));
	if (concatenated == NULL)
		return (NULL);
	i[2] = 0;
	while (i[2] < i[0])
	{
		concatenated[i[2]] = s1[i[2]];
		i[2]++;
	}
	i[3] = 0;
	while (i[3] < i[1])
	{
		concatenated[i[2]] = s2[i[3]];
		i[2]++;
		i[3]++;
	}
	concatenated[i[2]] = '\0';
	return (concatenated);
}

/*Command line for this one: cc -I . ft_strjoin.c ft_.c */