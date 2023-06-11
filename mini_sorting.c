/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:34:56 by niromano          #+#    #+#             */
/*   Updated: 2023/06/11 21:04:40 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	tri_a(t_list **p)
{
	int	trigger;
	
	trigger = 0;
	if (ft_lstsize(*p) == 3)
	{
		if ((*p)->next->content < (*p)->content && (*p)->content < (*p)->next->next->content)
			trigger = 1;
		else if ((*p)->next->content < (*p)->next->next->content && (*p)->next->next->content < (*p)->content)
			trigger = 2;
		else if ((*p)->next->next->content < (*p)->content && (*p)->content < (*p)->next->content)
			trigger = 3;
		else if ((*p)->content < (*p)->next->next->content && (*p)->next->next->content < (*p)->next->content)
			trigger = 4;
		else if ((*p)->next->next->content < (*p)->next->content && (*p)->next->content < (*p)->content)
			trigger = 5;
	}
	else if (ft_lstsize(*p) == 2)
	{
		if ((*p)->content > (*p)->next->content)
			trigger = 1;
	}
	return (trigger);
}

int	tri_b(t_list **p)
{
	int	trigger;
	
	trigger = 0;
	if (ft_lstsize(*p) == 3)
	{
		if ((*p)->next->next->content < (*p)->content && (*p)->content < (*p)->next->content)
			trigger = 1;
		else if ((*p)->content < (*p)->next->next->content && (*p)->next->next->content < (*p)->next->content)
			trigger = 2;
		else if ((*p)->next->content < (*p)->content && (*p)->content < (*p)->next->next->content)
			trigger = 3;
		else if ((*p)->next->content < (*p)->next->next->content && (*p)->next->next->content < (*p)->content)
			trigger = 4;
		else if ((*p)->content < (*p)->next->content && (*p)->next->content < (*p)->next->next->content)
			trigger = 5;
	}
	else if (ft_lstsize(*p) == 2)
	{
		if ((*p)->content < (*p)->next->content)
			trigger = 1;
	}
	return (trigger);
}

void	equal_trigger(t_list **a, t_list **b, int trigger)
{
	if (trigger == 1)
		swap_both(a, b);
	else if (trigger == 2)
		rotate_both(a, b);
	else if (trigger == 3)
		rev_rotate_both(a, b);
	else if (trigger == 4)
	{
		swap_both(a, b);
		rotate_both(a, b);
	}
	else if (trigger == 5)
	{
		swap_both(a, b);
		rev_rotate_both(a, b);
	}
	while (*b != NULL)
		push_a(a, b);
}

void	solo_trigger_a(t_list **a, int trigger)
{
	if (trigger == 1)
		swap_a(a);
	else if (trigger == 2)
		rotate_a(a);
	else if (trigger == 3)
		rev_rotate_a(a);
	else if (trigger == 4)
	{
		swap_a(a);
		rotate_a(a);
	}
	else if (trigger == 5)
	{
		swap_a(a);
		rev_rotate_a(a);
	}
}

void	solo_trigger_b(t_list **a, t_list **b, int trigger)
{
	if (trigger == 1)
		swap_b(b);
	else if (trigger == 2)
		rotate_b(b);
	else if (trigger == 3)
		rev_rotate_b(b);
	else if (trigger == 4)
	{
		swap_b(b);
		rotate_b(b);
	}
	else if (trigger == 5)
	{
		swap_b(b);
		rev_rotate_b(b);
	}
	while (*b != NULL)
		push_a(a, b);
}

void	mini_sorting(t_list **a, t_list **b)
{
	int	nb;
	int	len;
	int	trigger_a;
	int	trigger_b;
	
	check_ascending(*a, *b);
	len = ft_lstsize(*a);
	nb = medianes(a, len);
	while (len-- > 0)
	{
		if ((*a)->content < nb)
			push_b(a, b);
		else
			rotate_a(a);
	}
	trigger_a = tri_a(a);
	trigger_b = tri_b(b);
	if (trigger_a == trigger_b)
		equal_trigger(a, b, trigger_a);
	else
	{
		solo_trigger_a(a, trigger_a);
		solo_trigger_b(a, b, trigger_b);
	}
	check_ascending(*a, *b);
}
