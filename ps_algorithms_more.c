/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithms_more.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:09:09 by agarijo-          #+#    #+#             */
/*   Updated: 2023/04/20 19:02:10 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*more_numbers(t_node *head)
{
	int		head_size;
	t_node	*head_b;

	head_size = lst_size(head);
	head_b = NULL;
	while (head && !(check_if_in_order(head)))
	{
		if (head_size == 3)
			head = only_three_numbers(head);
		else
			move_all_to_b(&head, &head_b, &head_size);
	}
	recalculate_position_two_stacks(head, head_b);
	set_target_postion_b_stack(head, head_b);
	costs_on_more_numbers(&head, &head_b);
	lst_clear(&head_b);
	if (head)
		return (head);
	return (write(2, "Error\n", 6), NULL);
}

void	costs_on_more_numbers(t_node **head_a, t_node **head_b)
{
	int		b_head_size;
	t_node	*p_lowest_cost;

	b_head_size = 0;
	p_lowest_cost = NULL;
	while (*head_a && *head_b)
	{
		b_head_size = lst_size(*head_b);
		p_lowest_cost = calculate_total_cost(*head_a, *head_b, b_head_size);
		execute_lowest_cost(p_lowest_cost, head_a, head_b, b_head_size);
		push_a_pa(head_a, head_b);
		recalculate_position_two_stacks(*head_a, *head_b);
		set_target_postion_b_stack(*head_a, *head_b);
	}
	while (!(check_if_in_order(*head_a)))
	{
		if (((find_rank_on_stack(*head_a, 0))->position)
			<= (lst_size(*head_a) / 2))
			rotate_a_ra(head_a, 0);
		else
			reverse_rotate_a_rra(head_a, 0);
	}
}

void	move_all_to_b(t_node **head_a,
	t_node **head_b, int *head_size)
{
	int	og_head_size;

	og_head_size = *head_size;
	while (check_rank(*head_a, (og_head_size / 2)))
	{
		if ((*head_a)->rank < (og_head_size / 2))
		{
			push_b_pb(head_a, head_b);
			*head_size -= 1;
		}
		else
			rotate_a_ra(head_a, 0);
	}
	while (*head_size > 3)
	{
		push_b_pb(head_a, head_b);
		*head_size -= 1;
	}
}
