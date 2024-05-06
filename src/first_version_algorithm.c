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

// #include "push_swap.h"

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

t_list  **reset_cost(t_list **s)
{
  t_list    *tmp;

  tmp = *s;
  while (tmp)
  {
    tmp->cost = -50;
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
  if (i == 0)
    exit (printf("ha petao\n"));
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

  (void)i;
  tmp = *stack_b;
  while (*stack_b)
  {
    if (ft_lstsize(*stack_b) <= 1)
    {
      pa(stack_b, stack_a);
      return ;
    }
    new_pos(stack_b);
    tmp = find_big_index_node(stack_b);
    while (tmp->pos > 0)
    {
      if (tmp->pos <= (ft_lstsize(*stack_b) / 2) && (*stack_b)->next->data == tmp->data)
        sb(stack_b);
      else if (tmp->pos <= (ft_lstsize(*stack_b) / 2))
        rb(stack_b);
      else if (tmp->pos > (ft_lstsize(*stack_b) / 2))
        rrb(stack_b);
      new_pos(stack_b);
    }
    pa(stack_b, stack_a);
  }
  sleep (1);
}

void  take_rest(t_list **s, t_list **s_b, int i)
{
  t_list    *tmp;
  t_list    *tmp2;

  tmp = *s;
  if (i == 3 && ft_lstsize(tmp) == 2 && tmp->data > tmp->next->data)
      sa(s);
  else if (i == 5 && ft_lstsize(tmp) == 4)
    four_elems(s, s_b);
  else if (i == 7 && ft_lstsize(tmp) == 6)
  {
    new_pos(s);
    tmp2 = find_small_index_node(s, 0);
    while (tmp2->pos != 0)
    {
      if (tmp2->pos <= (ft_lstsize(tmp) / 2))
        ra(s);
      else if (tmp2->pos > (ft_lstsize(tmp) / 2))
        rra(s);
    }
    pa(s_b, s);
    five_elems(s, s_b);
    pb(s_b, s);
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
    take_rest(stack_a, stack_b, i);
    give_cheap_moves(stack_a, i);
    while (tmp && ++j < i)
    {
      pb(move_to_b(find_cheapest_move(stack_a, j), stack_a, i), stack_b);
      if ((*stack_b)->cost > (i / 2))
        rb(stack_b);
    }
    if (j == i)
      return (ft_big_sort(stack_a, stack_b, i));
    tmp = tmp->next;
  }
  from_b_to_a(stack_a, stack_b, i);
}
