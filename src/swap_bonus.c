/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:46:44 by erigonza          #+#    #+#             */
/*   Updated: 2024/05/14 19:14:27 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	swap_bonus(t_list **stack)
{
	t_list	*tmp;

	tmp = NULL;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	sa_bonus(t_list **stack_a)
{
	if (!(*stack_a || (*stack_a)->next))
		return ;
	swap_bonus(stack_a);
}

void	sb_bonus(t_list **stack_b)
{
	if (!(*stack_b || (*stack_b)->next))
		return ;
	swap_bonus(stack_b);
}

void	ss_bonus(t_list **stack_a, t_list **stack_b)
{
	swap_bonus(stack_a);
	swap_bonus(stack_b);
}
