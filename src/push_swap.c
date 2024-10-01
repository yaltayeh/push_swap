#include "push_swap.h"

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

DEF_OP2(push)
{
	t_list	*node;

	node = ft_lstpop_front(s1);
	ft_lstpush_front(s2, node);
}

DEF_OP(rotate)
{
	t_list	*node;

	node = ft_lstpop_front(s);
	ft_lstpush_back(s, node);
}

DEF_OP(reverse_rotate)
{
	t_list	*node;

	node = ft_lstpop_back(s);
	ft_lstpush_front(s, node);
}