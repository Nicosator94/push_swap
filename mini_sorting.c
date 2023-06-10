/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:34:56 by niromano          #+#    #+#             */
/*   Updated: 2023/06/10 17:50:28 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	tri(t_list **pile)
{
	int	trigger;
	
	trigger = 0;
	if (ft_lstsize(*pile) == 3)
	{
		if (...)
			ft_printf("t");
		else if ((*pile)->content > (*pile)->next->content > (*pile)->next->next->content)
			trigger = 0;
	}
	else if (ft_lstsize(*pile) == 2)
	{
		if ((*pile)->content < (*pile)->next->content)
			trigger = 1;
		else if ((*pile)->content > (*pile)->next->content)
			trigger = 0;
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

void	solo_trigger_b(t_list **b, int trigger)
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
	trigger_a = tri(a);
	trigger_b = tri(b);
	if (trigger_a == trigger_b)
		equal_trigger(a, b, trigger_a);
	else
	{
		solo_trigger_a(a, trigger_a);
		solo_trigger_b(b, trigger_b);
	}
	check_ascending(*a, *b);
}
