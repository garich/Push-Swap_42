/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:33:05 by agarijo-          #+#    #+#             */
/*   Updated: 2023/04/19 17:28:08 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_rank(t_node *head_a, int head_mid)
{
	t_node	*p_head;

	p_head = head_a;
	if (p_head)
	{
		while (p_head)
		{
			if (p_head->rank < head_mid)
				return (1);
			else
				p_head = p_head->next;
		}
	}
	return (0);
}

int	smallest_position(t_node *head)
{
	int		smallest;
	int		counter;
	int		position;
	t_node	*p_head;

	counter = 0;
	position = counter;
	p_head = head;
	if (p_head)
	{
		smallest = p_head->value;
		while (p_head)
		{
			if (smallest > p_head->value)
			{
				smallest = p_head->value;
				position = counter;
			}
			p_head = p_head->next;
			counter++;
		}
	}
	return (position);
}

void	recalculate_position_on_stack(t_node *head)
{
	int		counter;
	t_node	*p_head;

	p_head = head;
	counter = 0;
	while (p_head)
	{
		lst_add_pos_to_node(p_head, counter);
		p_head = p_head->next;
		counter++;
	}
}

void	recalculate_position_two_stacks(t_node *head_a, t_node *head_b)
{
	int		counter;
	t_node	*p_head;

	p_head = head_a;
	counter = 0;
	while (p_head)
	{
		lst_add_pos_to_node(p_head, counter);
		p_head = p_head->next;
		counter++;
	}
	p_head = head_b;
	counter = 0;
	while (p_head)
	{
		lst_add_pos_to_node(p_head, counter);
		p_head = p_head->next;
		counter++;
	}
}

void	set_target_postion_b_stack(t_node *head_a, t_node *head_b)
{
	t_node	*p_head_b;
	t_node	*target;
	int		offset;

	p_head_b = head_b;
	target = NULL;
	offset = 0;
	while (p_head_b)
	{
		if (!find_rank_on_stack(head_b, (p_head_b->rank) + offset + 1))
		{
			target = find_rank_on_stack(head_a, (p_head_b->rank) + offset + 1);
			offset = 0;
			while (!target)
				target = find_rank_on_stack(head_a, offset++);
			p_head_b->targ_position = target->position;
			p_head_b = p_head_b->next;
			offset = 0;
		}
		else
		{
			offset += 1;
		}
	}
}
