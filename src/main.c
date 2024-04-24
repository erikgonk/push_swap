/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:40:44 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/15 17:40:47 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  ft_num_checker(char *set)
{
  int   i;

  i = -1;
  while (set[++i])
  {
    if (set[i] == '-' || set[i] == '+')
      i++;
    if (set[i] < '0' || set[i] > '9')
      exit ((ft_fd_printf(2, "%s", ERROR_CHAR_NOT_VALID) * 0) + 1);
  }
}

void  ft_save_numbers(t_list **stack_a, t_list *new)
{
  t_list    *bottom;

  if (!new)
    return ;
  if (!*stack_a)
  {
    *stack_a = new;
    return ;
  }
  bottom = ft_bottom(*stack_a);
  bottom->next = new;
}

void  create_stack(t_list **stack_a, char **argv)
{
  int             i;
  long long int   num;
  
  i = 0;
  while (argv[++i])
  {
    ft_num_checker(argv[i]);
    num = ft_atoi(argv[i]);
    if (num > 2147483647 || num < -2147483648)
      exit ((ft_fd_printf(2, "%s", ERROR_NUM_NOT_VALID) * 0) + 1);
    ft_save_numbers(stack_a, ft_new_elem(num));
  }
}

int main(int argc, char **argv)
{
  t_list   *stack_a;
  t_list   *stack_b;

  stack_a = NULL;
  stack_b = NULL;
  if (argc < 2)
    exit ((ft_fd_printf(2, "%s", ERROR_ARG) * 0) + 1);
  create_stack(&stack_a, argv);
  pb(&stack_a, &stack_b);
  t_list   *tmp = stack_b;
  int l = 0;
  while (tmp) 
  {
    l = tmp->data;
    printf("%d\n", l);
    tmp = tmp->next;
  }
  exit (0);
}
