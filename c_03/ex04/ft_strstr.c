char		*ft_strstr(char *str, char *to_find)
{
	char *ptr;

	ptr = 0;
	while (*str)
	{
		if(*str == *to_find)
		{
			ptr = str;
			while (*to_find)
			{
				if (*str != *to_find)
				{
					return 0;
				}
				++to_find;
				++str;
			}
		}
		++str;
	}
	return (ptr);
}
