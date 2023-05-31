/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:06:27 by niromano          #+#    #+#             */
/*   Updated: 2023/05/31 09:08:07 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_list **a)
{
	t_list	*temp;
	t_list	*new;

	if (ft_lstsize(*a) < 2)
		return ;
	temp = ft_lstlast(*a);
	new = ft_lstnew(temp->content);
	new->next = *a;
	*a = new;
	temp = *a;
	while (temp->next->next != NULL)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
	ft_putstr_fd("rra\n", 1);
}

void	rev_rotate_b(t_list **b)
{
	t_list	*temp;
	t_list	*new;

	if (ft_lstsize(*b) < 2)
		return ;
	temp = ft_lstlast(*b);
	new = ft_lstnew(temp->content);
	new->next = *b;
	*b = new;
	temp = *b;
	while (temp->next->next != NULL)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
	ft_putstr_fd("rrb\n", 1);
}

void	rev_rotate_both(t_list **a, t_list **b)
{
	t_list	*temp;
	t_list	*new;

	if (ft_lstsize(*a) < 2 || ft_lstsize(*b) < 2)
		return ;
	temp = ft_lstlast(*a);
	new = ft_lstnew(temp->content);
	new->next = *a;
	*a = new;
	temp = *a;
	while (temp->next->next != NULL)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
	temp = ft_lstlast(*b);
	new = ft_lstnew(temp->content);
	new->next = *b;
	*b = new;
	temp = *b;
	while (temp->next->next != NULL)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
	ft_putstr_fd("rrr\n", 1);
}
