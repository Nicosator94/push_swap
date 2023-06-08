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

int	counter(char **new)
{
	int	i;

	i = 0;
	while (new[i] != NULL)
		i ++;
	return (i);
}

void	clear_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i ++;
	}
	free(matrix);
}
