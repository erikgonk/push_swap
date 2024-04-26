/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:47:20 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/17 12:47:23 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  rotate(t_list **stack)
{
  t_list   *last;
  t_list   *head;
  t_list   *second;

  if (ft_lstsize(*stack) < 2)
    return ;
  head = *stack;
  second = (*stack)->next;
  last = ft_lstlast(*stack);
  last->next = head;
  head->next = NULL;
  *stack = second;
}

void  ra(t_list **stack)
{
  rotate(stack);
  ft_fd_printf(1, "ra\n");
}

void  rb(t_list **stack)
{
  rotate(stack);
  ft_fd_printf(1, "rb\n");
}

void  rr(t_list **stack_a, t_list **stack_b)
{
  rotate(stack_a);
  rotate(stack_b);
  ft_fd_printf(1, "rr\n");
}