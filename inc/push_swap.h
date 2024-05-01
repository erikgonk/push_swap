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

# define ERROR_ARG "\n"
# define ERROR_CHAR_NOT_VALID "Error\nCharacter Not Valid\n"
# define ERROR_NUM_NOT_VALID "Error\nNumber Not Valid\n"
# define ERROR_MALLOC "Error\nMalloc\n"
# define ERROR_NUM_REPEATED "Error\nNumber Repeated\n"

typedef struct s_list
{
  int           data;
  int           pos;
  int           index;
  int           cost;
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
t_list  *new_pos(t_list **stack_a);
// Sorting
void  ft_elems(int elements, t_list **stack_a, t_list **stack_b);
t_list  **three_elems(t_list **s);
t_list  **four_elems(t_list **stack_a, t_list **stack_b);
t_list  **five_elems(t_list **stack_a, t_list **stack_b);
// Algorithn
t_list  *find_small_index_node(t_list **s, int bol);
t_list  **give_cheap_moves(t_list **s, int i);
t_list  *find_cheapest_move(t_list **s, int i);
t_list  **move_to_b(t_list *move, t_list **s, int i);
void  ft_big_sort(t_list **s, t_list **stack_b, int bol);
// Algorithn Utils
int   which_big_sort(t_list **s);
t_list  **reset_cost(t_list **s);
int give_check(t_list **s);
// SWAP
void    sa(t_list  **stack_a);
void    sb(t_list  **stack_b);
void    ss(t_list  **stack_a, t_list  **stack_b);
// PUSH
void  pa(t_list **stack_a, t_list **stack_b);
void  pb(t_list **stack_b, t_list **stack_a);
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
void	  ft_lstadd_front(t_list **lst, t_list *new);
int		  ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	  ft_lstadd_back(t_list **lst, t_list *new);
void	  ft_lstdelone(t_list *lst, void (*del)(int));
void	  ft_lstclear(t_list **lst, void (*del)(int));
void	  ft_lstiter(t_list *lst, void (*f)(int));
void	  ft_lstiter(t_list *lst, void (*f)(int));


// PARA COMENTAR
void printlist(t_list **stack_a, t_list **stack_b, int z);

#endif