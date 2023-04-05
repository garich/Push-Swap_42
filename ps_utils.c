/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:33:05 by agarijo-          #+#    #+#             */
/*   Updated: 2023/04/05 17:27:39 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_chunks(int head_size)
{
	int	*chunks;

	chunks = NULL;
	if (head_size < 100)
	{
		chunks = ft_calloc((3), sizeof(int));
		if (!chunks)
			return (NULL);
		chunks[0] = head_size / 3;
		chunks[1] = (head_size / 3) * 2 + 1;
		chunks[2] = head_size;
		printf("Chunk: %d\n", chunks[0]);
		printf("Chunk: %d\n", chunks[1]);
		printf("Chunk: %d\n", chunks[2]);
	}
	return (chunks);
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
