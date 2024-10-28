#include "push_swap.h"

int	is_continue_last(t_list *head, int ascending)
{
	t_list	*tail;

	tail = ft_lstlast(head);

	if (tail && tail->prev)
	{

		if (ascending)
		{
			if (tail->content.i32 > tail->prev->content.i32)
				return (1);
		}
		else
		{
			if (tail->content.i32 < tail->prev->content.i32)
				return (1);
		}
	}
	return (0);
}

int	is_continue_first(t_list *head, int ascending)
{
	if (head && head->next)
	{

		if (ascending)
		{
			if (head->content.i32 < head->next->content.i32)
				return (1);
		}
		else
		{
			if (head->content.i32 > head->next->content.i32)
				return (1);
		}
	}
	return (0);
}

void up_block(t_list **steps, t_list **a, t_list **b, int stack)
{
	int is_continue;

	is_continue = 1;
	while (is_continue)
	{
		if (stack & STACK_A)
		{
			is_continue = is_continue_last(*a, 1);
			rra(steps, a, b);
		}
		else if (stack & STACK_B)
		{
			is_continue = is_continue_last(*b, 0);
			rrb(steps, a, b);
		}
	}
}

