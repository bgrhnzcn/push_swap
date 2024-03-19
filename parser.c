/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:55:59 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/03/19 19:43:27 by bgrhnzcn         ###   ########.fr       */
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

	temp = stack->values;
	while (temp != NULL)
	{
		if (*((long *)(temp->content)) == value)
			return (true);
		temp = temp->next;
	}
	return (false);
}

static long	input(t_stack *stack, char **argv)
{
	long	i;
	long	*value;

	i = ft_strarrlen(argv) - 1;
	while (i >= 0)
	{
		if (!ft_strcheck(argv[i], check_character))
			return (true);
		value = malloc(sizeof (long));
		if (value == NULL)
			return (true);
		*value = ft_atoi(argv[i]);
		if (check_duplicate(stack, *value))
		{
			free(value);
			return (true);
		}
		ft_stackpush(stack, value);
		i--;
	}
	return (false);
}

int	parse_data(t_stack *stack, char **argv, int argc)
{
	char	**splitted;

	if (argc == 2)
	{
		splitted = ft_split(argv[1], ' ');
		if (input(stack, splitted))
		{
			ft_free_str_arr(splitted);
			return (true);
		}
		return (false);
	}
	if (input(stack, argv + 1))
		return (true);
	return (false);
}
