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
	sorting(&a, &b);
	return (0);
}
