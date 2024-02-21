#include<unistd.h>

void	putchar_screen(char c)
{
	write(1, &c, 1);
}

void	print_f(int index, char char1, char char_middle, char char_final)
{
	int	index_current;

	index_current = 1;
	while (index_current <= index)
	{
		if (index_current == 1)
			putchar_screen(char1);
		else if (index_current == index)
			putchar_screen(char_final);
		else
			putchar_screen(char_middle);
		index_current++;
	}
	putchar_screen('\n');
}

void	rush(int index, int line)
{
	int	line_current;

	line_current = 1;
	if (index >= 1 && line >= 1 )
	{
		while (line_current <= line)
		{
			if (line_current == 1)
				print_f(index, '/', '*', '\\');
			else if (line_current == line)
				print_f(index, '\\', '*', '/');
			else
				print_f(index, '*', ' ', '*');
			line_current++;
		}
	}
}

int	main(void)
{
	rush(4, 4);
	return (0);
}