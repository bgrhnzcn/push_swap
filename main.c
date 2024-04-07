/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:24:06 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/04/07 20:22:42 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	do_operation_a_helper(t_swap *target, t_stack *b)
{
	while (target != b->top->content)
	{
		if (target->is_above_median)
			rb(b);
		else
			rrb(b);
	}
}

void	do_operations_a(t_stack *a, t_stack *b)
{
	t_list	*temp;
	t_list	*target;
	t_swap	*swap;

	temp = a->top;
	while (temp != NULL)
	{
		swap = (t_swap *)temp->content;
		if (swap->is_cheapest)
		{
			target = swap->target;
			while (swap != a->top->content)
			{
				if (swap->is_above_median)
					ra(a);
				else
					rra(a);
			}
			do_operation_a_helper(target->content, b);
			break ;
		}
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
		if (swap->is_above_median)
			while (a->top->content != swap)
				rra(a);
	}
	pa(b, a);
}

void	swap_cheapest(t_swap *swap, t_swap *min)
{
	swap->is_cheapest = true;
	min->is_cheapest = false;
}

void	find_cheapest(t_stack *from, t_stack *to)
{
	t_swap	*swap;
	t_swap	*target;
	t_list	*temp;
	t_swap	*min;

	temp = from->top;
	min = (t_swap *)temp->content;
	while (temp != NULL)
	{
		swap = (t_swap *)temp->content;
		target = (t_swap *)swap->target;
		if (swap->is_above_median)
			swap->cost = from->count - swap->index;
		else
			swap->cost = swap->index + 2;
		if (target->is_above_median)
			swap->cost += to->count - target->index - 1;
		else
			swap->cost += target->index + 1;
		if (swap->cost < min->cost)
		{
			swap_cheapest(swap, min);
			min = swap;
		}
		temp = temp->next;
	}
}

void	prepare_stack_b(t_stack *a, t_stack *b)
{
	t_list	*temp;
	t_swap	*swap;
	int		i;

	i = b->count - 1;
	temp = b->top;
	while (temp != NULL)
	{
		swap = (t_swap *)temp->content;
		swap->is_cheapest = false;
		swap->index = i--;
		if (swap->index < b->count / 2)
			swap->is_above_median = false;
		else
			swap->is_above_median = true;
		find_target_b(swap, a);
		temp = temp->next;
	}
}

void	prepare_stack_a(t_stack *a, t_stack *b)
{
	t_list	*temp;
	t_swap	*swap;
	int		i;

	i = a->count - 1;
	temp = a->top;
	while (temp != NULL)
	{
		swap = (t_swap *)temp->content;
		swap->is_cheapest = false;
		swap->index = i--;
		if (swap->index < a->count / 2)
			swap->is_above_median = false;
		else
			swap->is_above_median = true;
		find_target_a(swap, b);
		temp = temp->next;
	}
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

	min = find_min(a);
	while (a->count > 3)
	{
		prepare_stack_a(a, b);
		ft_printf("------------------------\n");
		ft_lstiter(a->top, printf_target);
		ft_printf("------------------------\n");
		find_cheapest(a, b);
		do_operations_a(a, b);
	}
	if (!ft_lstissorted(a->top, t_swap_comp))
		sort_three(a);
	while (b->count > 0)
	{
		prepare_stack_b(a, b);
		do_operations_b(a, b);
	}
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
	ft_lstiter(a->top, printf_t_swap);
	ft_printf("-----------------------\n");
	first_checks(a, b);
	ft_lstiter(a->top, printf_t_swap);
	if (ft_lstissorted(a->top, t_swap_comp))
		ft_printf("Sirali");
	else
		ft_printf("sirasiz");
	ft_stackclear(a, free);
	ft_stackclear(b, free);
}
