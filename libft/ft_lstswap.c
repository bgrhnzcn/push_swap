/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:15:06 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/01/21 14:59:32 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstswap(t_list *first, t_list *second)
{
	if (first == NULL || second == NULL)
		return ;
	void *temp = first->content;
	first->content = second->content;
	second->content = temp;
}
