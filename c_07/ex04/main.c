#include <stdio.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int		main(int argc, char *argv[])
{
	printf("%s\n",ft_convert_base(argv[1], argv[2], argv[3]));
}
