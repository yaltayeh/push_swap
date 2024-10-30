#include "push_swap.h"

int check(t_list *steps, t_list *a, t_list *b)
{

}

int parser_steps(t_list **steps)
{
	char	*op;

	op = (void *)0x1;
	while (op)
	{
		op = get_next_line(0);
		if (!op)
			return (-1);
		
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		err;
	t_list	*steps;

	a = NULL;
	b = NULL;
	err = parser_stack(&a, argc, argv);
	err = parser_steps(&steps);
	if (check(steps, a, b) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}