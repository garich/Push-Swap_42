/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:02:11 by agarijo-          #+#    #+#             */
/*   Updated: 2023/03/24 19:40:48 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks(void)
{
	system("leaks -q --list push_swap");
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

t_node	*fill_list_with_array(int *array, int argc)
{
	int		counter;
	t_node	*node;
	t_node	*head;

	node = NULL;
	head = NULL;
	counter = 0;
	while (counter < argc)
	{
		node = lst_new_node();
		lst_add_value_to_node(node, array[counter]);
		lst_add_back(&head, node);
		counter++;
	}
	return (head);
}

char	**split_arguments(char *argv)
{
	char	**array_arguments_char;

	array_arguments_char = ft_split(argv, ' ');
	return (array_arguments_char);
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

int	main(int argc, char **argv)
{
	int		*array_arguments;
	t_node	*head;
	char	**args;

	array_arguments = NULL;
	head = NULL;
	args = NULL;
	if (argc == 1)
		exit(1);
	else if (argc == 2)
	{
		args = split_arguments(argv[1]);
		argc = count_array(args);
		argv = args;
		print_array(argv);
		printf("*** Num:%d\n", count_array(args));
		array_arguments = check_arguments(argc, argv);
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
		printf("Error\n");
	}
	else
	{
		head = fill_list_with_array(array_arguments, argc);
		lst_print(head);
		lst_clear(&head);
		free(array_arguments);
		if (args)
			free_malloc(args);
	}
	atexit(leaks);
}
