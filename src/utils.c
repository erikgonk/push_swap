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

t_list  *ft_bottom(t_list *stack)
{
  while (stack->next)
    stack = stack->next;
  return (stack);
}

t_list  *ft_new_elem(int num)
{
  t_list    *new;

  new = malloc(sizeof (t_list));
  if (!new)
    exit ((ft_fd_printf(2, "%s", ERROR_MALLOC) * 0) + 1);
  new->data = num;
  new->next = NULL;
  return (new);
}
