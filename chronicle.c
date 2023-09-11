#include "shellux.h"


/**
 * read_hstry - Reads history entries from a file
 * @informat: Pointer to the parameter inform_t struct
 *
 * This function reads history entries from a file into the parameter struct.
 * It starts by obtaining the path to the history file using the get_hstry_doc
 * function. If the path cannot be obtained, the function returns 0. It then
 * opens the history file for reading, and if the file opening fails or the
 * file size is less than 2 bytes, the function returns 0.
 *
 * The function allocates memory for a buffer and reads the file contents into
 * it. If the read operation encounters an error or returns a non-positive
 * value, the buffer is freed, the file is closed, and the function returns 0.
 *
 * The function processes the contents of the buffer, splitting it into
 * separate lines based on newline characters. Each line is used to build a
 * history entry using the build_hstry function, and the line count is
 * incremented.
 *
 * After processing all lines, the buffer is freed, and the line count is
 * stored in the parameter struct's histcount field. If the line count exceeds
 * the maximum history count (HISTORY_MAX), excess history entries are removed
 * using the del_node_idx function, and the history entries are renumbered
 * using the renumb_hstry function.
 *
 * Return: Number of history entries read and processed, or 0 on failure.
 */
int read_hstry(inform_t *informat)
{
	struct stat st;
	char *buffs = NULL;
	char *filename = fetch_hstry_doc(informat);
	int a, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;

	if (!filename)
	return (0);
	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buffs = malloc(sizeof(char) * (fsize + 1));
	if (!buffs)
		return (0);
	rdlen = read(fd, buffs, fsize);
	buffs[fsize] = 0;
	if (rdlen <= 0)
	return (free(buffs), 0);
	close(fd);
	for (a = 0; a < fsize; a++)
	if (buffs[a] == '\n')
	{
	buffs[a] = 0;
	build_hstry(informat, buffs + last, linecount++);
	last = a + 1;
	}
	if (last != a)
	build_hstry(informat, buffs + last, linecount++);
	free(buffs);
	informat->historycount = linecount;
	while (informat->historycount-- >= HISTORY_MAX)
	del_node_idx(&(informat->history), 0);
	renumb_hstry(informat);
	return (informat->historycount);
}



/**
 * renumb_hstry - Renumbers the history linked list after changes
 * @informat: Pointer to the structure containing potential arguments
 *
 * This function is responsible for renumbering the history linked list stored
 * within the provided parameter struct. It takes the 'informat' parameter,
 * which should point to the head of the linked list, and traverses through
 * the list. During traversal, each node's 'number' field is updated
 * sequentially, reflecting the new order of the history entries. After
 * renumbering, the 'histcount' field of the parameter struct is updated with
 * the new count of history entries.
 *
 * Return: The new histcount (count of history entries) after renumbering.
 */
int renumb_hstry(inform_t *informat)
{
	int a;

	listed_t *node = informat->history;

	for (a = 0; node; a++, node = node->next)
	{
	node->number = a;
	}

	return (informat->historycount = a);
}



/**
 * build_hstry - Adds an entry to the history linked list
 * @informat: Pointer to the structure containing potential arguments
 * @buffs: The buffer containing the history entry
 * @linecount: The history line count (histcount)
 *
 * This function appends a new history entry to the end of the linked list
 * contained within the 'informat' parameter. It takes the history entry
 * 'buffer' and its corresponding 'linecount' and creates a new node with this
 * information. If the history linked list already contains nodes, the new node
 * is added to the end of the list using the 'addNode_end' function. If the
 * list is empty, the new node becomes the first node in the list.
 *
 * The function updates the 'informat->history' pointer to point to the head of
 * the updated linked list, ensuring proper maintenance of the history entries.
 * The return value of the function is always 0.
 *
 * Return: Always returns 0.
 */
int build_hstry(inform_t *informat, char *buffs, int linecount)
{
	listed_t *node = NULL;

/* Check if informat->history is not NULL */
	if (informat->history)

	node = informat->history;

 /* Add a new node with the given buffer and line count to the history */
	addNode_end(&node, buffs, linecount);

/* Update informat->history if it was initially NULL */
	if (!informat->history)

	informat->history = node;

	return (0);
}



/**
 * fetch_hstry_doc - Retrieves the path to the history file
 * @informat: Pointer to the parameter inform_t struct
 *
 * This function constructs and returns the path to the history file based
 * on the user's home directory and the provided parameter struct. It first
 * retrieves the user's home directory using the environment variable "HOME".
 * If the directory cannot be obtained, the function returns NULL. Otherwise,
 * it dynamically allocates memory for the path and constructs it by
 * concatenating the home directory with the history file's name. The resulting
 * path is then returned as an allocated string.
 * It's the caller's responsibility to free the allocated memory.
 *
 * Return: A dynamically allocated string containing the history file,
 *	or NULL if memory allocation fails.
 */
char *fetch_hstry_doc(inform_t *informat)
{
	char *buffs;
	char *directory;

	/* Get user's home directory */
	directory = get_enviro(informat, "HOME=");

	if (!directory)

	return (NULL);

	/* Allocate memory for the path */
	buffs = malloc(sizeof(char) * (_strn_length(directory) +
	_strn_length(HISTORY_FILE) + 2));

	if (!buffs)
	return (NULL);

	/* Construct the path */
	buffs[0] = 0;

	_strn_copy(buffs, directory);
	_strn_concat(buffs, "/");
	_strn_concat(buffs, HISTORY_FILE);

	return (buffs);
}

/**
 * wrt_hstry - Writes history entries to a file
 * @informat: Pointer to the parameter inform_t struct
 *
 * This function writes history entries from the provided parameter struct
 * to a file. It first obtains the path to the history file using the
 * get_hstry_doc function. If the path cannot be obtained, the function
 * returns -1 to indicate an error. It then opens the history file for
 * writing, creating it if it doesn't exist or truncating it if it does.
 * The history entries are iterated over and written to the file, with each
 * entry followed by a newline character. After writing all entries, the
 * function flushes the output buffer and closes the file. If any step in
 * this process encounters an error, the function returns -1. Otherwise,
 * it returns 1 to indicate success.
 *
 * Return: 1 on successful writing of history, -1 on failure.
 */

