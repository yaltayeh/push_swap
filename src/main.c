#include <stdio.h>
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>


#define print_bits(x)                                             \
  do {                                                            \
    typeof(x) a__ = (x);                                          \
    char *p__ = (char *)&a__ + sizeof(x) - 1;                     \
    size_t bytes__ = sizeof(x);                                   \
    while (bytes__--) {                                           \
      char bits__ = 8;                                            \
      while (bits__--) putchar(*p__ & (1 << bits__) ? '1' : '0'); \
      p__--;                                                      \
    }                                                             \
    putchar('\n');                                                \
  } while (0)


void print_stack(t_content value)
{
	//printf("%ld, ", value.i64);
	print_bits(value.i16);	
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

#define RUN_OP(op) op(&steps, s1, s2)

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

void test1(t_list **s1, t_list **s2)
{
	t_list *big;
	t_list	*steps = NULL;

	while (*s1)
	{ 
		big = get_big(*s1);
		while (big != *s1)
		{
			if (s1 && (*s1)->next)
				if ((*s1)->content.i64 < (*s1)->next->content.i64)
					RUN_OP(sa);
			if (big == *s1)
				break;
			RUN_OP(ra);
		}
		RUN_OP(pa);
	}
	while (*s2)
		RUN_OP(pb);
}

void sort_by_bit(t_list **s1, t_list **s2, int class)
{
	int		mask;
	int		mask2;
	size_t	size;
	t_list	*steps;

	mask = 1 << class;
	mask2 = 1 << (class + 1);

	size = ft_lstsize(*s1);
	steps = NULL;
	while (size--)
	{
		if ((*s1)->content.i64 & mask)
		{
			RUN_OP(pa);
			// if ((*s2)->content.i64 & mask2)
			// 	RUN_OP(rb);
		}
		else
			RUN_OP(ra);
	}
	while (*s2)// && !((*s2)->content.i64 & mask2))
	{ 
		RUN_OP(pb);

	}

	// printf("a: %d ~~~~\n", class);
	// ft_lstiter(*s1, print_stack);
	// printf("\nb: %d ~~~~\n", class);
	// ft_lstiter(*s2, print_stack);
}

void test2(t_list **s1, t_list **s2)
{
	t_list *big;

	big = get_big(*s1);
	long value = big->content.i64;
	
	int class = 0;
	while (value)
	{
		// printf("\n-----------------\n");
		sort_by_bit(s1, s2, class++);
		// ft_lstiter(*s1, print_stack);
		value >>= 1;
	}
}




int main()
{
	t_list	*s1 = NULL;
	t_list	*s2 = NULL;

	long arr[] = {0, 23, 53, 64, 10, 42, 24, 80, 54, 45, 44};

	size_t count = sizeof(arr) / sizeof(arr[0]);


	count = 500;	
	t_list *node;
	for (size_t i = 0; i < count; i++)
	{
		if (!(node = ft_lstnew((t_content)(random() % (1 << 16)))))
			exit(1);
		ft_lstpush_back(&s1, node);
	}

	// printf("\n------------START------------\n");
	// printf("s1: \n");
	// ft_lstiter(s1, print_stack);
	// printf("\ns2: \n");
	// ft_lstiter(s2, print_stack);
	// printf("\n");


	//test1(&s1, &s2);
	test2(&s1, &s2);

	// printf("\n------------END------------\ns1: \n");
	// ft_lstiter(s1, print_stack);
	// printf("\ns2: \n");
	// ft_lstiter(s2, print_stack);
	// printf("\n");

	ft_lstclear(&s1, emtpy_func);
	ft_lstclear(&s2, emtpy_func);

	// printf("steps count: %d\n", steps_count);
}