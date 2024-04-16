/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:59:39 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/04/16 16:01:34 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_cheapest(t_swap *swap, t_swap **min)
{
	swap->is_cheapest = true;
	(*min)->is_cheapest = false;
	*min = swap;
}

static void	do_opr_both(t_swap *swap, t_swap *target, t_stack *a, t_stack *b)
{
	if (swap->is_above_median && target->is_above_median)
		rr(a, b);
	else if (!swap->is_above_median && !target->is_above_median)
		rrr(a, b);
	else
	{
		if (swap->is_above_median)
			ra(a);
		else
			rra(a);
		if (target->is_above_median)
			rb(b);
		else
			rrb(b);
	}
}

static void	do_opr_hlpr(t_swap *swap, t_swap *target, t_stack *a, t_stack *b)
{
	if (swap == (t_swap *)a->top->content)
	{
		if (target == (t_swap *)b->top->content)
			return ;
		else if (target->is_above_median)
			rb(b);
		else
			rrb(b);
	}
	else if (target == (t_swap *)b->top->content)
	{
		if (swap == (t_swap *)a->top->content)
			return ;
		else if (swap->is_above_median)
			ra(a);
		else
			rra(a);
	}
	else
		do_opr_both(swap, target, a, b);
}

void	do_operations_a(t_stack *a, t_stack *b)
{
	t_list	*temp;
	t_swap	*target;
	t_swap	*swap;

	temp = a->top;
	while (temp != NULL)
	{
		swap = (t_swap *)temp->content;
		target = (t_swap *)swap->target->content;
		if (swap->is_cheapest)
			while (swap != a->top->content || target != b->top->content)
				do_opr_hlpr(swap, target, a, b);
		temp = temp->next;
	}
	pb(a, b);
}

void	do_operations_b(t_stack *a, t_stack *b)
{
	t_list	*target;
	t_swap	*swap;

	target = ((t_swap *)b->top->content)->target;
	while (a->top != target)
	{
		swap = (t_swap *)target->content;
		if (swap->is_above_median)
			while (a->top->content != swap)
				ra(a);
		else
			while (a->top->content != swap)
				rra(a);
	}
	pa(b, a);
}
