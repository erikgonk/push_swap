/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:17:45 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/24 16:35:58 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *ft_bft_last(t_list *stack)
{
  t_list    *tmp;

  while (stack->next)
  {
    tmp = stack;
    stack = stack->next;
    if (!stack->next)
      return (tmp);
  }
  return (NULL);
}

int sort_checker(t_list *stack)
{
  t_list  *tmp;
  if (!stack->next)
    return (-1);
  tmp = stack->next;
  while (stack->next)
  {
    if (stack->data > tmp->data)
        return (0);
    tmp = tmp->next;
    stack = stack->next;
  }
  return (1);
}

void  asign_index(t_list *s)
{
  t_list    *tmp;
  t_list    *tmp2;

  tmp = s;
  while (tmp)
  {
    tmp2 = s;
    while (tmp2)
    {
      if (tmp2->data <= tmp->data)
        tmp->index++;
      tmp2 = tmp2->next;
    }
    tmp = tmp->next;
  }
}

int find_small_index(t_list **s)
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
  return (tmp->index);
}

t_list  *new_pos(t_list **stack_a)
{
  t_list    *tmp;
  int       i;

  tmp = *stack_a;
  if (!tmp)
    return (NULL);
  i = -1;
  while (tmp)
  {
    tmp->pos = ++i;
    tmp = tmp->next;
  }
  tmp = *stack_a;
  return (tmp);
}