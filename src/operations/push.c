#include "push_swap.h"

static int push(t_list **s1, t_list **s2)
{
	t_list	*node;

	node = ft_lstpop_front(s1);
	if (!node)
		return (0);
	ft_lstpush_front(s2, node);
	return (1);
}

int pa(t_list **steps, t_list **a, t_list **b)
{
	if (push(b, a))
	{
		if (!new_step(steps, __func__))
			return (-1);
		return (1);
	}
	return (0);
}

int pb(t_list **steps, t_list **a, t_list **b)
{
	if (push(a, b))
	{
		if (!new_step(steps, __func__))
			return (-1);
		return (1);
	}
	return (0);
}
