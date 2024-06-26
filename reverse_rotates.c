/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:48:45 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/04/14 01:58:22 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	t_list	*temp;

	ft_printf("rra\n");
	if (a->count <= 1)
		return ;
	temp = a->top;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = a->top;
	a->top = temp->next;
	temp->next = NULL;
}

void	rrb(t_stack *b)
{
	t_list	*temp;

	ft_printf("rrb\n");
	if (b->count <= 1)
		return ;
	temp = b->top;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = b->top;
	b->top = temp->next;
	temp->next = NULL;
}

void	rrr(t_stack *a, t_stack *b)
{
	t_list	*temp;

	ft_printf("rrr\n");
	if (a->count <= 1)
		return ;
	temp = a->top;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = a->top;
	a->top = temp->next;
	temp->next = NULL;
	if (b->count <= 1)
		return ;
	temp = b->top;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = b->top;
	b->top = temp->next;
	temp->next = NULL;
}
