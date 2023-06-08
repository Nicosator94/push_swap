
#include "push_swap.h"

void	first_part(t_list **a, t_list **b)
{
	unsigned int	total;
	int				nb;

	total = ft_lstsize(*a);
	nb = medianes(a, total);
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
	nb = medianes(b, len);
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
	nb = medianes(b, len);
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
	fill(a, b, part->len[1]);
}
