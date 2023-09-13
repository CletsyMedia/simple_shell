#include "shellux.h"

/**
 * _shaliases - Copies the alias that is in the builtin (man alias).
 * @informat: Pointer to the inform_t struct containing command information.
 *
 * Description:
 * This function simulates the behavior of the 'alias' built-in command in a
 * shell. When invoked without arguments, it prints the list of aliases
 * previously set, where each alias is displayed as 'alias_name'='alias_value'.
 * When provided with arguments, it either sets or prints aliases based on the
 * provided arguments. If the argument contains an equal sign ('='), it's
 * considered an alias to be set. If not, the argument is assumed to be an
 * alias name and its corresponding value is printed.
 *
 * Return:
 *	- Always 0, indicating successful execution of the function.
 */