/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:05:21 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/26 14:05:22 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  ft_num_checker(char *set)
{
  int   i;

  i = -1;
  while (set[++i])
  {
    if (set[i] == '-' || set[i] == '+')
      i++;
    if (set[i] < '0' || set[i] > '9')
      exit ((ft_fd_printf(2, "%s", ERROR_CHAR_NOT_VALID) * 0) + 1);
  }
}

void  ft_num_repeated(t_list *stack, int bol)
{
  t_list  *tmp;
  t_list  *tmp2;

  tmp = stack;
  tmp2 = stack;
  while(stack)
  {
    tmp = tmp2;
    bol = 0;
    while (tmp)
    {
      if (stack->data == tmp->data)
        bol++;
      tmp = tmp->next;
    }
    if (bol > 1)
      exit ((ft_fd_printf(2, "%s", ERROR_NUM_REPEATED) * 0) + 1);
    stack = stack->next;
  }
}
