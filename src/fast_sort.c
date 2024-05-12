/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:21:18 by erigonza          #+#    #+#             */
/*   Updated: 2024/05/12 17:13:30 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_elems(int elements, t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (sort_checker(*stack_a))
		exit(0);
	tmp = *stack_a;
	asign_index(tmp);
	if (elements == 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa(stack_a);
	}
	else if (elements == 3)
		three_elems(stack_a);
	else if (elements == 5)
		five_elems(stack_a, stack_b);
	else
		ft_big_sort(stack_a, stack_b);
}

t_list	**three_elems(t_list **s)
{
	while (!sort_checker(*s))
	{
		if ((*s)->data < (*s)->next->data)
			rra(s);
		else if ((*s)->next->data > (*s)->next->next->data)
			ra(s);
		if (!sort_checker(*s))
			sa(s);
	}
	return (s);
}

t_list	**five_elems(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = find_smallest_node(stack_a);
	new_pos(stack_a);
	while (ft_lstsize(*stack_a) != 3)
	{
		if (tmp->pos == 0)
			pb(stack_a, stack_b);
		if (ft_lstsize(*stack_b) == 2)
			break ;
		tmp = find_smallest_node(stack_a);
		if (tmp->pos <= (ft_lstsize(*stack_a) / 2))
			ra(stack_a);
		else
			rra(stack_a);
		new_pos(stack_a);
	}
	stack_a = three_elems(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	return (stack_a);
}
