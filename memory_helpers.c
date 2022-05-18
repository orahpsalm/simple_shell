#include "shell.h"

/**
 * free_array - frees an array of stings
 * @array: array to free
 */

void free_array(char **array)
{
	size_t i;

	for (i = 0; array[i] != '\0'; i++)
	{
		free(array[i]);
	}
	free(array);
}
