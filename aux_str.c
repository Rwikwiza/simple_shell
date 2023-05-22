#include "main.h"

char *strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *str1, char *str2);
char *_strchr(char *s, char v);
int _strspn(char *s, char *accept);

/**
 * _strcat - concatinates two strings
 * @dest: the string we are adding the second string to
 * @src: the string being added to dest
 *
 * Return: the function returns the pointer to dest string
 */

char *_strcat(char *dest, const char *src)
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


	total_length = dest_len + src_len;
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
 * _strcpy - the function copies strings
 * @dest: copying destination
 * @src: the string being copied
 *
 * Return: returns a char pointer
 */

char *_strcpy(char *dest, char *src)
{
	int len, i;

	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[len] = '\0';
	return (dest);
}



/**
 * _strcmp- the function compares two strings
 * @str1: the first string
 * @str2: the second string
 *
 * Return: returns -1 if str1 < str2, returns 1 if str1 > str2
 * returns 0 if str1 == str2
 */

int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}


/**
 * _strchr-finds the  first occurence of a charater in a string
 * @s: the string that we are finding the charater in
 * @c:the charater we are finding in s
 *
 * Return: returns a pointer to the first occurence of c
 */

char *_strchr(char *s, char c)
{
	while (*s >= '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	return (0);
}

/**
 * _strspn-determines how many charaters in an initial segment
 * of a string are made up of a specific set of charaters
 * @s: the string being searched
 * @accept: the charaters being looked up in s
 *
 * Return:calculates the length of the initial segment of the string s
 * that consists of entirely of charaters from the string 'accept'
 */

int _strspn(char *s, char *accept)
{
	unsigned int len;
	int i;

	len = 0;
	while (*s != '\0')
	{
		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
			{
				len++;
				break;
			}
			else if (accept[i + 1] == '\0')
			{
				return (len);
			}
		}
		s++;
	}
	return (len);
}
