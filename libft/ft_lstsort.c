/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 01:49:38 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/22 02:43:23 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//This function uses bubble-sort for now. Comparator gives true when current
//node bigger (define in comparator for different types) than next node.
void	ft_lstsort(t_list **list, t_bool (*comparator)(void *, void *))
{
	t_list	*curr;
	int		i;

	curr = *list;
	i = 0;
	while (i < ft_lstsize(*list))
	{
		while (curr->next != NULL)
		{
			if (comparator(curr, curr->next))
				ft_lstswap(curr, curr->next);
			else
				curr = curr->next;
		}
		i++;
	}
}
