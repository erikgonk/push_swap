/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:18:57 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/27 19:18:59 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_small_index_node(t_list **s)
{
  t_list  *tmp;
  t_list  *tmp2;

  tmp = *s;
  while (tmp)
  {
    tmp2 = *s;
    while (tmp2)
    {
      if (tmp->index > tmp2->index)
        break ;
      tmp2 = tmp2->next;
    }
    if (!tmp2)
      return (tmp->index);
    tmp = tmp->next;
  }
  return (tmp);
}

t_list  *find_cheapest_move(t_list **s, int  index)
{
  int       i;
  t_list    *tmp;
  t_list    *move;

  tmp = NULL;
  *s = new_pos(s);
  while (*s && i--)
  {
    move = find_small_index_node(s);
    if (!tmp)
      tmp = move;
    else if (move->pos > tmp->pos)
      continue ;
    else
      tmp = move;
  }
  return (tmp);
}

void  move_to_b(t_list *to_move, t_list **stack_a, t_list **stack_b)
{
  *stack_a = new_pos(stack_a);
  while (to_move && (to_move)->index != i)
  {
    if (to_move->index == i && to_move->pos < (ft_lstsize(to_move) / 2))
      ra(to_move);
    else if (to_move->index == i && to_move->pos >= (ft_lstsize(to_move) / 2))
      rra(to_move);
    to_move = to_move->next;
    if (!to_move)
      to_move = to_move;
  }
  pa(stack_a, stack_b);
}

void  ft_big_sort(t_list **stack_a, t_list **stack_b)
{
  int       index;
  int       i;
  t_list    *tmp;

  i = which_big_sort(stack_a);
  index = 0;
  move_to_b(find_cheapest_move(stack_a, i), stack_a, stack_b);
}