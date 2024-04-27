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

# include "../src/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_ARG "Error\nYou Need To Add Arguments\n"
# define ERROR_CHAR_NOT_VALID "Error\nCharacter Not Valid\n"
# define ERROR_NUM_NOT_VALID "Error\nNumber Not Valid\n"
# define ERROR_MALLOC "Error\nMalloc\n"
# define ERROR_NUM_REPEATED "Error\nNumber Repeated\n"

typedef struct s_list
{
  int           data;
  int           pos;
  int           index;
  struct s_list *prev;
  struct s_list *next;
}               t_list;
// main
t_list  *ft_new_elem(int num);
void    ft_save_numbers(t_list **stack_a, t_list *new);
int     create_stack(t_list **stack_a, char **argv);
// erros
void  ft_num_checker(char *set);
void  ft_num_checker(char *set);
void  ft_num_repeated(t_list *stack, int bol);
// utils
t_list  *ft_bft_last(t_list *stack);
int     sort_checker(t_list *stack);
void    asign_index(t_list *s);
int     find_small_index(t_list **s);
// Sorting
void  ft_elems(int elements, t_list **stack_a, t_list **stack_b);
void  three_elems(t_list **s);
void  four_elems(t_list **stack_a, t_list **stack_b);
void  five_elems(t_list **stack_a, t_list **stack_b);
// Algorithn
void  ft_big_sort(t_list **stack_a, t_list **stack_b);
// SWAP
void    sa(t_list  **stack_a);
void    sb(t_list  **stack_b);
void    ss(t_list  **stack_a, t_list  **stack_b);
// PUSH
void  pa(t_list **stack_a, t_list **stack_b);
void  pb(t_list **stack_a, t_list **stack_b);
// ROTATE
void  ra(t_list **stack);
void  rb(t_list **stack);
void  rr(t_list **stack_a, t_list **stack_b);
// REVERSE_ROTATE
void  rra(t_list **stack);
void  rrb(t_list **stack);
void  rrr(t_list **stack, t_list **stack_b);
// LST
t_list	*ft_lstnew(int  content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(int));
void	ft_lstclear(t_list **lst, void (*del)(int));
void	ft_lstiter(t_list *lst, void (*f)(int));
void	ft_lstiter(t_list *lst, void (*f)(int));

#endif