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

  if (ft_lstsize(*stack) < 2)
    return ;
  head = *stack;
  *stack = (*stack)->next;
  last = ft_bottom(*stack);
  // printf("%d\n", last->data);
  last->next = head;
  head->next = NULL;
  // printf("%d\n", head->data);
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