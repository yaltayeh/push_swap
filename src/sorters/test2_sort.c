#include "push_swap.h"



// void marge_2_a(t_list **a, t_list **b)
// {

// }

void	test2_sort(t_list **steps, t_list **a, t_list **b)
{
	size_t	size;
	size_t	i;

	size = ft_lstsize(*a);
	i = 0;
	while (i < size)
	{
		i += 2;
		if (i % 4 == 0)
		{
			if (*a && (*a)->next)
				if ((*a)->content.i32 > (*a)->next->content.i32)
					sa(steps, a, b);
			ra(steps, a, b);
			ra(steps, a, b);
		}
		else 
		{
			pb(steps, a, b);
			pb(steps, a, b);
			if (*b && (*b)->next)
				if ((*b)->content.i32 < (*b)->next->content.i32)
					sb(steps, a, b);
		}
	}
	print_block(*);

}