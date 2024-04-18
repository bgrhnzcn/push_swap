/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:55:59 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/04/18 15:42:05 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	check_character(int c)
{
	if (ft_isdigit(c) || c == '+' || c == '-')
		return (true);
	return (false);
}

static int	check_duplicate(t_stack *stack, long value)
{
	t_list	*temp;

	temp = stack->top;
	while (temp != NULL)
	{
		if (((t_swap *)(temp->content))->nbr == value)
			return (true);
		temp = temp->next;
	}
	return (false);
}

static long	input(t_stack *stack, char **argv)
{
	long	i;
	t_swap	*value;

	i = ft_strarrlen(argv) - 1;
	while (i >= 0)
	{
		if (!ft_strcheck(argv[i], check_character))
			return (false);
		value = malloc(sizeof (t_swap));
		if (value == NULL)
			return (false);
		value->nbr = ft_atol(argv[i]);
		if (check_duplicate(stack, value->nbr) || value->nbr > __INT_MAX__)
		{
			free(value);
			return (false);
		}
		ft_stackpush(stack, value);
		i--;
	}
	return (true);
}

int	parse_data(t_stack *stack, char **argv, int argc)
{
	char	**splitted;
	int		i;

	i = argc - 1;
	while (i > 0)
	{
		splitted = ft_split(argv[i], ' ');
		if (!input(stack, splitted))
		{
			ft_free_str_arr(splitted);
			return (true);
		}
		i--;
	}
	return (false);
}
