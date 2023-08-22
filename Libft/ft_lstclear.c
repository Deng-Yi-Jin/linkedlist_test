/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:22:26 by djin              #+#    #+#             */
/*   Updated: 2023/08/21 09:34:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*newnode;
	t_list	*prevnode;

	if (!lst || !del)
		return ;
	prevnode = 0;
	newnode = *lst;
	while (newnode != 0)
	{
		prevnode = newnode;
		newnode = newnode -> next;
		del(prevnode -> content);
		free(prevnode);
	}
	*lst = newnode;
}
