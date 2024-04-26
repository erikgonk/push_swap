/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:21:18 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/26 18:21:19 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  ft_elems(int elements, t_list **stack_a)
{
  if (elements == 2)
  {
    if ((*stack_a)->data > (*stack_a)->next->data)
      sa(stack_a);
    return ;
  }
  // else if (elements == 3)
  //   three_elems(stack_a);
  // else
  //   ft_big_sort(stack_a);
}

// void  three_elems(t_list **stack_a);

// void  ft_big_sort(t_list **stack_a);