/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:16:34 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/04/14 01:58:15 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	t_list	*temp;

	ft_printf("ra\n");
	if (a->count <= 1)
		return ;
	temp = a->top;
	a->top = temp->next;
	temp->next = NULL;
	ft_lstlast(a->top)->next = temp;
}

void	rb(t_stack *b)
{
	t_list	*temp;

	ft_printf("rb\n");
	if (b->count <= 1)
		return ;
	temp = b->top;
	b->top = temp->next;
	temp->next = NULL;
	ft_lstlast(b->top)->next = temp;
}

void	rr(t_stack *a, t_stack *b)
{
	t_list	*temp;

	ft_printf("rr\n");
	if (a->count <= 1)
		return ;
	temp = a->top;
	a->top = temp->next;
	temp->next = NULL;
	ft_lstlast(a->top)->next = temp;
	if (b->count <= 1)
		return ;
	temp = b->top;
	b->top = temp->next;
	temp->next = NULL;
	ft_lstlast(b->top)->next = temp;
}
