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

#include "push_swap.h"

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
  else if (elements == 4)
    four_elems(stack_a, stack_b);
  else if (elements == 5)
    five_elems(stack_a, stack_b);
  else
    ft_big_sort(stack_a, stack_b);
}

void  three_elems(t_list **s)
{
  if (!sort_checker(*s))
  {
		if ((*s)->data < (*s)->next->data)
			rra(s);
		else if ((*s)->next->data > (*s)->next->next->data)
			ra(s);
		if (!sort_checker(*s))
			sa(s);
  }
}

void  four_elems(t_list **stack_a, t_list **stack_b)
{
  int       i;

  i = find_small_index(stack_a);
  if ((*stack_a)->next->next->next->index == i)
  {
    rra(stack_a);
    pa(stack_a, stack_b);
  }
  else if ((*stack_a)->index == i)
    pa(stack_a, stack_b);
  else if ((*stack_a)->next->index == i)
  {
    ra(stack_a);
    pa(stack_a, stack_b);
  }
  else if ((*stack_a)->next->next->index == i)
  {
    rra(stack_a);
    rra(stack_a);
    pa(stack_a, stack_b);
  }
  three_elems(stack_a);
  pb(stack_b, stack_a);
}

void  five_elems(t_list **stack_a, t_list **stack_b)
{
  // quda corregir esto 
  int       i;

  i = find_small_index(stack_a);
  if ((*stack_a)->index == i)
    pa(stack_a, stack_b);
  else if ((*stack_a)->next->index == i)
  {
    ra(stack_a);
    pa(stack_a, stack_b);
  }
  else if ((*stack_a)->next->next->index == i)
  {
    ra(stack_a);
    ra(stack_a);
    pa(stack_a, stack_b);
  }
  else if ((*stack_a)->next->next->next->index == i)
  {
    rra(stack_a);
    rra(stack_a);
    pa(stack_a, stack_b);
  }
  else if ((*stack_a)->next->next->next->next->index == i)
  {
    rra(stack_a);
    pa(stack_a, stack_b);
  }
  four_elems(stack_a, stack_b);
  pb(stack_b, stack_a);
}