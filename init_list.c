/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:59:08 by niromano          #+#    #+#             */
/*   Updated: 2023/05/30 09:59:10 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_list(int argc, char *argv[])
{
	t_list	*list;
	t_list	*new;
	int		i;

	i = 2;
	list = ft_lstnew(ft_atoi(argv[1]));
	while (i < argc)
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(&list, new);
		i ++;
	}
	return (list);
}
