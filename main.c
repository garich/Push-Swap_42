/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:02:11 by agarijo-          #+#    #+#             */
/*   Updated: 2023/03/31 11:59:17 by agarijo-         ###   ########.fr       */
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
		exit(1);
	else if (argc == 2)
	{
		args = split_arguments(argv[1]);
		argc = count_array(args);
		if (argc)
		{
			argv = args;
			array_arguments = check_arguments(argc, argv);
		}
	}
	else
	{
		argc = argc - 1;
		array_arguments = check_arguments(argc, (argv + 1));
	}
	if (!array_arguments)
	{	
		if (args)
			free_malloc(args);
		write(2, "Error\n", 6);
	}
	else
	{
		push_swap(array_arguments, argc);
		if (args)
			free_malloc(args);
	}
	atexit(leaks);
}
