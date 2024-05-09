/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:20:38 by erigonza          #+#    #+#             */
/*   Updated: 2024/05/09 18:19:20 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
void	printlist(t_list **stack_a, t_list **stack_b, int z)
{
	t_list	*palprintf;

	palprintf = *stack_a;
	while (palprintf)
	{
		printf("%d [%d][%d] [%d]", palprintf->data, palprintf->cost,
			palprintf->target, palprintf->dir);
		if (palprintf->next)
			printf(" | ");
		palprintf = palprintf->next;
	}
	printf("\n");
	if (z == -1)
		return ;
	printlist(stack_b, stack_a, -1);
}*/

void	asign_smallest_median(t_list **s)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *s;
	while (tmp)
	{
		tmp2 = *s;
		while (tmp2)
		{
			if (tmp->data > tmp2->data)
				tmp->median++;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	bring_a_up(t_list **stack_a, t_list **stack_b, t_list *a, t_list *b)
{
	new_pos(stack_a);
	new_pos(stack_b);
	if (!stack_a)
		return ;
	while (a->pos != 0)
	{
		if (b->dir == BOTH && a->dir == UP && b->pos != 0)
			rr(stack_a, stack_b);
		else if (b->dir == BOTH && a->dir == DOWN && b->pos != 0)
			rrr(stack_a, stack_b);
		else if (a->dir == BOTH && b->dir == BOTH && b->pos != 0)
			rr(stack_a, stack_b);
		else if (a->dir == DOWN && b->dir == DOWN && b->pos != 0)
			rrr(stack_a, stack_b);
		else if (a->dir == UP && b->dir == UP && b->pos != 0)
			rr(stack_a, stack_b);
		else if (a->dir == DOWN)
			rra(stack_a);
		else if (a->dir == UP || a->dir == BOTH)
			ra(stack_a);
		new_pos(stack_b);
		new_pos(stack_a);
	}
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;

	while (*stack_b)
	{
		target_and_costdir_b(stack_a, stack_b);
		b = find_cheapest(stack_b);
		a = find_data(stack_a, b->target);
		bring_a_up(stack_a, stack_b, a, b);
		new_pos(stack_b);
		give_dir(stack_a, stack_b);
		while (b->pos != 0)
		{
			if (b->dir == UP)
				rb(stack_b);
			else if (b->dir == DOWN)
				rrb(stack_b);
			else if (b->dir == BOTH)
				rrb(stack_b);
			new_pos(stack_b);
		}
		pa(stack_a, stack_b);
	}
}

void	finish_it(t_list **s)
{
	t_list	*a;
	t_list	*tmp;

	a = *s;
	new_pos(s);
	tmp = find_smallest_node(s);
	while (!(a->pos == 0 && a->index == 0))
	{
		if (tmp->pos <= ft_lstsize(a))
			ra(s);
		else
			rra(s);
		new_pos(s);
		a = *s;
	}
}

void	ft_big_sort(t_list **stack_a, t_list **stack_b)
{
	int	med;

	med = find_media(stack_a);
	while (*stack_a)
	{
		if (ft_lstsize(*stack_a) == 3)
		{
			three_elems(stack_a);
			break ;
		}
		pb(stack_a, stack_b);
		if ((*stack_b)->data > med)
			rb(stack_b);
	}
	target_and_costdir_b(stack_a, stack_b);
	new_pos(stack_a);
	new_pos(stack_b);
	push_to_a(stack_a, stack_b);
	finish_it(stack_a);
}
