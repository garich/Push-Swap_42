/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_more.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:25:56 by agarijo-          #+#    #+#             */
/*   Updated: 2023/03/22 17:08:30 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_print(t_node *lst)
{
	while (lst)
	{
		printf("%d\n", lst->value);
		lst = lst->next;
	}
}

void	lst_clear(t_node **lst)
{
	t_node	*first;
	t_node	*next;

	first = *lst;
	while (first)
	{
		next = first->next;
		lst_free_node(first);
		first = next;
	}
	*lst = NULL;
}

void	lst_free_node(t_node *node)
{
	if (node)
		free(node);
}
