#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	check_box_n(int *line)
{
	int i;
	int pivot;
	int cnt;

	i = 0;
	cnt = 1;
	pivot = line[i];
	while (i < 4)
	{
		if (line[i] > pivot)
		{
			pivot = line[i];
			cnt++;
		}
		i++;
	}
	return (cnt);
}

int main(int argc, char *argv[])
{
	int line[4][4];
	int cnt = 0;
	for (int i=0; i<4; i++)
	{
		for (int j=0; j<4; j++)
		{	
			line[i][j] = (int)argv[1][cnt] - '0';
			printf("%d ",line[i][j]);
			cnt += 2;
		}
		printf("\n");
	}
}	
