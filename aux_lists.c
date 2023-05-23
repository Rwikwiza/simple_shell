#include "main.h"

void free_line_list(line_list *head);
sep_list *add_sep_node_end(sep_list **head, char *name, char *value);
void free_sep_list(sep_list *head);
line_list *add_line_node_end(line_list **head, char *dir);

/**
 * add_sep_node_end - Adds a node to the end of a alias_t linked list.
 * @head: A pointer to the head of the list_t list.
 * @name: The name of the new alias to be added.
 * @value: The value of the new alias to be added.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 */

sep_list *add_sep_node_end(sep_list **head, char *name, char *value)
{
	sep_list *node = malloc(sizeof(sep_list));
	sep_list *last;

	if (!node)
		return (NULL);

	node->next = NULL;
	node->name = malloc(sizeof(char) * (_strlen(name) + 1));
	if (!node->name)
	{
		free(node);
		return (NULL);
	}
	node->value = value;
	_strcpy(node->name, name);

	if (*head)
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = node;
	}
	else
		*head = node;

	return (node);
}

/**
 * add_line_node_end - Adds a node to the end of a list_t linked list.
 * @head: A pointer to the head of the list_t list.
 * @dir: The directory path for the new node to contain.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 */
line_list *add_line_node_end(line_list **head, char *dir)
{
	line_list *node = malloc(sizeof(line_list));
	line_list *last;

	if (!node)
		return (NULL);

	node->dir = dir;
	node->next = NULL;

	if (*head)
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = node;
	}
	else
		*head = node;

	return (node);
}

/**
 * free_sep_list - Frees a alias_t linked list.
 * @head: THe head of the alias_t list.
 */
void free_sep_list(sep_list *head)
{
	sep_list *next;

	while (head)
	{
		next = head->next;
		free(head->name);
		free(head->value);
		free(head);
		head = next;
	}
}

/**
 * free_line_list - Frees a list_t linked list.
 * @head: The head of the list_t list.
 */

void free_line_list(line_list *head)
{
	line_list *next;

	while (head)
	{
		next = head->next;
		free(head->dir);
		free(head);
		head = next;
	}
}
