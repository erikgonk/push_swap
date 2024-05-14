/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:40:44 by erigonza          #+#    #+#             */
/*   Updated: 2024/05/10 13:11:08 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

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
		if (argv[i][0] == '\0')
			exit((ft_fd_printf(2, "%s", ERROR_NUM_NOT_VALID) * 0) + 1);
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
