#include "main.h"

char *_strdup(const char *s);
int _strlen(const char *s);
int _isdigit(int c);
char *_strncat(char *dest, char *src, int n);

/**
 * _strdup - the function duplicates a string
 * @s: the string that we are duplcating
 *
 * Return: the function returns a pointer to the duplicate string
 */

char *_strdup(const char *s)
{
	int len;
	char *dup_str;

	if (s == NULL)
		return (NULL);

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	dup_str = malloc(sizeof(char) * (len + 1));
	if (dup_str == NULL)
		return (NULL);

	return (dup_str);
}

/**
 * _strlen- the function calculates the length of a string
 * @s: the string we are calculating the length
 *
 * Return: the function returns the length of the string
 */

int _strlen(const char *s)
{
	int len, i;

	len = 0;

	for (i = 0; s[i]; i++)
		len++;

	return (len);
}


/**
 * _strncat - concatenates two strings
 * @dest:  the string being added too
 * @src: the string we adding to dest
 * @n: the bytes to be used from src
 *
 * Return: it returns a pointer to a string
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, j, total_length;
	int dest_len = 0;
	int src_len = 0;

	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}
	while (src[src_len] != '\0')
	{
		src_len++;
	}

	if (n > src_len)
	{
		total_length = dest_len + src_len;
	}
	else
	{
		total_length = dest_len + n;
	}

	j = 0;
	for (i = dest_len; i < total_length; i++)
	{
		dest[i] = src[j];
		j++;
	}

	dest[total_length + 1] = '\0';
	return (dest);
}

/**
 * _isdigit - checks if a number is between 0-9
 * @c: the number we are checking
 *
 * Return: returns 1 if c is between 0-9 else returns 0
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}


/**
 * rev_string- reversing a string
 * @s: string to be reversed
 *
 * Return: returns nothing
 */

void rev_string(char *s)
{
	int i, len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len / 2; i++)
	{
		char temp = s[i];

		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
}
