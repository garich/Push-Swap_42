/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:26:23 by agarijo-          #+#    #+#             */
/*   Updated: 2023/04/11 16:17:31 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lst_new_node(void)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->rank = -1;
	new_node->position = -1;
	new_node->targ_position = -1;
	return (new_node);
}

void	lst_add_back(t_node **lst, t_node *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		lst_last(*lst)->next = new;
	}
}

t_node	*lst_second_to_last(t_node *lst)
{
	t_node	*second_to_last;

	second_to_last = NULL;
	while (lst)
	{
		if (!(lst->next))
			return (second_to_last);
		second_to_last = lst;
		lst = lst->next;
	}
	return (second_to_last);
}

t_node	*lst_last(t_node *lst)
{
	while (lst)
	{
		if (!(lst->next))
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	lst_size(t_node *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
