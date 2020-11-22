#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	it_is_printable(char c)
{
	if (' ' <= c && c <= '~')
	{
		return (1);
	}
	return (0);
}

char	to_hex(char c)
{
	c = c + '0';
	if (c > '9')
	{
		return (c+39);
	}
	return (c);
}
void	print_hex(char c)
{
	char hex1;
	char hex2;

	write(1, "\\", 2);
	hex1 = (int)c / 16;
	hex2 = (int)c % 16;

	ft_putchar(to_hex(hex1));
	ft_putchar(to_hex(hex2));
}


void	ft_putstr_non_printable(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (!it_is_printable(str[index]))
		{
			print_hex(str[index]);
		}
		else
		{
			ft_putchar(str[index]);
		}
		index++;
	}
}

int main()
{
	char str[] = "Coucou\ntu vas bien ?";
	ft_putstr_non_printable(str);
}

