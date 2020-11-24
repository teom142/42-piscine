#include <unistd.h>
#include <stdio.h>

char *g_hex = "0123456789abcdef";

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		test_add(long long addr, int cnt)
{
	if (!addr)
	{
		//while (cnt++ < 16)
		//{
			ft_putchar('0');
		//}
		return ;
	}
	test_add(addr >> 4, cnt + 1);
	ft_putchar(g_hex[addr % 16]);
}

void		input_add(void *add, unsigned int size)
{
	int i;
	int len;

	i = 0;
	while (size)
	{
		if (size / 16)
		{
			len = 16;
		}
		else
		{
			len = size;
		}
		test_add((long long)add, 0);
		ft_putchar('\n');
		size -= len;
	}
}

int main()
{
	char srt[] = "abcdefghizklmnopqrstuvwxyz";

	input_add(srt, 26);
}
