#include "rush02.h"

int	chk_number(char *num, char *line)
{
	while ((*line != ':' && *line != ' ') || *num)
		if (*num++ != *line++)
			return (0);
	return (1);
}

void	ft_charcat(char *dest, char c)
{
	while (*dest)
		dest++;
	*(dest++) = c;
	*dest = 0;
}

int	it_is_printable(char c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}

void	ft_putline(char *line)
{
	while (*line != ':')
		line++;
	while (*line == ' ' || *line == ':')
		line++;
	while (*line)
	{
		if (it_is_printable(*line))
			write(1, line, 1);
		line++;
	}
}
