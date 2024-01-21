/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:12:05 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/21 21:12:15 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_stackpop(t_stack *stack)
{
	void	*content;
	t_list	*temp;

	content = stack->values->content;
	temp = stack->values;
	stack->values = stack->values->next;
	ft_lstdelone(temp, NULL);
	stack->count--;
	return (content);
}
