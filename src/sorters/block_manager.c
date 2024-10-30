#include "push_swap.h"

/**
 * @param stack
 * 	`STACK_*` choose one only
*/
void up_block(t_list **steps, t_list **a, t_list **b, int stack)
{
	int is_continue;

	is_continue = 1;
	while (is_continue)
	{
		if (stack == STACK_A)
		{
			is_continue = is_continue_last(*a, 1);
			rra(steps, a, b);
		}
		else if (stack == STACK_B)
		{
			is_continue = is_continue_last(*b, 0);
			rrb(steps, a, b);
		}
		else
			is_continue = 0;
	}
}
