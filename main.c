/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:02:11 by agarijo-          #+#    #+#             */
/*   Updated: 2023/03/23 19:35:16 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks(void)
{
	system("leaks -q --list push_swap");
}

t_node	*fill_list_with_array(int *array, int argc)
{
	int		counter;
	t_node	*node;
	t_node	*head;

	node = NULL;
	head = NULL;
	counter = 0;
	while ((counter + 1) < argc)
	{
		node = lst_new_node();
		lst_add_value_to_node(node, array[counter]);
		lst_add_back(&head, node);
		counter++;
	}
	return (head);
}

int	*split_arguments(char *argv)
{
	char	**array_arguments_char;

	array_arguments_char = ft_split(argv, ' ');
	printf("test:%s\n", *(array_arguments_char));
	free(array_arguments_char);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	int		*array_arguments;
	t_node	*head;

	array_arguments = NULL;
	head = NULL;
	if (argc == 1)
		exit(1);
	else if (argc == 2)
	{
		split_arguments(argv[1]);
		// printf("%s\n", argv[1]);
	}
	else
	{
		array_arguments = check_arguments(argc, argv);
		if (!array_arguments)
			printf("Error\n");
		else
		{
			head = fill_list_with_array(array_arguments, argc);
			lst_print(head);
			lst_clear(&head);
			free(array_arguments);
		}
	}
	atexit(leaks);
}
