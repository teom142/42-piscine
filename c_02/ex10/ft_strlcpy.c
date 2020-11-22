unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int index;

	index = 0;
	while (src[index] && index < size-1)
	{
		dest[index] = src[index];
		index++;
	}
	index = 0;
	while (dest[index])
	{
		index++;
	}
	return (index);
}
