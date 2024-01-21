/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 00:50:32 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/22 01:13:01 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *content)
{
	free(content);
}

void	ft_stackclear(t_stack *stack)
{
	ft_lstclear(&stack->values, del);
	stack->count = 0;
	free(stack);
}
