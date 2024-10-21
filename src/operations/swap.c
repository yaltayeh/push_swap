#include "push_swap.h"

static int	swap(t_list **s)
{
	t_list	*node;

	if (!(*s && (*s)->next))
		return (0);

	node = ft_lstpop_front(s);
	ft_lstinsert(s, node);
	return (1);
}

int	sa(t_list **steps, t_list **a, t_list **b)
{
	(void)b;
	if (swap(a))
	{
		if (!new_step(steps, __func__))
			return (-1);
		return (1);
	}
	return (0);
}

int	sb(t_list **steps, t_list **a, t_list **b)
{
	(void)a;
	if (swap(b))
	{
		if (!new_step(steps, __func__))
			return (-1);
		return (1);
	}
	return (0);
}

int	ss(t_list **steps, t_list **a, t_list **b)
{
	t_step	*step;
	int		stat;

	stat = swap(a) | swap(b) << 1;
	if (stat == 1)
		step = new_step(steps, "sa");
	else if (stat == 2)
		step = new_step(steps, "sb");
	else if (stat == 3)
		step = new_step(steps, __func__);
	else
		return (0);
	if (!step)
		return (-1);
	return (1);
}
