/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:24:06 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/04/04 17:44:24 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_max(t_stack *stack)
{
	t_list	*max;
	t_list	*temp;

	max = stack->values;
	temp = stack->values;
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

	min = stack->values;
	temp = stack->values;
	while (temp != NULL)
	{
		if (*(long *)temp->content < *(long *)min->content)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

void	sort_three(t_stack *stack)
{
	t_list	*biggest;

	biggest = find_max(stack);
	if (biggest == stack->values)
		ra(stack);
	else if (biggest == stack->values->next)
		rra(stack);
	if (!ft_lstissorted(stack->values, int_comp))
		sa(stack);
}

void	do_operations_a(t_stack *a, t_stack *b)
{
	t_list	*temp;
	t_swap	*swap;

	temp = a->values;
	while (temp != NULL)
	{
		swap = (t_swap *)temp->content;
		if (swap->is_cheapest && swap->is_above_median)
			while(a->values->content != swap)
				ra(a);
		if (swap->is_cheapest && swap->is_above_median)
			while(a->values->content != swap)
				rra(a);
		pb(a, b);
		temp = temp->next;
	}
}

void	do_operations_b(t_stack *a, t_stack *b)
{
	t_list	*temp;
	t_swap	*swap;

	temp = a->values;
	while (temp != NULL)
	{
		swap = (t_swap *)temp->content;
		if (swap->is_cheapest && swap->is_above_median)
			while(a->values->content != swap)
				ra(a);
		if (swap->is_cheapest && swap->is_above_median)
			while(a->values->content != swap)
				rra(a);
		pb(a, b);
		temp = temp->next;
	}
}

void	find_cheapest(t_stack *a, t_stack *b)
{
	t_swap	*swap;
	t_list	*temp;

	temp = a->values;
	while (temp != NULL)
	{
		swap = (t_swap *)temp->content;
		
	}
	
}

void	find_target_b(t_swap *val, t_stack *a)
{
	t_list	*temp;
	t_swap	*swap;

	temp = a->values;
	val->target = find_min(a);
	while (temp != NULL)
	{
		swap = (t_swap *)temp->content;
		if (val->nbr < swap->nbr)
			val->target = temp;
		temp = temp->next;
	}
}

void	prepare_stack_b(t_stack *a, t_stack *b)
{
	t_list	*temp;
	t_swap	*swap;
	int		i;

	i = b->count - 1;
	temp = b->values;
	while (temp != NULL)
	{
		swap = (t_swap *)temp->content;
		swap->index = i--;
		if (swap->index < b->count / 2)
			swap->is_above_median = false;
		else
			swap->is_above_median = true;
		find_target_b(swap, a);
		temp = temp->next;
	}
}

void	send_back(t_stack *a, t_stack *b)
{
	while (b->count > 0)
	{
		prepare_stack_b(a, b);
	}
	
}

void	find_target_a(t_swap *val, t_stack *b)
{
	t_list	*temp;
	t_swap	*swap;

	temp = b->values;
	val->target = find_max(b);
	while (temp != NULL)
	{
		swap = (t_swap *)temp->content;
		if (val->nbr > swap->nbr)
			val->target = temp;
		temp = temp->next;
	}
}

void	prepare_stack_a(t_stack *a, t_stack *b)
{
	t_list	*temp;
	t_swap	*swap;
	int		i;

	i = a->count - 1;
	temp = a->values;
	while (temp != NULL)
	{
		swap = (t_swap *)temp->content;
		swap->index = i--;
		if (swap->index < a->count / 2)
			swap->is_above_median = false;
		else
			swap->is_above_median = true;
		find_target_a(swap, b);
		temp = temp->next;
	}
}

void	init(int argc, char **argv, t_stack *a, t_stack **b)
{
	if (argc <= 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	a = ft_stacknew();
	if (parse_data(a, argv, argc))
	{
		ft_putstr_fd("Error\n", 2);
		ft_lstclear(&a->values, free);
		free(a);
		exit(EXIT_FAILURE);
	}
	*b = ft_stacknew();
}

void	sort_stack(t_stack *a, t_stack *b)
{
	while (a->count > 3)
	{
		prepare_stack_a(a, b);
		find_cheapest(a, b);
		do_operations_a(a, b);
	}
	if (!ft_lstissorted(a->values, int_comp))
		sort_three(a);
	send_back(a, b);
}

void	first_checks(t_stack *a, t_stack *b)
{
	if (a->count > 3 && ft_lstissorted(a->values, int_comp))
		pb(a, b);
	if (a->count > 3 && ft_lstissorted(a->values, int_comp))
		pb(a, b);
	if (ft_lstissorted(a->values, int_comp))
		return ;
	sort_stack(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	init(argc, argv, a, &b);
	first_checks(a, b);
	ft_lstsort(&a->values, int_comp);
	ft_lstiter(a->values, printf_int);
	if (ft_lstissorted(a->values, int_comp))
		ft_printf("Sirali");
	else
		ft_printf("sirasiz");
	ft_stackclear(a, free);
	ft_stackclear(b, free);
}
