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