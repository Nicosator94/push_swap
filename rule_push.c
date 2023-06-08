/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:06:06 by niromano          #+#    #+#             */
/*   Updated: 2023/06/08 17:16:16 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **a, t_list **b)
{
	t_list	*new;
	t_list	*temp;

	if (ft_lstsize(*b) == 0)
		return ;
	new = ft_lstnew((*b)->content);
	ft_lstadd_front(a, new);
	temp = *b;
	*b = (*b)->next;
	free(temp);
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*new;
	t_list	*temp;

	if (ft_lstsize(*a) == 0)
		return ;
	new = ft_lstnew((*a)->content);
	ft_lstadd_front(b, new);
	temp = *a;
	*a = (*a)->next;
	free(temp);
	ft_putstr_fd("pb\n", 1);
}
