/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:13:13 by erigonza          #+#    #+#             */
/*   Updated: 2024/05/12 18:13:14 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		elems;

	if (argc == 1)
		exit (0);
	stack_a = NULL;
	stack_b = NULL;
	elems = create_stack(&stack_a, argv);
	ft_elems(elems, &stack_a, &stack_b);
	exit(0);
}
/* 
	if (sort_checker(stack_a))
		exit (printf("Todo ordenado") * 0);
*/