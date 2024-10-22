#include "push_swap.h"

static u_int8_t get_stack(const char *title)
{
	size_t	len;

	len = ft_strlen(title);
	if (title[len - 1] == 'a')
		return (STACK_A);
	else if (title[len - 1] == 'b')
		return (STACK_B);
	else if (ft_strchr("rs", title[len - 1]))
		return (STACK_BOTH);
	return (0);
}

static void name_to_type(t_step *step)
{
	step->stack = get_stack(step->title);
	if (step->title[0] == 's')
		step->op = OP_SWAP;
	else if (step->title[0] == 'p')
		step->op = OP_PUSH;
	else if (step->title[0] == 'r')
	{
		if (ft_strlen(step->title) == 2)
			step->op = OP_ROTATE;
		else
			step->op = OP_REVERSE_ROTATE;
	}
	else
		step->op = 0;
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
	name_to_type(step);
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
