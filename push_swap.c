/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:33:58 by niromano          #+#    #+#             */
/*   Updated: 2023/06/08 17:42:37 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		trigger;

	trigger = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = counter(argv);
		trigger = 1;
	}
	parsing_int(argc, argv, trigger);
	a = init_list(argc, argv);
	b = NULL;
	if (trigger == 1)
		clear_matrix(argv);
	if (ft_lstsize(a) < 2)
	{
		ft_lstclear(&a);
		exit(EXIT_SUCCESS);
	}
//	if (lstsize(a) < 8);
//		mini_sorting(&a, &b);
	sorting(&a, &b);
	return (0);
}
