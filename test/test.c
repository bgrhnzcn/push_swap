/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:54:31 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/22 23:15:55 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printf_int(void *integer)
{
	ft_printf("%d -> ", *((int *)integer));
}

t_bool	int_comp(void *curr, void *next)
{
	int	a;
	int	b;

	a = *((int *)curr);
	b = *((int *)next);
	if (a > b)
		return (true);
	return (false);
	//return (*((int *)curr) > *((int *)next));
}

int	main(void)
{
	t_list	*lst;
	int		*a;
	int		*a1;
	int		*a2;
	int		*a3;
	int		*a4;
	int		*a5;

	a = malloc(sizeof(int));
	a1 = malloc(sizeof(int));
	a2 = malloc(sizeof(int));
	a3 = malloc(sizeof(int));
	a4 = malloc(sizeof(int));
	a5 = malloc(sizeof(int));
	*a = 2;
	*a1 = 1;
	*a2 = 8;
	*a3 = 3;
	*a4 = 5;
	*a5 = 6;
	lst = ft_lstnew(a);
	ft_lstadd_front(&lst, ft_lstnew(a1));
	ft_lstadd_front(&lst, ft_lstnew(a2));
	ft_lstadd_front(&lst, ft_lstnew(a3));
	ft_lstadd_front(&lst, ft_lstnew(a4));
	ft_lstadd_front(&lst, ft_lstnew(a5));
	ft_lstsort(&lst, int_comp);
	ft_lstiter(lst, printf_int);
}
