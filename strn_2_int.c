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


