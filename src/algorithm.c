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

/*void printlist(t_list **stack_a, t_list **stack_b, int z)
{
  t_list  *palprintf;

  palprintf = *stack_a;
  while (palprintf) 
  {
    printf("%d[%d][%d]", palprintf->data, palprintf->pos, palprintf->cost);
    if (palprintf->next)
      printf(" | ");
    palprintf = palprintf->next;
  }
  printf("\n");
  if (z == -1)
    return ;
  printlist(stack_b, stack_a, -1);
}*/

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
      if (tmp2)
        tmp2 = tmp2->next;
    }
    if (!tmp2)
      return (tmp);
    if (tmp)
      tmp = tmp->next;
  }
  return (tmp);
}

t_list  **give_cheap_moves(t_list **s, int i)
{
  t_list    *tmp;
  int       k;

  tmp = new_pos(s);
  reset_cost(s);
  k = -1;
  tmp = *s;
  while (tmp && i--)
  {
    tmp = *s;
    tmp = find_small_index_node(s, 1);
    if (!tmp)
      break ;
    tmp->cost = ++k;
  }
  return (s);
}

t_list  *and_the_cheapest_is(t_list *t, t_list *res, t_list **s)
{
  t_list    *tmp;
  int       size;

  tmp = t;
  size = ft_lstsize(*s) / 2;
  if (!res)
    return (tmp);
  else if (size <= tmp->pos)
    tmp->last_cost = size - tmp->pos; 
  else if (size > tmp->pos)
    tmp->last_cost = size - (tmp->pos / 2); 
  if (res->last_cost <= tmp->last_cost)
    return (res);
  else if (res->last_cost > tmp->last_cost)
    return (tmp);
  return (res);
}

t_list  *find_cheapest_move(t_list **s, int i)
{
  t_list    *tmp;
  t_list    *res;

  (void)i;
  tmp = *s;
  res = NULL;
  while (tmp)
  {
    if (tmp->cost >= 0)
      res = and_the_cheapest_is(tmp, res, s);
    tmp = tmp->next;
  }
  return (res);
}

t_list  **move_to_b(t_list *move, t_list **s, int i)
{
  t_list    *tmp;

  tmp = *s;
  (void)i;
  while (tmp)
  {
    if (!tmp || !s || !move || !*s)
      break ;
    while (new_pos(s) && tmp->data == move->data && tmp->pos > 0)
    {
      if (tmp->pos <= (ft_lstsize(*s) / 2))
        ra(s);
      else if (tmp->pos > (ft_lstsize(*s) / 2))
        rra(s);
    }
    tmp = tmp->next;
  }
  return (s);
}

t_list  *find_big_index_node(t_list **s)
{
  t_list  *tmp;
  t_list  *tmp2;

  tmp = *s;
  while (tmp)
  {
    tmp2 = *s;
    while (tmp2)
    {
      if (tmp->data < tmp2->data)
        break ;
      tmp2 = tmp2->next;
    }
    if (!tmp2)
      return (tmp);
    tmp = tmp->next;
  }
  return (tmp);
}

void  from_b_to_a(t_list **stack_a, t_list **stack_b, int i)
{
  t_list  *tmp;

  tmp = *stack_b;
  asign_index(tmp);
  new_pos(stack_b);
  while (stack_b)
  {
    if (!*stack_b)
      return ;
    tmp = find_big_index_node(stack_b);
    if (tmp->cost > (i/2))
      rrb(stack_b);
    else if ((*stack_b)->next && (*stack_b)->data < (*stack_b)->next->data)
      sb(stack_b);
    pa(stack_b, stack_a);
  }
}

void  ft_big_sort(t_list **stack_a, t_list **stack_b, int bol)
{
  int       i;
  int       j;
  t_list    *tmp;

  i = bol;
  if (bol == 0)
    i = which_big_sort(stack_a);
  j = -1;
  tmp = *stack_a;
  while (tmp)
  {
    j = -1;
    give_cheap_moves(stack_a, i);
    while (tmp && ++j < i)
    {
      // if (ft_lstsize(*stack_a) == 5)
      // {
      //   five_elems(stack_a, stack_b);
      //   break ;
      // }
      pb(move_to_b(find_cheapest_move(stack_a, j), stack_a, i), stack_b);
      if ((*stack_b)->cost > (i / 2))
        rb(stack_b);
      // printf("\npasa a b ---------------> %d pos -> %d\n", (*stack_b)->data, (*stack_b)->cost);
      // usleep(500000);
    }
    printf("\n");
    if (j == i)
    {
      ft_big_sort(stack_a, stack_b, i);
      return ;
    }
    tmp = tmp->next;
  }
  from_b_to_a(stack_a, stack_b, i);
  new_pos(stack_a);
}
