/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:02:11 by agarijo-          #+#    #+#             */
/*   Updated: 2023/03/22 17:10:18 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks(void)
{
	system("leaks -q --list push_swap");
}

int	main(int argc, char *argv[])
{
	int		status;
	int		counter;
	int		*array_arguments;
	t_node	*head;
	t_node	*node;

	array_arguments = NULL;
	status = -1;
	counter = 0;
	head = NULL;
	if (argc == 1)
		exit(1);
	array_arguments = check_arguments(argc, argv);
	if (!array_arguments)
		printf("Error\n");
	else
	{
		while ((counter + 1) < argc)
		{
			node = lst_new_node();
			lst_add_value_to_node(node, array_arguments[counter]);
			lst_add_back(&head, node);
			counter++;
		}
		lst_print(head);
		lst_clear(&head);
		free(array_arguments);
	}
	atexit(leaks);
}
