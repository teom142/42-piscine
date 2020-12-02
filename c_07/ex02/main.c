#include <stdio.h>

int		ft_ultimate_range(int **range, int min, int max);

int		main()
{
	int		*range;
	int		min = 1;
	int		max = 5;

	printf("%d\n",ft_ultimate_range(&range,min,max));
	while (min < max)
	{
		printf("%d ",*range);
		range++;
		min++;
	}
}
