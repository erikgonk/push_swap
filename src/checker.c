/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:46:04 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/26 17:46:06 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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