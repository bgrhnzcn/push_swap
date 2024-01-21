/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:10:54 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/21 22:16:11 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *b, t_stack *a)
{
	if (b->count == 0)
		return ;
	ft_stackpush(a, ft_stackpop(b));
	ft_printf("pa\n");
}

void	pa(t_stack *a, t_stack *b)
{
	if (a->count == 0)
		return ;
	ft_stackpush(b, ft_stackpop(a));
	ft_printf("pb\n");
}
