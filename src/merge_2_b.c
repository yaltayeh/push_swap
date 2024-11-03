#include "push_swap.h"

static int	_block_a(t_stack *a, t_node **cur)
{
	t_node	*_cur;
	int		res;

	*cur = NULL;
	_cur = a->head;
	while (_cur)
	{
		if (_cur->next)
			if (ft_cmp_node(_cur, _cur->next, &res))
				return (-1);
		_cur = _cur->next;
		if (res >= 0)
			break ;
	}
	*cur = _cur;
	return (0);
}

static int	_block_b(t_stack *b, t_node **cur)
{
	t_node	*_cur;
	int		res;

	*cur = NULL;
	_cur = b->tail;
	while (_cur)
	{
		if (_cur->prev)
			if (ft_cmp_node(_cur, _cur->prev, &res))
				return (-1);
		_cur = _cur->prev;
		if (res >= 0)
			break ;
	}
	*cur = _cur;
	return (0);
}

int _merge_2_b(t_stack *steps, t_stack *a, t_stack *b)
{
	t_node	*cur_a;
	t_node	*cur_b;
	int		res;

	if (_block_a(a, &cur_a))
		return (-1);
	if (_block_b(b, &cur_b))
		return (-1);


	ft_printf("\n");
	if (cur_a)
		ft_printf("a: %d,  ", cur_a->data.i32);
	else
		ft_printf("a: %p,  ", NULL);
	if (cur_b)
		ft_printf("b: %d", cur_b->data.i32);
	else
		ft_printf("b: %p", NULL);
	ft_printf("\n");


	while ((b->tail && b->tail != cur_b) \
			|| (a->head && a->head != cur_a))
	{
		if (!b->tail || b->tail == cur_b)
			res = -1;
		else if (!a->head || a->head == cur_a)
			res = 1;
		else if (ft_cmp_node(a->head, b->tail, &res))
			return (-1);
		if (res < 0)
		{
			if (pb(steps, a, b) == -1)
				return (-1);
		}
		else
		{
			if (rrb(steps, a, b) == -1)
				return (-1);
		}
	}
	return (0);
}



static int	block_a(t_stack *a, int *count)
{
	t_node	*cur;
	int		test;


	*count = 0;
	cur = a->head;
	while (cur)
	{
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

	ft_printf("a: %d,  b: %d\n", count_a, count_b);

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
	ft_printf("a: %d,  b: %d\n", count_a, count_b);
	while (count_a--)
	{
		if (pb(steps, a, b) == -1)
			return (-1);
	}
	
	return (0);
}
