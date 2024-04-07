/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:20:18 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/04/07 20:21:10 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_max(t_stack *stack)
{
	t_list	*max;
	t_list	*temp;

	max = stack->top;
	temp = stack->top;
	while (temp != NULL)
	{
		if (*(long *)temp->content > *(long *)max->content)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

t_list	*find_min(t_stack *stack)
{
	t_list	*min;
	t_list	*temp;

	min = stack->top;
	temp = stack->top;
	while (temp != NULL)
	{
		if (*(long *)temp->content < *(long *)min->content)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

void	find_target_b(t_swap *val, t_stack *a)
{
	t_list	*temp;
	t_swap	*swap;
	t_swap	*target;

	temp = a->top;
	val->target = find_min(a);
	while (temp != NULL)
	{
		swap = (t_swap *)temp->content;
		target = (t_swap *)val->target->content;
		if (val->nbr < swap->nbr && swap->nbr > target->nbr)
			val->target = temp;
		temp = temp->next;
	}
}

void	find_target_a(t_swap *val, t_stack *b)
{
	t_list	*temp;
	t_swap	*swap;
	t_swap	*target;

	temp = b->top;
	val->target = find_max(b);
	while (temp != NULL)
	{
		swap = (t_swap *)temp->content;
		target = (t_swap *)val->target->content;
		if (val->nbr > swap->nbr && swap->nbr < target->nbr)
			val->target = temp;
		temp = temp->next;
	}
}
