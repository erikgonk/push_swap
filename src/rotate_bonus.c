/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:47:20 by erigonza          #+#    #+#             */
/*   Updated: 2024/05/15 17:22:16 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	rotate_bonus(t_list **stack)
{
	t_list	*last;
	t_list	*head;
	t_list	*second;

	if (ft_lstsize(*stack) < 2)
		return ;
	head = *stack;
	second = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = head;
	head->next = NULL;
	*stack = second;
}

void	ra_bonus(t_list **stack)
{
	rotate_bonus(stack);
}

void	rb_bonus(t_list **stack)
{
	rotate_bonus(stack);
}

void	rr_bonus(t_list **stack_a, t_list **stack_b)
{
	rotate_bonus(stack_a);
	rotate_bonus(stack_b);
}
