/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:59:36 by agarijo-          #+#    #+#             */
/*   Updated: 2023/04/05 17:09:59 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_array_weight(int *array, int argc)
{
	int	*weights;
	int	counter;
	int	displacement;
	int	weight;

	weights = ft_calloc((argc), sizeof(int));
	if (!weights)
		return (NULL);
	counter = 0;
	displacement = counter + 1;
	weight = 0;
	while (counter < argc)
	{
		while (displacement < argc)
		{
			if (array[counter] > array[displacement++])
				weight++;
		}
		weights[counter] = weight;
		weight = 0;
		displacement = 0;
		counter++;
	}
	return (weights);
}

void	print_array(char **array)
{
	int	counter;

	counter = 0;
	while (array[counter])
		printf("*** Printer Test:%s\n", array[counter++]);
}

int	count_array(char **array)
{
	int	counter;

	counter = 0;
	while (array[counter])
		counter++;
	return (counter);
}

void	free_malloc(void **result_array)
{
	int	counter;

	counter = 0;
	while (result_array[counter])
	{
		free(result_array[counter]);
		result_array[counter] = NULL;
		counter ++;
	}
	free(result_array);
}
