int	it_is_lowercase(char c)
{
	if ('a' <= c && c <= 'z')
	{
		return (1);
	}
	return (0);
}

char	*ft_strupcase(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if(it_is_lowercase(str[index]))
		{
			str[index] = str[index] - 32;
		}
		index++;
	}
	return (str);
}
