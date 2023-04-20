/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_more.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:25:56 by agarijo-          #+#    #+#             */
/*   Updated: 2023/04/11 16:20:37 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*fill_list_with_array(int *array, int argc)
{
	int		counter;
	t_node	*node;
	t_node	*head;
	int		*weights;

	node = NULL;
	head = NULL;
	counter = 0;
	weights = get_array_weight(array, argc);
	while (counter < argc)
	{
		node = lst_new_node();
		lst_add_value_to_node(node, array[counter]);
		lst_add_pos_to_node(node, counter);
		lst_add_rank_to_node(node, weights[counter]);
		lst_add_back(&head, node);
		counter++;
	}
	return (free (weights), head);
}

void	lst_print(t_node *lst)
{
	while (lst)
	{
		printf("VALUE\tPOS\tT.POS\tRANK\n");
		printf("%d\t%d\t%d\t%d\n", lst->value, lst->position,
			lst->targ_position, lst->rank);
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
