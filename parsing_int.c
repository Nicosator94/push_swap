/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 08:08:38 by niromano          #+#    #+#             */
/*   Updated: 2023/05/30 08:08:39 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	only_number(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (long_atoi(argv[i]) == 3000000000)
			return (1);
		i ++;
	}
	return (0);
}

static int	over_int(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (long_atoi(argv[i]) < -2147483648
			|| long_atoi(argv[i]) > 2147483647)
			return (1);
		i ++;
	}
	return (0);
}

static int	*fill_tab(int argc, char *argv[])
{
	int	*tab;
	int	i;

	i = 1;
	tab = malloc(sizeof(int) * (argc - 1));
	while (i < argc)
	{
		tab[i - 1] = long_atoi(argv[i]);
		i ++;
	}
	return (tab);
}

static int	duplicate_check(int argc, char *argv[])
{
	int	i;
	int	j;
	int	*tab;

	i = 1;
	tab = fill_tab(argc, argv);
	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j + 1 < argc)
		{
			if (tab[i] == tab[j++])
			{
				free(tab);
				return (1);
			}
		}
		i ++;
	}
	free(tab);
	return (0);
}

void	parsing_int(int argc, char *argv[], int trigger)
{
	if (argc < 2)
		exit(EXIT_FAILURE);
	if (only_number(argc, argv) == 1)
	{
		if (trigger == 1)
			clear_matrix(argv);
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	if (over_int(argc, argv) == 1)
	{
		if (trigger == 1)
			clear_matrix(argv);
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	if (duplicate_check(argc, argv) == 1)
	{
		if (trigger == 1)
			clear_matrix(argv);
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	return ;
}
