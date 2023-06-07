/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:34:02 by niromano          #+#    #+#             */
/*   Updated: 2023/05/24 11:34:04 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

void	parsing_int(int argc, char *argv[]);
long	long_atoi(const char *nptr);
t_list	*init_list(int argc, char *argv[]);
int	check_ascending(t_list *a);
int	sorting(t_list **a, t_list **b);

typedef struct s_info
{
	int	len[8];
	int	temp;
}	t_info;

//Rules

void	swap_a(t_list **a);
void	swap_b(t_list **b);
void	swap_both(t_list **a, t_list **b);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);
void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
void	rotate_both(t_list **a, t_list **b);
void	rev_rotate_a(t_list **a);
void	rev_rotate_b(t_list **b);
void	rev_rotate_both(t_list **a, t_list **b);

#endif
