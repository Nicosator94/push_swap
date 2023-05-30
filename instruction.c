/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:00:02 by niromano          #+#    #+#             */
/*   Updated: 2023/05/30 13:00:03 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list *a)
{
	int	temp;

	temp = a->next->content;
	a->next->content = a->content;
	a->content = temp;
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_list *b)
{
	int	temp;

	temp = b->next->content;
	b->next->content = b->content;
	b->content = temp;
	ft_putstr_fd("sb\n", 1);
}

void	swap_both(t_list *a, t_list *b)
{
	int	temp;

	temp = a->next->content;
	a->next->content = a->content;
	a->content = temp;

	temp = b->next->content;
	b->next->content = b->content;
	b->content = temp;
	ft_putstr_fd("ss\n", 1);
}

void	push_a(t_list **a, t_list **b)
{
	t_list	*new;

	new = ft_lstnew((*b)->content);
	ft_lstadd_front(a, new);
	*b = (*b)->next;
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*new;

	new = ft_lstnew((*a)->content);
	ft_lstadd_front(b, new);
	*a = (*a)->next;
	ft_putstr_fd("pb\n", 1);
}