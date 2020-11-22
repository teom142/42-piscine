int it_is_uppercase(char c)
{ 
	if ('A' <= c && c <= 'Z')
	{
		return (1);
	}
	return (0);
}

int ft_str_is_uppercase(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (!it_is_uppercase(str[index]))
		{
			return (0);
		}
		index++;
	}
	return (1);
}
