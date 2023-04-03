/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:19:20 by agarijo-          #+#    #+#             */
/*   Updated: 2023/04/03 11:35:05 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_in_order(t_node *head)
{
	t_node	*node;

	node = head;
	while (node && node->next && (node->value < node->next->value))
		node = node->next;
	if (node && node->next && (node->value > node->next->value))
		return (0);
	return (1);
}

t_node	*only_two_numbers(t_node *head)
{
	t_node	*node;

	node = NULL;
	node = swap_a_sa(head);
	if (node)
		return (node);
	return (write(2, "Error\n", 6), NULL);
}

t_node	*only_three_numbers(t_node *head)
{
	t_node	*node;

	node = head;
	while (!check_if_in_order(node))
	{
		if ((node->value > node->next->value)
			&& (node->next->value < node->next->next->value)
			&& node->next->next->value < node->value)
			node = rotate_a_ra(node);
		else if ((node->value < node->next->value)
			&& (node->next->value > node->next->next->value)
			&& node->next->next->value < node->value)
			node = reverse_rotate_a_rra(node);
		else
			node = swap_a_sa(node);
	}
	if (node)
		return (node);
	return (write(2, "Error\n", 6), NULL);
}

t_node	*only_four_numbers(t_node *head)
{
	t_node	*head_b;
	int		smallest_place;

	head_b = NULL;
	smallest_place = smallest_position(head);
	// printf("Smallest Place:%d\n", smallest_place);
	if (smallest_place == 1)
		head = swap_a_sa(head);
	else if (smallest_place == 2)
	{
		head = rotate_a_ra(head);
		head = rotate_a_ra(head);
	}
	else if (smallest_place == 3)
	{
		head = reverse_rotate_a_rra(head);
	}
	push_b_pb(&head, &head_b);
	head = only_three_numbers(head);
	push_a_pa(&head, &head_b);
	lst_clear(&head_b);
	if (head)
		return (head);
	return (write(2, "Error\n", 6), NULL);
}

t_node	*only_five_numbers(t_node *head)
{
	int		smallest_place;
	int		head_size;
	int		half_size;
	t_node	*head_b;

	head_b = NULL;
	smallest_place = smallest_position(head);
	head_size = lst_size(head);
	half_size = (head_size / 2) + (head_size % 2);
	// printf("Head Size:%d\n", head_size);
	// printf("Middle:%d\n", half_size);
	// printf("Smallest Place:%d\n", smallest_place);
	while (head && !(check_if_in_order(head)))
	{
		if (head_size == 3)
			head = only_three_numbers(head);
		else
		{	
			if (smallest_place < half_size)
			{
				while (smallest_place--)
					head = rotate_a_ra(head);
				push_b_pb(&head, &head_b);
			}
			else if (smallest_place >= half_size)
			{
				while (smallest_place++ < head_size)
					head = reverse_rotate_a_rra(head);
				push_b_pb(&head, &head_b);
			}
			smallest_place = smallest_position(head);
			head_size = lst_size(head);
			half_size = (head_size / 2) + (head_size % 2);
		}
	}
	while (head_b)
		push_a_pa(&head, &head_b);
	lst_clear(&head_b);
	if (head)
		return (head);
	return (write(2, "Error\n", 6), NULL);
}

void	push_swap(int *array, int argc)
{
	t_node	*head;

	head = NULL;
	if (argc == 1)
		write(1, "OK\n", 3);
	else
	{
		head = fill_list_with_array(array, argc);
		// write(2, "-> INPUT:\n", 10);
		// lst_print(head);
		// write(2, "<-\n", 3);
		if (check_if_in_order(head))
			write(1, "ORDEN\n", 6);
		else
		{
			if (argc == 2)
				head = only_two_numbers(head);
			if (argc == 3)
				head = only_three_numbers(head);
			if (argc == 4)
				head = only_four_numbers(head);
			if (argc > 4)
				head = only_five_numbers(head);
		}
		// write(2, "##STACK A:\n", 11);
		// lst_print(head);
		lst_clear(&head);
	}
	free(array);
}
