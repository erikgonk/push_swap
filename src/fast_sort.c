/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:21:18 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/26 18:21:19 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void  ft_elems(int elements, t_list **stack_a, t_list **stack_b)
{
  if (sort_checker(*stack_a))
    exit(0);
  t_list    *tmp;
  tmp = *stack_a;
  asign_index(tmp);
  if (elements == 2)
  {
    if ((*stack_a)->data > (*stack_a)->next->data)
      sa(stack_a);
  }
  else if (elements == 3)
    three_elems(stack_a);
  else
    ft_big_sort(stack_a, stack_b);
}

t_list  **three_elems(t_list **s)
{
  while (!sort_checker(*s))
  {
		if ((*s)->data < (*s)->next->data)
			rra(s);
		else if ((*s)->next->data > (*s)->next->next->data)
			ra(s);
		if (!sort_checker(*s))
			sa(s);
  }
  return (s);
}