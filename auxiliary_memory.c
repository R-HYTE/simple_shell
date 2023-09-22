#include "main.h"

/**
 * _memcpy - copies information between memory locations.
 * @destination: destination pointer.
 * @source: source pointer.
 * @size: size of the new pointer.
 *
 * Return: void
 */
void _memcpy(void *destination, const void *source, unsigned int size)
{
	char *dest_ptr = (char *)destination;
	const char *src_ptr = (const char *)source;
	unsigned int i;

	for (i = 0; i < size; i++)
		dest_ptr[i] = src_ptr[i];
}

/**
 * _realloc - Reallocates a memory block.
 * @ptr: Pointer to the memory previously allocated.
 * @old_size: Size, in bytes, of the allocated space of ptr.
 * @new_size: New size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * If new_size == old_size, returns ptr without changes.
 * NULL, If malloc fails.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(new_ptr, ptr, new_size);
	else
		_memcpy(new_ptr, ptr, old_size);

	free(ptr);
	return (new_ptr);
}

/**
 * _reallocdp - Reallocates a memory block of a double pointer.
 * @ptr: Double pointer to the memory previously allocated.
 * @old_size: Size, in bytes, of the allocated space of ptr.
 * @new_size: New size, in bytes, of the new memory block.
 *
 * Return: ptr to the reallocated memory block
 * if new_size == old_size, returns ptr without changes.
 * NULL, if malloc fails.
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **new_ptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(sizeof(char *) * new_size);
	if (new_ptr == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		new_ptr[i] = ptr[i];

	free(ptr);

	return (new_ptr);
}
