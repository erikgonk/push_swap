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

void	finishing(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (*stack_b)
		exit((ft_fd_printf(2, "%s", ERROR_CHECKER_STACK_B) * 0) + 1);
	if (sort_checker(tmp))
		exit (printf("OK") * 0);
	else
		exit (printf("KO") * 0);
}

int	swapping(char *move, t_list **s, t_list **s_b)
{
	if (move[0] == 's' && move[1] == 'a' && move[2] == '\0')
	{
		sa_bonus(s);
		return (1);
	}
	else if (move[0] == 's' && move[1] == 'b' && move[2] == '\0')
	{
		sb_bonus(s_b);
		return (1);
	}
	else if (move[0] == 's' && move[1] == 'b' && move[2] == '\0')
	{
		ss_bonus(s, s_b);
		return (1);
	}
	return (0);
}

int	pushing(char *move, t_list **s, t_list **s_b)
{
	if (move[0] == 'p' && move[1] == 'a' && move[2] == '\0')
	{
		sa_bonus(s);
		return (1);
	}
	else if (move[0] == 'p' && move[1] == 'b' && move[2] == '\0')
	{
		sb_bonus(s_b);
		return (1);
	}
	return (0);
}

int	rotating(char *move, t_list **s, t_list **s_b)
{
	if (move[0] == 'r' && move[1] == 'a' && move[2] == '\0')
	{
		ra_bonus(s);
		return (1);
	}
	else if (move[0] == 'r' && move[1] == 'b' && move[2] == '\0')
	{
		rb_bonus(s_b);
		return (1);
	}
	else if (move[0] == 'r' && move[1] == 'r' && move[2] == '\0')
	{
		rr_bonus(s, s_b);
		return (1);
	}
	return (0);
}

int	rev_rotating(char *move, t_list **s, t_list **s_b)
{
	if (move[0] == 'r' && move[1] == 'r' && move[2] == 'a' && move[3] == '\0')
	{
		rra_bonus(s);
		return (1);
	}
	else if (move[0] == 'r' && move[1] == 'r' && move[2] == 'b' && move[3] == '\0')
	{
		rrb_bonus(s_b);
		return (1);
	}
	else if (move[0] == 'r' && move[1] == 'r' && move[2] == 'r' && move[3] == '\0')
	{
		rrr_bonus(s, s_b);
		return (1);
	}
	return (0);
}
