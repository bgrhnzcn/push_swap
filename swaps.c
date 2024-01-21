/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:18:05 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/21 22:48:04 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	*temp1;
	int	*temp2;

	ft_printf("sa\n");
	if (a->count <= 1)
		return ;
	temp1 = ft_stackpop(a);
	temp2 = ft_stackpop(a);
	ft_stackpush(a, temp1);
	ft_stackpush(a, temp2);
}

void	sb(t_stack *b)
{
	int	*temp1;
	int	*temp2;

	ft_printf("sb\n");
	if (b->count <= 1)
		return ;
	temp1 = ft_stackpop(b);
	temp2 = ft_stackpop(b);
	ft_stackpush(b, temp1);
	ft_stackpush(b, temp2);
}

void	ss(t_stack *a, t_stack *b)
{
	int	*temp1;
	int	*temp2;

	ft_printf("ss\n");
	if (a->count > 1)
	{
		temp1 = ft_stackpop(a);
		temp2 = ft_stackpop(a);
		ft_stackpush(a, temp1);
		ft_stackpush(a, temp2);
	}
	if (b->count > 1)
	{
		temp1 = ft_stackpop(b);
		temp2 = ft_stackpop(b);
		ft_stackpush(b, temp1);
		ft_stackpush(b, temp2);
	}
}
