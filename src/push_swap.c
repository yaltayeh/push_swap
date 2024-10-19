#include "push_swap.h"



int	name_to_type(const char *title)
{
	if (!title)
		return (0);
	if (OP_CMP("sa"))
		return (SWAP | STACK_A);
	else if (OP_CMP("sb"))
		return (SWAP | STACK_B);
	else if (OP_CMP("ss"))
		return (SWAP | STACK_BOTH);
	else if (OP_CMP("pa"))
		return (PUSH | STACK_A);
	else if (OP_CMP("pb"))
		return (PUSH | STACK_B);
	else if (OP_CMP("ra"))
		return (ROTATE | STACK_A);
	else if (OP_CMP("rb"))
		return (ROTATE | STACK_B);
	else if (OP_CMP("rr"))
		return (ROTATE | STACK_BOTH);
	else if (OP_CMP("rra"))
		return (RROTATE | STACK_A);
	else if (OP_CMP("rrb"))
		return (RROTATE | STACK_B);
	else if (OP_CMP("rrr"))
		return (RROTATE | STACK_BOTH);
	return (0);
}

t_step	*new_step(t_list **steps, const char *title)
{
	static int id;
	t_step	*step;
	t_list	*node;


	step = init_step(id++, title);
	if (!step)
		return (NULL);
	node = ft_lstnew((t_content)(void *)step);
	if (!node)
		return (NULL);
	ft_lstpush_back(steps, node);
	return (step);
}

t_step *init_step(int id, const char *title)
{
	t_step	*step;

	step = ft_calloc(1, sizeof(t_step));
	step->id = id;
	ft_strlcpy(step->title, title, sizeof(step->title));
	step->type = name_to_type(title);
	return (step);
}

DEF_OP(swap)
{
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
	NEW_STEP;
	swap(steps, a);
}

DEF_OP2(sb)
{ 
	NEW_STEP;
	swap(steps, b);
}

DEF_OP2(ss)
{
	NEW_STEP;
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
	NEW_STEP;
	push(steps, a, b);
}

DEF_OP2(pb)
{
	NEW_STEP;
	push(steps, b, a);
}

DEF_OP(rotate)
{
	t_list	*node;

	if (!(*s && (*s)->next))
		return (0);
	node = ft_lstpop_front(s);
	ft_lstpush_back(s, node);
}

DEF_OP2(ra)
{
	if (rotate(steps, a));
		NEW_STEP;
}

DEF_OP2(rb)
{
	NEW_STEP;
	rotate(steps, b);
}

DEF_OP2(rr)
{
	NEW_STEP;
	rotate(steps, a);
	rotate(steps, b);
}

DEF_OP(reverse_rotate)
{
	t_list	*node;

	if (!(*s && (*s)->next))
		return (0);
	node = ft_lstpop_back(s);
	ft_lstpush_front(s, node);
}

DEF_OP2(rra)
{
	NEW_STEP;
	reverse_rotate(steps, a);
}

DEF_OP2(rrb)
{
	NEW_STEP;
	reverse_rotate(steps, b);
}

DEF_OP2(rrr)
{
	NEW_STEP;
	reverse_rotate(steps, a);
	reverse_rotate(steps, b);
}