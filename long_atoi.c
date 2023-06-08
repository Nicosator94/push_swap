/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 08:36:51 by niromano          #+#    #+#             */
/*   Updated: 2023/06/08 17:15:59 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	negatif(int less, long nb)
{
	if (less == 1)
		return (-nb);
	return (nb);
}

long	long_atoi(const char *nptr)
{
	int		i;
	long	nb;
	int		less;

	i = 0;
	nb = 0;
	less = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i ++;
	if (nptr[i] == '-')
		less ++;
	if (nptr[i] == '-' || nptr[i] == '+')
		i ++;
	if (nptr[i] >= '0' && nptr[i] <= '9')
	{
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			nb = nb * 10;
			nb = nb + nptr[i] - 48;
			i ++;
		}
		return (negatif(less, nb));
	}
	return (3000000000);
}
