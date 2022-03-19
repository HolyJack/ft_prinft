#include "libft.h"

int ft_nbrlen(long nbr)
{
	int len;

	len = 1;
	while (nbr /= 10)
		len++;
	return (len);
}