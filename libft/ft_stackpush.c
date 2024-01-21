/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:11:09 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/21 21:17:22 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackpush(t_stack *stack, void *content)
{
	t_list	*lst_content;

	lst_content = ft_lstnew(content);
	if (lst_content == NULL)
		return ;
	ft_lstadd_front(&stack->values, lst_content);
	stack->count++;
}
