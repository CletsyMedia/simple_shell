#include "shellux.h"


/**
 * _get_inform - Initializes inform_t struct with command arguments
 * @informat: Pointer to the inform_t struct
 * @av: Argument vector (array of strings)
 *
 * This function sets up the fields of the provided info_t struct with command
 * arguments. It takes a pointer to the info_t struct 'informat' and an
 * argument vector 'ag'. The 'fname' field is assigned the value of the first
 * element of 'ag'. If 'informat->arg' is not NULL, the function tokenizes it
 * using 'strntok' with delimiters " \t" and assigns the resulting array to
 * 'informat->argv'. If 'informat->argv' is NULL, memory is allocated for a
 * two-element array and 'informat->arg' is duplicated into
 * 'informat->argv[0]'. The loop counts the elements in 'informat->argv' to set
 * 'informat->argc'. The function also calls 'replc_aliases' and 'replc_vars'
 * to replace aliases and variables in 'informat'.
 */
void _get_inform(inform_t *informat, char **av)
{
	int a = 0; /* Initialize 'a' outside of the loop */
	 /* Set the 'fname' member of 'inform_t' to av[0] */
	informat->fname = av[0];

	if (informat->arg)
	{
	 /* Tokenize 'arg' and assign to 'argv' */
	informat->argv = strntok(informat->arg, " \t");

	if (!informat->argv)
	{
	/* Allocate memory for 'argv' */
	informat->argv = malloc(sizeof(char *) * 2);

	if (informat->argv)
	{
	/* Duplicate 'arg' to 'argv[0]' */
	informat->argv[0] = strn_duplicate(informat->arg);
	/* Set the second element of 'argv' to NULL */
	informat->argv[1] = NULL;
	}
	}
	 /* Iterate through 'argv' until NULL is encountered */
	while (informat->argv[a] != NULL)
	{
	a++; /* Increment 'a' */
	}

	informat->argc = a; /* Set 'argc' to the final value of 'a' */

	 /* Call the 'change_aliases' function with 'informat' as an argument */
	change_aliases(informat);
	 /* Call the 'change_vars' function with 'informat' as an argument */
	change_vars(informat);
	}
}


/**
 * _clr_inform - Initializes an inform_t struct
 * @informat: Pointer to the inform_t struct to be initialized
 *
 * This function sets the fields of the provided inform_t struct to their
 * initial values. It initializes the 'arg', 'argv', 'path', and 'argc' fields,
 * ensuring that the struct is properly prepared for subsequent usage.
 */