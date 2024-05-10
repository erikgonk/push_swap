/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:47:20 by erigonza          #+#    #+#             */
/*   Updated: 2024/05/10 10:52:02 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate(t_list **stack)
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

void	ra(t_list **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
