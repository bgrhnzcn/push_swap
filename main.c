/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:24:06 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/22 02:42:23 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "stdlib.h"

t_bool	int_comp(void *curr, void *next)
{
	return (*((int *)curr) > *((int *)next));
}

int	check_duplicate(t_stack *stack, int value)
{
	t_list	*temp;

	temp = stack->values;
	while (temp != NULL)
	{
		if (*((int *)(temp->content)) == value)
			return (true);
		temp = temp->next;
	}
	return (false);
}

int	parse_data(t_stack *stack, char **argv)
{
	int	i;
	int	*value;

	i = ft_strarrlen(argv) - 1;
	while (i > 1)
	{
		if (!ft_strcheck(argv[i], ft_isdigit))
			return (true);
		value = malloc(sizeof(int));
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

void	printf_int(void *integer)
{
	ft_printf("%d\n", *((int *)integer));
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*sorted;

	if (argc <= 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	sorted = ft_stacknew();
	if (parse_data(sorted, argv))
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	a = ft_stacknew();
	if (parse_data(a, argv))
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	b = ft_stacknew();
	ft_lstsort(&sorted->values, int_comp);
	ft_lstiter(sorted->values, printf_int);
	(void)b;
}