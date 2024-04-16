/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:51:06 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/04/16 16:02:50 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *stack)
{
	t_list	*biggest;

	biggest = find_max(stack);
	if (biggest == stack->top)
		ra(stack);
	else if (biggest == stack->top->next)
		rra(stack);
	if (!ft_lstissorted(stack->top, t_swap_comp))
		sa(stack);
}

static void	prepare_is_above(t_stack *stack)
{
	t_list	*temp;
	t_swap	*swap;
	int		i;

	i = 0;
	temp = stack->top;
	while (temp != NULL)
	{
		swap = (t_swap *)temp->content;
		swap->index = i++;
		swap->is_cheapest = false;
		if (swap->index <= stack->count / 2)
			swap->is_above_median = true;
		else
			swap->is_above_median = false;
		temp = temp->next;
	}
}

static void	prepare_stack(t_stack *from, t_stack *to,
				void (*find_target)(t_swap *val, t_stack *to))
{
	t_list	*temp;
	t_swap	*swap;

	temp = from->top;
	prepare_is_above(from);
	prepare_is_above(to);
	while (temp != NULL)
	{
		swap = (t_swap *)temp->content;
		find_target(swap, to);
		temp = temp->next;
	}
}

static void	find_cheapest(t_stack *from, t_stack *to)
{
	t_swap	*swap;
	t_swap	*target;
	t_list	*temp;
	t_swap	*min;

	temp = from->top;
	min = (t_swap *)temp->content;
	min->is_cheapest = true;
	while (temp != NULL)
	{
		swap = (t_swap *)temp->content;
		target = (t_swap *)swap->target->content;
		if (swap->is_above_median)
			swap->cost = swap->index;
		else
			swap->cost = from->count - swap->index;
		if (target->is_above_median)
			swap->cost += target->index;
		else
			swap->cost += to->count - target->index;
		swap->cost++;
		if (swap->cost < min->cost)
			swap_cheapest(swap, &min);
		temp = temp->next;
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{
	t_list	*min;

	while (a->count > 3)
	{
		prepare_stack(a, b, find_target_a);
		find_cheapest(a, b);
		do_operations_a(a, b);
	}
	if (!ft_lstissorted(a->top, t_swap_comp))
		sort_three(a);
	while (b->count > 0)
	{
		prepare_stack(b, a, find_target_b);
		do_operations_b(a, b);
	}
	prepare_is_above(a);
	min = find_min(a);
	while (a->top != min)
	{
		if (((t_swap *)min->content)->is_above_median)
			ra(a);
		else
			rra(a);
	}
}
