#include <unistd.h>
#include <libft.h>

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
	fprintf(stderr, "%d, ", value.i32);
}

int	main(const int argc, const char **argv)
{
	t_list	*a;
	t_list	*b;
	t_list	*steps;

	if (argc == 1)
		return (0);
	a = init_stack(argc, argv);
	b = NULL;
	
	steps = test_sort(&a, &b);

	steps_reducer(steps);
	
	ft_lstiter(a, print_stack);
	ft_lstclear(&a, NULL);
	ft_lstclear(&b, NULL);
	return (0);
}