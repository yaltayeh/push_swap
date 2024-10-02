#include <stdio.h>
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>




void print_stack(t_content value)
{
	printf("%ld, ", value.i64);
	// int i = 32;
	// int x = value.i64;
	// printf("\n");
	// while (i--)
	// 	(printf("%d", !!(x & (1 << 32))), (x <<= 1));
		
}

void emtpy_func(t_content value){}

#define TEST_OP(op, s)					\
	{									\
		printf("------------%s------------\n", #op); \
		op(&s);							\
		printf(#s":");					\
		ft_lstiter(s, print_stack);		\
		printf("\n"); \
	}

#define TEST_OP2(op, s1, s2)		\
	{									\
		printf("------------%s------------\n", #op); \
		op(&steps, &s1, &s2);					\
		printf(""#s1": ");				\
		ft_lstiter(s1, print_stack);	\
		printf("\n"#s2": ");			\
		ft_lstiter(s2, print_stack);	\
		printf("\n"); \
	}

t_list	*get_big(t_list *s)
{
	t_list	*big;

	big = s;
	while (s)
	{
		if (s->content.i64 > big->content.i64)
			big = s;
		s = s->next;
	}
	return (big);
}


void test1(t_list *s1, t_list *s2)
{
	t_list *big;
	t_list	*steps = NULL;

	while (s1)
	{
		big = get_big(s1);
		while (big != s1)
		{
			if (s1 && s1->next)
				if (s1->content.i64 < s1->next->content.i64)
					TEST_OP2(sa, s1, s2)
			if (big == s1)
				break;
			TEST_OP2(ra, s1, s2);
		}
		TEST_OP2(pa, s1, s2);
	}
	while (s2)
	{
		TEST_OP2(pb, s2, s1);
	}
}


void sort_by_bit(t_list **s1, t_list **s2, int class)
{
	int		mask;
	size_t	size;
	t_list	*steps;

	mask = 1 << class;
	size = ft_lstsize(*s1);
	steps = NULL;
	while (size--)
	{
		if ((*s1)->content.i64 & mask)
			(pa(&steps, &s1, &s2), printf("push - "));
		else
			(ra(&steps, &s1, &s2), printf("rotate - "));
	}
	while (*s2)
		(push(&steps, &s1, &s2), printf("push - "));
}

void test2(t_list **s1, t_list **s2)
{
	t_list *big;

	big = get_big(*s1);
	long value = big->content.i64;
	
	int class = 0;
	while (value)
	{
		printf("\n-------\n");
		sort_by_bit(s1, s2, class++);
		ft_lstiter(*s1, print_stack);
		value >>= 1;
	}
}


int main()
{
	t_list	*s1 = NULL;
	t_list	*s2 = NULL;

	long arr[8] = {0, 23, 53, 64, 545, 42, 24, 4242};

	size_t count = sizeof(arr) / sizeof(arr[0]);



	t_list *node;
	for (size_t i = 0; i < count; i++)
	{
		if (!(node = ft_lstnew((t_content)arr[i])))
			exit(1);
		ft_lstpush_back(&s1, node);
	}

	printf("\n------------START------------\n");
	printf("s1: ");
	ft_lstiter(s1, print_stack);
	printf("\ns2: ");
	ft_lstiter(s2, print_stack);
	printf("\n");


	//test1(s1, s2);
	test2(&s1, &s2);

	printf("\n------------END------------\ns1: ");
	ft_lstiter(s1, print_stack);
	printf("\ns2: ");
	ft_lstiter(s2, print_stack);
	printf("\n");

	ft_lstclear(&s1, emtpy_func);
	ft_lstclear(&s2, emtpy_func);
}