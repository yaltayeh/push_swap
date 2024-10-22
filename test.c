#include <stdio.h>
#include <limits.h>


int to_first_complement(int num)
{
    if (num < 0)
        num ^= INT_MAX;
    return (num + 1);
}

int main()
{
    printf("%u\n", to_first_complement(-10) + 1);
}