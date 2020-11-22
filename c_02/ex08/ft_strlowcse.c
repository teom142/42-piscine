int	it_is_uppercase(char c)
{
	if ('A' <= c && c <= 'Z')
	{
		return (1);
	}
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (it_is_uppercase(str[index]))
		{
			str[index] = str[index] + 32;
		}
		index++;
	}
	return (str);
}
