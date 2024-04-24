/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:47:20 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/17 12:47:23 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  rotate(t_list **stack)
{
  t_list   *head;
  t_list   *tmp;

  if (ft_lstsize(*stack) < 2)
    return ;
  head = ft_lstlast(*stack);
  head->next = *stack;
  tmp = ft_lstlast(*stack);
  tmp->next = NULL;
}
