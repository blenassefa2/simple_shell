#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

void read_command(char cmd[]);
void type_prompt(void);
/**
 * main - implements a simple shell
 *
 * Return: 0 always success
 */

int main(void)
{
	char cmd[100], command[100], *parameters[20];
	char *envp[] = {(char *) "PATH=/bin", 0};

	while (1)
	{
		type_prompt();
		read_command(command);
		if (fork() != 0)
			wait(NULL);
		else
		{
			int x = 0;


			parameters[0][0] = (char)command;
			x = execve(command, parameters, envp);
			if (x == -1)
				printf("./shell: No such file or directory\n");
		}
		strcpy(cmd, "");
	}
}
/**
 * type_prompt - display the prompt of the shell
 *
 */
void type_prompt(void)
{
	printf("#cisfun$ ");
}
/**
 * read_command - reads the commands passed to the shell
 * @cmd: character array to hold the commands read
 */
void read_command(char cmd[])
{
	char line[1024];
	int count = 0;

	for (; ;)
	{
		int c = fgetc(stdin);

		line[count++] = (char) c;
		if (c == '\n')
			break;
	}
	strcpy(cmd, line);
}
