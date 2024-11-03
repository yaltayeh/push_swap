#include "push_swap.h"

static int	block_a(t_stack *a, t_node **cur)
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

static int	block_b(t_stack *b, t_node **cur)
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

int merge_2_b(t_stack *steps, t_stack *a, t_stack *b)
{
	t_node	*cur_a;
	t_node	*cur_b;
	int		res;

	if (block_a(a, &cur_a))
		return (-1);
	if (block_b(b, &cur_b))
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
