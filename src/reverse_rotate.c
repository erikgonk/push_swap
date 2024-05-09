/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:47:44 by erigonza          #+#    #+#             */
/*   Updated: 2024/05/09 18:20:21 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*bfr_last;
	t_list	*last;

	if (!*stack)
		return ;
	first = *stack;
	bfr_last = ft_bft_last(*stack);
	last = ft_lstlast(*stack);
	*stack = last;
	(*stack)->next = first;
	bfr_last->next = NULL;
}

void	rra(t_list **stack)
{
	reverse_rotate(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack)
{
	reverse_rotate(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
