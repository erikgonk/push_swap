/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:20:59 by erigonza          #+#    #+#             */
/*   Updated: 2024/05/10 11:03:16 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	no_bigger(t_list **stack_a, t_list *stack_b)
{
	t_list	*a;
	t_list	*b;
	int		bol;

	bol = 0;
	a = *stack_a;
	b = stack_b;
	while (bol == 0 && a)
	{
		if (a->data > b->data)
			return (0);
		if (!a->next)
			bol = 1;
		a = a->next;
	}
	b->target = find_smallest_num(stack_a);
	return (1);
}

int	find_smallest_num(t_list **s)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *s;
	tmp2 = *s;
	while (tmp)
	{
		if (tmp->data <= tmp2->data)
			tmp2 = tmp;
		tmp = tmp->next;
	}
	return (tmp2->data);
}

t_list	*find_data(t_list **s, int data)
{
	t_list	*tmp;

	tmp = *s;
	while (tmp)
	{
		if (tmp->data == data)
			return (tmp);
		else if (!tmp->next)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

t_list	*find_cheapest(t_list **s)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *s;
	tmp2 = *s;
	while (tmp)
	{
		if (tmp->cost <= tmp2->cost)
			tmp2 = tmp;
		tmp = tmp->next;
	}
	return (tmp2);
}

int	find_media(t_list **s)
{
	t_list		*tmp;
	int			i;

	tmp = *s;
	i = ft_lstsize(tmp) / 2;
	asign_smallest_median(s);
	tmp = *s;
	while (tmp)
	{
		if (tmp->median == i)
			break ;
		tmp = tmp->next;
	}
	return (tmp->data);
}
