#include "push_swap.h"

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

int	steps_reducer(t_list **steps)
{
	t_list *p;

	int removed = 0;
	(void)removed;
	p = *steps;
	while (p)
	{
		t_step *step = p->content.ptr;
		t_step *next_step = NULL;
		if (p->next)
		{
			next_step = p->next->content.ptr;
			if ((step->type & PUSH) && (next_step->type & PUSH))
			{
				if ((step->type & 3) != (next_step->type & 3))
				{
					ft_strlcpy(step->title, "  ", -1);
					ft_strlcpy(next_step->title, "  ", -1);
					t_list *tmp = p->prev;
					ft_lstdelone(p->next,  (void *)free);
					ft_lstdelone(p,  (void *)free);
					p = tmp;
					removed += 2;
					continue;
				}
			}
			if ((step->type & ROTATE) && (next_step->type & ROTATE))
			{
				if ((step->type & 3) != (next_step->type & 3))
				{
					ft_strlcpy(step->title, "rr", -1);
					ft_lstdelone(p->next,  (void *)free);
					removed++;
				}
			}
			if ((step->type & RROTATE) && (next_step->type & RROTATE))
			{
				if ((step->type & 3) != (next_step->type & 3))
				{
					ft_strlcpy(step->title, "rrr", -1);
					ft_lstdelone(p->next,  (void *)free);
					removed++;
				}
			}
		}
		p = p->next;
	}
	return (0);
}
