#include "push_swap.h"

static int	block_a(t_stack *a, int *count)
{
	t_node	*cur;
	int		test;

	*count = 0;
	cur = a->head;
	while (cur)
	{
		test = 0;
		if (cur->next)
			if (ft_cmp_node(cur, cur->next, &test))
				return (-1);
		cur = cur->next;
		(*count)++;
		if (test >= 0)
			break ;
	}
	return (0);
}

static int	block_b(t_stack *b, int *count)
{
	t_node	*cur;
	int		test;

	cur = b->tail;
	*count = 0;
	while (cur)
	{
		test = 0;
		if (cur->prev)
			if (ft_cmp_node(cur, cur->prev, &test))
				return (-1);
		cur = cur->prev;
		(*count)++;
		if (test >= 0)
			break ;
	}
	return (0);
}

int merge_2_b(t_stack *steps, t_stack *a, t_stack *b)
{
	int	count_a;
	int	count_b;
	int		res;

	if (block_a(a, &count_a))
		return (-1);
	if (block_b(b, &count_b))
		return (-1);
	if (count_a == 1)
	{
		// if (ft_cmp_node())
		rra(steps, a, b);
		return (0);
	}
	while (count_b && count_a)
	{
		if (ft_cmp_node(a->head, b->tail, &res))
			return (-1);
		if (res < 0)
		{
			if (pb(steps, a, b) == -1)
				return (-1);
			count_a--;
		}
		else
		{
			if (rrb(steps, a, b) == -1)
				return (-1);
			count_b--;
		}
	}
	while (count_a--)
		if (pb(steps, a, b) == -1)
			return (-1);
	while (count_b--)
		if (rrb(steps, a, b) == -1)
			return (-1);
	return (0);
}
