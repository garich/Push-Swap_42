/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:44:47 by agarijo-          #+#    #+#             */
/*   Updated: 2023/04/19 17:47:33 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_lowest_cost(t_node *p_to_less_cost, t_node **head_a,
	t_node **head_b, int head_b_size)
{
	int		a_cost;
	int		b_cost;

	b_cost = calculate_head_b_cost(p_to_less_cost, head_b_size);
	a_cost = calculate_head_a_cost(*head_a, p_to_less_cost);
	while (a_cost > 0 && b_cost > 0)
		rotate_a_b_rr(head_a, head_b, a_cost--, b_cost--);
	while (a_cost < 0 && b_cost < 0)
		reverse_rotate_a_b_rrr(head_a, head_b, a_cost++, b_cost++);
	while (a_cost > 0)
		rotate_a_ra(head_a, a_cost--);
	while (b_cost > 0)
		rotate_b_rb(head_b, b_cost--);
	while (a_cost < 0)
		reverse_rotate_a_rra(head_a, a_cost++);
	while (b_cost < 0)
		reverse_rotate_b_rrb(head_b, b_cost++);
}

t_node	*calculate_total_cost(t_node *head_a, t_node *head_b, int head_b_size)
{
	t_node	*p_head_b;
	t_node	*p_to_less_cost;
	int		a_cost;
	int		b_cost;
	int		total_cost;

	p_head_b = head_b;
	p_to_less_cost = NULL;
	total_cost = 199999;
	while (p_head_b)
	{
		b_cost = calculate_head_b_cost(p_head_b, head_b_size);
		a_cost = calculate_head_a_cost(head_a, p_head_b);
		if (total_cost > abs(a_cost) + abs(b_cost))
		{
			total_cost = abs(a_cost) + abs(b_cost);
			p_to_less_cost = p_head_b;
		}
		p_head_b = p_head_b->next;
	}
	return (p_to_less_cost);
}

int	calculate_head_a_cost(t_node *head_a, t_node *head_b)
{
	t_node	*p_head_b;
	int		head_size;
	int		cost;

	p_head_b = head_b;
	head_size = lst_size(head_a);
	if (p_head_b->targ_position <= (head_size / 2))
		cost = p_head_b->targ_position;
	else
		cost = 0 - head_size + p_head_b->targ_position;
	return (cost);
}

int	calculate_head_b_cost(t_node *head, int b_size)
{
	t_node	*p_head;
	int		cost;

	p_head = head;
	if (p_head->position <= (b_size / 2))
		cost = p_head->position;
	else
		cost = p_head->position - b_size;
	return (cost);
}

t_node	*find_rank_on_stack(t_node *head, int rank)
{
	t_node	*p_head;

	p_head = head;
	while (p_head)
	{
		if (rank == p_head->rank)
			return (p_head);
		p_head = p_head->next;
	}
	return (NULL);
}
