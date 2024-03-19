/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:58:08 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/03/18 17:58:43 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	int_comp(void *curr, void *next)
{
	return (*((int *)curr) > *((int *)next));
}

void	printf_int(void *integer)
{
	ft_printf("%d\n", *((int *)integer));
}
