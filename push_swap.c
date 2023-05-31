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

void	afficher(t_list **a, t_list **b)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = *a;
	temp_b = *b;
	while (temp_a != NULL)
	{
		ft_printf("a = %d\n", temp_a->content);
		temp_a = temp_a->next;
	}
	ft_printf("\n");
	while (temp_b != NULL)
	{
		ft_printf("b = %d\n", temp_b->content);
		temp_b = temp_b->next;
	}
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

int	tri(t_list **a, t_list **b)
{
	if (check_ascending(*a) == 0 && *b == NULL)
		return (0);
	while (*a != NULL && ft_lstsize(*a) > 1)
	{
		if ((*a)->content < (*a)->next->content)
			push_b(a, b);
		else if ((*a)->content > (*a)->next->content)
		{
			push_b(a, b);
			push_b(a, b);
			if (ft_lstsize(*a) > 1 && (*a)->content > (*a)->next->content)
				swap_both(a, b);
			else
				swap_b(b);
		}
	}
	while (*b != NULL)
		push_a(a, b);
	if (tri(a, b) == 0)
	{
		afficher(a, b);
		ft_lstclear(a);
		ft_lstclear(b);
		exit(EXIT_SUCCESS);
	}
	return (-1);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	parsing_int(argc, argv);
	a = init_list(argc, argv);
	b = NULL;
	if (ft_lstsize(a) < 2)
	{
		ft_lstclear(&a);
		exit(EXIT_SUCCESS);
	}
	tri(&a, &b);
	return (0);
}
