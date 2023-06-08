/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:16:43 by niromano          #+#    #+#             */
/*   Updated: 2023/06/08 17:16:45 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search_value(t_list **b, int *next_value)
{
	t_list	*temp;
	int		len;

	temp = *b;
	len = 0;
	next_value[0] = temp->content;
	next_value[1] = 0;
	while (temp != NULL)
	{
		if (next_value[0] < temp->content)
		{
			next_value[0] = temp->content;
			next_value[1] = len;
		}
		len ++;
		temp = temp->next;
	}
	if (next_value[1] > (ft_lstsize(*b) / 2))
		next_value[1] = -1;
}

void	wheel(t_list **a, t_list **b)
{
	int	value[2];

	while (*b != NULL)
	{
		search_value(b, value);
		while (value[1] >= 0 && (*b)->content != value[0])
			rotate_b(b);
		while (value[1] < 0 && (*b)->content != value[0])
			rev_rotate_b(b);
		push_a(a, b);
	}
}
