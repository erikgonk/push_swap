/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:31:44 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/15 17:32:16 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_ARG "Error\nYou Need To Add Arguments\n"

typedef struct s_lst
{
  int           data;
  struct s_lst *next;
}               t_lst;

void    swap(t_lst  **stack);
void    sa(t_lst  **stack_a);
void    sb(t_lst  **stack_b);
void    ss(t_lst  **stack_a, t_lst  **stack_b);

void  pa(t_lst **stack_a, t_lst **stack_b);
void  pb(t_lst **stack_a, t_lst **stack_b);

#endif