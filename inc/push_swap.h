/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:31:44 by erigonza          #+#    #+#             */
/*   Updated: 2024/05/14 16:12:23 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_ARG "Error\n"
# define ERROR_CHAR_NOT_VALID "Error\n"
# define ERROR_NUM_NOT_VALID "Error\n"
# define ERROR_MALLOC "Error\n"
# define ERROR_NUM_REPEATED "Error\n"

# define UP 0
# define DOWN 1
# define BOTH 2
# define TOP 3

typedef struct s_list
{
	int				data;
	int				pos;
	int				index;
	int				dir;
	int				target;
	int				bol;
	int				cost;
	int				median;
	int				last_cost;
	struct s_list	*next;
}					t_list;
// main
t_list				*ft_new_elem(int num);
void				ft_save_numbers(t_list **stack_a, t_list *new);
int					create_stack(t_list **stack_a, char **argv);
// erros
void				ft_num_checker(char *set);
void				ft_num_checker(char *set);
void				ft_num_repeated(t_list *stack, int bol);
// utils
t_list				*ft_bft_last(t_list *stack);
int					sort_checker(t_list *stack);
void				asign_index(t_list *s);
int					find_small_index(t_list **s);
t_list				*new_pos(t_list **stack_a);
// Sorting
void				ft_elems(int elements, t_list **stack_a, t_list **stack_b);
t_list				**three_elems(t_list **s);
t_list				**five_elems(t_list **stack_a, t_list **stack_b);
// Algorithm
void				asign_smallest_median(t_list **s);
void				bring_a_up(t_list **stack_a, t_list **stack_b, t_list *a,
						t_list *b);
void				push_to_a(t_list **stack_a, t_list **stack_b);
void				finish_it(t_list **s);
void				ft_big_sort(t_list **s, t_list **stack_b);
// Algorithm Utils
t_list				*find_cheapest(t_list **s);
int					find_smallest_num(t_list **s);
int					find_media(t_list **s);
int					no_bigger(t_list **stack_a, t_list *stack_b);
t_list				*find_data(t_list **s, int data);
// Target, Cost & Direction UTILS
void				give_dir_b(t_list *b);
void				give_dir(t_list **stack_a, t_list **stack_b);
t_list				*find_smallest_node(t_list **s);
t_list				**reset_cost(t_list **s);
// Target, Cost & Direction
void				gec(t_list *a, t_list *b);
void				give_extra_cost(t_list **stack_a, t_list **stack_b);
void				give_cost(t_list **s, int top);
void				target_while(t_list *a, t_list *b, t_list **stack_a);
void				target_and_costdir_b(t_list **stack_a, t_list **stack_b);
// SWAP
void				sa(t_list **stack_a);
void				sb(t_list **stack_b);
void				ss(t_list **stack_a, t_list **stack_b);
// PUSH
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_b, t_list **stack_a);
// ROTATE
void				ra(t_list **stack);
void				rb(t_list **stack);
void				rr(t_list **stack_a, t_list **stack_b);
// REVERSE_ROTATE
void				rra(t_list **stack);
void				rrb(t_list **stack);
void				rrr(t_list **stack, t_list **stack_b);
// LST
t_list				*ft_lstnew(int content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(int));
void				ft_lstclear(t_list **lst, void (*del)(int));
void				ft_lstiter(t_list *lst, void (*f)(int));
void				ft_lstiter(t_list *lst, void (*f)(int));
//
// BONUS
// main
void				make_move(t_list **stack_a, t_list **stack_b);
// Utils Checker
int					rev_rotating(char *move, t_list **s, t_list **s_b);
int					rotating(char *move, t_list **s, t_list **s_b);
int					pushing(char *move, t_list **s, t_list **s_b);
int					swapping(char *move, t_list **s, t_list **s_b);
void				finishing(t_list **stack_a, t_list **stack_b);
// SWAP_BONUS
void				sa_bonus(t_list **stack_a);
void				sb_bonus(t_list **stack_b);
void				ss_bonus(t_list **stack_a, t_list **stack_b);
// PUSH_BONUS
void				pa_bonus(t_list **stack_a, t_list **stack_b);
void				pb_bonus(t_list **stack_b, t_list **stack_a);
// ROTATE_BONUS
void				ra_bonus(t_list **stack);
void				rb_bonus(t_list **stack);
void				rr_bonus(t_list **stack_a, t_list **stack_b);
// REVERSE_ROTATE_BONUS
void				rra_bonus(t_list **stack);
void				rrb_bonus(t_list **stack);
void				rrr_bonus(t_list **stack, t_list **stack_b);
// PARA COMENTAR
// void				printlist(t_list **stack_a, t_list **stack_b, int z);

#endif
