#include "ft_printf.h"

int main(void)
{
	ft_printf("TEST %d\n", -100);
	ft_printf("TEST %d\n", 100);
	ft_printf("TEST %s\n", "ABC");
	ft_printf("TEST %x\n", 100);
	ft_printf("\n");
	ft_printf("TEST %.2d\n", -100);
	ft_printf("TEST %.2d\n", 100);
	ft_printf("TEST %.2s\n", "ABC");
	ft_printf("TEST %.2x\n", 100);
	ft_printf("\n");
	ft_printf("TEST %.10d\n", -100);
	ft_printf("TEST %.10d\n", 100);
	ft_printf("TEST %.10s\n", "ABC");
	ft_printf("TEST %.10x\n", 100);
	ft_printf("\n");
	ft_printf("TEST %5.3d\n", -100);
	ft_printf("TEST %5.3d\n", 100);
	ft_printf("TEST %5.3s\n", "ABC");
	ft_printf("TEST %5.3x\n", 100);
	ft_printf("\n");
	ft_printf("TEST %5.10d\n", -100);
	ft_printf("TEST %5.10d\n", 100);
	ft_printf("TEST %5.10s\n", "ABC");
	ft_printf("TEST %5.10x\n", 100);
	ft_printf("\n");
	ft_printf("TEST %10.10d\n", -100);
	ft_printf("TEST %10.10d\n", 100);
	ft_printf("TEST %10.10s\n", "ABC");
	ft_printf("TEST %10.10x\n", 100);
	
	return (0);
}
