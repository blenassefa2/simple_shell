#include "shell.h"
/**
* main - carries out the read, execute then print output loop
*
* Return: 0
*/

int main(void)
{
	char *line = NULL, *pathcommand = NULL, *path = NULL;
	size_t bufsize = 0;
	ssize_t linesize = 0;
	char **command = NULL, **paths = NULL;
	
	
	
	while (1)
	{
		free_buffers(command);
		free_buffers(paths);
		free(pathcommand);
		type_prompt();
		linesize = getline(&line, &bufsize, stdin);
		if (linesize < 0)
			break;
		
		if (line[linesize - 1] == '\n')
			line[linesize - 1] = '\0';
		*command = strtok(line," ");
		if (command == NULL || *command == NULL || **command == '\0')
			continue;
		
		
		execution("/bin/", command);
	}

	free(line);
	return (0);	
}