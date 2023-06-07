
#include "push_swap.h"

int	sorting(t_list **a, t_list **b)
{
	t_info	part;

	if (check_ascending(*a) == 0 && *b == NULL)
	{
		ft_lstclear(a);
		exit(EXIT_SUCCESS);
	}
	first_part(a, b);
	second_part(a, b, &part);
	third_part(a, b, &part);
	fourth_part(a, b, &part);
	fifth_part(a, b, &part);
	sixth_part(a, b, &part);
	wheel(a, b);
	if (check_ascending(*a) == 0 && *b == NULL)
	{
		ft_lstclear(a);
		exit(EXIT_SUCCESS);
	}
    return (-1);
}
