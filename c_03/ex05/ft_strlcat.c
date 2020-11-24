
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	index;

	index = 0;
	while (*dest && index < size)
	{
		dest++;
		index++;
	}
	
	while (*src && index < size -1)
	{
		*dest = *src;
		dest++;
		src++;
		index++;
	}
	if (index < size){
		*dest = 0;
	}
	return (index);
}

