#include "push_swap.h"


int    merge_sort(t_stack *steps, t_stack *a, t_stack *b)
{
	if (!steps || !a || !b || a->data_type != b->data_type)
		return (-1);
	while (a->head)
		if (merge_2_b(steps, a, b))
			return (-1);	
	while (b->head)
		if (pa(steps, a, b) == -1)
			return (-1);
	return (0);
}