#include <unistd.h>
#include <libft.h>
#include <push_swap.h>
#include <sys/errno.h>

int	togger_complement(int num)
{
    if (num < 0)
        num ^= INT_MAX;
    return (num + 1);
}

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

int	add_new_node(t_list **lst, int number)
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
int	init_stack(t_list **stack, const int argc, char **argv)
{
	int			i;
	char		*slice;
	int			ret;

	i = 1;
	while (i < argc)
	{
		slice = ft_strtok(argv[i], ", \n\t");
		while (slice)
		{
			if (!ft_strcheck(slice, ft_isdigit))
				return (EINVAL);
			ret = add_new_node(stack, ft_atoi(slice));
			if (ret)
				return (ret);
			slice = ft_strtok(NULL, ", \n\t");
		}
		i++;
	}
	return (0);
}

void	free_lst(void ** lst)
{
	size_t	i;

	i = 0;
	while (lst[i])
	{
		free(lst[i]);
		i++;
	}
	free(lst);	
}

int	main(const int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_list	*steps;
	int	count_before;
	int	count_after;

	if (argc == 1)
		return (0);
	a = NULL;
	int err = init_stack(&a, argc, argv);
	if (err)
	{
		errno = err;
		perror("");
		exit(1);
	}
	b = NULL;
	steps = NULL;

	// steps = test_sort(&a, &b);
	// steps = radix_sort(&a, &b);
	steps = test2_sort(&a, &b);
	//ft_lstiter(steps, print_step2);
	// ft_fprintf(2, "\n----------------------------\n");

	count_before = ft_lstsize(steps);
	steps_reducer(&steps);
	count_after = ft_lstsize(steps);
	
	ft_lstiter(steps, print_step);

	// ft_fprintf(2, "\n======== A ========\n");
	// ft_lstiter(a, print_stack);
	// ft_fprintf(2, "\n======== B ========\n");
	// ft_lstiter(b, print_stack);
	//ft_fprintf(2, "\n----------------------------\n");
	ft_fprintf(2, "total steps: %d\nsteps_reducer: %d\n", count_after, count_before - count_after);

	ft_lstclear(&a, NULL);
	ft_lstclear(&b, NULL);
	ft_lstclear(&steps, (void *)free);
	return (0); 
}