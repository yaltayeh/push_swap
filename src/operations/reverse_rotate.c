#include "push_swap.h"

static int reverse_rotate(t_list **s)
{
	t_list	*node;

	if (!(*s && (*s)->next))
		return (0);
	node = ft_lstpop_back(s);
	ft_lstpush_front(s, node);
	return (1);
}

int	rra(t_list **steps, t_list **a, t_list **b)
{
	(void)b;
	if (reverse_rotate(a))
	{
		if (!new_step(steps, __func__))
			return (-1);
		return (1);
	}
	return (0);
}

int	rrb(t_list **steps, t_list **a, t_list **b)
{
	(void)a;
	if (reverse_rotate(b))
	{
		if (!new_step(steps, __func__))
			return (-1);
		return (1);
	}
	return (0);
}

int	rrr(t_list **steps, t_list **a, t_list **b)
{
	t_step	*step;
	int		stat;

	stat = reverse_rotate(a) | reverse_rotate(b) << 1;
	if (stat == 1)
		step = new_step(steps, "rra");
	else if (stat == 2)
		step = new_step(steps, "rrb");
	else if (stat == 3)
		step = new_step(steps, __func__);
	else
		return (0);
	if (!step)
		return (-1);
	return (1);
}
