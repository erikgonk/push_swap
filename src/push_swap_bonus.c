/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:15:11 by erigonza          #+#    #+#             */
/*   Updated: 2024/05/15 18:41:45 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	make_move(t_list **stack_a, t_list **stack_b)
{
	char	*move;

	move = get_next_line(0);
	if (!move)
		finishing(stack_a, stack_b);
	if (swapping(move, stack_a, stack_b))
		free(move);
	else if (pushing(move, stack_a, stack_b))
		free(move);
	else if (rotating(move, stack_a, stack_b))
		free(move);
	else if (rev_rotating(move, stack_a, stack_b))
		free(move);
	else
	{
		free(move);
		exit((ft_fd_printf(2, "%s", ERROR_CHECKER_NOT_MOVE) * 0) + 1);
	}
}

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;

	if (argc == 1)
		exit(0);
	create_stack(&stack_a, argv);
	while (42 > -42)
		make_move(&stack_a, &stack_b);
	exit(0);
}
