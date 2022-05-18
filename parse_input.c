#include "shell.h"

/**
 * arg_counter - counts the number of arguments
 * @user_input: string of the user input
 * Return: number of arguments
 */

int arg_counter(char *user_input)
{
	int args, start, i;

  args = 1;
	start = 0;
  i = 0;
  
	while (user_input[i] != '\0' && user_input[i] != '\n')
	{
		if (user_input[i] != ' ')
			start = 1;
		if (user_input[i] == ' ' && user_input[i + 1] != ' '
		    && user_input[i + 1] != '\n' && start == 1)
			args++;
		i++;
	}
	return (args);
}


/**
 * parse_input - parses the user_input to create array of strings
 * @user_input: the string to tokenize
 * @path_array: the array of directories in PATH
 * @NAME: name of the programme
 *
 * Return: rray of arguments
 */

char **parse_input(char *user_input, char **path_array, char *NAME)
{
	char **commands, *token, *dir_path = NULL;
	int args = 1, i = 0;

	args = arg_counter(user_input);
	commands = malloc(sizeof(char *) * (args + 1));
	if (commands == NULL)
	{
		free_array(path_array);
		return (NULL);
	}
	token = strtok(user_input, "\n ");
	if (path_check(token) == -1)
	{
		dir_path = find_path(path_array, token);
		if (dir_path == NULL)
		{
			free(commands);
			free_array(path_array);
			command_error(NAME, token);
			exitcode = 127;
			return (NULL);
		}
		else if (_strcmp("no_access", dir_path) == 0)
		{
			free(commands);
			free_array(path_array);
			access_error(NAME, token);
			exitcode = 126;
			return (NULL);
		}
		commands[0] = _strdup(dir_path);
		free(dir_path);
	}
	else
		commands[0] = _strdup(token);
	for (i = 1; i < args; i++)
	{
		token = strtok(0, "\n ");
		commands[i] = _strdup(token);
	}
	commands[i] = NULL;
	return (commands);
}
