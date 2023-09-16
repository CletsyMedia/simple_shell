#ifndef _SHELLUX_H_
#define _SHELLUX_H_

#include <fcntl.h>	/* File control options */
#include <errno.h>	/* Error number definitions */
#include <stdio.h>	/* Standard I/O functions */
#include <stdlib.h>	/* Standard library functions */
#include <sys/stat.h>	/* File status functions */
#include <limits.h>	/* Implementation-defined constants */
#include <sys/types.h>	/* Basic system data types */
#include <sys/wait.h>	/* Process control related functions */
#include <unistd.h>	/* POSIX operating system API */
#include <string.h>	/* String manipulation functions */
#include <signal.h>	/* Signal handling functions */






/* Custom bug handler prototypes */

/* Writes a single character to the standard error */
int _errputchar(char c);

/* Writes a string to the standard error */
void _errputs(char *str);

/* Writes a character to a file descriptor */
int _putfnd(char c, int fd);

/* Writes a string to a file descriptor */
int _putsfnd(char *str, int fd);


/* Custom bug2 handler prototypes */

/* Removes comments from a string */
void slice_comnts(char *buffs);

/* Prints digits */
int prntd(int input, int fd);

/* Check error if a string of an integer can not be changed to an integer */
int err_atoi(char *s);

/* Prints error messages with additional information */
void _prnterr(inform_t *informat, char *estr);

/* Changes a number to a string with specified base and case */
char *change_num(long int number, int base, int flags);



/* Custom Chain link(LinkedList) */

/* Deletes a node at a specified index */
int del_node_idx(listed_t **, unsigned int);

/* Frees the memory allocated for a linked list */
void _free_list(listed_t **);

/* Adds a node to the beginning of a linked list */
listed_t *addNode(listed_t **, const char *, int);

/* Adds a node to the end of a linked list */
listed_t *addNode_end(listed_t **, const char *, int);

/* Prints the contents of a linked list of strings */
size_t prntList_strn(const listed_t *);



/* Custom Chain link2(LinkedList) */

/* Prints the contents of a linked list */
size_t prnt_list(const listed_t *h);

/* Finds a node based on triggers or starts */
listed_t *node_triggers(listed_t *node, char *prefix, char c);

/* Gets the index of a node in a linked list */
ssize_t get_node_idx(listed_t *head, listed_t *node);

/* Returns the length of a linked list */
size_t list_len(const listed_t *h);

/* Converts a linked list of strings to an array of strings */
char **listTostrns(listed_t *head);



/* Spliting 2 Parsingall the command */
/* Searches for a command in specified directories and returns its path */
char *_search_path(inform_t *, char *pathstr, char *comnd);

/* Checks if a given path corresponds to an executable command */
int _this_comnd(inform_t *informat, char *path);

/* Creates a duplicate string with a specified range of characters */
char *_duplicate_chars(char *pathstr, int begin, int end);

/* Tokenizes a string into an array of strings using a specified delimiter */
char **strntok(char *, char *);

/* Tokenizes a string into an array of strings using a single delimiter char */
char **strntok1(char *, char);


/* Custom Chronicle(history check) */
/* Reads history from a file and populates the history linked list */
int read_hstry(inform_t *informat);

/* Builds the history linked list with new entries */
int build_hstry(inform_t *informat, char *buffs, int linecount);

/* Renumbers the history entries */
int renumb_hstry(inform_t *informat);

/* Fetches the history document or file */
char *fetch_hstry_doc(inform_t *informat);

/* Writes the history linked list to a file */
int wrt_hstry(inform_t *informat);


/* Memory reallocation 2 Memory mgt */

/* Frees memory allocated for a buffer */
int buffs_free(void **ptr);

/* Frees memory allocated for an array of strings */
void free_mem(char **pp);

/* Sets a specified number of bytes in memory with a given value */
char *memory_set(char *s, charb, unsigned int a);

/* Reallocates memory for a given pointer with a new size */
void *reallocate_mem(void *ptr, unsigned int old_mem, unsigned int new_mem);


/* labyrinth(Iteration) */

/* Executes the shell loop for simple_shell */
int _exec_hsh(inform_t *informat, char **av);

/* Searches for and handles built-in commands in the shell environment */
int _search_builtins(inform_t *informat);

/* Locates and executes a command using the PATH environment variable */
void locate_comnd(inform_t *informat);

/* Forks and executes a command using the execve system call */
void fork_exec_comnd(inform_t *informat);



/* string manipulations */

/* Concatenates two strings and returns the result */
char *_strn_concat(char *dest, char *src);

/* Calculates the length of a string */
int _strn_length(char *s);

/* Compares two strings and returns the difference between ASCII values */
int _strn_compare(char *str1, char *str2);

/* Checks if a string contains any character from another string */
char *triggers(const char *haystack, const char *pin);


/* Custom string manipulation1: Copy a substring */

/* Prints a string followed by a newline to standard output */
void _puts(char *str);

/* Copies a string and returns the result */
char *_strn_copy(char *dest, char *src);

/* Writes a character to standard output and returns the character written */
int _putchar(char ch);

/* Creates a duplicate of a string and returns the new string */
char *strn_duplicate(const char *str);















































































































































































































































































































































































#endif /* _SHELLUX_H_ */













