#include "shellux.h"
/**
 * _atoi - Converts a string of digits to an integer.
 * @s: Pointer to the input string.
 *
 * This function converts the string 's' into an integer. It iterates through
 * the characters of the string, identifying digits and signs to calculate the
 * corresponding integer value. The function takes into account negative signs
 * and stops conversion after processing non-digit characters following at
 * least one digit. The resulting integer is returned as the output of the
 * function.
 *
 * Return: The integer value represented by the input string.
 */