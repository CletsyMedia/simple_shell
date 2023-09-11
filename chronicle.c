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