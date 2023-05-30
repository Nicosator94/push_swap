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

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	t_list	*temp;

	parsing_int(argc, argv);
	a = init_list(argc, argv);
	temp = a;
	b = NULL;
	while (ft_lstsize(a) != 0)
	{
		ft_printf("%d\n", a->content);
		a = a->next;
	}
	while (ft_lstsize(b) != 0)
	{
		ft_printf("%d\n", b->content);
		b = b->next;
	}
	ft_lstclear(&temp);
	return (0);
}
