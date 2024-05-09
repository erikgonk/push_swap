/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_target_cost_dir.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:14:36 by erigonza          #+#    #+#             */
/*   Updated: 2024/05/09 18:38:54 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	give_dir_b(t_list *b)
{
	int	size;
	int	bol;

	size = ft_lstsize(b) / 2;
	bol = 0;
	if (ft_lstsize(b) % 2 == 0)
		bol = 1;
	while (b)
	{
		if (b->pos == 0)
			b->dir = TOP;
		else if (b->pos == size && bol == 1)
			b->dir = BOTH;
		else if (b->pos > size)
			b->dir = DOWN;
		else if (b->pos <= size)
			b->dir = UP;
		b = b->next;
	}
}

void	give_dir(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	int		size;
	int		bol;

	a = *stack_a;
	b = *stack_b;
	size = ft_lstsize(a) / 2;
	bol = 0;
	if (ft_lstsize(a) % 2 == 0)
		bol = 1;
	while (a)
	{
		if (a->pos == 0)
			a->dir = TOP;
		else if (a->pos == size && bol == 1)
			a->dir = BOTH;
		else if (a->pos > size)
			a->dir = DOWN;
		else if (a->pos <= size)
			a->dir = UP;
		a = a->next;
	}
	give_dir_b(b);
}

t_list	*find_smallest_node(t_list **s)
{
	t_list		*tmp;
	t_list		*tmp2;
	int			i;

	i = -1;
	tmp = *s;
	while (tmp)
	{
		i = -1;
		tmp2 = *s;
		while (tmp2 && ++i)
		{
			if (tmp->index == i)
				return (tmp);
			tmp2 = tmp2->next;
		}
		if (!tmp->next)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

t_list	**reset_cost(t_list **s)
{
	t_list	*tmp;

	tmp = *s;
	while (tmp)
	{
		tmp->cost = -50;
		tmp->dir = -50;
		tmp->target = -50;
		tmp = tmp->next;
	}
	return (s);
}
