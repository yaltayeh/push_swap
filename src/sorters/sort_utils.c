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

t_step	*new_step(t_list **steps, const char *title)
{
	t_step	*step;
	t_list	*node;

	step = init_step(title);
	if (!step)
		return (NULL);
	node = ft_lstnew((t_content)(void *)step);
	if (!node)
		return (free(step), NULL);
	ft_lstpush_back(steps, node);
	return (step);
}

t_step *init_step(const char *title)
{
	t_step	*step;

	step = ft_calloc(1, sizeof(t_step));
	ft_strlcpy(step->title, title, sizeof(step->title));
	//step->type = name_to_type(title);
	return (step);
}
