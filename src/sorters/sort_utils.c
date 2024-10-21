#include "push_swap.h"

t_list	*get_small(t_list *s)
{
	t_list	*small;

	small = s;
	while (s)
	{
		if (s->content.i32 < small->content.i32)
			small = s;
		s = s->next;
	}
	return (small);
}

int	check_mask(t_list *s, int mask)
{
	while (s)
	{
		if (s->content.i32 & mask)
			return (1);
		s = s->next;
	}
	return (0);
}