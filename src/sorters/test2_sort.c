#include "push_swap.h"


int	is_continue(t_list *head, int ascending)
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

void merge_2_a(t_list **steps, t_list **a, t_list **b)
{
	int	a_is_continue;
	int	b_is_continue;
	int	a_value;
	int	b_value;

	a_is_continue = 1;
	b_is_continue = 1;
	while (a_is_continue || b_is_continue)
	{
		a_value = INT_MIN;
		b_value = INT_MIN;
		if (a_is_continue)
		{
			a_is_continue = is_continue(*a, 1);
			if (*a)
				a_value = ft_lstlast(*a)->content.i32;
		}
		if (b_is_continue)
		{
			b_is_continue = is_continue(*b, 0);
			if (*b)
				b_value = ft_lstlast(*b)->content.i32;
		}
		if (a_value > b_value)
			rra(steps, a, b);
		else
		{
			rrb(steps, a, b);
			pa(steps, a, b);
		}
	}
}

void	test2_sort(t_list **steps, t_list **a, t_list **b)
{
	size_t	size;
	size_t	i;

	size = ft_lstsize(*a);
	i = 0;
	while (i < size)
	{
		i += 2;
		if (i % 4 == 0)
		{
			if (*a && (*a)->next)
				if ((*a)->content.i32 > (*a)->next->content.i32)
					sa(steps, a, b);
			ra(steps, a, b);
			ra(steps, a, b);
		}
		else 
		{
			pb(steps, a, b);
			pb(steps, a, b);
			if (*b && (*b)->next)
				if ((*b)->content.i32 < (*b)->next->content.i32)
					sb(steps, a, b);
		}
	}
	ft_fprintf(2, "\n======= A ======\n");
	ft_lstiter(*a, print_stack);
	ft_fprintf(2, "\n======= B ======\n");
	ft_lstiter(*b, print_stack);
	print_block(*)
	t_list *point = ft_lstlast(*steps);
	merge_2_a(steps, a, b);
	print_block(*);
	ft_lstiter(point, print_step2);
	ft_fprintf(2, "\n");
}

/*
 	 143847876
 	 297418499
 	1061798952
A:
	-1324205367
B: 
  876532785
 -238795689

 rra rra rra rrb pa rrb pa rrb pa rrb pa
*/