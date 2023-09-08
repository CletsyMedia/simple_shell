#include "shellux.h"

/**
 * err_atoi - Convert a string to an integer.
 * @s: The string to be converted.
 *
 * This function converts the input string 's' to an integer.
 * It iterates through each character of the string using a loop.
 * The function accumulates the numeric value of the digits to form the
 * resulting integer. If the string contains invalid characters or the
 * resulting integer exceeds the range of int', the function
 * Return: -1. If successful, it returns the converted integer.
 */
int err_atoi(char *s)
{
	unsigned long int answer = 0;
	int a = 0;

	if (*s == '+')
	/* If the string starts with '+', skip it */
	s++;

	for (a = 0; s[a] != '\0'; a++)
	{
	switch (s[a])
	{
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	/* Multiply the current answer by 10 */
	answer *= 10;
	/* Add the digit to the answer */
	answer += (s[a] - '0');
	if (answer > INT_MAX)
	/* Non-digit character encountered, return error */
	{
	return (-1);
	}
	goto end_switch; /* Use a label and goto to exit the switch */

	default: /* If the character is not a digit */
	return (-1); /* Return -1 to indicate failure */
	goto end_switch; /* Use a label and goto to exit the switch */
	}
	}
end_switch:
	return (answer); /* Return the calculated integer value */
}


/**
 * _prnterr - Prints an error message with context information.
 * @informat: Pointer to the `inform_t` struct.
 * @estr: String containing specified error type.
 *
 * This function prints an error message to the standard error output (stderr).
 * It includes context information such as the filename, line number, and the
 * command name from the `inform_t` struct. The error type specified by 'estr'
 * is also included in the message. The purpose of this function is to provide
 * detailed error messages to the user with relevant context information.
 * Return: 0 if no numbers in string, converted number otherwise
 *	-1 on error
 */
void _prnterr(inform_t *informat, char *estr)
{
	/* Print the filename from inform_t */
	_errputs(informat->fname);

	/* Print a colon and space separator */
	_errputs(": ");

	/* Print the line count to STDERR */
	prntd(informat->line_count, STDERR_FILENO);

	/* Print a colon and space separator */
	_errputs(": ");

	/* Print the name of the executable from inform_t */
	_errputs(informat->argv[0]);

	/* Print a colon and space separator */
	_errputs(": ");

	/* Print the provided error message */
	_errputs(estr);
}

/**
 * prntd - Prints a decimal (integer) number in base 10.
 * @input: The integer number to be printed.
 * @fd: The file descriptor to write the output to.
 *
 * This function prints the given integer number using the specified
 * file descriptor. It handles negative numbers by printing the '-' sign
 * and then converting the absolute value to characters. It uses the
 * provided '_putchar' function to print characters.
 *
 * Return: The number of characters printed.
 */
int prntd(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int a, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _errputchar;

	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;

	current = _abs_;
	for (a = 1000000000; a > 1; a /= 10)
	{
		if (_abs_ / a)
		{
			__putchar('0' + current / a);
			count++;
		}
		current %= a;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * slice_comnts - Replace the first instance of '#' with '\0' in a string.
 * @buffs: Pointer to the string to be modified.
 *
 * This function scans through the given string and replaces the first
 * occurrence of '#' with '\0' if the '#' character is either at the beginning
 * of the string or preceded by a space character.
 * This effectively removes comments from the string.
 *
 * Return: Always 0.
 */
void slice_comnts(char *buffs)
{
	int a = 0;

	while (buffs[a] != '\0')
	{
	/* If the char is '#' and is either the first char or preceded by a space */
	if (buffs[a] == '#' && (!a || buffs[a - 1] == ' '))
	{
	/* Replace '#' with a null terminator to slice the comment */
	buffs[a] = '\0';
	break;
	}
	a++;
	}
}

/**
 * change_num - Converts a number to a string in the specified base.
 * @number: The number to be converted.
 * @base: The base for conversion (e.g., decimal, hexadecimal).
 * @flags: Flags specifying conversion options.
 *
 * This function converts the given number to its string representation using
 * the specified base. The 'flags' parameter can be used to control the
 * conversion, such as handling signed or unsigned numbers and choosing
 * uppercase or lowercase letters for hexadecimal bases.
 *
 * Return: A pointer to the string containing the converted number.
 */
char *change_num(long int number, int base, int flags)
{
	unsigned long n = number;
	static char *arr, buffs[50];
	char signal = 0, *pntr;

	if (!(flags & CONVERTING_UNSIGNED) && number < 0)
	{
		n = -number;
		signal = '-';
	}

	arr = flags & CONVERTING_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pntr = &buffs[49];
	*pntr = '\0';

	do	{
		*--pntr = arr[n % base];
		n /= base;
	} while (n != 0);

	if (signal)
		*--pntr = signal;
	return (pntr);
}





