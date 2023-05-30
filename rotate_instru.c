/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instru.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:31:21 by niromano          #+#    #+#             */
/*   Updated: 2023/05/30 14:31:22 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **a)
{
	t_list	*temp;

	temp = ft_lstnew((*a)->content);
	*a = (*a)->next;
	ft_lstadd_back(a, temp);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_list **b)
{
	t_list	*temp;

	temp = ft_lstnew((*b)->content);
	*b = (*b)->next;
	ft_lstadd_back(b, temp);
	ft_putstr_fd("rb", 1);
}

void	rotate_both(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = ft_lstnew((*a)->content);
	*a = (*a)->next;
	ft_lstadd_back(a, temp);
	temp = ft_lstnew((*b)->content);
	*b = (*b)->next;
	ft_lstadd_back(b, temp);
	ft_putstr_fd("rr", 1);
}

void	rev_rotate_a(t_list **a)
{
	t_list	*temp;

	temp
	*a = new;
}