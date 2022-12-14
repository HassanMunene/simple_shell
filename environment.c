#include "main.h"
/**
 * _getenv - gets the environ variable
 * @name: name of the env variabl to look for
 * Return: pointer to the env variable
 **/
char *_getenv(char *name)
{
	int i = 0;
	char *token, *deli = "=";
	char *dup;

	while (environ[i] != NULL)
	{
		dup = _strdup(environ[i]);
		token = _strtok(environ[i], deli);
		if (_strcmp(token, name) == 0)
		{
			token = _strtok(NULL, deli);
			environ[i] = _strcpy(environ[i], dup);
			free(dup);
			return (token);
		}
		environ[i] = _strcpy(environ[i], dup);
		free(dup);
		i++;
	}
	return (0);
}
/**
 * _printenv - prints the enviroment
 * @argv: pointer to the commands
 * Return: 1 on success
 */
int _printenv(char **argv)
{
	int i;
	(void) argv;

	for (i = 0; *environ[i] != '\0'; i++)
	{
		_puts(environ[i]);
		_puts("\n");
	}
	return (0);
}
/**
 * _setenv - sets a new enviromental variable
 * @argv: pointer to the input commands
 * Return: 1 on success
 */
int _setenv(char **argv)
{
	int status = EXIT_SUCCESS, exist = 0, i = 0;
	char *dup = 0, *tok = 0, *val = 0;

	while (environ[i])
	{
		dup = _strdup(environ[i]);
		tok = _strtok(dup, "=");
		if (!_strcmp(tok, argv[1]))
		{
			tok = _strcat(argv[1], "=");
			val = _strcat(tok, argv[2]);

			environ[i] = _strcpy(environ[i], val);
			free(tok);
			free(val);
			exist = 1;
		}
		free(dup);
		i++;
	}

	/* if the variable does not exist then create it */

	if (!exist)
	{
		/* not implemented */
	}

	return (status);
}
/**
 * _unsetenv - unsets an enviromental var
 * @argv: pointer to the buffer with the command line
 * Return: 1 on success
 */
int _unsetenv(char **argv)
{
	int i = 0, exist = 0, len = 0, j = 0;
	char *tok, *copy;
	char **new_env;

	while (environ[i])
	{
		copy = _strdup(environ[i]);
		tok = _strtok(copy, "=");
		if (!_strcmp(tok, argv[1]))
		{
			exist = 1;
		}
		len++;
		i++;
		free(copy);
	}

	if (exist)
	{
		new_env = malloc(sizeof(char *) * (len - 1));
		for (i = 0; i < len; i++)
		{
			copy = _strdup(environ[i]);
			tok = _strtok(copy, "=");
			if (!_strcmp(tok, argv[1]))
			{
				printf("-------------> Removing: %s\n", environ[i]);
				continue;
			}
			new_env[j] = environ[i];
			j++;
		}
		new_env[len - 1] = NULL;
		environ = new_env;
	}
	return (1);
}
/**
 * _non_int - executes the shell in non-interactive mode
 * @arr: array of structures to handle built in commands
 */
void _non_int(built_in_t arr[])
{
	char **argv;
	char *buff = 0;
	int status = EXIT_SUCCESS;
	size_t buffsize = 1024;
	int err_count = 0;

	while (getline(&buff, &buffsize, stdin) != EOF)
	{
		err_count++;
		argv = token_buff(buff, " \t\r\n\a");
		status = shell_execute(argv, arr);
		free(argv);
	}
	free(buff);
	exit(status);
}
