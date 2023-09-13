#include "shellux.h"


/**
 * _setenviro - Initializes a new environment variable or modifies an existing
 * one.
 * @informat: Pointer to the inform_t struct containing command information.
 * @var: The string representing the environment variable property.
 * @value: The string representing the environment variable value.
 *
 * This function either initializes a new environment variable with the
 * specified property and value or modifies an existing environment variable.
 * It updates the environment_changed flag to indicate that the environment has
 * been modified.
 *
 * Return: Always 0.
 */