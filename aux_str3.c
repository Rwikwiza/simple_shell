#include "main.h"

int token_length(char *str, char *delim);
int token_count(char *str, char *delim);
char **_strtok(char *line, char *delim);

/**
 * token_length -the function locates the delimiter index marking the end
 *             of the first token contained within a string.
 * @str: the string
 * @delim: the delimiter
 *
 * Return: it returns the delimiter index marking the end of
 *         the intitial token pointed to be str.
 */

int token_length(char *str, char *delim)
{
	int i = 0, len = 0;

	while (*(str + i) && *(str + i) != *delim)
	{
		len++;
		i++;
	}

	return (len);
}

/**
 * token_count - the function counts the number of delimited
 *                words contained within a string.
 * @str: the string
 * @delim: the delimiter
 *
 * Return: returns the number of words contained within string.
 */

int token_count(char *str, char *delim)
{
	int i, tokens = 0, len = 0;

	for (i = 0; *(str + i); i++)
		len++;

	for (i = 0; i < len; i++)
	{
		if (*(str + i) != *delim)
		{
			tokens++;
			i += token_length(str + i, delim);
		}
	}

	return (tokens);
}

/**
 * _strtok - Tokenizes a string.
 * @line: The string.
 * @delim: The delimiter character to tokenize the string by.
 *
 * Return: A pointer to an array containing the tokenized words.
 */
char **_strtok(char *line, char *delim)
{
	char **pointer;
	int i = 0, tokens, j, letters, k;

	tokens = token_count(line, delim);
	if (tokens == 0)
		return (NULL);

	pointer = malloc(sizeof(char *) * (tokens + 2));
	if (!pointer)
		return (NULL);

	for (j = 0; j < tokens; j++)
	{
		while (line[i] == *delim)
			i++;

		letters = token_length(line + i, delim);

		pointer[j] = malloc(sizeof(char) * (letters + 1));
		if (!pointer[j])
		{
			for (i -= 1; i >= 0; i--)
				free(pointer[i]);
			free(pointer);
			return (NULL);
		}

		for (k = 0; k < letters; k++)
		{
			pointer[j][k] = line[i];
			i++;
		}

		pointer[j][k] = '\0';
	}
	pointer[j] = NULL;
	pointer[j + 1] = NULL;

	return (pointer);
}
