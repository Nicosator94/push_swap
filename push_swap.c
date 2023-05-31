/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:33:58 by niromano          #+#    #+#             */
/*   Updated: 2023/05/24 11:34:00 by niromano         ###   ########.fr       */
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

void	tri(t_list **a, t_list **b)
{
	if (check_ascending(*a) != 0)
	{
		if ((*a)->content > (*a)->next->content)
		{
			push_b(a, b);
			push_b(a, b);
		}
		if ((*b)->content > (*b)->next->content)
			swap_both(a, b);
		else
			swap_b(b);
	}
}

void	afficher(t_list **a, t_list **b)
{
	while (*a != NULL)
	{
		ft_printf("a = %d\n", (*a)->content);
		*a = (*a)->next;
	}
	while (*b != NULL)
	{
		ft_printf("b = %d\n", (*b)->content);
		*b = (*b)->next;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	t_list	*temp_a;
	t_list	*temp_b;

	parsing_int(argc, argv);
	a = init_list(argc, argv);
	b = NULL;
//	tri(&a, &b);

	rotate_b(&b);

	temp_a = a;
	temp_b = b;
	afficher(&a, &b);
	ft_lstclear(&temp_a);
	ft_lstclear(&temp_b);
	return (0);
}
