#include <unistd.h>
#include <libft.h>
#include <push_swap.h>

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
	ft_printf("%d, ", value.i32);
}

void print_step(t_content content)
{
	t_step *step = content.ptr;
	ft_printf("%s\n", step->title);
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
	steps = NULL;

	steps = test_sort(&a, &b);
	
	// steps_reducer(&steps);
	
	// ft_printf("\n======= A ========\n");
	// ft_lstiter(a, print_stack);
	// ft_printf("\n======= B ========\n");
	// ft_lstiter(b, print_stack);
	// ft_printf("\n====== steps =====\n");
	ft_lstiter(steps, print_step);

	ft_lstclear(&a, NULL);
	ft_lstclear(&b, NULL);
	ft_lstclear(&steps, (void *)free);
	return (0); 
}