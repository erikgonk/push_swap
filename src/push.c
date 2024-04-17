/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:46:44 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/17 12:46:48 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  pa(t_lst **stack_a, t_lst **stack_b)
{
  if (!*stack_b)
    return ;
  ft_lstadd_front(stack_b, *stack_a);
}

void  pb(t_lst **stack_a, t_lst **stack_b)
{
  if (!*stack_a)
    return ;
  ft_lstadd_front(stack_a, *stack_b);
}