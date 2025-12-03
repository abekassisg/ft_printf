/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaabekas <gaabekas@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:47:11 by gaabekas          #+#    #+#             */
/*   Updated: 2025/11/21 18:32:54 by gaabekas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	current = lst;
	if (lst == NULL || f == NULL)
		return ;
	while (current != NULL)
	{
		f(current->content);
		current = current->next;
	}
}

// void	f(void *)
// {
// 	printf("Hello\n");
// }

// int	main(void)
// {
// 	t_list	*example;
// 	t_list	*new;
// 	int	i = 0;

// 	example = ft_lstnew(&i);
// 	new = ft_lstnew(&i);
// 	ft_lstadd_back(&example, new);
// 	ft_lstiter(example, &f);	
// 	return (0);
// }