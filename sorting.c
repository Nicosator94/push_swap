/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:16:35 by niromano          #+#    #+#             */
/*   Updated: 2023/06/08 17:16:36 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorting(t_list **a, t_list **b)
{
	t_info	part;

	check_ascending(*a, *b);
	first_part(a, b);
	second_part(a, b, &part);
	third_part(a, b, &part);
	fourth_part(a, b, &part);
	fifth_part(a, b, &part);
	sixth_part(a, b, &part);
	wheel(a, b);
	check_ascending(*a, *b);
    return (-1);
}
