/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:48:11 by niromano          #+#    #+#             */
/*   Updated: 2023/06/02 11:48:12 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	average(t_list **a, int len)
{
	t_list	*temp;
	int		min;
	int		max;
	int		nb;

	temp = *a;
	min = temp->content;
	max = temp->content;
	while (len > 0)
	{
		if (min > temp->content)
			min = temp->content;
		if (max < temp->content)
			max = temp->content;
		temp = temp->next;
		len --;
	}
	nb = (min + max) / 2;
	return (nb);
}

int	little_average(t_list **a, int len, int max_nb)
{
	t_list	*temp;
	int		min;
	int		max;
	int		nb;

	temp = *a;
	min = temp->content;
	max = temp->content;
	while (len > 0)
	{
		if (min > temp->content && temp->content < max_nb)
			min = temp->content;
		if (max < temp->content && temp->content < max_nb)
			max = temp->content;
		temp = temp->next;
		len --;
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

void	first_part(t_list **a, t_list **b, int *len)
{
	unsigned int	total;
	int				nb;

	total = ft_lstsize(*a);
	nb = average(a, total);
	len[0] = 0;
	len[1] = 0;
	while (total-- > 0)
	{
		if ((*a)->content <= nb)
		{
			push_b(a, b);
			len[1] ++;
		}
		else
		{	
			rotate_a(a);
			len[0] ++;
		}
	}
}

void	second_part(t_list **a, t_list **b, int len, int *new_len)
{
	int	nb;

	new_len[0] = 0;
	new_len[1] = 0;
	nb = average(b, len);
	while (len > 0)
	{
		if ((*b)->content < nb)
		{
			rotate_b(b);
			new_len[1] ++;
		}
		else
		{
			push_a(a, b);
			new_len[0] ++;
		}
		len --;
	}
}

void	fill(t_list **a, t_list **b, int len)
{
	while (len > 0)
	{
		push_b(a, b);
		len --;
	}
}

void	third_part(t_list **a, t_list **b, int len, int *new_len)
{
	int	nb;

	new_len[0] = 0;
	new_len[1] = 0;
	nb = average(a, len);
	while (len > 0)
	{
		if ((*a)->content > nb)
		{
			push_b(a, b);
			rotate_b(b);
			new_len[1] ++;
		}
		else
		{
			push_b(a, b);
			new_len[0] ++;
		}
		len --;
	}
}

void	rot_switch(t_list **b, int len)
{
	while (len > 0)
	{
		rev_rotate_b(b);
		len --;
	}
}

void	fourth_part(t_list **a, t_list **b, int len, int *new_len)
{
	int	nb;
	int	little_nb;

	new_len[0] = 0;
	new_len[1] = 0;
	nb = average(a, len);
	little_nb = little_average(a, len, nb);
	while (len > 0)
	{
		if ((*a)->content < nb)
		{
			push_b(a, b);
			if ((*b)->content > little_nb)
			{
				rotate_b(b);
				new_len[1] ++;
			}
		}
		else
		{
			rotate_a(a);
			new_len[0] ++;
		}
		len --;
	}
}

int	sorting(t_list **a, t_list **b)
{
	int	len[8][2];

	if (check_ascending(*a) == 0 && *b == NULL)
	{
		ft_lstclear(a);
		ft_lstclear(b);
		exit(EXIT_SUCCESS);
	}
	first_part(a, b, len[0]);
	second_part(a, b, len[0][1], len[1]);
	second_part(a, b, len[1][1], len[2]);
	fill(a, b, len[2][0]);
	third_part(a, b, len[1][0], len[3]);
	rot_switch(b, len[3][1]);
	fourth_part(a, b, len[0][0], len[4]);
	rot_switch(b, len[4][1]);
	third_part(a, b, len[4][0], len[5]);
	rot_switch(b, len[5][1]);

	final_part(a, b);
//	if (check_ascending(*a) == 0 && *b == NULL)
//	{
		ft_lstclear(a);
		ft_lstclear(b);
		exit(EXIT_SUCCESS);
//	}
	return (-1);
}
