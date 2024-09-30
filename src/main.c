#include <stdio.h>
#include "push_swap.h"
#include <stdlib.h>

void print_stack(t_content value)
{
	printf("%3lu,", value.i64);
}

void emtpy_func(t_content value){}

#define TEST_OP(op, s)				\
	op(&s);							\
	printf(#s":");					\
	ft_lstiter(s, print_stack);		\
	printf(" "#op"\n");				\

#define TEST_OP2(op, s1, s2)		\
	op(&s1, &s2);					\
	printf(""#s1": ");				\
	ft_lstiter(s1, print_stack);	\
	printf("\n"#s2": ");			\
	ft_lstiter(s2, print_stack);	\
	printf(" "#op"\n");				\

int main()
{
	t_list	*s1 = NULL;
	t_list	*s2 = NULL;
	size_t count = 10;

	t_list *node;
	for (size_t i = 0; i < count; i++)
	{
		if (!(node = ft_lstnew((t_content)(random() % 20))))
			exit(1);
		ft_lstpush_front(&s1, node);
	}

	ft_lstiter(s1, print_stack);
	printf(" init\n");

	TEST_OP(swap,			s1)
	TEST_OP(rotate,			s1)
	TEST_OP(swap,			s1)
	TEST_OP(reverse_rotate, s1)
	TEST_OP2(push, s1, s2);
	TEST_OP2(push, s1, s2);
	TEST_OP2(push, s1, s2);
	TEST_OP2(push, s1, s2);
	TEST_OP2(push, s1, s2);

	ft_lstclear(&s1, emtpy_func);
	ft_lstclear(&s2, emtpy_func);
}