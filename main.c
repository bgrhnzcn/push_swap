/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:24:06 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/03/19 19:43:30 by bgrhnzcn         ###   ########.fr       */
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

t_list	*find_cheapest(t_stack *a, t_stack *b)
{
	
}

void	sort_stack(t_stack *a, t_stack *b)
{
	t_list	*cheapest;
	while (a->count > 3)
	{
		cheapest = find_cheapest(a, b);
		apply_operations(a, b, cheapest);
	}
	
}

void	init(int argc, char **argv, t_stack *a, t_stack *b)
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
	b = ft_stacknew();
}

void	first_checks(t_stack *a, t_stack *b)
{
	if (ft_lstissorted(a->values, int_comp))
		return;
	if (a->count == 2)
		ra(a);
	if (a->count == 3)
		sort_three(a);
	if (a->count == 4)
	{
		pb(a, b);
		sort_stack(a, b);
	}
	else
	{
		pb(a, b);
		pb(a, b);
		sort_stack(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	init(argc, argv, a, b);
	ft_lstsort(&a->values, int_comp);
	ft_lstiter(a->values, printf_int);
	if (ft_lstissorted(a->values, int_comp))
		ft_printf("Sirali");
	else
		ft_printf("sirasiz");
	ft_stackclear(a, free);
	ft_stackclear(b, free);
}
