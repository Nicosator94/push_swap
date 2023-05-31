/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:06:20 by niromano          #+#    #+#             */
/*   Updated: 2023/05/31 09:06:21 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **a)
{
	t_list	*new;
	t_list	*temp;

	new = ft_lstnew((*a)->content);
	temp = *a;
	*a = (*a)->next;
	free(temp);
	ft_lstadd_back(a, new);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_list **b)
{
	t_list	*new;
	t_list	*temp;

	new = ft_lstnew((*b)->content);
	temp = *b;
	*b = (*b)->next;
	free(temp);
	ft_lstadd_back(b, new);
	ft_putstr_fd("rb\n", 1);
}

void	rotate_both(t_list **a, t_list **b)
{
	t_list	*new;
	t_list	*temp;

	new = ft_lstnew((*a)->content);
	temp = *a;
	*a = (*a)->next;
	free(temp);
	ft_lstadd_back(a, new);
	new = ft_lstnew((*b)->content);
	temp = *b;
	*b = (*b)->next;
	free(temp);
	ft_lstadd_back(b, new);
	ft_putstr_fd("rr\n", 1);
}
