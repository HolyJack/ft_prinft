#include "include/ft_printf.h"
#include <stdio.h>

int main(void)
{
	char *s = "-%4.3x-\n";

	if (printf(s, 1) == ft_printf(s, 1))
		printf("OK");
	else 
		printf("KO");
	return (0);
}
