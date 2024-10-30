#include "push_swap.h"

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
	//merge_2_a(steps, a, b);
	up_block(steps, a, b, STACK_A);
	up_block(steps, a, b, STACK_B);
	up_block(steps, a, b, STACK_A);
	up_block(steps, a, b, STACK_B);
	print_block(*);
	ft_lstiter(point->next, print_step2);
	ft_fprintf(2, "\n");
}