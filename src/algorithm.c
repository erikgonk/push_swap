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

void printlist(t_list **stack_a, t_list **stack_b, int z)
{
  t_list  *palprintf;

  palprintf = *stack_a;
  while (palprintf) 
  {
    //printf("num -> %d ---> index %d cost ----> %d\n", palprintf->data, palprintf->index, palprintf->cost);
    printf("%d[%d] ", palprintf->data, palprintf->index);
    palprintf = palprintf->next;
  }
  printf("\n");
  if (z == -1)
    return ;
  printlist(stack_b, stack_a, -1);
}

t_list  **reset_cost(t_list **s)
{
  t_list      *tmp;

  tmp = *s;
  while (tmp)
  {
    tmp->cost = -1;
    tmp = tmp->next;
  }
  return (s);
}

t_list  *find_small_index_node(t_list **s, int bol)
{
  t_list  *tmp;
  t_list  *tmp2;

  tmp = *s;
  while (tmp)
  {
    tmp2 = *s;
    if (tmp->cost >= 0 && bol == 1)
      tmp = tmp->next;
    while (tmp2)
    {
      if (tmp2->cost >= 0 && bol == 1)
        tmp2 = tmp2->next;
      else if (tmp->index > tmp2->index)
        break ;
      tmp2 = tmp2->next;
    }
    if (!tmp2)
      return (tmp);
    tmp = tmp->next;
  }
  return (tmp);
}

t_list  **give_cheap_moves(t_list **s, int i)
{
  t_list    *tmp;
  int       k;

  tmp = new_pos(s);
  tmp = *s;
  k = -1;
  while (tmp && i--)
  {
    tmp = find_small_index_node(s, 1);
    tmp->cost = ++k;
    if (i)
      tmp = tmp->next;
  }

  return (s);
}

t_list  *find_cheapest_move(t_list **s, int i)
{
  t_list    *tmp;

  tmp = *s;
  while (tmp)
  {
    if (tmp->cost == i)
      return (tmp);
    tmp = tmp->next;
  }
  return (tmp);
}

t_list  **move_to_b(t_list *move, t_list **s)
{
  t_list    *tmp;

  tmp = *s;

  while (tmp)
  {
    new_pos(s);
    while (tmp->data == move->data && tmp->pos != 0)
    {
      new_pos(s);
      if (tmp->pos < (ft_lstsize(*s) / 2))
        ra(s);
      else if (tmp->pos > (ft_lstsize(*s) / 2))
        rra(s);
    }
    tmp = tmp->next;
  }
  return (s);
}


void  ft_big_sort(t_list **stack_a, t_list **stack_b)
{
  int       index;
  int       i;
  int       j;
  t_list    *tmp;
  i = which_big_sort(stack_a);
  j = -1;
  index = 0;
  tmp = *stack_a;
  while (tmp)
  {
    j = -1;
    stack_a = give_cheap_moves(stack_a, i);
    printlist(stack_b, stack_a, 0);
    while (tmp && ++j < i)
    {
      pa(move_to_b(find_cheapest_move(stack_a, j), stack_a), stack_b);
    printf("AQUIII\n");
    }
    tmp = tmp->next;
  }
}


