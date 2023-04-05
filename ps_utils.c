/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:33:05 by agarijo-          #+#    #+#             */
/*   Updated: 2023/04/02 19:34:15 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
