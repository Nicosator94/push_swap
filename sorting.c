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

int	first_part(t_list **a, t_list **b)
{
	unsigned int	total;
	int				nb;
	int				len;

	nb = average(a);
	total = ft_lstsize(*a);
	len = 0;
	while (total-- > 0)
	{
		if ((*a)->content <= nb)
		{
			push_b(a, b);
			len ++;
		}
		else
			rotate_a(a);
	}
	return (len);
}

int	second_part(t_list **a, t_list **b, int temp)
{
	unsigned int	total;
	int				nb;
	int				len;
	int				time;

	nb = average(b);
	total = ft_lstsize(*b);
	len = 0;
	time = 0;
	while (total-- > 0)
	{
		if ((*b)->content <= nb)
		{
			rotate_b(b);
			len ++;
		}
		else
		{
			push_a(a ,b);
			time ++;
		}
	}
	if (temp == 0)
		temp = second_part(a, b, 1);
	while (time > 0)
	{
		push_b(a, b);
		time --;
	}
	return (len);
}

int	third_part(t_list **a, t_list **b)
{
	unsigned int	total;
	int				nb;
	int				len;

	nb = average(a);
	total = ft_lstsize(*a);
	len = 0;
	while (total-- > 0)
	{
		if ((*a)->content <= nb)
		{
			push_b(a, b);
			len ++;
		}
		else
			rotate_a(a);
	}
	return (len);
}

void	fourth_part(t_list **a, t_list **b)
{
	while (*a != NULL)
		push_b(a, b);
}

void	fifth_part(t_list **a, t_list **b, int nb)
{
	int	time;

	time = 0;
	while (nb > 0)
	{
		push_a(a, b);
		while (ft_lstsize(*a) > 1 && (*a)->content > (*a)->next->content)
		{
			swap_a(a);
			push_b(a, b);
			time ++;
		}
		while (time > 0)
		{
			push_a(a, b);
			time --;
		}
		nb --;
	}
}

int	sorting(t_list **a, t_list **b)
{
	int	tab[3];

	if (check_ascending(*a) == 0 && *b == NULL)
	{
	//	afficher(a, b);
		ft_lstclear(a);
		ft_lstclear(b);
		exit(EXIT_SUCCESS);
	}
	tab[0] = first_part(a, b);
	tab[1] = second_part(a, b, 0);
	tab[2] = third_part(a, b);
	fourth_part(a, b);
	fifth_part(a, b, tab[2]);
	fifth_part(a, b, tab[0]);
	fifth_part(a, b, tab[1]);
	if (check_ascending(*a) == 0 && *b == NULL)
	{
		//afficher(a, b);
		ft_lstclear(a);
		ft_lstclear(b);
		exit(EXIT_SUCCESS);
	}
	return (-1);
}
