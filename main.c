/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:02:11 by agarijo-          #+#    #+#             */
/*   Updated: 2023/03/18 20:56:55 by agarijo-         ###   ########.fr       */
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
		return (printf("Error\n"), 0);
	// printf("%d\n", status);
	// printf("Check-check:%d\n", ft_atoi_ps("1654564655664545645665465645645645665654655646565456456566546546546546546546546546546546546546545654", &status));
	// printf("%d\n", status);
	atexit(leaks);
}
