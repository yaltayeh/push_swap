#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void __attribute__((constructor)) before(); 
void __attribute__((destructor)) after();

int main(void)
{
	printf("%s\n", __func__);
	exit(0);
}

void before(void)
{
	printf("%s\n", __func__);
}

void after(void)
{
	printf("%s\n", __func__);
}