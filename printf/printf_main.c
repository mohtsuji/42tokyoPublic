#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int	count1;
	int	count2;

	count1 = printf("%");
	count2 = ft_printf("%");
	count1 = printf("%s\n", "");
	count2 = ft_printf("%s\n", "");
	count1 = printf("%15d\n", -42);
	count2 = ft_printf("%15d\n", -42);
	count1 = printf("%u\n", 42);
	count2 = ft_printf("%u\n", 42);
	count1 = printf("%i\n", 42);
	count2 = ft_printf("%i\n", 42);
	count1 = printf("%%\n");
	count2 = ft_printf("%%\n");
	count1 = printf("%x\n", 42);
	count2 = ft_printf("%x\n", 42);
	count1 = printf("%X\n", 42);
	count2 = ft_printf("%X\n", 42);
	count1 = printf("%p\n", "42");
	count2 = ft_printf("%p\n", "42");

	printf("%d\n", count1);
	printf("%d\n", count2);
	return (0);
}
