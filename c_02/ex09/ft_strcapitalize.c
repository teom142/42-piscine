#include<unistd.h>
int	it_is_alphabet_or_num(char c)
{
	if ('a' <= c && c <= 'z')
	{
		return (1);
	}
	if ('A' <= c && c <= 'Z')
	{
		return (1);
	}
	if ('0' <= c && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	it_is_lowercase(char c)
{
	if ('a' <= c && c <= 'z')
	{
		return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (index == 0 || !it_is_alphabet_or_num(str[index-1]))
		{
			if (it_is_lowercase(str[index]))
			{
				str[index] = str[index] - 32;
			}
		}
		index++;
	}
	return (str);
}

int main()
{
	char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	write(1, ft_strcapitalize(str), sizeof(str));
}

