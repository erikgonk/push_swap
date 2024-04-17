/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:47:20 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/17 12:47:23 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  rotate(t_lst *stack)
{
  if (!stack)
    return ;
  t_lst   *tmp;

  tmp = stack;
  //(*stack)->next = tmp;
  
  while (stack->next)
    stack = stack->next; 
  stack->next = tmp;
    stack = stack->next;
  stack->next = 0;
}

void  pruebas(t_lst *lst)
{

	lst = malloc(sizeof(sizeof(int)));
	lst->data = (13);
	lst->next = malloc(sizeof(t_lst));
	lst->next->data = (12);
	lst->next->next = malloc(sizeof(t_lst));
	lst->next->next->data = (10);
}

int main(void)
{
  t_lst *lst;
  int l = 0;

  lst = NULL;
  pruebas(lst);
  rotate(lst);
  while (lst) 
  {
    l = lst->data;
    printf("%d\n", l);
    lst = lst->next;
  }
  return 0;
}