#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*range_num;
	int		index;

	if (min >= max)
		return (0);
	range_num = (int*)malloc(max - min);
	index = 0;
	while (min < max)
	{
		range_num[index] = min;
		min++;
		index++;
	}
	return (range_num);
}
