/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:53:51 by erigonza          #+#    #+#             */
/*   Updated: 2024/05/14 16:11:52 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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
# define ERROR_CHECKER_STACK_B "Error\n"
# define ERROR_CHECKER_NOT_MOVE "Error\n"

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
// Main
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
// erros
void				ft_num_checker(char *set);
void				ft_num_checker(char *set);
void				ft_num_repeated(t_list *stack, int bol);
// utils
t_list				*ft_new_elem(int num);
void				ft_save_numbers(t_list **stack_a, t_list *new);
int					create_stack(t_list **stack_a, char **argv);
// utils 2
t_list				*ft_bft_last(t_list *stack);
int					sort_checker(t_list *stack);
void				asign_index(t_list *s);
int					find_small_index(t_list **s);
t_list				*new_pos(t_list **stack_a);
// PARA COMENTAR
//void				printlist(t_list **stack_a, t_list **stack_b, int z);
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
#endif
