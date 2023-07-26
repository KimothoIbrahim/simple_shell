#include "main.h"

/**
 * main - Entry function to the shell
 * @ac: count of arguments provided with command
 * @av: array of strings arguments privided in command line
 * @env: enviroment variables
 * Return: 0 on success, 1 on failure
 */
int main(int ac __attribute__((unused)),
		 char **av __attribute__((unused)), char **env)
{
	char *line = NULL;
	int inter_active = isatty(STDIN_FILENO);
	size_t len = 0;

	if (inter_active)
		/* only print the prompt if the shell is launched in interactive mode */
		_puts("$", 0);

	/* Loop until the user terminates with Ctrl + D */
	while (getline(&line, &len, stdin) != -1)
	{
		if (line[0] == '\0' || line[0] == '\n')
			continue;
		execute(line, env);
		_puts("$", 0);
	}
	free(line);
	return (0);
}
