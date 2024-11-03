#include <unistd.h>
#include <libft.h>
#include <push_swap.h>
#include <sys/errno.h>
#include <stdio.h>

#define PRINT_STACKS 1

int	int_cmp(int a, int b)
{
	return (a - b);
}

int	main(const int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*steps;
	int		err;
	// int	count_before;
	// int	count_after;

	if (argc == 1)
		return (0);
	a = ft_init_stack(FT_INT, int_cmp, NULL, NULL);
	err = parser_stack(&a, argc, argv);
	if (err)
	{
		errno = err;
		perror("");
		exit(1);
	}
	b = ft_init_stack(FT_INT, int_cmp, NULL, NULL);
	steps = ft_init_stack(FT_POINTER, NULL, NULL, free);

	pb(steps, a, b);
	pb(steps, a, b);
	pb(steps, a, b);
	pb(steps, a, b);

	if ((err = merge_sort(steps, a, b)))
	{
		ft_fprintf(2, "Error in sorting '%d'\n", err);
		return (1);
	}
	// count_before = ft_stack_size(steps);
	// steps_reducer(steps);
	// count_after = ft_stack_size(steps);
	
	ft_fprintf(2, "\n======== STEPS ========\n");
	ft_stack_head_iter(steps, print_step2);

	if (PRINT_STACKS)
	{
		ft_fprintf(0, "\n========== A ==========\n");
		ft_stack_head_iter(a, print_stack);
		ft_fprintf(0, "\n========== B ==========\n");
		ft_stack_head_iter(b, print_stack);
	}
	// ft_fprintf(2, "-------------------\n");
	// ft_fprintf(2, "total steps: %d\nsteps_reducer: %d\n", count_after, count_before - count_after);
	// ft_fprintf(2, "-------------------\n");

	ft_stack_clear(&a);
	ft_stack_clear(&b);
	ft_stack_clear(&steps);
	return (0); 
}