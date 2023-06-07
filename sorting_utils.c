
#include "push_swap.h"

int	check_ascending(t_list *a)
{
	int	len;
	len = 1;
	while (a != NULL)
	{
		if (a->next != NULL)
		{
			if (a->content > a->next->content)
				return (len);
		}
		len ++;
		a = a->next;
	}
	return (0);
}

void	init_part(t_info *part)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		part->len[i] = 0;
		i ++;
	}
	part->temp = 0;
}

void	fill(t_list **a, t_list **b, int len)
{
	while (len > 0)
	{
		push_b(a, b);
		len --;
	}
}

int	average(t_list **a, int len)
{
	t_list	*temp;
	int		min;
	int		max;
	int		nb;

	temp = *a;
	min = temp->content;
	max = temp->content;
	while (len > 0)
	{
		if (min > temp->content)
			min = temp->content;
		if (max < temp->content)
			max = temp->content;
		temp = temp->next;
		len --;
	}
	nb = (min + max) / 2;
	return (nb);
}

int	under_average(t_list **a, int len, int nb)
{
	t_list	*temp;
	t_utils	utils;

	utils.trigger = 0;
	temp = *a;
	while (utils.trigger != 1)
	{
		if (temp->content < nb)
		{
			utils.min = temp->content;
			utils.max = temp->content;
			utils.trigger = 1;
		}
		else if (len-- > 0)
			temp = temp->next;
	}
	while (len-- > 0)
	{
		if (utils.min > temp->content && temp->content < nb)
			utils.min = temp->content;
		if (utils.max < temp->content && temp->content < nb)
			utils.max = temp->content;
		temp = temp->next;
	}
	return ((utils.min + utils.max) / 2);
}
