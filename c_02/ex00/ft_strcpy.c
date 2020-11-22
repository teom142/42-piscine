char	*ft_strcpy(char *dest, char *src)
{
	int index;

	index = 0;
	prt_str(src);
	prt_str("\n");
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	return (dest);
}
