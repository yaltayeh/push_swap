#include "push_swap.h"
#include <sys/errno.h>

void print_stack(t_content value)
{
	ft_fprintf(0, "%11d\n", value.i32);
}

void print_step(t_content content)
{
	t_step *step = content.ptr;
	ft_printf("%s\n", step->title);
}

void print_step2(t_content content)
{
	t_step *step = content.ptr;
	ft_fprintf(2, "%s ", step->title);
}

static int	add_new_node(t_list **lst, int number)
{
	t_list	*node;

	if (ft_lstsearch(*lst, (t_content)number))
	{
		ft_lstclear(lst, NULL);
		return (EINVAL);
	}
	node = ft_lstnew((t_content)number);
	if (!node)
	{
		ft_lstclear(lst, NULL);
		return (ENOMEM);
	}
	ft_lstpush_back(lst, node);
	return (0);
}

int	parser_stack(t_list **stack, const int argc, char **argv)
{
	int			i;
	const char		*slice;
	int			ret;
	int			number;

	i = 1;
	while (i < argc)
	{
		slice = ft_strtok(argv[i], ", \n\t");
		while (slice)
		{
			number = ft_atoi_r(&slice);
			if (*slice != '\0')
				return (EINVAL);
			ret = add_new_node(stack, number);
			if (ret)
				return (ret);
			slice = ft_strtok(NULL, ", \n\t");
		}
		i++;
	}
	return (0);
}

void block_count(t_list *a, t_list *b, int *a_count, int *b_count)
{
	*a_count = 0;
	*b_count = 0;
	int prev_value;
	prev_value = INT_MAX;
	while (a)
	{
		if (a->content.i32 <= prev_value)
			(*a_count)++;
		prev_value = a->content.i32;
		a = a->next;
	}
	prev_value = INT_MIN;
	while (b)
	{
		if (b->content.i32 >= prev_value)
			(*b_count)++;
		prev_value = b->content.i32;
		b = b->next;
	}
}

// int	block_maker(t_list *a_stack, t_list *b_stack,
// 				t_list **a_blocks, t_list **b_blocks)
// {

// }