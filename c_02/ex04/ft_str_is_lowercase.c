int	it_is_lowercase(char c)
{
	if ('a' <= c && c <= 'z')
	{
		return (1);
	}
	return (0);
}

int	ft_str_is_lowercase(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (!it_is_lowercase(str[index]))
		{
			return (0);
		}
		index++;
	}
	return (1);
}
