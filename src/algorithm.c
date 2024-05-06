/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:20:38 by erigonza          #+#    #+#             */
/*   Updated: 2024/05/06 13:20:41 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printlist(t_list **stack_a, t_list **stack_b, int z)
{
  t_list  *palprintf;

  palprintf = *stack_a;
  while (palprintf) 
  {
    printf("%d[%d]", palprintf->data, palprintf->target);
    if (palprintf->next)
      printf(" | ");
    palprintf = palprintf->next;
  }
  printf("\n");
  if (z == -1)
    return ;
  printlist(stack_b, stack_a, -1);
}

void  asign_smallest_median(t_list **s)
{
  t_list    *tmp;
  t_list    *tmp2;

  tmp = *s;
  while (tmp)
  {
    tmp2 = *s;
    while (tmp2)
    {
      if (tmp->data > tmp2->data)
        tmp->median++;
      tmp2 = tmp2->next;
    }
    tmp = tmp->next;
  }
}

t_list  *find_smallest_num(t_list **s)
{
  t_list    *tmp;
  t_list    *tmp2;
  int       i;

  i = -1;
  tmp = *s;
  tmp2 = *s;
  while (tmp)
  {
    i = -1;
    tmp2 = *s;
    while (tmp2 && ++i)
    {
      if (tmp2->median == i)
        return (tmp2);
    }
    tmp = tmp->next;
  }
  return (tmp);
}

int find_media(t_list **s)
{
  t_list    *tmp;
  int       i;

  tmp = *s;
  i = ft_lstsize(tmp) / 2;
  asign_smallest_median(s);
  tmp = *s;
  while (tmp)
  {
    if (tmp->median == i)
      break ;
    tmp = tmp->next;
  }
  return (tmp->data);
}

void  target_while(t_list *a, t_list *b, int size, t_list **stack_a, t_list **stack_b)
{
  int     i;
  int     bol;
  t_list  *tmp;

  bol = 0;
  i = b->median + 1;
  printlist(stack_b, stack_a, 0);
  while (a && bol != -5)
  {
    if ((i - 1) == size)
      bol = -5;
    else if (a->median == i)
    {
      bol = -5;
      b->target = a->data;
    }
    else if (!a->next && b->target == -50)
    {
      i++;
      a = *stack_a;
    }
    else
      a = a->next;
  }
}

void  give_dir_b(t_list *b)
{
  int   size;
  int   bol;

  size = ft_lstsize(b) / 2;
  bol = 0;
  if (ft_lstsize(b) % 2 == 0)
    bol = 1;
  while (b)
  {
    if (b->pos == 0)
      b->dir = TOP;
    else if (b->pos == size && bol == 1)
      b->dir = BOTH;
    else if (b->pos > size)
      b->dir = DOWN;
    else if (b->pos <= size)
      b->dir = UP;
    b = b->next;
  }
}

void  give_dir(t_list **stack_a, t_list **stack_b)
{
  t_list    *a;
  t_list    *b;
  int       size;
  int       bol;

  a = *stack_a;
  b = *stack_b;
  size = ft_lstsize(a) / 2;
  bol = 0;
  if (ft_lstsize(a) % 2 == 0)
    bol = 1;
  while (a)
  {
    if (a->pos == 0)
      a->dir = TOP;
    else if (a->pos == size && bol == 1)
      a->dir = BOTH;
    else if (a->pos > size)
      a->dir = DOWN;
    else if (a->pos <= size)
      a->dir = UP;
    a = a->next;
  }
  give_dir_b(b);
}

void  give_cost(t_list **s, int top)
{
  t_list    *tmp;
  int       size;
  // int       bol;

  tmp = *s;
  size = ft_lstsize(tmp) / 2;
  // bol = 0;
  // if (ft_lstsize(tmp) % 2 == 0)
  //   bol = 1;
  while (tmp)
  {
    if (tmp->pos == 0)
      tmp->cost = 0;
    else if (tmp->dir == UP || tmp->dir == BOTH)
      tmp->cost = tmp->pos;
    else if (tmp->pos == top)
      tmp->cost = 1;
    // else if (bol == 0)// impar
    //   tmp->cost = top - tmp->pos;
    else if (tmp->dir == DOWN)
      tmp->cost = top - tmp->pos + 1;
    tmp = tmp->next;
  }
}

t_list  *find_data(t_list **s, int data)
{
  t_list    *tmp;

  tmp = *s;
  while (tmp)
  {
    if (tmp->data == data)
      return (tmp);
    else if (!tmp->next)
      return (tmp);
    tmp = tmp->next;
  }
  return (tmp);
}

void  give_extra_cost(t_list **stack_a, t_list **stack_b)
{
  t_list    *a;
  t_list    *b;
  t_list    *tmp;

  a = *stack_a;
  b = *stack_b;
  while (b)
  {
    tmp = find_data(stack_a, b->target);
    // if (b->bol == 1)
    //   b->cost += 0;
    if (tmp->dir == BOTH && b->dir == BOTH)
    {
      if (tmp->cost > b->cost)
        b->cost = tmp->cost;   
    }
    else if (b->pos == 0)
      b->cost = tmp->cost;
    else if (tmp->dir == DOWN && b->dir == UP)
      b->cost += tmp->cost;
    else if (tmp->dir == UP && b->dir == DOWN)
      b->cost += tmp->cost;
    else if (b->dir == BOTH && b->cost < tmp->cost)
      b->cost = tmp->cost;
    b = b->next;
  }
}

void  target_and_costdir_b(t_list **stack_a, t_list **stack_b)
{
  t_list    *a;
  t_list    *b;
  int       med;
  int       med2;

  med = ft_lstsize(*stack_a) + ft_lstsize(*stack_b) - 1;
  med2 = ft_lstsize(*stack_b) - 1;
  b = *stack_b;
  while (b)
  {
    a = *stack_a;
    target_while(a, b, med2, stack_a, stack_b);
    printf("\n\n\n\t\t\t\t\t\t\tEL TARGET ES -> %d [%d]\n\n\n", b->data, b->target);
    b = b->next;
  }
  new_pos(stack_a);
  new_pos(stack_b);
  give_dir(stack_a, stack_b);
  med = ft_lstsize(*stack_a) - 1;
  give_cost(stack_a, med);
  med = ft_lstsize(*stack_b) - 1;
  give_cost(stack_b, med);
  give_extra_cost(stack_a, stack_b);
}

t_list  *find_cheapest(t_list **s)
{
  t_list    *tmp;
  int       i;

  tmp = *s;
  i = -1;
  while (tmp && ++i >= -1)
  { 
    // printf("\ni ---> %d\ntmp ----> %d [%d]", i, tmp->data, tmp->cost);
    if (tmp->dir == BOTH && tmp->cost == i)
      return (tmp);
    else if (tmp->cost == i)
      return (tmp);
  }
  return (tmp);
}

void  bring_a_up(t_list **stack_a, t_list **stack_b, t_list *a, t_list *b)
{
  new_pos(stack_a);
  while (a->pos != 0)
  {
    if (b->dir == BOTH && a->dir == UP)
      rr(stack_a, stack_b);
    else if (b->dir == BOTH && a->dir == DOWN)
      rrr(stack_a, stack_b);
    else if (a->dir == BOTH && b->dir == BOTH && b->pos != 0)
      rr(stack_a, stack_b);
    else if (a->dir == DOWN)
      rra(stack_a);
    else if (a->dir == UP)
      ra(stack_a);
    new_pos(stack_a);
  }
}

void  push_to_a(t_list **stack_a, t_list **stack_b)
{
  t_list    *a;
  t_list    *b;
  
  // printlist(stack_b, stack_b, -1);
  // printlist(stack_a, stack_a, -1);
  // printf("\n");
  while (*stack_b)
  {
    target_and_costdir_b(stack_a, stack_b);
    b = find_cheapest(stack_b);
    // printf("\n-----B --------------> %d [%d] -----\n", b->data, b->target);
    a = find_data(stack_a, b->target);
    // printf("\n-----A --------------> %d -----\n", a->data);
    bring_a_up(stack_a, stack_b, a, b);
    // printlist(stack_a, stack_a, -1);
    // printf("\n");
    // printf("\n-----B-----\n");
    // printlist(stack_b, stack_b, -1);
    // printf("\n-----A-----\n");
    // printlist(stack_a, stack_a, -1);
    // printf("\n");
    // usleep(2000000);
    while (b->pos != 0)
    {
      target_and_costdir_b(stack_a, stack_b);
      if (a->dir == BOTH)
        rb(stack_b);
      else if (a->dir == DOWN)
        rb(stack_b);
      else if (a->dir == UP)
        rrb(stack_b);
      new_pos(stack_b);
    }
    pb(stack_b, stack_a);
  }
}

void  ft_big_sort(t_list **stack_a, t_list **stack_b)
{
  int       med;
  t_list    *tmp;

  med = find_media(stack_a);
  tmp = *stack_a;
  while (*stack_a)
  {
    if (ft_lstsize(*stack_a) == 3)
    {
      three_elems(stack_a);
      break ;
    }
    pb(stack_a, stack_b);
    if ((*stack_b)->data > med)
      rb(stack_b);
  }
  target_and_costdir_b(stack_a, stack_b);
  new_pos(stack_b);
  new_pos(stack_a);
  push_to_a(stack_a, stack_b);
  printlist(stack_a, stack_b, 0);
}