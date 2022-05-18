#include "shell.h"


/**
 * _strlen - returns the length of a null-terminated string
 * @str: string
 * Return: length of string, minuse the null terminator
 */

int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}


/**
 * _strcmp - compares two strings
 * @s1: string (first)
 * @s2: string (second)
 * Reurn: the difference of s1 and s2 (s1 - s2) or 0 if they're equal
 */

int _strcmp(char *s1, char *s2)
{
	int index;

	for (index = 0; s1[index] != '\0' && s2[index] != '\0'; index++)
	{
		if (s1[index] < s2[index])
			return (s1[index] - s2[index]);
		else if (s1[index] > s2[index])
			return (s1[index] - s2[index]);
	}
	return (0);
}


/**
 * _strdup - returns a pointer to a newly allocaed space in memory
 * @str: string
 * Return: pointer to newly alocated space in memory
 */

char *_strdup(char *str)
{
	int length, i;
	char *arr;

	length = 0;
	if (str == NULL)
		return (NULL);

	length = _strlen(str);

	arr = malloc((length + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	for (i = 0; i < length; i++)
		arr[i] = str[i];
	arr[i] = '\0';

	return (arr);
}


/**
 * _putchar - prints a single character to standard output
 * @c: character to print out
 * Return: 1 if successful, -1 if not successful
 */

int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
