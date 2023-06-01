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

int	average(t_list **a)
{
	t_list	*temp;
	int		min;
	int		max;
	int		nb;

	temp = *a;
	min = temp->content;
	max = temp->content;
	while (temp != NULL)
	{
		if (min > temp->content)
			min = temp->content;
		if (max < temp->content)
			max = temp->content;
		temp = temp->next;
	}
	nb = (min + max) / 2;
	return (nb);
}

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
	int				nb;

	nb = average(a);
	total = ft_lstsize(*a);
	while (total-- > 0)
	{
		if ((*a)->content <= nb)
			push_b(a, b);
		else
			rotate_a(a);
	}
}

void	second_part(t_list **b)
{
	unsigned int	total;
	int				nb;

	nb = average(b);
	total = ft_lstsize(*b);
	while (total-- > 0)
	{
		if ((*b)->content <= nb)
			rotate_b(b);
		else
			swap_b(b);
	}
}

void	third_part(t_list **a, t_list **b)
{
	unsigned int	total;
	int				nb;

	nb = average(a);
	ft_printf("%d\n", nb);
	total = ft_lstsize(*a);
	while (total-- > 0)
	{
		if ((*a)->content <= nb)
			push_b(a, b);
		else
			rotate_a(a);
	}
}

void	four_part(t_list **a, t_list **b)
{
	while (*a != NULL)
		push_b(a, b);
}

int	sorting(t_list **a, t_list **b)
{
	if (check_ascending(*a) == 0 && *b == NULL)
	{
	//	afficher(a, b);
		ft_lstclear(a);
		ft_lstclear(b);
		exit(EXIT_SUCCESS);
	}
	first_part(a, b);
	second_part(b);
	third_part(a, b);
	four_part(a, b);
//	if (check_ascending(*a) == 0 && *b == NULL)
//	{
		afficher(a, b);
		ft_lstclear(a);
		ft_lstclear(b);
		exit(EXIT_SUCCESS);
//	}
	return (-1);
}
