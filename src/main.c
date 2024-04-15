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

void  pruebas(char *str, t_lst *lst)
{
  int l = 0;

  (void)str;
	lst = malloc(sizeof(sizeof(int)));
	lst->data = (13);
	lst->next = malloc(sizeof(t_lst));
	lst->next->data = (12);
	lst->next->next = malloc(sizeof(t_lst));
	lst->next->next->data = (10);
  while (lst) 
  {
    l = lst->data;
    printf("%d\n", l);
    lst = lst->next;
  }
}

int main(int argc, char **argv)
{
  t_lst  lst;

  if (argc < 2)
    exit ((ft_fd_printf(2, "%s") * 0) + 1);
  pruebas(argv[1], &lst);
  exit (0);
}