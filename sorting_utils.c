
#include "push_swap.h"

void	check_ascending(t_list *a, t_list *b)
{
	int		len;
	t_list	*temp;

	temp = a;
	len = 1;
	while (a != NULL)
	{
		if (a->next != NULL)
		{
			if (a->content > a->next->content)
				return ;
		}
		len ++;
		a = a->next;
	}
	if (b == NULL)
	{
		ft_lstclear(&temp);
		exit(EXIT_SUCCESS);
	}
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

int	medianes(t_list **a, int len)
{
	t_list	*temp;
	t_list	*nb_temp;
	t_counter	cnt;
	int		temp_len;

	nb_temp = *a;
	temp_len = len;
	while (nb_temp != NULL)
	{
		temp = *a;
		cnt = init_cnt(nb_temp->content);
		len = temp_len;
		while (temp != NULL && len-- > 0)
		{
			if (temp->content < cnt.nb)
				cnt.dn ++;
			else
				cnt.up ++;
			temp = temp->next;
		}
		if (cnt.up == cnt.dn || cnt.up == cnt.dn + 1 || cnt.up == cnt.dn - 1)
			return(cnt.nb);
		nb_temp = nb_temp->next;
	}
	return (cnt.nb);
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
