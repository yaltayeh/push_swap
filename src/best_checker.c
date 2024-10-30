#include "push_swap.h"

int check(t_list *steps, t_list *a, t_list *b)
{

}

int main(int argc, char **argv)
{
    t_list  *a;
    t_list  *b;
    int     err;
    t_list  *steps;

    a = NULL;
    b = NULL;
    err = parser_stack(&a, argc, argv);
    if (check(steps, a, b) == 1)
        ft_printf("OK\n");
    else 
}