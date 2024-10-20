#include "push_swap.h"

t_list	*get_small(t_list *s);

t_list *test1(t_list **s1, t_list **s2)
{
	t_list *small;
	t_list *_steps = NULL;
	t_list	**steps;

	steps = &_steps;
	while (*s1)
	{ 
		small = get_small(*s1);
		while (small != *s1)
		{
			if (s1 && (*s1)->next)
				if ((*s1)->content.i32 > (*s1)->next->content.i32)
					RUN_OP(sa);
			if (small == *s1)
				break;
			RUN_OP(ra);
		}
		RUN_OP(pb);
	}
	while (*s2)
		RUN_OP(pa);
	return (_steps);
}