#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - it propmpts and reads line
 *
 * Return: 0
 */
int main(void)
{
	char line[100], *arguments[100];
	int n = 6;
	while (n--)
	{
		printf("$ ");
		scanf("%[^\n]s", line);
		
		

		int n = 0;
		*arguments[n] = strtok(line," ");
		while (*arguments)
		{
			printf("%s\n", *arguments);
			strcpy(*(arguments[n++]),strtok(NULL," "));
			
		}
			
		getchar();
	}
	return (0);
}

