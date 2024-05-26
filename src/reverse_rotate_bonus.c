/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:47:44 by erigonza          #+#    #+#             */
/*   Updated: 2024/05/10 10:52:22 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	reverse_rotate_bonus(t_list **stack)
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

void	rra_bonus(t_list **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	reverse_rotate_bonus(stack);
}

void	rrb_bonus(t_list **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	reverse_rotate_bonus(stack);
}

void	rrr_bonus(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a && (*stack_a)->next)
		reverse_rotate_bonus(stack_a);
	if (*stack_b && (*stack_b)->next)
		reverse_rotate_bonus(stack_b);
}
