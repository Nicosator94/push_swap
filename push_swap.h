/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:34:02 by niromano          #+#    #+#             */
/*   Updated: 2023/06/08 17:16:11 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

void	parsing_int(int argc, char *argv[], int trigger);
long	long_atoi(const char *nptr);
t_list	*init_list(int argc, char *argv[]);
int		sorting(t_list **a, t_list **b);
int		counter(char **new);
void	clear_matrix(char **matrix);

typedef struct s_info
{
	int	len[8];
	int	temp;
}	t_info;

typedef struct s_utils
{
	int	min;
	int	max;
	int	trigger;
}	t_utils;

typedef struct s_counter
{
	int	nb;
	int	up;
	int	dn;
}	t_counter;

t_counter	init_cnt(int nb);

//Parts

void	first_part(t_list **a, t_list **b);
void	second_part(t_list **a, t_list **b, t_info *part);
void	third_part(t_list **a, t_list **b, t_info *part);
void	fourth_part(t_list **a, t_list **b, t_info *part);
void	fifth_part(t_list ** a, t_list **b, t_info *part);
void	sixth_part(t_list **a, t_list **b, t_info *part);

//Wheel

void	search_value(t_list **b, int *next_value);
void	wheel(t_list **a, t_list **b);

// Utils

void	check_ascending(t_list *a, t_list *b);
void	init_part(t_info *part);
void	fill(t_list **a, t_list **b, int len);
int		medianes(t_list **a, int len);
int		under_average(t_list **a, int len, int nb);

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
