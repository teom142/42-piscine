int	it_is_alpha(char c)
{
	if ('a' <= c && c <= 'z')
	{
		return (1);
	}
	if ('A' <= c && c <= 'Z')
	{
		return (1);
	}
	return (0);
}

int	ft_str_is_alpha(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (!it_is_alpha(str[index]))
		{
			return (0);
		}
		index++;
	}
	return (1);
}
