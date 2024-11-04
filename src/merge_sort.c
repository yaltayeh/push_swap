#include "push_swap.h"


int	move_2b(t_stack *steps, t_stack *a, t_stack *b)
{
	int	block_count;

	block_count = 0;
	if (a_head_block(a, &block_count))
		return (-1);
	while (block_count--)
	{
		if (pb(steps, a, b) == -1)
			return (-1);
	}
	return (0);
}

int	move_2a(t_stack *steps, t_stack *a, t_stack *b)
{
	int	block_count;

	block_count = 0;
	if (b_head_block(b, &block_count))
		return (-1);
	while (block_count--)
	{
		if (pa(steps, a, b) == -1)
			return (-1);
	}
	return (0);
	
}

int    merge_sort(t_stack *steps, t_stack *a, t_stack *b)
{
	int test = 0;
	if (!steps || !a || !b || a->data_type != b->data_type)
		return (-1);
	if (ft_stack_size(a) > ft_stack_size(b))
	{
		while (ft_stack_size(a) > ft_stack_size(b))
		{
			if (move_2b(steps, a, b) == -1)
				return (-2);
		}
		test = 1;
	}
	else if (ft_stack_size(a) < ft_stack_size(b))
	{
		while (ft_stack_size(a) < ft_stack_size(b))
		{
			if (move_2a(steps, a, b) == -1)
				return (-3);
		}
		test = 2;
	}
	while (a->head)
	{
		if (merge_2_b(steps, a, b))
			return (-4);	
	}
	(void)test;
	while (b->head)
		if (pa(steps, a, b) == -1)
			return (-1);
	return (0);
}