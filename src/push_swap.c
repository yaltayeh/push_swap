#include "push_swap.h"

int steps_count = 0;

DEF_OP(swap)
{
	size_t	len;
	t_list	*tmp;

	if (!(*s && (*s)->next))
		return (0);
	tmp = (*s)->next;
	(*s)->next = tmp->next;
	ft_lstpush_front(s, tmp);
	return (1);
}

DEF_OP2(sa)
{
	STEP;
	swap(steps, a);
}
DEF_OP2(sb)
{
	STEP;
	swap(steps, b);
}
DEF_OP2(ss)
{
	sa(steps, a, b);
	sb(steps, a, b);
}

DEF_OP2(push)
{
	t_list	*node;

	node = ft_lstpop_front(a);
	ft_lstpush_front(b, node);
}
DEF_OP2(pa)
{
	STEP;
	push(steps, a, b);
}

DEF_OP2(pb)
{
	STEP;
	push(steps, b, a);
}


DEF_OP(rotate)
{
	t_list	*node;

	node = ft_lstpop_front(s);
	ft_lstpush_back(s, node);
}
DEF_OP2(ra)
{
	STEP;
	rotate(steps, a);
}
DEF_OP2(rb)
{
	STEP;
	rotate(steps, b);
}
DEF_OP2(rr)
{
	rotate(steps, a);
	rotate(steps, b);
}


DEF_OP(reverse_rotate)
{
	t_list	*node;

	node = ft_lstpop_back(s);
	ft_lstpush_front(s, node);
}

DEF_OP2(rra)
{
	STEP;
	reverse_rotate(steps, a);
}
DEF_OP2(rrb)
{
	STEP;
	reverse_rotate(steps, b);
}
DEF_OP2(rrr)
{
	reverse_rotate(steps, a);
	reverse_rotate(steps, b);
}