/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_cost_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:14:21 by erigonza          #+#    #+#             */
/*   Updated: 2024/05/09 18:39:14 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	give_cost(t_list **s, int top)
{
	t_list	*tmp;
	int		size;

	tmp = *s;
	size = ft_lstsize(tmp) / 2;
	while (tmp)
	{
		if (tmp->pos == 0)
			tmp->cost = 0;
		else if (tmp->dir == UP || tmp->dir == BOTH)
			tmp->cost = tmp->pos;
		else if (tmp->pos == top)
			tmp->cost = 1;
		else if (tmp->dir == DOWN)
			tmp->cost = top - tmp->pos + 1;
		tmp = tmp->next;
	}
}

void	gec(t_list *a, t_list *b)
{
	if (a->dir == UP && b->dir == UP)
	{
		if (a->cost > b->cost)
			b->cost = a->cost;
	}
	else if (b->pos == 0)
		b->cost = a->cost;
	else if ((b->dir == BOTH || a->dir == BOTH) && b->cost < a->cost)
		b->cost = a->cost;
	else
		b->cost += a->cost;
}

void	give_extra_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*b;
	t_list	*a;

	b = *stack_b;
	while (b)
	{
		a = find_data(stack_a, b->target);
		if (a->dir == BOTH && b->dir == BOTH)
		{
			if (a->cost > b->cost)
				b->cost = a->cost;
		}
		else if (a->dir == DOWN && b->dir == DOWN)
		{
			if (a->cost > b->cost)
				b->cost = a->cost;
		}
		else
			gec(a, b);
		b = b->next;
	}
}

void	target_while(t_list *a, t_list *b, t_list **stack_a)
{
	int	i;
	int	bol;

	bol = 0;
	i = b->median + 1;
	while (a && bol != -5)
	{
		if (no_bigger(stack_a, b))
		{
			bol = -5;
		}
		else if (a->median == i)
		{
			bol = -5;
			b->target = a->data;
		}
		else if (!a->next && b->target == -50)
		{
			i++;
			a = *stack_a;
		}
		else
			a = a->next;
	}
}

void	target_and_costdir_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	int		med;
	int		med2;

	med = ft_lstsize(*stack_a) + ft_lstsize(*stack_b) - 1;
	med2 = ft_lstsize(*stack_b) - 1;
	b = *stack_b;
	reset_cost(stack_b);
	while (b)
	{
		a = *stack_a;
		target_while(a, b, stack_a);
		b = b->next;
	}
	new_pos(stack_a);
	new_pos(stack_b);
	give_dir(stack_a, stack_b);
	med = ft_lstsize(*stack_a) - 1;
	give_cost(stack_a, med);
	med = ft_lstsize(*stack_b) - 1;
	give_cost(stack_b, med);
	give_extra_cost(stack_a, stack_b);
}
