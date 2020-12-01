#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*retu;

	len = 0;
	while (src[len])
		len++;
	retu = (char*)malloc(len);
	len = 0;
	while (src[len])
	{
		retu[len] = src[len];
		len++;
	}
	retu[len] = 0;
	return (retu);
}
