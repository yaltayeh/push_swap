#include "push_swap.h"

t_list	*get_small(t_list *s);

t_list *test_sort(t_list **a, t_list **b)
{
	t_list *small;
	t_list	*steps;

	while(*a)
	{ 
		small = get_small(*a);
		while (small != *a)
		{
			if (a && (*a)->next)
			{
				if ((*a)->content.i32 > (*a)->next->content.i32)
					sa(&steps, a, b);
			}
			if (small == *a)
				break;
			ra(&steps, a, b);
		}
		pb(&steps, a, b);
	}
	while (*b)
		pa(&steps, a, b);
	return (steps);
}