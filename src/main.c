#include <unistd.h>
#include <libft.h>
#include <push_swap.h>

int	togger_complement(int num)
{
    if (num < 0)
        num ^= INT_MAX;
    return (num + 1);
}

t_list	*init_stack(const int argc, const char **argv)
{
	t_list	*node;
	t_list	*stack;
	int		number;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		number = ft_atoi(argv[i]);
		//number = togger_complement(number);
		if (ft_lstsearch(stack, (t_content)number))
		{
			ft_lstclear(&stack, NULL);
			exit(1);
		}
		node = ft_lstnew((t_content)number);
		if (!node)
		{
			ft_lstclear(&stack, NULL);
			exit(1);
		}
		ft_lstpush_back(&stack, node);
		i++;
	}
	return (stack);
}

void print_stack(t_content value)
{
	//int i32;

	//i32 = togger_complement(value.i32);
	

	ft_fprintf(2, "%d, ", value.i32);
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

int	main(const int argc, const char **argv)
{
	t_list	*a;
	t_list	*b;
	t_list	*steps;
	int	count_before;
	int	count_after;

	if (argc == 1)
		return (0);
	a = init_stack(argc, argv);
	b = NULL;
	steps = NULL;

	steps = test_sort(&a, &b);
	//steps = radix_sort(&a, &b);

	//ft_lstiter(steps, print_step2);
	ft_fprintf(2, "\n----------------------------\n");

	count_before = ft_lstsize(steps);
	steps_reducer(&steps);
	count_after = ft_lstsize(steps);
	
	ft_lstiter(steps, print_step);

	ft_fprintf(2, "\n======== A ========\n");
	ft_lstiter(a, print_stack);
	ft_fprintf(2, "\n======== B ========\n");
	ft_lstiter(b, print_stack);
	//ft_fprintf(2, "\n----------------------------\n");
	ft_fprintf(2, "total steps: %d\nsteps reducer: %d\n", count_after, count_before - count_after);

	ft_lstclear(&a, NULL);
	ft_lstclear(&b, NULL);
	ft_lstclear(&steps, (void *)free);
	return (0); 
}