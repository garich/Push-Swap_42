/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:02:11 by agarijo-          #+#    #+#             */
/*   Updated: 2023/03/19 16:39:34 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks(void)
{
	system("leaks -q --list push_swap");
}

int	main(int argc, char *argv[])
{
	int	status;

	status = -1;
	if (argc == 1)
		exit(1);
	status = check_arguments(argc, argv);
	if (!status)
		printf("Error\n");
	atexit(leaks);
}
