/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:40:44 by erigonza          #+#    #+#             */
/*   Updated: 2024/05/15 18:42:11 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	finishing(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (*stack_b)
		exit((ft_fd_printf(2, "%s", ERROR_CHECKER_STACK_B) * 0) + 1);
	if (sort_checker(*stack_a))
		exit(printf("OK") * 0);
	else
		exit(printf("KO") * 0);
}

int	swapping(char *move, t_list **s, t_list **s_b)
{
	if (move[0] == 's' && move[1] == 'a' && move[2] == '\n')
	{
		if (!*s)
			return (1);
		sa_bonus(s);
		return (1);
	}
	else if (move[0] == 's' && move[1] == 'b' && move[2] == '\n')
	{
		if (!*s_b)
			return (1);
		sb_bonus(s_b);
		return (1);
	}
	else if (move[0] == 's' && move[1] == 's' && move[2] == '\n')
	{
		if (*s)
			sa_bonus(s);
		if (*s_b)
			sb_bonus(s_b);
		return (1);
	}
	return (0);
}

int	pushing(char *move, t_list **s, t_list **s_b)
{
	if (move[0] == 'p' && move[1] == 'a' && move[2] == '\n')
	{
		if (!*s_b)
			return (1);
		pa_bonus(s, s_b);
		return (1);
	}
	else if (move[0] == 'p' && move[1] == 'b' && move[2] == '\n')
	{
		if (!*s)
			return (1);
		pb_bonus(s_b, s);
		return (1);
	}
	return (0);
}

int	rotating(char *move, t_list **s, t_list **s_b)
{
	if (move[0] == 'r' && move[1] == 'a' && move[2] == '\n')
	{
		if (!*s)
			return (1);
		ra_bonus(s);
		return (1);
	}
	else if (move[0] == 'r' && move[1] == 'b' && move[2] == '\n')
	{
		if (!*s_b)
			return (1);
		rb_bonus(s_b);
		return (1);
	}
	else if (move[0] == 'r' && move[1] == 'r' && move[2] == '\n')
	{
		rr_bonus(s, s_b);
		return (1);
	}
	return (0);
}

int	rev_rotating(char *move, t_list **s, t_list **s_b)
{
	if (move[0] == 'r' && move[1] == 'r' && move[2] == 'a' && move[3] == '\n')
	{
		if (!*s)
			return (1);
		rra_bonus(s);
		return (1);
	}
	else if (move[0] == 'r' && move[1] == 'r' && move[2] == 'b'
		&& move[3] == '\n')
	{
		if (!*s_b)
			return (1);
		rrb_bonus(s_b);
		return (1);
	}
	else if (move[0] == 'r' && move[1] == 'r' && move[2] == 'r'
		&& move[3] == '\n')
	{
		rrr_bonus(s, s_b);
		return (1);
	}
	return (0);
}
