
#include "push_swap.h"

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

void	first_part(t_list **a, t_list **b)
{
	unsigned int	total;
	int				nb;

	total = ft_lstsize(*a);
	nb = average(a, total);
	while (total-- > 0)
	{
		if ((*a)->content <= nb)
			push_b(a, b);
		else
			rotate_a(a);
	}
}

void	second_part(t_list **a, t_list **b, t_info *part)
{
	int	nb;
	int	len;

	init_part(part);
	len = ft_lstsize(*b);
	nb = average(b, len);
	while (len > 0)
	{
		if ((*b)->content < nb)
			rotate_b(b);
		else
		{
			push_a(a, b);
			part->temp ++;
		}
		len --;
	}
}

void	third_part(t_list **a, t_list **b, t_info *part)
{
	int	len;
	int	nb;

	len = ft_lstsize(*b);
	nb = average(b, len);
	while (len > 0)
	{
		if ((*b)->content < nb)
		{
			rotate_b(b);
			part->len[0] ++;
		}
		else
		{
			push_a(a, b);
			part->len[1] ++;
		}
		len --;
	}
}

void	fill(t_list **a, t_list **b, int len)
{
	while (len > 0)
	{
		push_b(a, b);
		len --;
	}
}

void	fourth_part(t_list **a, t_list **b, t_info *part)
{
	int	nb;

	nb = average(a, part->temp);
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

int	under_average(t_list **a, int len, int nb)
{
	t_list	*temp;
	int		min;
	int		max;
	int		under_nb;
	int		trigger;

	trigger = 0;
	temp = *a;
	while (trigger != 1)
	{
		if (temp->content < nb)
		{
			min = temp->content;
			max = temp->content;
			trigger = 1;
		}
		else
		{
			temp = temp->next;
			len --;
		}
	}
	while (len > 0)
	{
		if (temp->content < nb)
		{
			if (min > temp->content)
				min = temp->content;
			if (max < temp->content)
				max = temp->content;
		}
		temp = temp->next;
		len --;
	}
	under_nb = (min + max) / 2;
	return (under_nb);
}

void	fifth_part(t_list ** a, t_list **b, t_info *part)
{
	int	len;
	int	nb;
	int	under_nb;

	len = ft_lstsize(*a);
	nb = average(a, len);
	under_nb = under_average(a, len, nb);
	while (len > 0)
	{
		if ((*a)->content < nb)
		{
			if ((*a)->content > under_nb)
			{
				push_b(a, b);
				rotate_b(b);
				part->len[5] ++;
			}
			else
			{
				push_b(a, b);
				part->len[4] ++;
			}
		}
		else
			rotate_a(a);
		len --;
	}
}

void	sixth_part(t_list **a, t_list **b, t_info *part)
{
	int	nb;
	int	len;

	len = ft_lstsize(*a);
	nb = average(a, len);

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
}

void	search_value(t_list **b, int *next_value)
{
	t_list	*temp;
	int		len;

	temp = *b;
	len = 0;
	next_value[0] = temp->content;
	next_value[1] = 0;
	while (temp != NULL)
	{
		if (next_value[0] < temp->content)
		{
			next_value[0] = temp->content;
			next_value[1] = len;
		}
		len ++;
		temp = temp->next;
	}
	if (next_value[1] > (ft_lstsize(*b) / 2))
		next_value[1] = -1;
}

void	wheel(t_list **a, t_list **b)
{
	int	value[2];

	while (*b != NULL)
	{
		search_value(b, value);
		while (value[1] >= 0 && (*b)->content != value[0])
			rotate_b(b);
		while (value[1] < 0 && (*b)->content != value[0])
			rev_rotate_b(b);
		push_a(a, b);
	}
}

int	sorting(t_list **a, t_list **b)
{
	t_info	part;

	first_part(a, b);
	second_part(a, b, &part);
	third_part(a, b, &part);
	fill(a, b, part.len[1]);
	fourth_part(a, b, &part);
	fifth_part(a, b, &part);
	sixth_part(a, b, &part);
	fill(a, b, part.len[7]);
	wheel(a, b);
//	if (check_ascending(*a) == 0 && *b == NULL)
//	{
		ft_lstclear(a);
		ft_lstclear(b);
		exit(EXIT_SUCCESS);
//	}
    return (-1);
}
