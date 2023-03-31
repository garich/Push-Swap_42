/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:33:21 by agarijo-          #+#    #+#             */
/*   Updated: 2023/03/30 20:32:50 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split_arguments(char *argv)
{
	char	**array_arguments_char;

	array_arguments_char = ft_split(argv, ' ');
	return (array_arguments_char);
}

// While ends if STATUS equals 0. 
// STATUS equals 0 only if check_argument_format fails to comply.
int	*check_arguments(int argc, char *argv[])
{
	int	counter;
	int	status;
	int	*array_arguments;

	counter = 0;
	status = -1;
	array_arguments = ft_calloc((argc), sizeof(int));
	if (!array_arguments)
		return (NULL);
	while (counter < argc && status != 0)
	{
		status = check_argument_format(argv[counter]);
		if (!status)
			return (free(array_arguments), NULL);
		array_arguments[counter] = ft_atoi_ps(argv[counter], &status);
		if (!status)
			return (free(array_arguments), NULL);
		counter++;
	}
	if (check_argument_duplicate(array_arguments, argc))
		return (free(array_arguments), NULL);
	return (array_arguments);
}

int	check_argument_format(char *argument)
{
	int	arg_length;
	int	counter;

	arg_length = ft_strlen(argument);
	counter = 0;
	if (arg_length == 0)
		return (0);
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

int	check_argument_duplicate(int *array_arguments, int size)
{
	int	position;
	int	counter;

	position = 0;
	counter = position + 1;
	while (position < size)
	{
		while (counter < size)
		{
			if (array_arguments[position] == array_arguments[counter++])
				return (1);
		}
		position++;
		counter = position + 1;
	}
	return (0);
}
