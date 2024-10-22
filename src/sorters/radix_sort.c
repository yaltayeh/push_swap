#include "push_swap.h"

static void	sort_by_bit(t_list **steps, t_list **a, t_list **b, int class)
{
	int		mask;
	//int		mask2;

	mask = 1 << class;
	// mask2 = 0;
	// if (class <= 31)
	// 	mask2 = 1 << (class + 1);


	while(check_mask(*a, mask))
	{
		if ((*a)->content.i32 & mask)
		{
			if (pb(steps, a, b) == 1)
				(void)0;//ft_fprintf(2, "pb ");
			// if ((*b)->content.i32 & mask2)
			// 	RUN_OP(rb);
		}
		else
		{
			if (ra(steps, a, b) == 1)
				(void)0;//ft_fprintf(2, "ra ");
		}
	}
	while (*b)//  && !((*b)->content.i32 & mask2))
	{ 
		if (pa(steps, a, b) == 1)
			(void)0;//ft_fprintf(2, "pa ");
	}
}

t_list *radix_sort(t_list **a, t_list **b)
{
	t_list *big;
	t_list *steps;

	big = get_big(*a);
	int value = big->content.i32 & INT_MAX;
	
	int class = 0;
	steps = NULL;
	sort_by_bit(&steps, a, b, 31);
	return (steps);
	while (value)
	{
		sort_by_bit(&steps, a, b, class++);
		value >>= 1;
	}
	return (steps);
}