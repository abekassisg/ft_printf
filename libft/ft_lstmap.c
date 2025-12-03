/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaabekas <gaabekas@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:27:38 by gaabekas          #+#    #+#             */
/*   Updated: 2025/11/21 18:32:27 by gaabekas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*updated;
	t_list	*new_list;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		updated = ft_lstnew(f(lst->content));
		if (updated == NULL)
			return (ft_lstclear(&new_list, del), NULL);
		ft_lstadd_back(&new_list, updated);
		lst = lst->next;
	}
	return (new_list);
}
