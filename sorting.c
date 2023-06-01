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
	while (*a != NULL)
	{
		
	}
}

void	second_part(t_list **a, t_list **b)
{
	while (*b != NULL)
	{

	}
}

int	sorting(t_list **a, t_list **b)
{
	first_part(a, b);
	second_part(a, b);
	if (check_ascending(*a) == 0 && *b == NULL)
	{
		afficher(a, b);
		ft_lstclear(a);
		ft_lstclear(b);
		exit(EXIT_SUCCESS);
	}
	return (-1);
}
