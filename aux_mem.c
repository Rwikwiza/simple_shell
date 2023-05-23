#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * copy_memory - Copies data from one memory location to another.
 * @dest: Destination pointer.
 * @src: Source pointer.
 * @size: Number of bytes to copy.
 *
 * Return: No return value.
 */
void copy_memory(void *dest, const void *src, unsigned int size)
{
	char *char_dest = (char *)dest;
	const char *char_src = (const char *)src;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_dest[i] = char_src[i];
}

/**
 * reallocate_memory - Reallocates a memory block.
 * @ptr: Pointer to the memory previously allocated.
 * @old_size: Size, in bytes, of the allocated space of ptr.
 * @new_size: New size, in bytes, of the new memory block.
 *
 * Return: Pointer to the reallocated memory block.
 *         If new_size == old_size, returns ptr without changes.
 *         If malloc fails or invalid parameters are provided, returns NULL.
 */
void *reallocate_memory(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return NULL;
	}

	if (ptr == NULL)
		return malloc(new_size);

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return NULL;

	if (new_size < old_size)
		copy_memory(new_ptr, ptr, new_size);
	else
		copy_memory(new_ptr, ptr, old_size);

	free(ptr);
	return new_ptr;
}

/**
 * reallocate_double_pointer - Reallocates a memory block for a double pointer.
 * @ptr: Double pointer to the memory previously allocated.
 * @old_size: Size, in bytes, of the allocated space of ptr.
 * @new_size: New size, in bytes, of the new memory block.
 *
 * Return: Pointer to the reallocated memory block.
 *         If new_size == old_size, returns ptr without changes.
 *         If malloc fails or invalid parameters are provided, returns NULL.
 */
char **reallocate_double_pointer(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **new_ptr;
	unsigned int i;

	if (new_size == 0)
	{
		free(ptr);
		return NULL;
	}

	if (ptr == NULL)
		return malloc(sizeof(char *) * new_size);

	new_ptr = malloc(sizeof(char *) * new_size);
	if (new_ptr == NULL)
		return NULL;

	for (i = 0; i < old_size; i++)
		new_ptr[i] = ptr[i];

	free(ptr);
	return new_ptr;
}

