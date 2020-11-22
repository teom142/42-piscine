int it_is_num(char c)
{
	if ('0' <= c && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_str_is_numeric(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (!it_is_num(str[index]))
		{
			return (0);
		}
		index++;
	}
	return (1);
}
