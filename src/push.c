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

#include "../inc/push_swap.h"

void    push(t_list **src, t_list **dst)
{
	t_list	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}

void  pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	ft_fd_printf(1, "pa\n");
}

void  pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_fd_printf(1, "pb\n");
}
