/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:24:06 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/04/14 02:46:03 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_opr_both(t_swap *swap, t_swap *target, t_stack *a, t_stack *b)
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

void	do_opr_hlpr(t_swap *swap, t_swap *target, t_stack *a, t_stack *b)
{
	if (swap == (t_swap *)a->top->content)
	{
		if (target == (t_swap *)b->top->content)
			return ;
		else
			if (target->is_above_median)
				rb(b);
			else
				rrb(b);
	}
	else if (target == (t_swap *)b->top->content)
	{
		if (swap == (t_swap *)a->top->content)
			return ;
		else
			if (swap->is_above_median)
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

void	swap_cheapest(t_swap *swap, t_swap **min)
{
	swap->is_cheapest = true;
	(*min)->is_cheapest = false;
	*min = swap;
}

void	find_cheapest(t_stack *from)
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
			swap->cost = swap->index + 2;
		if (target->is_above_median)
			swap->cost += target->index;
		else
			swap->cost += target->index + 1;
		swap->cost++;
		if (swap->cost < min->cost)
			swap_cheapest(swap, &min);
		temp = temp->next;
	}
}

void	prepare_is_above(t_stack *stack)
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
		if (swap->index + 1 <= stack->count / 2)
			swap->is_above_median = true;
		else
			swap->is_above_median = false;
		temp = temp->next;
	}
}

void	prepare_stack(t_stack *from, t_stack *to, void (*find_target)(t_swap *val, t_stack *to))
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

void	sort_three(t_stack *stack)
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

void	init(int argc, char **argv, t_stack **a, t_stack **b)
{
	if (argc <= 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	*a = ft_stacknew();
	if (parse_data(*a, argv, argc))
	{
		ft_putstr_fd("Error\n", 2);
		ft_stackclear(*a, free);
		exit(EXIT_FAILURE);
	}
	*b = ft_stacknew();
}

void	sort_stack(t_stack *a, t_stack *b)
{
	t_list	*min;

	while (a->count > 3)
	{
		prepare_stack(a, b, find_target_a);
		find_cheapest(a);
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

void	first_checks(t_stack *a, t_stack *b)
{
	if (ft_lstissorted(a->top, t_swap_comp))
		return ;
	if (a->count > 3)
		pb(a, b);
	if (a->count > 3)
		pb(a, b);
	sort_stack(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	init(argc, argv, &a, &b);
	first_checks(a, b);
	ft_stackclear(a, free);
	ft_stackclear(b, free);
}
