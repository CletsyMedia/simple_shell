#include "shellux.h"

/**
 * main - The entry point of the shell program.
 * @av: An array of strings containing the command-line arguments.
 * @ac: The number of command-line arguments.
 *
 * This function serves as the entry point for the shell program.
 * It initializes the necessary data structures and handles
 * command-line arguments. If an input file is provided as an argument,
 * it attempts to open the file for reading and associates it with the
 * shell's input. The shell environment is then populated,
 * command history is read, and the main shell loop is entered to process user
 * input and execute commands.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int ac, char **av)
{
	inform_t informat[] = { INFORM_INIT };
	int fd = 2;

	int new_fd = fd + 3;

	if (ac == 2)
	{
	new_fd = open(av[1], O_RDONLY);
	if (new_fd == -1)
	{
	if (errno == EACCES)
	exit(126);
	if (errno == ENOENT)
	{
	_errputs(av[0]);

	_errputs(": 0: Can't open this file");

	_errputs(av[1]);
	_errputchar('\n');
	_errputchar(BUFFER_FLUSH);
	exit(127);
	}
	return (EXIT_FAILURE);
	}
	informat->readfd = new_fd;
	}
	_pop_enviro_list(informat);

	read_hstry(informat);
	_exec_hsh(informat, av);

	return (EXIT_SUCCESS);
}

