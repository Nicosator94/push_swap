/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 07:49:58 by niromano          #+#    #+#             */
/*   Updated: 2023/06/01 07:49:59 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_ascending(t_list *a)
{
	int	len;

	len = 1;
	while (a != NULL)
	{
		if (a->next != NULL)
		{
			if (a->content > a->next->content)
				return (len);
		}
		len ++;
		a = a->next;
	}
	return (0);
}

void	first_part(t_list **a, t_list **b)
{
	unsigned int	total;

	total = ft_lstsize(*a);
	while (total-- > 0)
	{
		if ((*a)->content < 0)
		{
			push_b(a, b);
			if ((*b)->content <= -1073741824)
				rotate_b(b);
		}
		else
			rotate_a(a);
	}
	total = ft_lstsize(*a);
	while (total-- > 0)
	{
		if ((*a)->content < 1073741824)
			push_b(a, b);
		else
			rotate_a(a);
	}
	while (*a != NULL)
		push_b(a, b);
}

void	second_part(t_list **a, t_list **b, int nb)
{
	int	i;

	i = 0;
	while (ft_lstsize(*b) > 0 && (*b)->content >= nb)
	{
		push_a(a, b);
		while (ft_lstsize(*a) > 1 && (*a)->content > (*a)->next->content)
		{
			swap_a(a);
			push_b(a, b);
			i ++;
		}
		while (i > 0)
		{
			push_a(a, b);
			i --;
		}
	}
}

int	sorting(t_list **a, t_list **b)
{
	if (check_ascending(*a) == 0 && *b == NULL)
	{
		afficher(a, b);
		ft_lstclear(a);
		ft_lstclear(b);
		exit(EXIT_SUCCESS);
	}
	first_part(a, b);
	second_part(a, b, 1073741824);
	second_part(a, b, 0);
	second_part(a, b, -1073741824);
	second_part(a, b, -2147483648);
	if (check_ascending(*a) == 0 && *b == NULL)
	{
		afficher(a, b);
		ft_lstclear(a);
		ft_lstclear(b);
		exit(EXIT_SUCCESS);
	}
	return (-1);
}
