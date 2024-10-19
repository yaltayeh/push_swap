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
	static int counter = 0;
	//print_bits(value.i32);
	printf("%10d%s", value.i32, (++counter % 10 == 0)? "\n": " ");
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

#define RUN_OP(op) op(steps, s1, s2)

t_list	*get_big(t_list *s)
{
	t_list	*big;

	big = s;
	while (s)
	{
		if (s->content.i32 > big->content.i32)
			big = s;
		s = s->next;
	}
	return (big);
}

// void test1(t_list **s1, t_list **s2)
// {
// 	t_list *big;
// 	t_list	*steps = NULL;

// 	while (*s1)
// 	{ 
// 		big = get_big(*s1);
// 		while (big != *s1)
// 		{
// 			if (s1 && (*s1)->next)
// 				if ((*s1)->content.i32 < (*s1)->next->content.i32)
// 					RUN_OP(sa);
// 			if (big == *s1)
// 				break;
// 			RUN_OP(ra);
// 		}
// 		RUN_OP(pa);
// 	}
// 	while (*s2)
// 		RUN_OP(pb);
// }

int	check_mask(t_list *s, int mask)
{
	while (s)
	{
		if (s->content.i32 & mask)
			return (1);
		s = s->next;
	}
	return (0);
}

void	sort_by_bit(t_list **steps, t_list **s1, t_list **s2, int class)
{
	int		mask;
	int		mask2;
	size_t	size;

	mask = 1 << class;
	mask2 = 0;
	if (class <= 31)
		mask2 = 1 << (class + 1);

	while (check_mask(*s1, mask))
	{
		if (((*s1)->content.i32 & mask))
		{
			RUN_OP(pa);
			if ((*s2)->content.i32 & mask2)
				RUN_OP(rb);
		}
		else
			RUN_OP(ra);
	}
	while (*s2  && !((*s2)->content.i32 & mask2))
	{ 
		RUN_OP(pb);
	}
}

t_list *test2(t_list **s1, t_list **s2)
{
	t_list *big;
	t_list *steps;

	big = get_big(*s1);
	int value = big->content.i32;
	
	int class = 0;
	steps = NULL;
	while (value)
	{
		sort_by_bit(&steps, s1, s2, class++);
		value >>= 1;
	}
	return (steps);
}

void print_step(t_content content)
{
	static int counter = 0;
	t_step *s = content.ptr;
	printf("%s%s", s->title, (++counter % 40 == 0) ? " " : " ");
}

int main()
{
	t_list	*s1 = NULL;
	t_list	*s2 = NULL;
	t_list	*steps;
	int count = 100;

	t_list *node;
	for (size_t i = 0; i < count; i++)
	{
		if (!(node = ft_lstnew((t_content)(random() % ((1 << 31) - 1)))))
			exit(1);
		ft_lstpush_back(&s1, node);
	}

	//s1->next->next->next->next->content.i32 = 453252;

	//test1(&s1, &s2);
	steps = test2(&s1, &s2);

	t_list *p;

	int removed = 0;
	p = steps;
	while (p)
	{
		t_step *step = p->content.ptr;
		t_step *next_step = NULL;
		if (p->next)
		{
			next_step = p->next->content.ptr;
			if ((step->type & PUSH) && (next_step->type & PUSH))
			{
				if ((step->type & 3) != (next_step->type & 3))
				{
					ft_strlcpy(step->title, "  ", -1);
					ft_strlcpy(next_step->title, "  ", -1);
					t_list *tmp = p->prev;
					ft_lstdelone(p->next,  (void *)free);
					ft_lstdelone(p,  (void *)free);
					p = tmp;
					removed += 2;
					continue;
				}
			}
			if ((step->type & ROTATE) && (next_step->type & ROTATE))
			{
				if ((step->type & 3) != (next_step->type & 3))
				{
					ft_strlcpy(step->title, "rr", -1);
					ft_lstdelone(p->next,  (void *)free);
					removed++;
				}
			}
			if ((step->type & RROTATE) && (next_step->type & RROTATE))
			{
				if ((step->type & 3) != (next_step->type & 3))
				{
					ft_strlcpy(step->title, "rrr", -1);
					ft_lstdelone(p->next,  (void *)free);
					removed++;
				}
			}
		}
		p = p->next;
	}
	
	ft_lstiter(steps, print_step);

	printf("\ncount steps: %zu\n", ft_lstsize(steps));
	printf("remove steps count: %d\n", removed);

	ft_lstiter(s1, print_stack);

	ft_lstclear(&s1, emtpy_func);
	ft_lstclear(&s2, emtpy_func);
	ft_lstclear(&steps, (void *)free);
	return (0);
}