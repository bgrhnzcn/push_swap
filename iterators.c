/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:58:08 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/04/03 17:53:57 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	t_swap_comp(void *curr, void *next)
{
	return (((t_swap *)curr)->nbr > ((t_swap *)next)->nbr);
}

void	printf_int(void *integer)
{
	ft_printf("%d\n", *((int *)integer));
}
