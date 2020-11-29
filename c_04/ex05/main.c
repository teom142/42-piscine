#include <stdio.h>

int		ft_atoi_base(char *str, char *base);

int main(int argc, char *argv[])
{
	char str[] = "-++--127812gcdhb";
	char base[] = "abcdefgh";
	printf("%d\n",ft_atoi_base(str, base));
//	ft_atoi_base(argv[1], argv[2]);
}
