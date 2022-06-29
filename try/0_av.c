#include <stdio.h>
/**
 * main - reads all comand line arfuments
 *
 * Return: 0 always
 */

int main(int ac, char **av)
{
	while (*av)
	{
		printf("%s\n", *av);
		av++;
	}
	return (0);
}
