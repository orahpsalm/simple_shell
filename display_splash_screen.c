#include "shell.h"
#define MAX_LEN 128

/**
 * display_splash_screen - display custom ascii art when programme starts
 * @file_ptr - pointer to .txt file that contains ascii art
 */

void display_splash_screen(FILE *file_ptr)
{
	char read_string[MAX_LEN];

	while (fgets(read_string, sizeof(read_string), file_ptr) != NULL)
		printf("%s", read_string);
}
