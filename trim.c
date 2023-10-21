#include "main.h"

/**
* trim - Trim leading and trailing whitespace from a string.
* @str: The string to be trimmed.
*
* Return: A newly allocated trimmed string, or NULL on failure.
*/
char *trim(char *str)
{
	int start = 0, end = 0, len = 0, i;

	char *trimmed = NULL;

	if (str == NULL)
		return (NULL);

	/* Find the index of the first non-whitespace character*/
	while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n')
		start++;

	/* Find the index of the last non-whitespace character*/
	end = start;
	while (str[end] != '\0')
		end++;
	end--;
	while (end >= start && (str[end] == ' '
	|| str[end] == '\t' || str[end] == '\n'))
		end--;

	/* Calculate the length of the trimmed string*/
	len = end - start + 1;

	/* Allocate memory for the trimmed string*/
	trimmed = malloc((len + 1) * sizeof(char));
	if (trimmed == NULL)
		return (NULL);

	/* Copy the trimmed string into the newly allocated memory*/
	for (i = 0; i < len; i++)
		trimmed[i] = str[start + i];
	trimmed[len] = '\0';

	return (trimmed);
}
