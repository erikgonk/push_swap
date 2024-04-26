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
