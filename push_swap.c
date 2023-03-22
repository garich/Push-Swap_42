/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:33:21 by agarijo-          #+#    #+#             */
/*   Updated: 2023/03/22 14:54:48 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// While ends if STATUS equals 0. 
// STATUS equals 0 only if check_argument_format fails to comply.
int	*check_arguments(int argc, char *argv[])
{
	int	counter;
	int	status;
	int	*array_arguments;

	counter = 1;
	status = -1;
	array_arguments = ft_calloc((argc - 1), sizeof(int));
	if (!array_arguments)
		return (0);
	while (counter < argc && status != 0)
	{
		status = check_argument_format(argv[counter]);
		if (!status)
			return (free(array_arguments), NULL);
		array_arguments[counter - 1] = ft_atoi_ps(argv[counter], &status);
		if (!status)
			return (free(array_arguments), NULL);
		counter++;
	}
	if (check_argument_duplicate(array_arguments))
		return (printf("Duplicado\n"), free(array_arguments), NULL);
	printf("Todo ok.\n");
	return (array_arguments);
}

int	check_argument_format(char *argument)
{
	int	arg_length;
	int	counter;

	arg_length = ft_strlen(argument);
	counter = 0;
	if (argument[counter] == '+'
		|| argument[counter] == '-')
		counter++;
	while (counter < arg_length)
	{
		if (!ft_isdigit(argument[counter]))
			return (0);
		counter++;
	}
	return (1);
}

int	check_argument_duplicate(int *array_arguments)
{
	int	position;
	int	counter;

	position = 0;
	counter = position + 1;
	while (array_arguments[position])
	{
		while (array_arguments[counter])
			if (array_arguments[position] == array_arguments[counter++])
				return (1);
		position++;
		counter = position + 1;
	}
	return (0);
}

void	push_swap(void)
{
}
