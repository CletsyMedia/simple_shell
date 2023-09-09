#include "shellux.h"


/**
 * strntok - Splits a given input string into separate words
 * using specified delimiters.
 * @str: The input string to be split.
 * @d: The delimiters used to separate words.
 * This function takes an input string and a delimiter string and splits the
 * input string into separate words using the specified delimiters.
 * It returns a dynamically allocated array of strings, where each element in
 * the array represents a word. If no words are found or if memory allocation
 * fails, it returns NULL.
 *
 * Return: A pointer to an array of strings containing separated words,
 * or NULL on failure.
 */
char **strntok(char *str, char *d)
