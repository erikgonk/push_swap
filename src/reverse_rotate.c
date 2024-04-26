/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:47:44 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/17 12:47:45 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  reverse_rotate(t_list **stack)
{
  t_list    *first;
  t_list    *bfr_last;
  t_list    *last;

  if (!*stack)
    return ;
  first = *stack;
  bfr_last = ft_bft_last(*stack);
  last = ft_lstlast(*stack);
  first = last;
  bfr_last->next = NULL;
  first->next = (*stack)->next;
  *stack = first;
  printf("%d\n", (*stack)->next->data);
  printf("%d\n", (*stack)->data);
}

void  rra(t_list **stack)
{
  reverse_rotate(stack);
  ft_fd_printf(1, "rra\n");
}

void  rrb(t_list **stack)
{
  reverse_rotate(stack);
  ft_fd_printf(1, "rrb\n");
}

void  rrr(t_list **stack_a, t_list **stack_b)
{
  reverse_rotate(stack_a);
  reverse_rotate(stack_b);
  ft_fd_printf(1, "rrr\n");
}