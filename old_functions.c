/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:38:36 by agarijo-          #+#    #+#             */
/*   Updated: 2023/04/05 12:27:21 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	*get_array_weight(int *array, int argc)
{
	int	*weights;
	int	*sorted_array;
	int	counter;
	int	displacement;

	weights = ft_calloc((argc), sizeof(int));
	sorted_array = ft_calloc((argc), sizeof(int));
	if (!weights || !sorted_array)
		return (NULL);
	sorted_array = sort_og_array_for_weights(array, sorted_array, argc);
	counter = 0;
	displacement = 0;
	while (counter < argc)
	{
		while ((counter + displacement) < argc)
		{
			if (array[counter] == sorted_array[counter + displacement])
				weights[counter] = counter + displacement;
			displacement++;
		}
		displacement = 0;
		counter++;
	}
	return (free (sorted_array), weights);
}

int	*sort_og_array_for_weights(int *array, int *sorted_array, int argc)
{
	int	counter;
	int	displacement;
	int	temp;

	counter = -1;
	displacement = 1;
	while (counter++ < (argc - 1))
		sorted_array[counter] = array[counter];
	counter = 0;
	while (counter < argc)
	{
		while ((counter + displacement) < argc)
		{
			if (sorted_array[counter] > sorted_array[counter + displacement])
			{
				temp = sorted_array[counter];
				sorted_array[counter] = sorted_array[counter + displacement];
				sorted_array[counter + displacement] = temp;
			}
			displacement++;
		}
		displacement = 1;
		counter++;
	}
	return (sorted_array);
}