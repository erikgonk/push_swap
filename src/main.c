/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:40:44 by erigonza          #+#    #+#             */
/*   Updated: 2024/05/09 18:45:47 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_list	*ft_new_elem(int num)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		exit((ft_fd_printf(2, "%s", ERROR_MALLOC) * 0) + 1);
	new->data = num;
	new->next = NULL;
	return (new);
}

void	ft_save_numbers(t_list **stack_a, t_list *new)
{
	t_list		*bottom;
	static int	i;

	if (!i)
		i = 0;
	if (!new)
		return ;
	new->last_cost = -50;
	new->index = -1;
	new->target = -50;
	new->bol = 0;
	new->dir = UP;
	new->median = 0;
	new->cost = -50;
	new->pos = ++i;
	if (!*stack_a)
	{
		*stack_a = new;
		return ;
	}
	bottom = ft_lstlast(*stack_a);
	bottom->next = new;
}

int	create_stack(t_list **stack_a, char **argv)
{
	int				i;
	long long int	num;

	i = 0;
	while (argv[++i])
	{
		ft_num_checker(argv[i]);
		num = ft_atoi(argv[i]);
		if (num > 2147483647 || num < -2147483648)
		{
			i = 0;
			while (argv[i])
				free(argv[i]);
			free(argv);
			exit((ft_fd_printf(2, "%s", ERROR_NUM_NOT_VALID) * 0) + 1);
		}
		ft_save_numbers(stack_a, ft_new_elem(num));
		ft_num_repeated(*stack_a, 0);
	}
	return (i - 1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		elems;
	t_list	*tmp;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 3)
		exit((ft_fd_printf(2, "%s", ERROR_ARG) * 0) + 1);
	elems = create_stack(&stack_a, argv);
	ft_elems(elems, &stack_a, &stack_b);
	tmp = stack_a;
	while (tmp)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
//	if (sort_checker(stack_a))
//		exit(printf("Todo ordenado") * 0);
	exit(0);
}
