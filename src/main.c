#include <unistd.h>
#include <libft.h>
#include <push_swap.h>
#include <sys/errno.h>

#define PRINT_STACKS 0

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
	int err = parser_stack(&a, argc, argv);
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
	merge_sort(&steps, &a, &b);
	//ft_lstiter(steps, print_step2);
	// ft_fprintf(2, "\n----------------------------\n");

	count_before = ft_lstsize(steps);
	steps_reducer(&steps);
	count_after = ft_lstsize(steps);
	
	ft_lstiter(steps, print_step);

	if (PRINT_STACKS)
	{
		ft_fprintf(0, "\n======== A ========\n");
		ft_lstiter(a, print_stack);
		ft_fprintf(0, "\n======== B ========\n");
		ft_lstiter(b, print_stack);
	}
	ft_fprintf(2, "-------------------\n");
	ft_fprintf(2, "total steps: %d\nsteps_reducer: %d\n", count_after, count_before - count_after);
	ft_fprintf(2, "-------------------\n");

	ft_lstclear(&a, NULL);
	ft_lstclear(&b, NULL);
	//ft_lstclear(&steps, (void *)free);
	return (0); 
}