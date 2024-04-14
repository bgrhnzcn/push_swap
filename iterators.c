/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:58:08 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/04/08 16:18:59 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	t_swap_comp(void *curr, void *next)
{
	return (((t_swap *)curr)->nbr > ((t_swap *)next)->nbr);
}

void	printf_t_swap(void *swap)
{
	ft_printf("%d", ((t_swap *)swap)->nbr);
}

void	printf_target(void *target)
{
	ft_printf("%d\n", ((t_swap *)((t_swap *)target)->target->content)->nbr);
}
