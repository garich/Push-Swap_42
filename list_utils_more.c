/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_more.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:25:56 by agarijo-          #+#    #+#             */
/*   Updated: 2023/03/30 13:55:50 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_add_value_to_node(t_node *node, int add_value)
{
	if (node)
		node->value = add_value;
}

void	lst_add_next_to_node(t_node *node, t_node *next)
{
	if (node)
		node->next = next;
}

t_node	*fill_list_with_array(int *array, int argc)
{
	int		counter;
	t_node	*node;
	t_node	*head;

	node = NULL;
	head = NULL;
	counter = 0;
	while (counter < argc)
	{
		node = lst_new_node();
		lst_add_value_to_node(node, array[counter]);
		lst_add_back(&head, node);
		counter++;
	}
	return (head);
}

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
