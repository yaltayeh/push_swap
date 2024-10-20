#include "push_swap.h"

int rotate(t_list **s)
{
	t_list	*node;

	if (!(*s && (*s)->next))
		return (0);
	node = ft_lstpop_front(s);
	ft_lstpush_back(s, node);
	return (1);
}

int	ra(t_list **steps, t_list **a, t_list **b)
{
	(void)b;
	if (rotate(a))
	{
		if (!new_step(steps, __func__))
			return (-1);
		return (1);
	}
	return (0);
}

int	rb(t_list **steps, t_list **a, t_list **b)
{
	(void)a;
	if (rotate(b))
	{
		if (!new_step(steps, __func__))
			return (-1);
		return (1);
	}
	return (0);
}

int	rr(t_list **steps, t_list **a, t_list **b)
{
	t_step	*step;
	int		stat;

	stat = rotate(a) | rotate(b) << 1;
	if (stat == 1)
		step = new_step(steps, "ra");
	else if (stat == 2)
		step = new_step(steps, "rb");
	else if (stat == 3)
		step = new_step(steps, __func__);
	else
		return (0);
	if (!step)
		return (-1);
	return (1);
}
