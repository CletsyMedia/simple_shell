#include "shellux.h"


/**
 * free_mem - This frees a string of strings
 * @pp: This is the string of strings
 * The free_mem function deallocates memory for a string array, including
 * its individual strings and the array itself. It takes a char ** pointer as
 * input, iterates through the strings, and releases memory to prevent leaks.
 */