#include "push_swap.h"

static unsigned char get_stack(const char *title)
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

void	update_step(t_step *step)
{
	size_t	len;

	len = ft_strlen(step->title);
	if (len > 1)
	{
		step->title[len - 1] = step->title[len - 2];
		step->stack = STACK_BOTH;
	}
}

void	steps_reducer(t_list **steps)
{
	t_list	*p;
	t_step	*step;
	t_step	*next_step;

	p = *steps;
	while (p)
	{
		step = p->content.ptr;
		next_step = NULL;
		if (p->next)
		{
			next_step = p->next->content.ptr;
			if (step->op == next_step->op)
				if ((step->stack ^ next_step->stack) == 3)
				{
					ft_lstdelone(p->next, (void *)free);
					if (step->op == OP_PUSH)
						ft_lstdelone(p,  (void *)free);
					else
						update_step(step);
					p = *steps;
					continue;
				}
		}
		p = p->next;
	}
}
