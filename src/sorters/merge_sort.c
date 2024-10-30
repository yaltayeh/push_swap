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

size_t  block_len(t_list *cur, int ascending, int tail)
{
    size_t  len;

    len = 0;
	if (!tail)
	{
		while (cur)
		{
			len++; 
			if (ascending)
				if (cur->content.i32 > cur->next->content.i32)
					break ;
			if (!ascending)
				if (cur->content.i32 < cur->next->content.i32)
					break ;
			cur = cur->next;
		}
	}
	else
	{
		cur = ft_lstlast(cur);
		while (cur)
		{
			len++; 
			if (ascending)
				if (cur->content.i32 < cur->prev->content.i32)
					break ;
			if (!ascending)
				if (cur->content.i32 > cur->prev->content.i32)
					break ;
			cur = cur->prev;
		}
	}
    return (len);
}


int merge_2a(t_list **steps, t_list **a, t_list **b)
{
	int		is_continue;
	int		values[2];
	int		err;

	is_continue = ((1 * !!*a) | (2 * !!*b));
	while (is_continue)
	{
		values[0] = INT_MIN;
		values[1] = INT_MIN;
		if (is_continue & 1)
		{
			is_continue &= is_continue_last(*a, 1);
			values[0] = ft_lstlast(*a)->content.i32;
		}
		if (is_continue & 2)
		{
			is_continue &= is_continue_first(*b, 0) << 1;
			values[1] = (*b)->content.i32;
		}
		if (values[0] > values[1])
			err = ra(steps, a, b);
		else if (values[0] < values[1])
			err = pa(steps, a, b);
		if (err == -1)
			return (-1);		
	}
	return (1);
}

int merge_2b(t_list **steps, t_list **a, t_list **b)
{
	int		values[2];
	int		err;
	size_t	lens[2];
	t_list	*tmp;

	lens[0] = block_len(*a, 1, 0);
	ft_fprintf(2, "%p\n", *b);
	lens[1] = block_len(*b, 0, 1);
	fprintf(stderr, "lens [%zu, %zu]\n", lens[0], lens[1]);
	while (lens[0] || lens[1])
	{
		values[0] = INT_MAX;
		values[1] = INT_MAX;
		if (lens[0])
			values[0] = (*a)->content.i32;
		if (lens[1])
		{
			tmp = ft_lstlast(*b);
			if (tmp)
				values[1] = tmp->content.i32;
		}
		if (values[0] > values[1])
		{
			err = rb(steps, a, b);
			if (err == 1)
				lens[1]--;
		}
		else if (values[0] < values[1])
		{
			err = pb(steps, a, b);
			if (err == 1)
				lens[0]--;
		}
		if (err == -1)
			return (-1);		
	}
	return (1);
}

void    merge_sort(t_list **steps, t_list **a, t_list **b)
{
	int		err;

	print_block(*);

	ft_fprintf(2, "====== A =====\n");
	ft_lstiter(*a, print_stack);
	ft_fprintf(2, "====== B =====\n");
	ft_lstiter(*b, print_stack);
	err = merge_2b(steps, a, b);
	
	ft_fprintf(2, "====== A =====\n");
	ft_lstiter(*a, print_stack);
	ft_fprintf(2, "====== B =====\n");
	ft_lstiter(*b, print_stack);
	err = merge_2b(steps, a, b);
	
	// print_block(*);
	// ft_fprintf(2, "====== A =====\n");
	// ft_lstiter(*a, print_stack);
	// ft_fprintf(2, "====== B =====\n");
	// ft_lstiter(*b, print_stack);
	// ft_fprintf(2, "err: %d\n", err);
	// err = merge_2b(steps, a, b);
	// print_block(*);
	(void)err;
}