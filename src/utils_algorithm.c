/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:26:33 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/29 14:26:34 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int   which_big_sort(t_list **s)
{
  t_list    *tmp;
  int       i;

  tmp = *s;
  i = ft_lstsize(tmp);
  if (i <= 100)
    return (3);
  else if (i <= 300)
    return (5);
  else if (i > 300)
    return (7);
  return (0);
}

int give_check(t_list **s)
{
  t_list    *tmp;
  int       check;

  tmp = *s;
  check = tmp->data;
  return (check);
}

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