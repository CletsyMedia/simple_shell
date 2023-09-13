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
