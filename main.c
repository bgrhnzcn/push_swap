/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:24:06 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/04/16 16:09:07 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(int argc, char **argv, t_stack **a, t_stack **b)
{
	if (argc == 1)
		exit(EXIT_FAILURE);
	*a = ft_stacknew();
	if (parse_data(*a, argv, argc))
	{
		ft_putstr_fd("Error\n", 2);
		ft_stackclear(*a, free);
		exit(EXIT_FAILURE);
	}
	*b = ft_stacknew();
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
