#include "push_swap.h"

t_list	*get_small(t_list *s);

int	check_mask(t_list *s, int mask);

void	sort_by_bit(t_list **steps, t_list **s1, t_list **s2, int class)
{
	int		mask;
	int		mask2;
	size_t	size;

	mask = 1 << class;
	mask2 = 0;
	if (class <= 31)
		mask2 = 1 << (class + 1);

	while (check_mask(*s1, mask))
	{
		if (((*s1)->content.i32 & mask))
		{
			RUN_OP(pa);
			if ((*s2)->content.i32 & mask2)
				RUN_OP(rb);
		}
		else
			RUN_OP(ra);
	}
	while (*s2  && !((*s2)->content.i32 & mask2))
	{ 
		RUN_OP(pb);
	}
}

t_list *test2(t_list **s1, t_list **s2)
{
	t_list *small;
	t_list *steps;

	small = get_small(*s1);
	int value = small->content.i32;
	
	int class = 0;
	steps = NULL;
	while (value)
	{
		sort_by_bit(&steps, s1, s2, class++);
		value >>= 1;
	}
	return (steps);
}