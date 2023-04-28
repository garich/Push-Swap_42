/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:02:11 by agarijo-          #+#    #+#             */
/*   Updated: 2023/04/28 16:11:03 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks(void)
{
	system("leaks -q --list push_swap");
}

int	main(int argc, char **argv)
{
	int		*array_arguments;
	char	**args;

	array_arguments = NULL;
	args = NULL;
	if (argc == 1)
		exit(0);
	else
		array_arguments = manage_array(&argc, &args, argv);
	if (!array_arguments)
	{
		if (args)
			free_malloc((void *)args);
		write(2, "Error\n", 6);
	}
	else
	{
		push_swap(array_arguments, argc);
		if (args)
			free_malloc((void *)args);
	}
	// atexit(leaks);
}
