/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:58:38 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/24 16:58:39 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew(int content)
{
	t_list	*hal;

	hal = (t_list *)malloc(sizeof(*hal));
	if (!hal)
		return (NULL);
	hal->data = content;
	hal->next = NULL;
	return (hal);
}

int	ft_lstsize(t_list *lst)
{
	size_t		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
