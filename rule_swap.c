/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:06:11 by niromano          #+#    #+#             */
/*   Updated: 2023/05/31 09:06:13 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **a)
{
	int	temp;

	temp = (*a)->next->content;
	(*a)->next->content = (*a)->content;
	(*a)->content = temp;
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_list **b)
{
	int	temp;

	temp = (*b)->next->content;
	(*b)->next->content = (*b)->content;
	(*b)->content = temp;
	ft_putstr_fd("sb\n", 1);
}

void	swap_both(t_list **a, t_list **b)
{
	int	temp;

	temp = (*a)->next->content;
	(*a)->next->content = (*a)->content;
	(*a)->content = temp;
	temp = (*b)->next->content;
	(*b)->next->content = (*b)->content;
	(*b)->content = temp;
	ft_putstr_fd("ss\n", 1);
}