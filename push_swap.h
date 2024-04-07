/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:26:48 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/04/07 20:22:03 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_swap
{
	long	nbr;
	long	index;
	long	cost;
	t_bool	is_cheapest;
	t_bool	is_above_median;
	t_list	*target;
}	t_swap;

void	printf_t_swap(void *integer);
void	printf_target(void *integer);
t_bool	t_swap_comp(void *curr, void *next);
t_list	*find_min(t_stack *stack);
t_list	*find_max(t_stack *stack);
int		parse_data(t_stack *stack, char **argv, int argc);
void	find_target_a(t_swap *val, t_stack *b);
void	find_target_b(t_swap *val, t_stack *a);

void	pa(t_stack *b, t_stack *a);
void	pb(t_stack *a, t_stack *b);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

#endif
