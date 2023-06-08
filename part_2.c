/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:15:13 by niromano          #+#    #+#             */
/*   Updated: 2023/06/08 17:15:17 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fourth_part(t_list **a, t_list **b, t_info *part)
{
	int	nb;

	nb = medianes(a, part->temp);
	while (part->temp > 0)
	{
		if ((*a)->content > nb)
		{
			push_b(a, b);
			rotate_b(b);
			part->len[3] ++;
		}
		else
		{
			push_b(a, b);
			part->len[2] ++;
		}
		part->temp --;
	}
}

void	fifth_part(t_list ** a, t_list **b, t_info *part)
{
	int	len;
	int	nb;
	int	under_nb;

	len = ft_lstsize(*a);
	nb = medianes(a, len);
	under_nb = under_average(a, len, nb);
	while (len-- > 0)
	{
		if ((*a)->content < nb && (*a)->content > under_nb)
		{
			push_b(a, b);
			rotate_b(b);
			part->len[5] ++;
		}
		else if ((*a)->content < nb)
		{
			push_b(a, b);
			part->len[4] ++;
		}
		else
			rotate_a(a);
	}
}

void	sixth_part(t_list **a, t_list **b, t_info *part)
{
	int	nb;
	int	len;

	len = ft_lstsize(*a);
	nb = medianes(a, len);

	while (len > 0)
	{
		if ((*a)->content < nb)
		{
			push_b(a, b);
			part->len[6] ++;
		}
		else
		{
			rotate_a(a);
			part->len[7] ++;
		}
		len --;
	}
	fill(a, b, part->len[7]);
}
