/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:33:21 by agarijo-          #+#    #+#             */
/*   Updated: 2023/03/18 13:24:43 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_arguments(int argc, char *argv[])
{
	int	counter;
	int	status;

	counter = 1;
	status = -1;
	while (counter < argc)
	{
		status = check_argument_format(argv[counter]);
		printf("%d\n", status);
		counter++;
	}
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

void	push_swap(void)
{

}
