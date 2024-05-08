/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:46:44 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/17 12:46:48 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void  swap(t_list  **stack)
{
  t_list   *tmp;

  tmp = NULL;
  tmp = *stack;
  *stack = (*stack)->next;
  tmp->next = (*stack)->next;
  (*stack)->next = tmp;
}

void  sa(t_list  **stack_a)
{
  if (!(*stack_a || (*stack_a)->next))
    return ;
  swap(stack_a);
  ft_fd_printf(1, "sa\n");
}

void  sb(t_list  **stack_b)
{
  if (!(*stack_b || (*stack_b)->next))
    return ;
  swap(stack_b);
  ft_fd_printf(1, "sb\n");
}

void  ss(t_list  **stack_a, t_list  **stack_b)
{
  swap(stack_a);
  swap(stack_b);
  ft_fd_printf(1, "ss\n");
}