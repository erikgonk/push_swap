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

t_list  **four_elems(t_list **stack_a, t_list **stack_b)
{
  int       i;
  t_list    *tmp;

  i = find_small_index(stack_a);
  *stack_a = new_pos(stack_a);
  tmp = *stack_a;
  while (tmp && (*stack_a)->index != i)
  {
    if (tmp->index == i && tmp->pos < (ft_lstsize(*stack_a) / 2))
      ra(stack_a);
    else if (tmp->index == i && tmp->pos >= (ft_lstsize(*stack_a) / 2))
      rra(stack_a);
    tmp = tmp->next;
    if (!tmp)
      tmp = *stack_a;
  }
  if (sort_checker(*stack_a))
    return (stack_a);
  pa(stack_a, stack_b);
  stack_a = three_elems(stack_a);
  pb(stack_b, stack_a);
  return (stack_a);
}

t_list  **five_elems(t_list **stack_a, t_list **stack_b)
{
  int       i;
  t_list    *tmp;

  i = find_small_index(stack_a);
  *stack_a = new_pos(stack_a);
  tmp = *stack_a;
  while (tmp && (*stack_a)->index != i)
  {
    if (tmp->index == i && tmp->pos < (ft_lstsize(*stack_a) / 2))
      ra(stack_a);
    else if (tmp->index == i && tmp->pos >= (ft_lstsize(*stack_a) / 2))
      rra(stack_a);
    tmp = tmp->next;
    if (!tmp)
      tmp = *stack_a;
  }
  if (sort_checker(*stack_a))
    return (stack_a);
  pa(stack_a, stack_b);
  stack_a = four_elems(stack_a, stack_b);
  pb(stack_b, stack_a);
  return (stack_a);
}