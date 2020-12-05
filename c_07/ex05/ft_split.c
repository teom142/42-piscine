#include <stdlib.h>

int		it_is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

long long	word_num(char *str, char *charset)
{
	long long	num;

	num = 0;
	while (*str)
	{
		if (!it_is_charset(*str, charset))
		{
			num++;
			while (!it_is_charset(*str, charset) && *str)
				str++;
		}
		str++;
	}
	return (num);
}

void		ft_strcpy(char *dest, char *start, char *end)
{
	while (start < end)
	{
		*dest = *start;
		dest++;
		start++;
	}
	*dest = 0;
}

char		**ft_split(char *str, char *charset)
{
	char		**ret;
	long long	i;
	char		*start;

	ret = (char**)malloc(sizeof(char*) * word_num(str, charset) + 1);
	i = 0;
	while (*str)
	{
		if (!it_is_charset(*str, charset))
		{
			start = str;
			while (!it_is_charset(*str, charset) && *str)
				str++;
			ret[i] = (char*)malloc(str - start + 1);
			ft_strcpy(ret[i], start, str);
			i++;
		}
		str++;
	}
	ret[i] = 0;
	return (ret);
}

