#include <stdio.h>

int before() __attribute__((constructor));
int after() __attribute__((destructor));

int before()
{
	printf("%s\n", __func__);
	return (0);
}

int after()
{
	printf("%s\n", __func__);
	return (0);
}

int main()
{
	printf("%s\n", __func__);
	return (0);
}