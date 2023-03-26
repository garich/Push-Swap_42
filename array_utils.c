/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:59:36 by agarijo-          #+#    #+#             */
/*   Updated: 2023/03/26 22:12:28 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_malloc(char **result_array)
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
