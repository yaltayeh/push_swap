#include "libft.h"
#include <string.h>
#include <stdio.h>

int main()
{
	char str[] = "42542   5235   , ,,, 3525     \t \t,,,\t 535      ";
	char *slice;

	slice = ft_strtok(str, "\t ,");
	while (slice)
	{
		if (!ft_strcheck(slice, ft_isdigit))
			return 0;
		printf("%s is digits\n", slice);
		slice = ft_strtok(NULL, "\t ,");
	}
}