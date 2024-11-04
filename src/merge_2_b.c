#include "push_swap.h"

int merge_2_b(t_stack *steps, t_stack *a, t_stack *b)
{
	int		test;
	int		block_size[4];

	if (a_head_block(a, &block_size[0]))
		return (-1);
	if (b_tail_block(b, &block_size[1]))
		return (-1);
	if (b_head_block(b, &block_size[2]))
		return (-1);
	if (a_tail_block(a, &block_size[3]))
		return (-1);
	if (block_size[0] == 1)
	{
		if (steps->tail && ft_strcmp(steps->tail->data.ptr, "rra") == 0)
			test = sa(steps, a, b);
		else
			test = rra(steps, a, b);
		if (test == 1)
			return (0);
		if (test == -1)
			return (-1);
	}
	while (block_size[0] && block_size[1])
	{
		if (ft_cmp_node(a->head, b->tail, &test))
			return (-1);
		if (test < 0)
		{
			if (pb(steps, a, b) == -1)
				return (-1);
			block_size[0]--;
		}
		else
		{
			if (rrb(steps, a, b) == -1)
				return (-1);
			block_size[1]--;
		}
	}
	while (block_size[0]--)
		if (pb(steps, a, b) == -1)
			return (-1);
	while (block_size[1]--)
		if (rrb(steps, a, b) == -1)
			return (-1);
	return (0);
}
