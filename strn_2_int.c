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
int _atoi(char *s)
{
	int a;
	int signal = 1;
	int flags = 0;
	int output;
	unsigned int answer = 0;

	for (a = 0; s[a] != '\0' && flags != 2; a++)
	{
		switch (s[a])
		{
			case '-':
				signal *= -1;
				break;
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				flags = 1;
				answer *= 10;
				answer += (s[a] - '0');
				break;
			default:
				if (flags == 1)
					flags = 2;
				break;
		}
	}
	if (signal == -1)
		output = -answer;
	else
		output = answer;

	return (output);
}

/**
 * isDelimiter - Checks if a character is a delimiter.
 * @c: The character to check.
 * @delimeter: The string containing delimiter characters.
 * Return: 1 if the character is a delimiter, 0 if not.
 */
int isDelimiter(char c, char *delimeter)
{
	/* Initialize a while loop that iterates through the delimiter string */
	while (*delimeter)
	{
	/* Check if the current character in the delimiter string matches 'c' */
		if (*delimeter++ == c)
		{
			/* If a match is found, return 1 (indicating 'c' is a delimiter) */
			return (1);
		}
	}
	return (0);
}


/**
 * isAlphabetic - Checks whether a character is an alphabetic character.
 * @c: The character to be checked.
 *
 * This function determines whether the input character 'c'
 * is an alphabetic character, including both lowercase and uppercase
 * letters ('a' to 'z' and 'A' to 'Z'). It returns 1 if the character is
 * alphabetic and 0 otherwise.
 *
 * Return: 1 if the character is alphabetic, 0 otherwise.
 */
int isAlphabetic(int c)
{
	/* Check if it's an alphabetic character. */
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))

		return (1);

	/* Check if it's not an alphabetic character. */
	else
		return (0);
}

/**
 * active - Checks if the shell is running in interactive mode.
 *	Determines if the shell is connected to a terminal and
 *	if the input file descriptor is within a certain range.
 * @informat: Pointer to the inform_t struct containing command information.
 *
 * Return: 1 if the shell is in interactive mode, 0 otherwise.
 */
int active(inform_t *informat)
{
	/* Find out if the shell is connected(active)*/
	return (isatty(STDIN_FILENO) && informat->readfd <= 2);
}



