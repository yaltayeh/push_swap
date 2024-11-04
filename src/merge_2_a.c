#include "push_swap.h"

static void	possible_1(t_stack *steps, t_stack *a, t_stack *b, int blocks[4])
{
	int	test;

	while (blocks[2] && blocks[3])
	{
		test = 0;
		if (ft_cmp_node(b->head, a->tail, &test))
			return (-1);
		if (test > 0)
		{
			if (pa(steps, a, b) == -1)
				return (-1);
			blocks[2]--;
		}
		else
		{
			if (rra(steps, a, b) == -1)
				return (-1);
			blocks[3]--;
		}
	}
}

int merge_2_a(t_stack *steps, t_stack *a, t_stack *b)
{
	int		test;
	int		blocks[4];

	if (a_head_block(a, &blocks[0]))
		return (-1);
	if (b_tail_block(b, &blocks[1]))
		return (-1);
	if (b_head_block(b, &blocks[2]))
		return (-1);
	if (a_tail_block(a, &blocks[3]))
		return (-1);
	if (blocks[2] == 1)
	{
		if (steps->tail && ft_strcmp(steps->tail->data.ptr, "rra") == 0)
			test = sb(steps, a, b);
		else
			test = rrb(steps, a, b);
		if (test == 1)
			return (0);
		if (test == -1)
			return (-1);
	}
	while (blocks[2] && blocks[3])
	{
		if (ft_cmp_node(b->head, a->tail, &test))
			return (-1);
		if (test > 0)
		{
			if (pa(steps, a, b) == -1)
				return (-1);
			blocks[2]--;
		}
		else
		{
			if (rra(steps, a, b) == -1)
				return (-1);
			blocks[3]--;
		}
	}
	while (blocks[2]--)
		if (pa(steps, a, b) == -1)
			return (-1);
	while (blocks[3]--)
		if (rra(steps, a, b) == -1)
			return (-1);
	return (0);
}
