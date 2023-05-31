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
	while (check_ascending(*a) != 0)
	{
	//	first_part(a, b);
	}
	while (*b != NULL)
	{
	//	second_part(a, b);
	}
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	t_list	*temp;
	t_list	*temp2;

	parsing_int(argc, argv);
	a = init_list(argc, argv);
	b = NULL;
	tri(&a, &b);
	temp = a;
	temp2 = b;
	while (a != NULL)
	{
		ft_printf("a = %d\n", a->content);
		a = a->next;
	}
	while (b != NULL)
	{
		ft_printf("b = %d\n", b->content);
		b = b->next;
	}
	ft_lstclear(&temp);
	ft_lstclear(&temp2);
	return (0);
}
