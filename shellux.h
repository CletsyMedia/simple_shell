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


/* Buffer sizes for reading and writing data */
#define WRITE_BUFFER_SIZE 1024
#define BUFFER_FLUSH -1
#define READ_BUFFER_SIZE 1024

/* Defines constants for command chaining modes */
#define NORM_COMND	0	/* Normal command execution */
#define OR_COMND	1	/* Execute next command if previous command fails */
#define AND_COMND	2	/* Execute next command if previous command succeeds */
#define CHAIN_COMND	3	/* Chain multiple commands with sequential execution */





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
char *memory_set(char *s, char, unsigned int a);

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



/* strnarry manipulations */

/* Concatenates two strings and returns the result */
char *_strn_concat(char *dest, char *src);

/* Calculates the length of a string */
int _strn_length(char *s);

/* Compares two strings and returns the difference between ASCII values */
int _strn_compare(char *str1, char *str2);

/* Checks if a string contains any character from another string */
char *triggers(const char *haystack, const char *pin);


/* Custom strnarry2 manipulations: Copy a substring */

/* Prints a string followed by a newline to standard output */
void _puts(char *str);

/* Copies a string and returns the result */
char *_strn_copy(char *dest, char *src);

/* Writes a character to standard output and returns the character written */
int _putchar(char ch);

/* Creates a duplicate of a string and returns the new string */
char *strn_duplicate(const char *str);


/* Custom egress(exits)	*/

/* Copies a specified number of characters from one string to another */
char *strn_copy(char *, char *, int);

/* Concatenates a specified number of characters from one string to another */
char *strn_concat(char *dest, char *str, int n);

/* Appends a single character to a string and returns the result */
char *strn_char(char *s, char c);


/* strn_2_int(atoi converts a string representation of an int) */

/* Checks if a character is a delimiter */
int isDelimiter(char, char *);

/* Checks if a character is alphabetic */
int isAlphabetic(int);

/* Converts a string representation of an integer to an integer */
int _atoi(char *);

/* Checks if the shell is interactive or inactive */
int active(inform_t *);


/* sh_comnd built-ins cd, exit, help(usage) */

/* Changes the current working directory */
int _shcdr(inform_t *informat);

/* Displays the help message */
int _shhelp(inform_t *informat);

/* Exits the shell */
int _shexit(inform_t *informat);


/* sh_comnd2 built-ins history and aliases(shorthnd cmds) */

/* Displays the command history */
int _shhstry(inform_t *informat);

/* Manages command aliases */
int _shaliases(inform_t *informat);


/* vr_modifiers */

/* Changes command aliases */
int change_aliases(inform_t *informat);

/* Changes environment variables */
int change_vars(inform_t *informat);

/* Manages command chaining */
int _chain(inform_t *informat, char *buffs, size_t *p);

/* Checks command chaining */
void _checkChain(inform_t *informat, char *buffs, size_t *p,
size_t a, size_t len);

/* Changes string value */
int change_strn(char **older, char *newer);


/* Custom get_theline(read a line from a file malloc & returns len) */

/* Gets input from user */
ssize_t get_the_input(inform_t *informat);

/* Sets signal handlers */
void sign_handlers(int sign_num);

/* Gets input line */
int get_the_line(inform_t *informat, char **ptr, size_t *length);


/* Custom scoop_information */

/* Retrieves information from input */
void _get_inform(inform_t *, char **);

/* Clears information stored in the structure */
void _clr_inform(inform_t *);

/* Frees the allocated memory in the structure */
void _free_inform(inform_t *, int);


/* Custom scoop_environment functions */

/* Unsets an environment variable */
int _unsetenviro(inform_t *, char *);

/* Retrieves the list of environment variables */
char **_getenviro(inform_t *);

/* Sets an environment variable */
int _setenviro(inform_t *, char *, char *);


/* Custom environment_dome functions */

/* Populates environment variables from the linked list */
int _pop_enviro_list(inform_t *informat);

/* Sets an environment variable */
int _shsetenviro(inform_t *informat);

/* Unsets an environment variable */
int _shunsetenviro(inform_t *informat);

/* Retrieves the value of an environment variable */
char *get_enviro(inform_t *informat, const char *name);

/* Custom shell command for handling environment variables */
int _shenviro(inform_t *informat);



#endif /* _SHELLUX_H_ */
