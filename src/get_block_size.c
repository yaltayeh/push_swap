#include "push_swap.h"

int	a_head_block(t_stack *a, int *count)
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

int	a_tail_block(t_stack *a, int *count)
{
	t_node	*cur;
	int		test;

	*count = 0;
	cur = a->tail;
	while (cur)
	{
		test = 0;
		if (cur->prev)
			if (ft_cmp_node(cur, cur->prev, &test))
				return (-1);
		cur = cur->prev;
		(*count)++;
		if (test <= 0)
			break ;
	}
	return (0);
}

int	b_head_block(t_stack *b, int *count)
{
	t_node	*cur;
	int		test;

	cur = b->head;
	*count = 0;
	while (cur)
	{
		test = 0;
		if (cur->next)
			if (ft_cmp_node(cur, cur->next, &test))
				return (-1);
		cur = cur->next;
		(*count)++;
		if (test <= 0)
			break ;
	}
	return (0);
}

int	b_tail_block(t_stack *b, int *count)
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